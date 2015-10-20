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
 *  Fereastra de Login
 * */

namespace ClientChat2
{
    public partial class Login : Form
    {
        //se construieste un client
        ClientChat clientChat;

        public Login()
        {
            InitializeComponent();
            //se instantiaza clientul cu instanta stocata in variabila statica
            this.clientChat = Variabile.ClientChat;
        }

        //evenimentul de clic prin care se apeleaza procedura de executie a login-ului
        private void button1_Click(object sender, EventArgs e)
        {
            ExecutaLogin();
        }

        //un eveniment prin care se porneste un thread, se inchide fereastra curenta si se deschide fereastra de register
        private void button2_Click(object sender, EventArgs e)
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(RegisterWindow));
            t.Start();
            this.Close();
        }

        //metoda prin care se inchide fereastra de login si se porneste un thread prin care se deschide fereastra de Chat
        public static void LoginComplete()
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(ChatWindowThread));
            t.Start();
            Login.ActiveForm.Close();
        }

        //metoda de rulare a ferestrei de chat prin thread
        public static void ChatWindowThread()
        {
            Application.Run(Program.chatw);
        }

        //metoda de rulare a ferestrei de register prin thread
        public static void RegisterWindow()
        {
            Application.Run(Program.regw);
        }

        //se verifica daca textbox-ul username-ului este valid pentru a activa butonul de login
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica daca textbox-ul parolei este valid pentru a activa butonul de login
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        // se verifica validitatea datelor pentru login
        private bool VerificaDate()
        {
            if (this.textBox1.Text.Length > 6 && this.textBox2.Text.Length > 6)
                return true;
            return false;
        }

        //eveniment prin care este capturata tasta enter si folosita pentru a actiona butonul de Login
        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ExecutaLogin();
            }
        }

        //metoda prin care se executa login-ul
        private void ExecutaLogin()
        {
            if (button1.Enabled)
            {
                string parola = Criptare.Hashing(this.textBox2.Text);
                Variabile.Identitate = this.textBox1.Text;
                Variabile.Parola = parola;
                //se trimite la server, pentru a fi analizat, utilizatorul si parola
                clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.Login, parola);
            }
        }
    }
}
