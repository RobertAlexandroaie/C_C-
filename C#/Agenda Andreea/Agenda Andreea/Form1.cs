using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Xml;

namespace Agenda_Andreea
{
    public partial class Form1 : Form
    {
        private List<Persoana> Contacte; //lista de Contacte
        private int itemSelectat = -1; //ultimul item selectat in lista (folosit pentru a modifica contactele)

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            if (File.Exists("contacte.db")) // verific daca exista fisierul cu contacte
            {
                //deschid stream-ul petru a citi fisierul
                Stream stream = File.Open("contacte.db", FileMode.Open);
                //Un obiect de deserializare a formatului binar
                BinaryFormatter formatter = new BinaryFormatter();
                //citesc contactele
                Contacte = (List<Persoana>)formatter.Deserialize(stream);
                stream.Close();
                AdaugaContacteLista();
            }
            else // daca fisierul nu exista instantiez o lista goala
                Contacte = new List<Persoana>();
        }

        // metoda prin care adaug contactele deserializate in lista
        private void AdaugaContacteLista()
        {
            foreach (Persoana contact in Contacte)
            {
                listView1.Items.Add(contact.Nume);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Persoana p = new Persoana(textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text, dateTimePicker1.Value); //construirea contactului
            Contacte.Add(p);

            listView1.Items.Add(p.Nume);
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            dateTimePicker1.Value = DateTime.Now;
        }

        private void listView1_Click(object sender, EventArgs e)
        {
            textBox1.Text = Contacte[listView1.SelectedItems[0].Index].Nume;
            textBox2.Text = Contacte[listView1.SelectedItems[0].Index].Email;
            textBox3.Text = Contacte[listView1.SelectedItems[0].Index].Telefon;
            textBox4.Text = Contacte[listView1.SelectedItems[0].Index].AlteInformatii;
            dateTimePicker1.Value = Contacte[listView1.SelectedItems[0].Index].DataNasterii;
        }

        //butonul de stergere
        private void button3_Click(object sender, EventArgs e)
        {
            Remove();
        }

        //metoda pt stergerea Contactelor
        void Remove()
        {   //vom pune secventa de cod intr-o struct try-catch pt situatiile in care nu vom avea nici un item selectat din lista iar indexul va fi negativ
            try
            {
                listView1.Items.Remove(listView1.Items[itemSelectat]);
                Contacte.RemoveAt(itemSelectat);
            }
            catch (Exception e)
            { Console.WriteLine(e.ToString()); }
        }


        //atunci cand doresc sa fac modificari si sa le salvez
        private void button1_Click(object sender, EventArgs e)
        {
            Contacte[itemSelectat].Nume = textBox1.Text;
            Contacte[itemSelectat].Email = textBox2.Text;
            Contacte[itemSelectat].Telefon = textBox3.Text;
            Contacte[itemSelectat].AlteInformatii = textBox4.Text;
            Contacte[itemSelectat].DataNasterii = dateTimePicker1.Value;
            //pentru a modifica numele si in lista persoane
            listView1.Items[itemSelectat].Text = textBox1.Text;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            //deschid stream-ul petru a scrie fisierul
            Stream stream = File.Open("contacte.db", FileMode.Create);
            //un formator binar pentru a scrie obiectul in fisier
            BinaryFormatter formatter = new BinaryFormatter();
            // serializez obiectul
            formatter.Serialize(stream, Contacte);
            stream.Close();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            // verific intai daca am selectat un contact in lista
            if (listView1.SelectedItems.Count > 0)
            itemSelectat = listView1.SelectedItems[0].Index;
        }
    }

}
