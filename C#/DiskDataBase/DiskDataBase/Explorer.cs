using System;
using System.Globalization;
using System.IO;
using System.Windows.Forms;

/**
 * @author: DĂNILĂ Ionuț, Group 1A
 */

namespace DiskDataBase
{
    public partial class Explorer : Form
    {
        private int _id;

        public Explorer()
        {
            InitializeComponent();
        }

        private void filesBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.filesBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.diskManagementDataSet);
        }

        private void getDrives()
        {
            foreach (DriveInfo drive in DriveInfo.GetDrives())
            {
                if (drive.IsReady)
                {
                    cDrives.Items.Add(drive.RootDirectory);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            getDrives();
            if (cDrives.Items.Count != 0)
                cDrives.Text = cDrives.Items[0].ToString();
            this.filesTableAdapter.Fill(this.diskManagementDataSet.Files);
        }

        private void GetDirectories(string root, int parentId)
        {

            foreach (var dir in Directory.GetDirectories(root))
            {
                try
                {
                    Application.DoEvents();
                    DiskManagementDataSet.FilesRow newRow = diskManagementDataSet.Files.NewFilesRow();
                    _id++;
                    progressBar1.Value = _id;
                    newRow.FileID = _id;
                    newRow.Filename = dir.Substring(dir.LastIndexOf("\\", System.StringComparison.Ordinal) + 1);
                    newRow.Path = dir;
                    newRow.ParentID = parentId;
                    newRow.Type = "directory";
                    diskManagementDataSet.Files.Rows.Add(newRow);
                    filesTableAdapter.Update(diskManagementDataSet.Files);
                    GetFiles(dir, newRow.FileID);
                    GetDirectories(dir, newRow.FileID);
                }
                catch (Exception e)
                {
                    this.textBox1.AppendText("Directory \"" + dir + "\" is not Accessible!\r\n");
                }
            }
        }

        private void GetFiles(string root, int parentId)
        {

            foreach (var file in Directory.GetFiles(root))
            {
                try
                {
                    Application.DoEvents();
                    DiskManagementDataSet.FilesRow newRow = diskManagementDataSet.Files.NewFilesRow();
                    _id++;
                    progressBar1.Value = _id;
                    newRow.FileID = _id;
                    newRow.Filename = file.Substring(file.LastIndexOf("\\", System.StringComparison.Ordinal) + 1);
                    newRow.Path = file;
                    newRow.ParentID = parentId;
                    newRow.Type = "file";
                    diskManagementDataSet.Files.Rows.Add(newRow);
                    filesTableAdapter.Update(diskManagementDataSet.Files);
                }
                catch (Exception e)
                {
                    this.textBox1.AppendText("File \"" + file + "\" is not Accessible!\r\n");
                }
            }
        }

        private void cDrives_SelectedIndexChanged(object sender, EventArgs e)
        {
            AddTree();
        }

        private void AddTree()
        {
            string query = "Path LIKE '%" + cDrives.Text + "%'";

            var returnedRows = diskManagementDataSet.Files.Select(query);
            var results = returnedRows.Length;

            if (results > 0)
            {
                foreach (var returnedRow in returnedRows)
                {
                    if (returnedRow["Type"].ToString().Equals("directory"))
                        AddNode(returnedRow["Path"].ToString(), null); //null because we might not have the first node yet
                }
            }
            else
            {
                this.textBox1.AppendText("No directories found in Database for Partition \"" + cDrives.Text + "\"! Press \"Scan Partition\" to add Directories!\r\n");
            }
        }

        private void AddNode(string text, TreeNode parent)
        {
            if (parent == null)
            {
                //Add/Find the first node
                if (text.IndexOf("\\", System.StringComparison.Ordinal) != -1)
                {
                    int parentIndex;
                    string nodeString;
                    if (text.IndexOf(":", System.StringComparison.Ordinal) != -1) //C:\ want to preserve the backslash
                    {
                        //Check to see if it exists first                        
                        nodeString = text.Substring(0, text.IndexOf("\\", System.StringComparison.Ordinal) + 1);
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
                        nodeString = text.Substring(0, text.IndexOf("\\", System.StringComparison.Ordinal));
                        parentIndex = treeFiles.Nodes.IndexOfKey(nodeString);

                        if (parentIndex == -1)
                        {
                            treeFiles.Nodes.Add(nodeString, nodeString);
                            parentIndex = treeFiles.Nodes.Count - 1;
                        }
                    }

                    parent = treeFiles.Nodes[parentIndex];
                    text = text.Substring(text.IndexOf("\\", System.StringComparison.Ordinal) + 1);
                }
                else
                {
                    //Simply add it if it does not exist
                    if (treeFiles.Nodes.IndexOfKey(text) == -1)
                        treeFiles.Nodes.Add(text, text);
                }
            }

            if (text.IndexOf("\\", System.StringComparison.Ordinal) != -1)
            {
                string nodeString = text.Substring(0, text.IndexOf("\\", System.StringComparison.Ordinal));
                if (parent != null)
                {
                    int parentIndex = parent.Nodes.IndexOfKey(nodeString);

                    if (parentIndex == -1)
                    {
                        parent.Nodes.Add(nodeString, nodeString);
                        parentIndex = parent.Nodes.Count - 1;
                    }

                    AddNode(text.Substring(text.IndexOf("\\", System.StringComparison.Ordinal) + 1), parent.Nodes[parentIndex]);
                }
            }
            else
            {
                //No children nodes necessary, just add it
                if (parent != null && parent.Nodes.IndexOfKey(text) == -1)
                    parent.Nodes.Add(text, text);
            }
        }

        private void Scaneaza()
        {
            string query = "Path LIKE '%" + cDrives.Text + "%'";

            var returnedRows = diskManagementDataSet.Files.Select(query);
            var results = returnedRows.Length;

            if (results > 0)
            {
                foreach (var returnedRow in returnedRows)
                {
                    if (returnedRow["Path"].ToString().Contains(cDrives.Text))
                        returnedRow.Delete();
                }
            }
            filesTableAdapter.Update(returnedRows);
            GetDirectories(cDrives.Text, _id);
            listView1.Clear();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            _id = 0;
            this.button1.Enabled = false;
            cDrives.Enabled = false;
            Scaneaza();
            this.button1.Enabled = true;
            cDrives.Enabled = true;
            AddTree();
            progressBar1.Value = progressBar1.Maximum;
        }

        private void AddList(string fullPath)
        {
            listView1.Clear();
            progressBar2.Value = 2;
            string query = "Path LIKE '%" + cDrives.Text + "%'";
            //this.filesTableAdapter.Fill(this.diskManagementDataSet.Files);

            var returnedRows = diskManagementDataSet.Files.Select("Path = '" + fullPath + "'");
            var results = returnedRows.Length;

            if (results > 0)
            {
                var parentId = returnedRows[0]["FileID"].ToString();
                progressBar2.PerformStep();
                //this.filesTableAdapter.Fill(this.diskManagementDataSet.Files);

                progressBar2.PerformStep();
                var files = diskManagementDataSet.Files.Select("ParentID = '" + parentId + "'");
                var nrFiles = returnedRows.Length;

                if (nrFiles > 0)
                {
                    foreach (var file in files)
                    {
                        progressBar2.PerformStep();
                        Application.DoEvents();
                        if (file["Path"].ToString().Contains(cDrives.Text))
                        {
                            if (file["Type"].ToString().Equals("directory"))
                                listView1.Items.Add("Filename", file["Filename"].ToString(), 0);
                            else
                                listView1.Items.Add("Filename", file["Filename"].ToString(), 1);
                        }

                    }
                }
            }
            progressBar2.Value = progressBar2.Maximum;
        }

        private void treeFiles_AfterSelect(object sender, TreeViewEventArgs e)
        {
            button2.Enabled = false;
            button3.Enabled = false;
            var fullPath = treeFiles.SelectedNode.FullPath;
            fullPath = fullPath.Replace(@"\\", @"\");
            AddList(fullPath);
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            button2.Enabled = true;
            button3.Enabled = true;
            if (listView1.SelectedItems.Count > 0)
                CheckFile();
        }

        private void CheckFile()
        {
            var fullPath = treeFiles.SelectedNode.FullPath;
            var file = listView1.SelectedItems[0].Text;
            fullPath = fullPath.Replace(@"\\", @"\") + "\\" + file;

            if (!File.Exists(fullPath))
            {
                button2.Enabled = false;
                button3.Enabled = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            var fullPath = treeFiles.SelectedNode.FullPath;
            string file = listView1.SelectedItems[0].Text;
            fullPath = fullPath.Replace(@"\\", @"\");
            var fullPathFile = fullPath + "\\" + file;

            var result = MessageBox.Show("Delete File " + file, "Delete File", MessageBoxButtons.YesNo, MessageBoxIcon.Stop,
                            MessageBoxDefaultButton.Button1);
            switch (result)
            {
                case DialogResult.Yes:
                    string query = "Path='" + fullPathFile + "'";

                    var returnedRows = diskManagementDataSet.Files.Select(query);
                    var results = returnedRows.Length;

                    if (results > 0)
                        returnedRows[0].Delete();
                    filesTableAdapter.Update(returnedRows);

                    AddList(fullPath);
                    break;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var fullPath = treeFiles.SelectedNode.FullPath;
            string file = listView1.SelectedItems[0].Text;
            fullPath = fullPath.Replace(@"\\", @"\");
            var fullPathFile = fullPath + "\\" + file;
            string query = "Path='" + fullPathFile + "'";

            var returnedRows = diskManagementDataSet.Files.Select(query);
            var results = returnedRows.Length;

            if (results > 0)
            {
                var ipb = new InputBox();
                ipb.ShowDialog();

                if (!ipb.Name.Equals("CANCELFORM"))
                {
                    returnedRows[0]["Filename"] = ipb.Name;
                    filesTableAdapter.Update(returnedRows);
                    AddList(fullPath);
                }
            }

        }
    }
}
