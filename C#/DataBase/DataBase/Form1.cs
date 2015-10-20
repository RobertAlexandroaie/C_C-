using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO; 

namespace DataBase
{
    public partial class Form1 : Form
    {
        int id = 0;

        public Form1()
        {
            InitializeComponent();
            getDrives();
            if (cDrives.Items.Count != 0)
                cDrives.Text = cDrives.Items[0].ToString();
        }

        private void getDrives()
        {
            foreach (DriveInfo drive in DriveInfo.GetDrives())
            {
                if (drive.IsReady) 
                    cDrives.Items.Add(drive.RootDirectory);
            }

            foreach (var dir in Directory.GetDirectories("C:\\"))
            {
                if (!dir.Contains("$Recycle.Bin"))
                {
                    HDDExplorerDataSet.FilesRow newRow = hDDExplorerDataSet.Files.NewFilesRow();
                    id++;
                    newRow.ID = id;
                    newRow.Item = dir;
                    newRow.Parent = "C:\\";
                    newRow.Type = "directory";
                    hDDExplorerDataSet.Files.Rows.Add(newRow);
                }
                //scanFiles(dir);
            }
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'hDDExplorerDataSet.Files' table. You can move, or remove it, as needed.
            this.filesTableAdapter.Fill(this.hDDExplorerDataSet.Files);
        }

        private void btnScan_Click(object sender, EventArgs e)
        {
            if (cDrives.Text != string.Empty)
            {
                
            }
        }

        private void btnStop_Click(object sender, EventArgs e)
        {

        }
    }
}
