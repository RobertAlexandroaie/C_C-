using System;
using System.Windows.Forms;

/**
 * @author: DĂNILĂ Ionuț, Group 1A
 */

namespace DiskDataBase
{
    public partial class InputBox : Form
    {
        public InputBox()
        {
            InitializeComponent();
        }

        public new string Name { get; set; }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Close();
            Name = "CANCELFORM";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Name = textBox1.Text;
            this.Close();
        }
    }
}
