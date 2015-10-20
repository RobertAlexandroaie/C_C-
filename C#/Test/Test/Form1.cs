using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //this.tabControl1.TabPages.Clear();
            AdaugaTab();
            AdaugaTab();
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                AdaugaLinie();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AdaugaLinie();
        }

        private void AdaugaLinie()
        {
            string mesaj = null;
            TabPage paginaCurenta = tabControl1.SelectedTab;
            if (paginaCurenta.Contains(textBox2))
            {
                mesaj = this.textBox2.Text.Remove(0, 1);
                this.textBox1.AppendText("<  > " + mesaj + "\r\n");
                this.textBox2.Text = "";
                this.textBox2.Focus();
            }

            TextBox text2 = null;
            TextBox text1 = null;
            Button button = null;

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

            if (text2 != null && text1 != null && button != null)
            {
                mesaj = text2.Text.Remove(0, 1);
                text1.AppendText("<  > " + mesaj + "\r\n");
                text2.Text = "";
                text2.Focus();
            }
        }

        private void AdaugaTab()
        {
            string title = "Vasile";
            // 
            // button1
            // 
            Button butonTab = new Button();
            butonTab.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            butonTab.Location = new System.Drawing.Point(135, 35);
            butonTab.Name = "butonTab" + (tabControl1.TabCount + 1).ToString();
            butonTab.Size = new System.Drawing.Size(64, 53);
            butonTab.TabIndex = 2;
            butonTab.Text = "Send";
            butonTab.UseVisualStyleBackColor = true;
            butonTab.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox2
            // 
            TextBox textTab2 = new TextBox();
            textTab2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            textTab2.Location = new System.Drawing.Point(4, 20);
            textTab2.Multiline = true;
            textTab2.Name = "textTab2" + (tabControl1.TabCount + 1).ToString();
            textTab2.Size = new System.Drawing.Size(120, 80);
            textTab2.TabIndex = 0;
            textTab2.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            // 
            // textBox1
            // 
            TextBox textTab1 = new TextBox();
            textTab1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
            | System.Windows.Forms.AnchorStyles.Left)
            | System.Windows.Forms.AnchorStyles.Right)));
            textTab1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            textTab1.Location = new System.Drawing.Point(4, 4);
            textTab1.Multiline = true;
            textTab1.Name = "textTab1" + (tabControl1.TabCount + 1).ToString();
            textTab1.ReadOnly = true;
            textTab1.Size = new System.Drawing.Size(190, 10);
            textTab1.TabIndex = 10;
            textTab1.TabStop = false;

            TabPage anotherPage = new TabPage(title);
            anotherPage.Controls.Add(butonTab);
            anotherPage.Controls.Add(textTab2);
            anotherPage.Controls.Add(textTab1);
            anotherPage.Font = new System.Drawing.Font("Verdana", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            anotherPage.Location = new System.Drawing.Point(4, 25);
            anotherPage.Name = "tabPage" + (tabControl1.TabCount + 1).ToString();
            anotherPage.Padding = new System.Windows.Forms.Padding(3);
            anotherPage.Size = new System.Drawing.Size(491, 390);
            anotherPage.TabIndex = tabControl1.TabCount + 1;
            anotherPage.UseVisualStyleBackColor = true;
            tabControl1.TabPages.Add(anotherPage);

            //tabControl1.TabPages[tabControl1.TabCount].Focus();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                System.IO.StreamReader sr = new
                   System.IO.StreamReader(openFileDialog1.FileName);
                MessageBox.Show(sr.ReadToEnd());
                sr.Close();
            }
        }
    }
}
