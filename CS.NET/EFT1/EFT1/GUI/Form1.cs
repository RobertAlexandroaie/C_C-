using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using EFT1;

namespace GUI
{
    public partial class Form1 : Form
    {
        private TestEntities _context = new TestEntities();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'testDataSet.ORDERDETAILS' table. You can move, or remove it, as needed.
            this.oRDERDETAILSTableAdapter.Fill(this.testDataSet.ORDERDETAILS);
            // TODO: This line of code loads data into the 'testDataSet.ORDER' table. You can move, or remove it, as needed.
            this.oRDERTableAdapter.Fill(this.testDataSet.ORDER);
            // TODO: This line of code loads data into the 'testDataSet.CUSTOMER' table. You can move, or remove it, as needed.
            this.cUSTOMERTableAdapter.Fill(this.testDataSet.CUSTOMER);

        }

        //private void buttonInsertCustomer_Click(object sender, EventArgs e)
        //{
        //    _context.InsertCustomer(Int16.Parse(textBoxID.Text), textBoxName.Text, textBoxAdresa.Text);
        //}


    }
}
