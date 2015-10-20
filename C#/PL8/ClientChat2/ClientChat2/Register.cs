using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Text.RegularExpressions;
using System.Runtime.Serialization.Formatters.Binary;
using System.Reflection;
using System.Runtime.Serialization;
using System.IO;

namespace ClientChat2
{
    public partial class Register : Form
    {
        ClientChat clientChat;

        public Register()
        {
            InitializeComponent();
            //se foloseste obiectul client din variabila statica
            this.clientChat = Variabile.ClientChat;
        }

        //eveniment prin care se porneste pagina de login si se inchide pagina de register, prin thread nou
        private void button2_Click(object sender, EventArgs e)
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(LoginWindow));
            t.Start();
            this.Close();
        }

        //metoda folosita de threadul de mai sus
        public static void LoginWindow()
        {
            Application.Run(Program.logw);
        }

        //se valideaza datele introduse pentru register
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (this.textBox1.Text.Length > 6)
            {
                //se valideaza, la server, existenta utilizatorului introdus
                Variabile.Identitate = this.textBox1.Text;
                clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.UserValidate, "UtilizatorNou");
                this.pictureBox1.Enabled = true;
            }
            else
            {
                //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                this.pictureBox1.Image = Properties.Resources.wrong;
                this.pictureBox1.Enabled = false;
                this.textBox6.Text = "Username to short!";
            }

            //o metoda prin care se verifica daca toate datele introduse sunt valide
            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica lungimea parolei
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (this.textBox2.Text.Length > 6)
            {
                this.pictureBox2.Image = Properties.Resources.ok;
                this.textBox6.Text = "Password OK!";
                this.pictureBox2.Enabled = true;
            }
            else
            {
                //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                this.pictureBox2.Image = Properties.Resources.wrong;
                this.textBox6.Text = "Password to short!";
                this.pictureBox2.Enabled = false;
            }

            //o metoda prin care se verifica daca toate datele introduse sunt valide
            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica corectitudinea emailului
        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (this.textBox5.Text.Length != 0)
            {
                const string expression = @"^([a-zA-Z0-9_\-\.]+)@((\[[0-9]{1,3}" +
                              @"\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([a-zA-Z0-9\-]+\" +
                              @".)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$";

                Regex regex = new Regex(expression);
                if (regex.IsMatch(this.textBox5.Text))
                {
                    this.pictureBox3.Image = Properties.Resources.ok;
                    this.textBox6.Text = "E-mail OK!";
                    this.pictureBox3.Enabled = true;
                }
                else
                {
                    //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                    this.pictureBox3.Image = Properties.Resources.wrong;
                    this.textBox6.Text = "Invalid E-mail!";
                    this.pictureBox3.Enabled = false;
                }
            }

            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica corectitudinea numelui
        private void textBox3_TextChanged_1(object sender, EventArgs e)
        {
            if (this.textBox3.Text.Length > 3)
            {
                const string expression = @"[a-zA-Z]";

                Regex regex = new Regex(expression);

                if (regex.IsMatch(textBox3.Text))
                {
                    this.pictureBox4.Image = Properties.Resources.ok;
                    this.textBox6.Text = "First Name OK!";
                    this.pictureBox4.Enabled = true;
                }
                else
                {
                    //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                    this.pictureBox4.Image = Properties.Resources.wrong;
                    this.textBox6.Text = "Only Letters";
                    this.pictureBox4.Enabled = false;
                }
            }
            else
            {
                //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                this.pictureBox4.Image = Properties.Resources.wrong;
                this.textBox6.Text = "First Name to Short!";
                this.pictureBox4.Enabled = false;
            }

            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica corectitudinea prenumelui
        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (this.textBox4.Text.Length > 3)
            {
                const string expression = @"[a-zA-Z]";

                Regex regex = new Regex(expression);

                if (regex.IsMatch(textBox4.Text))
                {
                    this.pictureBox5.Image = Properties.Resources.ok;
                    this.textBox6.Text = "Last Name OK!";
                    this.pictureBox5.Enabled = true;
                }
                else
                {
                    //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                    this.pictureBox5.Image = Properties.Resources.wrong;
                    this.textBox6.Text = "Only Letters";
                    this.pictureBox5.Enabled = false;
                }
            }
            else
            {
                //daca datele introduse nu sunt corecte, sunt afisate anumite imagini si mesaje
                this.pictureBox5.Image = Properties.Resources.wrong;
                this.textBox6.Text = "Last Name to Short!";
                this.pictureBox5.Enabled = false;
            }

            if (VerificaDate())
                this.button1.Enabled = true;
            else
                this.button1.Enabled = false;
        }

        //se verifica corectitudinea tuturor datelor introduse pentru a activa butonul de register
        private bool VerificaDate()
        {
            if (this.pictureBox1.Enabled && 
                this.pictureBox2.Enabled && 
                this.pictureBox3.Enabled && 
                this.pictureBox4.Enabled && 
                this.pictureBox5.Enabled)
                return true;
            return false;
        }

        //un eveniment prin care se trateaza folosirea butonului de register
        private void button1_Click(object sender, EventArgs e)
        {
            MessageLibrary.Utilizator newUser = new MessageLibrary.Utilizator(this.textBox3.Text + " " + this.textBox4.Text,
                this.textBox1.Text, Criptare.Hashing(this.textBox2.Text), this.textBox5.Text);

            //se creaza un stringbuilder inc are sunt introduse informatiile despre utilizatorul nou creat
            StringBuilder UserBuilder = new StringBuilder();
            UserBuilder.Append(newUser.Username + "%^^%" + newUser.Password + "%^^%" + newUser.Email + "%^^%" + newUser.Name + "%^^%");

            //se trimite la server, spre verificare, utilizatorul nou creat
            Variabile.Identitate = this.textBox1.Text;
            clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.Register, UserBuilder.ToString());
        }

        //o metoda care foloseste un thread pentru a inchide fereastra de register si a deschide fereastra de Chat
        public static void RegisterComplete()
        {
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(ChatWindowThread));
            t.Start();
            Login.ActiveForm.Close();
        }

        //metoda apelata de threadul de mai sus
        public static void ChatWindowThread()
        {
            Application.Run(Program.chatw);
        }
    }
}
