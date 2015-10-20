using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Reflection;
using System.Runtime.Serialization;
using System.IO;
using System.Threading;
using System.Windows.Forms;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa in care este dezvoltata logica aplicatiei
 * */

namespace ClientChat2
{
    class ClientChat
    {
        //se construieste un client TCP
        TcpClient client;
        //se construieste un stream de retea
        NetworkStream stream;
        //se construieste un array de biti
        byte[] message = new byte[4096];

        //se instantiaza clientul TCP
        public ClientChat()
        {
            client = new TcpClient();
        }

        //se conecteaza clientul la server folosind un ip si port si se incepe citirea asincrona din stream
        public bool Connect(string IP, int PORT)
        {
            try
            {
                // se conecteaza clientul la server folosind un ip si port
                client.Connect(IP, 2005);
                //se preia stream-ul clientului
                stream = client.GetStream();
                //se incepe citirea asincrona din stream
                stream.BeginRead(message, 0, 4096, ReadCallback, client);
            }
            catch (SocketException e)
            {
                Console.WriteLine(e);
            }
            if (client.Connected)
                return true;
            else
                return false;
        }

        //procedura de serializarea a cererii trimise la server
        public void TrimiteMesaj(MessageLibrary.Variabile.TipMesaj tipMesaj, string mesajText)
        {
            // se construieste un obiect de timp Mesaj in care se include identitatea Expeditorului, tipul mesajului si cerinta
            MessageLibrary.Mesaj mesaj = new MessageLibrary.Mesaj(Variabile.Identitate, tipMesaj, mesajText);
            stream = client.GetStream();

            try
            {
                //se contruieste un stream in memorie
                MemoryStream memStream = new MemoryStream();
                //se construieste un serializator binar
                BinaryFormatter bformatter = new BinaryFormatter();
                //serializatorul binar serializeaza mesajul in stream
                bformatter.Serialize(memStream, mesaj);
                //se citeste intr-un array de biti mesajul din stream
                byte[] bytes = memStream.ToArray();
                memStream.Close();
                //se trimite array-ul de biti spre server
                stream.Write(bytes, 0, bytes.Length);
            }
            catch (SocketException se)
            {
                Console.WriteLine(se.Message);
            }
        }

        // Callback pentru citirea din stream
        private void ReadCallback(IAsyncResult result)
        {
            int read = 0;
            
            try
            {
                //se incheie citirea din stream
                read = stream.EndRead(result);
            }
            catch(Exception e)
            {
                // daca apare o exceptie la citire inseaman ca server-ul este inchis,
                // astfel clinetul se inchide
                MessageBox.Show("Server was Closed! Chat Client will now Exit","Chat Client");
                Application.Exit();
            }

            //se construieste un nou stream in memorie din mesajul in biti citit pana acum
            MemoryStream Mstream = new MemoryStream(message, 0, read);
            //se construieste un deserializator binar
            BinaryFormatter bformatter = new BinaryFormatter();
            MessageLibrary.Mesaj inputMessage;
            //se deserializeaza mesajul primit de la server sub forma obiectului Mesaj, construit anterior
            inputMessage = bformatter.Deserialize(Mstream) as MessageLibrary.Mesaj;
            //Proceseaza mesajul primit
            ProceseazaMesaj(inputMessage);
            //reseteaza citirea din stream
            stream.BeginRead(message, 0, 4096, ReadCallback, client);
        }

        //proceseaza mesajul primit in functie de tipul mesajului
        private void ProceseazaMesaj(MessageLibrary.Mesaj inputMessage)
        {
            switch (inputMessage.TipM)
            {
                    // se proceseaza mesajul primit in urma incercarii de logare
                case MessageLibrary.Variabile.TipMesaj.ResponseLogin:
                    {
                        // daca logarea s-a efectuat cu succes
                        if (inputMessage.MesajText.Equals("LoginSuccess"))
                        {
                            // porneste o procedura pentru a inchide fereastra de login si a porni fereastra de chat
                            Login.LoginComplete();
                            break;
                        }

                        // daca login-ul nu s-a efectuat
                        if (inputMessage.MesajText.Equals("WrongUsernamePassword"))
                        {
                            //utilizatorului ii apare un mesaj de eroare
                            MessageBox.Show("The Username or Password is incorrect! Try again!");
                            break;
                        }

                        // daca utilizatorul este deja logat in chat
                        if (inputMessage.MesajText.Equals("UsernameAlreadyLogin"))
                        {
                            // apare un mesaj de eroare
                            MessageBox.Show("Username already using the Chat!");
                            break;
                        }

                        break;
                    }

                    //se proceseaza lista de utilizatori primita
                case MessageLibrary.Variabile.TipMesaj.UsersList:
                    {
                        //se imparte mesajul primit in submesaje
                        Variabile.Utilizatori = inputMessage.MesajText.Split(new string[] { "$^^$" }, StringSplitOptions.RemoveEmptyEntries);
                        //se curata listele in care vor fi introdusi utilizatorii
                        Program.chatw.listView1.Items.Clear();
                        Program.chatw.comboBox1.Items.Clear();

                        foreach (string s in Variabile.Utilizatori)
                        {
                            //se introduce fiecare utilizator in lista laterala si in combobox
                            Program.chatw.listView1.Items.Add(s);
                            Program.chatw.comboBox1.Items.Add(s);
                        }

                        //se cere numele ferestrei de la server, pentru a vedea cine detine fereastra de chat
                        TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.RequestTitleWindow, "TitluFereastra");
                        break;
                    }

                    //se verifica raspunsul de validare a username-ului la Register
                case MessageLibrary.Variabile.TipMesaj.ResponseUserValidate:
                    {
                        //daca utilizatorul exista
                        if (inputMessage.MesajText.Equals("UsernameExists"))
                        {
                            //se afiseaza in fereastra de Register imaginea unui x (wrong)
                            Program.regw.pictureBox1.Image = Properties.Resources.wrong;
                            //se afiseaza pe ecran un mesaj corespunzator
                            Program.regw.textBox6.Text = "Username exists! Choose another...";
                        }
                        else
                        {
                            // daca utilizatorul nu exista se afiseaza in fereastra de Register imaginea unui check (corect)
                            Program.regw.pictureBox1.Image = Properties.Resources.ok;
                            //se afiseaza pe ecran un mesaj corespunzator
                            Program.regw.textBox6.Text = "Username OK";
                        }
                        break;
                    }

                    //se proceseaza mesajul de la register
                case MessageLibrary.Variabile.TipMesaj.ResponseRegister:
                    {
                        //daca mesajul este corect
                        if (inputMessage.MesajText.Equals("RegisterSuccess"))
                        {
                            //se inchide fereastra de register si se deschide fereastra de chat
                            Register.RegisterComplete();
                            break;
                        }
                        break;
                    }

                    //se proceseaza numele ferestrei primit de la server
                case MessageLibrary.Variabile.TipMesaj.TitluFereastra:
                    {
                        //se schimba numele ferestrei de chat pentru a contine utilizatorul curent
                        Program.chatw.Text = "Client Chat" + " - " + inputMessage.MesajText;
                        Variabile.Nume = inputMessage.MesajText;
                        break;
                    }

                    //se proceseaza informatiile primite despre utilizatorul selectat
                case MessageLibrary.Variabile.TipMesaj.ReceiveUserInfo:
                    {
                        //se afiseaza in label-urile de mai jos informatiile primite, dupa ce au fost impartite in substringuri
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "&^^&" }, StringSplitOptions.RemoveEmptyEntries);
                        Program.chatw.label7.Text = elementeMesaj[0];
                        Program.chatw.label2.Text = elementeMesaj[2];
                        Program.chatw.label6.Text = elementeMesaj[1];
                        break;
                    }

                    //se proceseaza mesajul public primit
                case MessageLibrary.Variabile.TipMesaj.ReceivePublicMessage:
                    {
                        //se imparte mesajul primit in subelemente, compuse din numele expeditorului si mesajul
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);
                        //se afiseaza in textboxul respectiv mesajul primit
                        Program.chatw.textBox1.AppendText("< " + elementeMesaj[0] + " > " + elementeMesaj[1] + "\r\n");
                        break;
                    }

                    //se proceseaza fisierul primit
                case MessageLibrary.Variabile.TipMesaj.ReceiveFile:
                    {
                        //fisierul primit are, pe langa continut, numele sau si expeditorul
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);
                        // elementeMesaj[0] - Expeditor
                        // elementeMesaj[1] - Nume Fisier
                        // elementeMesaj[2] - ContinutFisier

                        //se deschide fereastra de Save
                        Program.chatw.saveFileDialog1.FileName = elementeMesaj[1];
                        Program.chatw.saveFileDialog1.ShowDialog();

                        //se preiau bitii din stringul transmis
                        UTF8Encoding enc = new UTF8Encoding();
                        byte[] Fisier = enc.GetBytes(elementeMesaj[2]);
                        
                        //se verifica daca numele selectat de utilizator nu este gol
                        if (Program.chatw.saveFileDialog1.FileName != "")
                        {
                            // Salveaza fisierul
                            System.IO.FileStream fs = (System.IO.FileStream)Program.chatw.saveFileDialog1.OpenFile();
                            fs.Write(Fisier, 0, Fisier.Length);
                            fs.Close();
                        }
                        break;
                    }

                    //se proceseaza mesajul privat primit
                case MessageLibrary.Variabile.TipMesaj.ReceivePrivateMessage:
                    {
                        //se imparte stringul primit in elemente componente
                        string[] elementeMesaj = inputMessage.MesajText.Split(new string[] { "%^^%" }, StringSplitOptions.RemoveEmptyEntries);
                        //elementeMesaj[0] -- Utilizatorul care a trimis
                        //elementeMesaj[1] -- Mesajul

                        bool gasit = false; TabPage pagina = null;
                        //se verifica daca exista deja o pagina de tab deschisa
                        foreach (TabPage tabp in Program.chatw.tabControl1.TabPages)
                        {
                            //in acel caz
                            if (tabp.Text.Equals(elementeMesaj[0]))
                            {
                                gasit = true;
                                pagina = tabp;
                                //se preia pagina existenta si se focalizeaza
                                Program.chatw.tabControl1.SelectedTab = pagina;
                                //se adauga textul primit in componentele generate dinamic
                                Program.chatw.AdaugaTextPagina(elementeMesaj[1], elementeMesaj[0]);
                                break;
                            }
                        }

                        if (!gasit)
                        {
                            //daca pagina nu exista deja
                            Program.chatw.titlu = elementeMesaj[0];
                            //se creaza pagina folosind un delegat
                            Program.chatw.Invoke(Program.chatw.delegat);
                            //se adauga textul primit in componentele generate dinamic
                            Program.chatw.AdaugaTextPagina(elementeMesaj[1], elementeMesaj[0]);
                        }
                        break;
                    }
            }
        }
    }
}
