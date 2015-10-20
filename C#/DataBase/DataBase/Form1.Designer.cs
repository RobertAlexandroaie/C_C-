namespace DataBase
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.hDDExplorerDataSet = new DataBase.HDDExplorerDataSet();
            this.filesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.filesTableAdapter = new DataBase.HDDExplorerDataSetTableAdapters.FilesTableAdapter();
            this.tableAdapterManager = new DataBase.HDDExplorerDataSetTableAdapters.TableAdapterManager();
            this.filesListBox = new System.Windows.Forms.ListBox();
            this.cDrives = new System.Windows.Forms.ComboBox();
            this.treeFiles = new System.Windows.Forms.TreeView();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnScan = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.hDDExplorerDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.filesBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // hDDExplorerDataSet
            // 
            this.hDDExplorerDataSet.DataSetName = "HDDExplorerDataSet";
            this.hDDExplorerDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // filesBindingSource
            // 
            this.filesBindingSource.DataMember = "Files";
            this.filesBindingSource.DataSource = this.hDDExplorerDataSet;
            // 
            // filesTableAdapter
            // 
            this.filesTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.FilesTableAdapter = this.filesTableAdapter;
            this.tableAdapterManager.UpdateOrder = DataBase.HDDExplorerDataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            // 
            // filesListBox
            // 
            this.filesListBox.DataSource = this.filesBindingSource;
            this.filesListBox.DisplayMember = "Parent";
            this.filesListBox.FormattingEnabled = true;
            this.filesListBox.Location = new System.Drawing.Point(12, 52);
            this.filesListBox.Name = "filesListBox";
            this.filesListBox.Size = new System.Drawing.Size(300, 212);
            this.filesListBox.TabIndex = 1;
            this.filesListBox.ValueMember = "ID";
            // 
            // cDrives
            // 
            this.cDrives.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cDrives.FormattingEnabled = true;
            this.cDrives.Location = new System.Drawing.Point(12, 12);
            this.cDrives.Name = "cDrives";
            this.cDrives.Size = new System.Drawing.Size(121, 21);
            this.cDrives.TabIndex = 2;
            // 
            // treeFiles
            // 
            this.treeFiles.Location = new System.Drawing.Point(349, 49);
            this.treeFiles.Name = "treeFiles";
            this.treeFiles.Size = new System.Drawing.Size(364, 215);
            this.treeFiles.TabIndex = 3;
            // 
            // btnStop
            // 
            this.btnStop.Enabled = false;
            this.btnStop.Location = new System.Drawing.Point(237, 12);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 5;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnScan
            // 
            this.btnScan.Location = new System.Drawing.Point(156, 12);
            this.btnScan.Name = "btnScan";
            this.btnScan.Size = new System.Drawing.Size(75, 23);
            this.btnScan.TabIndex = 4;
            this.btnScan.Text = "Scan";
            this.btnScan.UseVisualStyleBackColor = true;
            this.btnScan.Click += new System.EventHandler(this.btnScan_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(653, 413);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnScan);
            this.Controls.Add(this.treeFiles);
            this.Controls.Add(this.cDrives);
            this.Controls.Add(this.filesListBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.hDDExplorerDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.filesBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private HDDExplorerDataSet hDDExplorerDataSet;
        private System.Windows.Forms.BindingSource filesBindingSource;
        private HDDExplorerDataSetTableAdapters.FilesTableAdapter filesTableAdapter;
        private HDDExplorerDataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.ListBox filesListBox;
        private System.Windows.Forms.ComboBox cDrives;
        private System.Windows.Forms.TreeView treeFiles;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnScan;

    }
}

