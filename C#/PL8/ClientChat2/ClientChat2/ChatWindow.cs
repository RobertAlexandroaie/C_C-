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
 *  Fereastra principala de Chat
 * */

namespace ClientChat2
{
    public partial class ChatWindow : Form
    {
        //clientul de chat folosit
        ClientChat clientChat;

        //un delegate pentru adaugare de tab-uri
        public delegate void AdaugaComponente();
        public AdaugaComponente Delegat;
        
        //un string public pentru construirea de pagini la tab
        public string titlu = null;

        public ChatWindow()
        {
            InitializeComponent();
            //folosirea aceluiasi client, chiar daca pagina anterioara s-a inchis
            this.clientChat = Variabile.ClientChat;

            //initializare delegat
            Delegat = AdaugaTab; 
        }

        //la incarcarea ferestrei
        private void ChatWindow_Load(object sender, EventArgs e)
        {
            //se cere lista de utilizatori de la server
            clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.RequestUsersList, "FreshLogin");
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            //se verifica apasarea tastei Enter si se copie textul scris in textbox-ul superior
            if (e.KeyChar == (char)13)
            {
                AdaugaLinie();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // apsarea butonului Send executa aceeasi operatie ca apasarea tastei ENter in interiorul textbox-ului
            AdaugaLinie();
        }

        // adaugarea mesajului primit in tab-uri noi, dinamic
        public void AdaugaTextPagina(string mesaj, string Expeditor)
        {
            //se preia pagina curenta
            TabPage paginaCurenta = tabControl1.SelectedTab;

            //se instantiaza controalele necesare, adaugate dinamic in pagina Tab-ului
            TextBox text2 = null;
            TextBox text1 = null;
            Button button = null;

            //se instantiaza controalele in functie de numele controalelor din pagina
            foreach (Control c in paginaCurenta.Controls)
            {
                if (c.Name.Equals("textTab2" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    text2 = c as TextBox;
                }

                if (c.Name.Equals("textTab1" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    text1 = c as TextBox;
                }

                if (c.Name.Equals("butonTab" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    button = c as Button;
                }
            }

            //se verifica daca s-au gasit toate controalele necesare
            if (text2 != null && text1 != null && button != null)
            {
                //se afiseaza mesajul primit si expeditorul mesajului
                text1.AppendText("< " + Expeditor + " > " + mesaj + "\r\n");
                text2.Text = String.Empty;
                text2.Focus();
            }
        }

        // se copie mesajul din textbox-ul inferior in textbox-ul superior
        // si se trimite tuturor clientilor (in cazul mesajului public) sau unui anumit client (mesaj privat)
        private void AdaugaLinie()
        {
            string mesaj = null;
            // se preia pagina curenta
            TabPage paginaCurenta = tabControl1.SelectedTab;
            
            // folosim numele paginii pentru a sti cui se adreseaza utilizatorul (Destinatarul mesajului)
            string NumePagina = paginaCurenta.Text;

            // daca pagina curenta este in Main Chat
            if (paginaCurenta.Contains(textBox2))
            {
                // daca textbox-ul inferior nu este gol
                if (this.textBox2.Text.Length > 0)
                {
                    //se copie mesajul in textboxul superior
                    mesaj = this.textBox2.Text.Trim();
                    this.textBox1.AppendText("< " + Variabile.Nume + " > " + mesaj);
                    this.textBox1.AppendText("\r\n");
                    this.textBox2.Text = String.Empty;
                    this.textBox2.Focus();
                }
                // se trimite mesajul copiat la toti clientii
                clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.SendPublicMessage, mesaj);
            }

            //se construiesc trei controale, in cazul in care mesajul este intr-un tab creat dinamic
            TextBox text2 = null;
            TextBox text1 = null;
            Button button = null;

            //se instantiaza controalele in functie de numele controalelor din pagina
            foreach (Control c in paginaCurenta.Controls)
            {
                if (c.Name.Equals("textTab2" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    text2 = c as TextBox;
                }

                if (c.Name.Equals("textTab1" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    text1 = c as TextBox;
                }

                if (c.Name.Equals("butonTab" + (tabControl1.SelectedIndex + 1).ToString()))
                {
                    button = c as Button;
                }
            }

            //se verifica daca s-au gasit toate controalele necesare
            if (text2 != null && text1 != null && button != null)
            {
                if (text2.Text.Length > 0)
                {
                    //daca textboxul inferior nu este gol se copie mesajul in textboxul superior
                    mesaj = text2.Text.Trim();
                    text1.AppendText("< " + Variabile.Nume + " > " + mesaj + "\r\n");
                    text2.Text = String.Empty;
                    text2.Focus();
                }
                // se trimite mesajul unui anumit client (care are acelasi nume cu numele paginii)
                clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.SendPrivateMessage, NumePagina + "%^^%" + mesaj);
            }
        }

        // evenimentul de dublu clic implementat asupra listei de utilizatori
        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            string title = null;
            // se cauta elementul selectat pentru a prelua numele
            foreach (ListViewItem item in listView1.SelectedItems)
            {
                if (item.Selected)
                    title = item.Text;
            }
            this.titlu = title;
            // se adauga, dinamic, un tab
            AdaugaTab();
        }

        // procedura de adaugare de tab-uri
        private void AdaugaTab()
        {
            // se instantiaza butonul de send
            Button butonTab = new Button();
            butonTab.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            butonTab.Location = new System.Drawing.Point(135, 35);
            butonTab.Name = "butonTab" + (tabControl1.TabCount + 1).ToString();
            butonTab.Size = new System.Drawing.Size(64, 53);
            butonTab.TabIndex = 2;
            butonTab.Text = "Send";
            butonTab.UseVisualStyleBackColor = true;
            butonTab.Click += new System.EventHandler(this.button1_Click);
            
            // se instantiaza un textbox inferior
            TextBox textTab2 = new TextBox();
            textTab2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            textTab2.Location = new System.Drawing.Point(4, 20);
            textTab2.Multiline = true;
            textTab2.Name = "textTab2" + (tabControl1.TabCount + 1).ToString();
            textTab2.Size = new System.Drawing.Size(120, 80);
            textTab2.TabIndex = 0;
            textTab2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            
            // se instantiaza textboxul superior
            TextBox textTab1 = new TextBox();
            textTab1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
            | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            textTab1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            textTab1.Location = new System.Drawing.Point(4, 4);
            textTab1.Multiline = true;
            textTab1.Name = "textTab1" + (tabControl1.TabCount + 1).ToString();
            textTab1.ReadOnly = true;
            textTab1.Size = new System.Drawing.Size(190, 0);
            textTab1.TabIndex = 10;
            textTab1.TabStop = false;
          
            //se adauga componentele create intr-o pagina noua
            TabPage anotherPage = new TabPage(this.titlu);
            anotherPage.Controls.Add(butonTab);
            anotherPage.Controls.Add(textTab2);
            anotherPage.Controls.Add(textTab1);
            
            //se personalizeaza pagina creata
            anotherPage.Font = new System.Drawing.Font("Verdana", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            anotherPage.Location = new System.Drawing.Point(4, 25);
            anotherPage.Name = "tabPage" + (tabControl1.TabCount + 1).ToString();
            anotherPage.Padding = new System.Windows.Forms.Padding(3);
            anotherPage.Size = new System.Drawing.Size(491, 390);
            anotherPage.TabIndex = tabControl1.TabCount + 1;
            anotherPage.UseVisualStyleBackColor = true;
            
            //se adauga pagina creata la controlul de tab-uri
            tabControl1.TabPages.Add(anotherPage);
            
            //se selecteaza pagina selectata si se face focus pe ea
            tabControl1.SelectedTab = tabControl1.TabPages[tabControl1.TabCount-1];
        }

        // o metoda pentru a deschide fereastra de selectie de fisiere
        public void OpenFIleDialog()
        {
            //se selecteaza fisierul in fereastra deschisa
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                this.button2.Text = "File Selected";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //se porneste un thread pentru a deschide fereastra de selectie de fisiere, pentru ca aplicatia sa nu se blocheze
            System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(OpenFIleDialog));
            t.Start();
        }

        //se trimite fisierul utilizatorului selectat
        private void button3_Click(object sender, EventArgs e)
        {
            //in cazul in care este selectat fisierul si utilizatorul selectat
            if (this.button2.Text.Equals("File Selected") && this.comboBox1.SelectedIndex > 0)
            {
                //se creaza un stream al fisierului
                System.IO.StreamReader sr = new System.IO.StreamReader(openFileDialog1.FileName);
                string Fisier = sr.ReadToEnd();
                sr.Close();

                //se trimite streamul spre utilizatorul selectat
                clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.SendFile, this.comboBox1.SelectedItem.ToString() + "%^^%" + openFileDialog1.FileName + "%^^%" + Fisier);
            }
            else
            {
                MessageBox.Show("First select the file and the Recipient User!","Client Chat");
            }
        }

        // eveniment in care se trateaza selectia unui item din lista cu utilizatori
        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            string user = null;
            //se gaseste item-ul selectat
            foreach (ListViewItem item in listView1.SelectedItems)
            {
                if (item.Selected)
                    user = item.Text;
            }

            //se cere de la server informatii despre utilizatorul selectat
            clientChat.TrimiteMesaj(MessageLibrary.Variabile.TipMesaj.GetUserInfo, user);
        }
    }
}
