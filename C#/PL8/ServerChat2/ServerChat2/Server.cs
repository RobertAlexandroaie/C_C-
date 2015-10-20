using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Runtime.Serialization.Formatters.Binary;
using System.Reflection;
using System.Runtime.Serialization;
using System.IO;
using System.Threading;

/** Client si Server Chat
 * @Author: Ionut Danila
 * */

namespace ServerChat2
{
    // Un Server TCP Asyncron care foloseste threaduri si callbacks pentru a nu se bloca
    public class ServerTCP
    {
        //Listener pentru eventualele conexiuni
        private TcpListener tcpListener;

        //lista clientilor conectati
        private List<Client> clients;

        //baza de date cu utilizatori
        private string UsersFile = "UsersList.xml";

        //lista cu utilizatori din baza de date
        private List<MessageLibrary.Utilizator> DBUsers;

        // Thread signal.
        public static ManualResetEvent allDone = new ManualResetEvent(false);

        // Constructor pentru un server nou folosind IPAddress si Port
        public ServerTCP(IPAddress localaddr, int port) : this()
        {
            tcpListener = new TcpListener(localaddr, port);
        }

        // Constructor privat pentru a instatia lista cu clienti
        private ServerTCP()
        {
            this.clients = new List<Client>();
        }

        // Un getter pentru toti clientii
        public IEnumerable<TcpClient> TcpClients
        {
            get
            {
                foreach (Client client in this.clients)
                {
                    yield return client.TcpClient;
                }
            }
        }

        // Porneste TCP Server pentru Listen la clienti
        public void Start()
        {
            try
            {
                //start server
                this.tcpListener.Start();

                //citeste baza de date cu utilizatori
                DBUsers = ParsareXML.ReadXMLDocument(UsersFile);

                while (true)
                {
                    // Set the event to nonsignaled state.
                    allDone.Reset();

                    //O metoda asyncron de ascultare a conexiunilor
                    AfiseazaMesaj("-- Waiting for a connection...");
                    this.tcpListener.BeginAcceptTcpClient(AcceptTcpClientCallback, null);

                    // Wait until a connection is made before continuing.
                    allDone.WaitOne();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Only ONE Instance of the server can run!");
            }
        }

        // Callback pentru operatia de Accept a clientului
        private void AcceptTcpClientCallback(IAsyncResult result)
        {
            //finalizeaza acceptul
            TcpClient tcpClient = tcpListener.EndAcceptTcpClient(result);
            // creaza un buffer pentru citirea mesajului
            byte[] buffer = new byte[tcpClient.ReceiveBufferSize];

            //creaza un client local si il adauga in lista de clienti
            Client client = new Client(tcpClient, buffer);
            AfiseazaMesaj("-- New Client from " + client.TcpClient.Client.RemoteEndPoint);

            lock (this.clients)
            {
                this.clients.Add(client);
            }
            //preia stream-ul clientului
            NetworkStream networkStream = client.NetworkStream;

            try
            {
                //incepe citirea asincron a mesajului
                networkStream.BeginRead(client.Buffer, 0, client.Buffer.Length, ReadCallback, client);
            }
            catch (Exception e)
            {
                AfiseazaMesaj("Eroare!");
            }
            
            // Signal the main thread to continue.
            allDone.Set();

            try
            {
                //reseteaza metoda de accept asincron
                tcpListener.BeginAcceptTcpClient(AcceptTcpClientCallback, null);
            }
            catch(Exception e)
            {
                AfiseazaMesaj("Eroare Begin Accept!");
            }
        }


        // Opreste Serverul TCP din ascultare si deconecteaza toti clientii
        public void Stop()
        {
            try
            {
                this.tcpListener.Stop();
            }
            catch(SocketException e)
            {
                AfiseazaMesaj(e.ToString());
            }

            // lock blocheaza lista cu clienti si obtine acces exclusiv
            lock (this.clients)
            {
                foreach (Client client in this.clients)
                {
                    try
                    {
                        //deconecteaza clientii
                        client.TcpClient.Client.Disconnect(false);
                    }
                    catch(Exception e)
                    {
                        AfiseazaMesaj(e.ToString());
                    }
                }
                this.clients.Clear();
            }
        }

        // Trimite un mesaj, in biti, la toti clientii conectati
        public void Write(byte[] bytes)
        {
            foreach (Client client in this.clients)
            {
                Write(client.TcpClient, bytes);
            }
        }

        // Trimite un mesaj in biti la un anumit client
        public void Write(TcpClient tcpClient, byte[] bytes)
        {
            NetworkStream networkStream = tcpClient.GetStream();
            //metoda asyncron de scriere a mesajului
            networkStream.BeginWrite(bytes, 0, bytes.Length, WriteCallback, tcpClient);
        }

        // Callback pentru operatia de scriere
        private void WriteCallback(IAsyncResult result)
        {
            TcpClient tcpClient = result.AsyncState as TcpClient;
            NetworkStream networkStream = tcpClient.GetStream();
            //finalizeaza scrierea asincron
            networkStream.EndWrite(result);
        }

        private void AfiseazaMesaj(string mesajInput)
        {
            Console.WriteLine(mesajInput);
        }

        // Callback pentru citirea din stream
        private void ReadCallback(IAsyncResult result)
        {
            Client client = result.AsyncState as Client;
            if (client == null) return;
            NetworkStream networkStream = client.NetworkStream;
            int read = 0;

            try
            {
                read = networkStream.EndRead(result);
            }
            catch(Exception e)
            {
                AfiseazaMesaj("-- User "+client.Identitate+" ("+client.TcpClient.Client.RemoteEndPoint+")"+" is Offline");
                TrimiteMesajPublic("Server" + "%^^%"+ "User "+client.Identitate+" went Offline...",client);
            }

            if (read == 0)
            {
                lock (this.clients)
                {
                    this.clients.Remove(client);
                    TrimiteListaUtilizatori();
                    return;
                }
            }

            MemoryStream stream = new MemoryStream(client.Buffer, 0, read);
            BinaryFormatter bformatter = new BinaryFormatter();

            MessageLibrary.Mesaj inputMessage = bformatter.Deserialize(stream) as MessageLibrary.Mesaj;

            //Proceseaza mesajul primit
            ProceseazaMesaj(inputMessage, client);

            //reseteaza citirea din stream
            networkStream.BeginRead(client.Buffer, 0, client.Buffer.Length, ReadCallback, client);
        }

        private void ProceseazaMesaj(MessageLibrary.Mesaj inputMessage, Client client)
        {
            switch (inputMessage.TipM)
            {
                case MessageLibrary.Variabile.TipMesaj.Login:
                    {
                        AfiseazaMesaj("-- New Login Request from " + client.TcpClient.Client.RemoteEndPoint);
                        int gasit = 0; MessageLibrary.Utilizator uGasit = null;

                        foreach (MessageLibrary.Utilizator u in DBUsers)
                        {
                            if (u.Username.ToUpper().Equals(inputMessage.Identitate.ToUpper()))
                            {
                                if (inputMessage.MesajText.Equals(u.Password))
                                {
                                    uGasit = u;
                                    gasit = 1;
                                }
                            }
                        }

                        if (gasit.Equals(1))
                            foreach (Client clientInput in clients)
                            {
                                if (clientInput.Identitate != null)
                                    if (clientInput.Identitate.ToUpper().Equals(uGasit.Name.ToUpper()))
                                    {
                                        gasit = 2;
                                    }
                            }

                        if (gasit.Equals(1))
                        {
                            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseLogin, "LoginSuccess", client);
                            client.Identitate = uGasit.Name;
                            AfiseazaMesaj("-- User " + client.Identitate + " (" + client.TcpClient.Client.RemoteEndPoint + ") " + "is Online!");
                            TrimiteMesajPublic("Server" + "%^^%" + "User " + client.Identitate + " went Online...", client);
                        }

                        if (gasit.Equals(0))
                        {
                            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseLogin, "WrongUsernamePassword", client);
                        }

                        if (gasit.Equals(2))
                        {
                            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseLogin, "UsernameAlreadyLogin", client);
                        }
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.RequestUsersList:
                    {
                        TrimiteListaUtilizatori();
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.RequestTitleWindow:
                    {
                        TrimiteTitluFereastraChat(client);
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.GetUserInfo:
                    {
                        StringBuilder DetaliiUtilizator = new StringBuilder();

                        foreach (MessageLibrary.Utilizator u in DBUsers)
                        {
                            if (u.Name.ToUpper().Equals(inputMessage.MesajText.ToUpper()))
                            {
                                DetaliiUtilizator.Append(u.Username);
                                DetaliiUtilizator.Append("&^^&");
                                DetaliiUtilizator.Append(u.Email);
                                DetaliiUtilizator.Append("&^^&");
                                DetaliiUtilizator.Append(u.Name);
                                DetaliiUtilizator.Append("&^^&");
                            }
                        }

                        CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ReceiveUserInfo, DetaliiUtilizator.ToString(), client);
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.UserValidate:
                    {
                        AfiseazaMesaj("-- New Username Request from " + client.TcpClient.Client.RemoteEndPoint);
                        bool gasit = false;

                        foreach (MessageLibrary.Utilizator u in DBUsers)
                        {
                            if (u.Username.ToUpper().Equals(inputMessage.Identitate.ToUpper()))
                            {
                                gasit = true;
                            }
                        }

                        if (gasit)
                        {
                            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseUserValidate, "UsernameExists", client);
                        }
                        else
                        {
                            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseUserValidate, "UsernameOK", client);
                        }
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.Register:
                    {
                        string[] userDescription = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);

                        MessageLibrary.Utilizator userNew = new MessageLibrary.Utilizator(userDescription[3],
                            userDescription[0],userDescription[1],userDescription[2]);
                        DBUsers.Add(userNew);
                        ParsareXML.WriteXMLFile(UsersFile, DBUsers);

                        CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ResponseRegister, "RegisterSuccess", client);
                        client.Identitate = userNew.Name;
                        AfiseazaMesaj("-- User " + client.Identitate + " (" + client.TcpClient.Client.RemoteEndPoint + ") " + "Registered and is Online!");
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.SendPublicMessage:
                    {
                        string MesajPublic = client.Identitate+"%^^%"+inputMessage.MesajText;
                        TrimiteMesajPublic(MesajPublic, client);
                        AfiseazaMesaj("-- User " + client.Identitate + " (" + client.TcpClient.Client.RemoteEndPoint + ") " + "sent a Public message!");
                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.SendPrivateMessage:
                    {
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);
                        //elementeMesaj[0] - Destinatarul
                        //elementeMesaj[1] - Mesaj

                        foreach (Client cSearch in clients)
                        {
                            if (cSearch.Identitate.Equals(elementeMesaj[0]))
                            {
                                string MesajPrivat = client.Identitate + "%^^%" + elementeMesaj[1];
                                TrimiteMesajPrivat(MesajPrivat, cSearch);
                                break;
                            }
                        }

                        break;
                    }

                case MessageLibrary.Variabile.TipMesaj.SendFile:
                    {
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);
                        //elementeMesaj[0] - Destinatarul
                        //elementeMesaj[1] - Numele Fisierului
                        //elementeMesaj[2] - Continutul

                        foreach (Client cSearch in clients)
                        {
                            if (cSearch.Identitate.Equals(elementeMesaj[0]))
                            {
                                string ContinutFisier = client.Identitate + "%^^%" + elementeMesaj[1] + "%^^%" + elementeMesaj[2];
                                TrimiteFisier(ContinutFisier, cSearch);
                                break;
                            }
                        }

                        break;
                    }
            }
        }

        private void CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj tipMesaj, string mesajText, Client client)
        {
            MessageLibrary.Mesaj mesaj = new MessageLibrary.Mesaj("Server", tipMesaj, mesajText);

            try
            {
                MemoryStream memStream = new MemoryStream();
                BinaryFormatter bformatter = new BinaryFormatter();
                bformatter.Serialize(memStream, mesaj);
                byte[] bytes = memStream.ToArray();
                memStream.Close();
                Write(client.TcpClient, bytes);
            }
            catch (SocketException se)
            {
                Console.WriteLine(se.Message);
            }
        }

        private void TrimiteListaUtilizatori()
        {
            StringBuilder usersList = new StringBuilder();

            foreach (Client client in this.clients)
            {
                if (client.Identitate != null)
                {
                    usersList.Clear();

                    foreach (Client c in clients)
                    {
                        if (!client.Identitate.Equals(c.Identitate))
                            usersList.Append(c.Identitate + "$^^$");
                    }

                    CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.UsersList, usersList.ToString(), client);
                }
            }
        }

        private void TrimiteMesajPublic(string MesajPublic, Client cPublic)
        {
            foreach (Client client in this.clients)
            {
                if (client.Identitate != null && client.Identitate != cPublic.Identitate)
                {
                    CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ReceivePublicMessage, MesajPublic, client);
                }
            }
        }

        private void TrimiteMesajPrivat(string MesajPrivat, Client cPublic)
        {
           CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ReceivePrivateMessage, MesajPrivat, cPublic);
        }

        private void TrimiteFisier(string ContinutFisier, Client cPublic)
        {
            CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.ReceiveFile, ContinutFisier, cPublic);
        }

        private void TrimiteTitluFereastraChat(Client client)
        {
            if (client.Identitate != null)
            {
                CompuneMesajTrimite(MessageLibrary.Variabile.TipMesaj.TitluFereastra, client.Identitate, client);
            }
        }

    }


    // O clasa interna Client pentru a usura lucrul
    internal class Client
    {
        public Client(TcpClient tcpClient, byte[] buffer)
        {
            this.TcpClient = tcpClient;
            this.Buffer = buffer;
        }

        // returneaza Clientul TCP
        public TcpClient TcpClient { get; private set; }


        // returneaza Bufferul.
        public byte[] Buffer { get; private set; }


        // returneaza streamul clientului
        public NetworkStream NetworkStream { get { return TcpClient.GetStream(); } }

        //identitatea care apare in lista cu utilizatori
        public String Identitate { get; set; }
    }
}