using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Fereastra de Conectare
 * */

namespace ClientChat2
{
    public partial class Connect : Form
    {
        //se instantiaza un nou client de Chat
        static ClientChat clientChat = new ClientChat();

        public Connect()
        {
            InitializeComponent();
        }

        //se proceseaza evenimentul de clic pe butonul de Conectare
        private void button1_Click(object sender, EventArgs e)
        {
            ConecteazaServer();
        }

        //se conecteaza la server
        private void ConecteazaServer()
        {
            if (clientChat.Connect("10.1.5.4", 2005))
            {
                //se foloseste un thread pentru a porni pagina de Login si a inchide pagina de conectare
                System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(ThreadProc));
                t.Start();
                this.Close();
            }
            else
            {
                //daca serverul nu este pornit apare un mesaj corespunzator
                MessageBox.Show("Chat Server is Offline! Try again later!", "Client Chat");
            }
        }

        //procedura pe care o foloseste thread-ul de mai sus
        public static void ThreadProc()
        {
            Variabile.ClientChat = clientChat;
            Application.Run(new Login());
        }

        //la incarcarea paginii se incearca conectarea automata la server
        private void Connect_Load(object sender, EventArgs e)
        {
            ConecteazaServer();
        }
    }
}
