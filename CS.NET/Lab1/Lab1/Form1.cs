using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Objects;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Lab1
{
    public partial class Form1 : Form
    {
        private short _maxID = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GetCusotmers();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (var tabele = new Test())
            {
                var c = new Customer { CustomerID = (short)(_maxID+1), Adresa = textBox2.Text, Name = textBox1.Text };
                tabele.AddToCustomer(c);
                tabele.SaveChanges();
                GetCusotmers();
            }
        }

        private void GetCusotmers()
        {
            var tabele = new Test();
            comboBox1.DataSource = tabele.Customer;
            comboBox1.DisplayMember = "CustomerID";
            _maxID = tabele.Customer.Max(s => s.CustomerID);
            tabele.Dispose();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            using (var tabele = new Test())
            {
                var customer = (Customer) comboBox1.SelectedItem;
                int selectedCustomerID = customer.CustomerID;

                //select customer dupa CustomerID
                var customerQuery =
                    from p in tabele.Customer
                    where p.CustomerID == selectedCustomerID
                    select p;
                var selectedCustomer = customerQuery.ToList();

                //afiseaza Numele
                textBox1.Text = selectedCustomer.Count > 0 ? selectedCustomer.First().Name : "NECUNOSCUT";

                //afiseaza Adresa
                textBox2.Text = selectedCustomer.Count > 0 ? selectedCustomer.First().Adresa : "NECUNOSCUT";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (var tabele = new Test())
            {
                var customer = (Customer)comboBox1.SelectedItem;
                int selectedCustomerID = customer.CustomerID;

                //select customer dupa CustomerID
                var customerQuery =
                    from p in tabele.Customer
                    where p.CustomerID == selectedCustomerID
                    select p;
                var selectedCustomer = customerQuery.ToList();
            }
        }
    }
}
