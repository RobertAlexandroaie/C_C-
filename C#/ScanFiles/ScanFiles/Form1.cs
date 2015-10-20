//Downloaded from
//Visual C# Kicks - http://vckicks.110mb.com/
//The Code Project - http://www.codeproject.com/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO; //Needed

namespace ScanFiles
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            getDrives();
            if (cDrives.Items.Count != 0)
                cDrives.Text = cDrives.Items[0].ToString();
        }

        //Find the names of the harddrives
        private void getDrives()
        {
            foreach (DriveInfo drive in DriveInfo.GetDrives())
            {
                if (drive.IsReady) //Check to see there is something in the drive
                    cDrives.Items.Add(drive.RootDirectory);
            }
        }

        //Recursive function to scan through directories
        bool stop; //Tells the function to stop
        private void scanFiles(string rootDirectory)
        {
            this.Text = "Scanning Files...";
            try
            {
                if (stop) return;
                foreach (string dir in Directory.GetDirectories(rootDirectory))
                {
                    if (stop) return;
                    Application.DoEvents();
                    if (dir.ToLower().IndexOf("$recycle.bin") == -1)
                        scanFiles(dir); //recursive call
                }

                foreach (string file in Directory.GetFiles(rootDirectory))
                {
                    if (stop) return;
                    Application.DoEvents();
                    addNode(file, null); //null because we might not have the first node yet
                }
            }
            catch (Exception)
            {
            }
        }

        //Recursive function to add a full path into a treeview
        private void addNode(string text, TreeNode parent)
        {
            if (text.EndsWith("\\")) text.TrimEnd(new char[] { '\\' });

            if (parent == null)
            {
                //Add/Find the first node
                if (text.IndexOf("\\") != -1)
                {
                    int parentIndex;
                    string nodeString;
                    if (text.IndexOf(":") != -1) //C:\ want to preserve the backslash
                    {
                        //Check to see if it exists first                        
                        nodeString = text.Substring(0, text.IndexOf("\\") + 1);
                        parentIndex = treeFiles.Nodes.IndexOfKey(nodeString);

                        //Node does not exist so create it
                        if (parentIndex == -1)
                        {
                            //Important to set the key to the text so it is easier to look up the node later
                            treeFiles.Nodes.Add(nodeString, nodeString); 
                            parentIndex = treeFiles.Nodes.Count - 1;
                        }

                    }
                    else
                    {
                        nodeString = text.Substring(0, text.IndexOf("\\"));
                        parentIndex = treeFiles.Nodes.IndexOfKey(nodeString);

                        if (parentIndex == -1)
                        {
                            treeFiles.Nodes.Add(nodeString, nodeString);
                            parentIndex = treeFiles.Nodes.Count - 1;
                        }
                    }

                    parent = treeFiles.Nodes[parentIndex];
                    text = text.Substring(text.IndexOf("\\") + 1);
                }
                else
                {
                    //Simply add it if it does not exist
                    if (treeFiles.Nodes.IndexOfKey(text) == -1)
                        treeFiles.Nodes.Add(text, text);
                }
            }

            if (text.IndexOf("\\") != -1)
            {
                string nodeString = text.Substring(0, text.IndexOf("\\"));
                int parentIndex = parent.Nodes.IndexOfKey(nodeString);

                if (parentIndex == -1)
                {
                    parent.Nodes.Add(nodeString, nodeString);
                    parentIndex = parent.Nodes.Count - 1;
                }

                addNode(text.Substring(text.IndexOf("\\") + 1), parent.Nodes[parentIndex]);
            }
            else
            {
                //No children nodes necessary, just add it
                if (parent.Nodes.IndexOfKey(text) == -1)
                    parent.Nodes.Add(text, text);
            }
        }

        private void btnScan_Click(object sender, EventArgs e)
        {
            if (cDrives.Text != string.Empty)
            {
                stop = false;

                btnStop.Enabled = true;
                btnScan.Enabled = false;

                scanFiles(cDrives.Text);
                this.Text = "Done";

                btnStop.Enabled = false;
                btnScan.Enabled = true;
            }
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            stop = true;
        }        

        private void treeFiles_NodeMouseDoubleClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            treeFiles.PathSeparator = "\\"; //Make sure to separate by \
            string fullPath = e.Node.FullPath;

            //fullPath will most likey having somethinc like C:\\hello\file.txt
            //Check for the double backlash and remove it
            //Note: "\\" means \ and @"\\" means \\
            if (fullPath.IndexOf(@"\\") != -1)
            {
                fullPath = fullPath.Substring(0, fullPath.IndexOf(@"\\")) + "\\" + fullPath.Substring(fullPath.IndexOf(@"\\") + 2);
            }

            System.Diagnostics.Process.Start(fullPath);
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            treeFiles.Nodes.Clear();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            stop = true; //Abort scanning if it were running
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.codeproject.com");
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://vckicks.110mb.com/csharp_resources.html");
        }
    }
}