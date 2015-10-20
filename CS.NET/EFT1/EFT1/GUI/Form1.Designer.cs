namespace GUI
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
            this.dataGridViewCustomer = new System.Windows.Forms.DataGridView();
            this.cUSTOMERIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.nAMEDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.aDRESADataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cUSTOMERBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.testDataSet = new GUI.TestDataSet();
            this.cUSTOMERTableAdapter = new GUI.TestDataSetTableAdapters.CUSTOMERTableAdapter();
            this.dataGridViewOrder = new System.Windows.Forms.DataGridView();
            this.oRDERIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dATADataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.cUSTOMERIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.vALOAREDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.oRDERBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.oRDERTableAdapter = new GUI.TestDataSetTableAdapters.ORDERTableAdapter();
            this.dataGridViewDetails = new System.Windows.Forms.DataGridView();
            this.oRDERIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pRODUSDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.vALOAREDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sERIALDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.oRDERDETAILSBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.oRDERDETAILSTableAdapter = new GUI.TestDataSetTableAdapters.ORDERDETAILSTableAdapter();
            this.textBoxID = new System.Windows.Forms.TextBox();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.textBoxAdresa = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonInsertCustomer = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewCustomer)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cUSTOMERBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.testDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewOrder)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.oRDERBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDetails)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.oRDERDETAILSBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewCustomer
            // 
            this.dataGridViewCustomer.AutoGenerateColumns = false;
            this.dataGridViewCustomer.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewCustomer.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.cUSTOMERIDDataGridViewTextBoxColumn,
            this.nAMEDataGridViewTextBoxColumn,
            this.aDRESADataGridViewTextBoxColumn});
            this.dataGridViewCustomer.DataSource = this.cUSTOMERBindingSource;
            this.dataGridViewCustomer.Location = new System.Drawing.Point(12, 12);
            this.dataGridViewCustomer.Name = "dataGridViewCustomer";
            this.dataGridViewCustomer.Size = new System.Drawing.Size(344, 150);
            this.dataGridViewCustomer.TabIndex = 0;
            // 
            // cUSTOMERIDDataGridViewTextBoxColumn
            // 
            this.cUSTOMERIDDataGridViewTextBoxColumn.DataPropertyName = "CUSTOMERID";
            this.cUSTOMERIDDataGridViewTextBoxColumn.HeaderText = "CUSTOMERID";
            this.cUSTOMERIDDataGridViewTextBoxColumn.Name = "cUSTOMERIDDataGridViewTextBoxColumn";
            // 
            // nAMEDataGridViewTextBoxColumn
            // 
            this.nAMEDataGridViewTextBoxColumn.DataPropertyName = "NAME";
            this.nAMEDataGridViewTextBoxColumn.HeaderText = "NAME";
            this.nAMEDataGridViewTextBoxColumn.Name = "nAMEDataGridViewTextBoxColumn";
            // 
            // aDRESADataGridViewTextBoxColumn
            // 
            this.aDRESADataGridViewTextBoxColumn.DataPropertyName = "ADRESA";
            this.aDRESADataGridViewTextBoxColumn.HeaderText = "ADRESA";
            this.aDRESADataGridViewTextBoxColumn.Name = "aDRESADataGridViewTextBoxColumn";
            // 
            // cUSTOMERBindingSource
            // 
            this.cUSTOMERBindingSource.DataMember = "CUSTOMER";
            this.cUSTOMERBindingSource.DataSource = this.testDataSet;
            // 
            // testDataSet
            // 
            this.testDataSet.DataSetName = "TestDataSet";
            this.testDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // cUSTOMERTableAdapter
            // 
            this.cUSTOMERTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridViewOrder
            // 
            this.dataGridViewOrder.AutoGenerateColumns = false;
            this.dataGridViewOrder.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewOrder.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.oRDERIDDataGridViewTextBoxColumn,
            this.dATADataGridViewTextBoxColumn,
            this.cUSTOMERIDDataGridViewTextBoxColumn1,
            this.vALOAREDataGridViewTextBoxColumn});
            this.dataGridViewOrder.DataSource = this.oRDERBindingSource;
            this.dataGridViewOrder.Location = new System.Drawing.Point(361, 168);
            this.dataGridViewOrder.Name = "dataGridViewOrder";
            this.dataGridViewOrder.Size = new System.Drawing.Size(445, 150);
            this.dataGridViewOrder.TabIndex = 1;
            // 
            // oRDERIDDataGridViewTextBoxColumn
            // 
            this.oRDERIDDataGridViewTextBoxColumn.DataPropertyName = "ORDERID";
            this.oRDERIDDataGridViewTextBoxColumn.HeaderText = "ORDERID";
            this.oRDERIDDataGridViewTextBoxColumn.Name = "oRDERIDDataGridViewTextBoxColumn";
            // 
            // dATADataGridViewTextBoxColumn
            // 
            this.dATADataGridViewTextBoxColumn.DataPropertyName = "DATA";
            this.dATADataGridViewTextBoxColumn.HeaderText = "DATA";
            this.dATADataGridViewTextBoxColumn.Name = "dATADataGridViewTextBoxColumn";
            // 
            // cUSTOMERIDDataGridViewTextBoxColumn1
            // 
            this.cUSTOMERIDDataGridViewTextBoxColumn1.DataPropertyName = "CUSTOMERID";
            this.cUSTOMERIDDataGridViewTextBoxColumn1.HeaderText = "CUSTOMERID";
            this.cUSTOMERIDDataGridViewTextBoxColumn1.Name = "cUSTOMERIDDataGridViewTextBoxColumn1";
            // 
            // vALOAREDataGridViewTextBoxColumn
            // 
            this.vALOAREDataGridViewTextBoxColumn.DataPropertyName = "VALOARE";
            this.vALOAREDataGridViewTextBoxColumn.HeaderText = "VALOARE";
            this.vALOAREDataGridViewTextBoxColumn.Name = "vALOAREDataGridViewTextBoxColumn";
            // 
            // oRDERBindingSource
            // 
            this.oRDERBindingSource.DataMember = "ORDER";
            this.oRDERBindingSource.DataSource = this.testDataSet;
            // 
            // oRDERTableAdapter
            // 
            this.oRDERTableAdapter.ClearBeforeFill = true;
            // 
            // dataGridViewDetails
            // 
            this.dataGridViewDetails.AutoGenerateColumns = false;
            this.dataGridViewDetails.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewDetails.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.oRDERIDDataGridViewTextBoxColumn1,
            this.pRODUSDataGridViewTextBoxColumn,
            this.vALOAREDataGridViewTextBoxColumn1,
            this.sERIALDataGridViewTextBoxColumn});
            this.dataGridViewDetails.DataSource = this.oRDERDETAILSBindingSource;
            this.dataGridViewDetails.Location = new System.Drawing.Point(362, 12);
            this.dataGridViewDetails.Name = "dataGridViewDetails";
            this.dataGridViewDetails.Size = new System.Drawing.Size(444, 150);
            this.dataGridViewDetails.TabIndex = 2;
            // 
            // oRDERIDDataGridViewTextBoxColumn1
            // 
            this.oRDERIDDataGridViewTextBoxColumn1.DataPropertyName = "ORDERID";
            this.oRDERIDDataGridViewTextBoxColumn1.HeaderText = "ORDERID";
            this.oRDERIDDataGridViewTextBoxColumn1.Name = "oRDERIDDataGridViewTextBoxColumn1";
            // 
            // pRODUSDataGridViewTextBoxColumn
            // 
            this.pRODUSDataGridViewTextBoxColumn.DataPropertyName = "PRODUS";
            this.pRODUSDataGridViewTextBoxColumn.HeaderText = "PRODUS";
            this.pRODUSDataGridViewTextBoxColumn.Name = "pRODUSDataGridViewTextBoxColumn";
            // 
            // vALOAREDataGridViewTextBoxColumn1
            // 
            this.vALOAREDataGridViewTextBoxColumn1.DataPropertyName = "VALOARE";
            this.vALOAREDataGridViewTextBoxColumn1.HeaderText = "VALOARE";
            this.vALOAREDataGridViewTextBoxColumn1.Name = "vALOAREDataGridViewTextBoxColumn1";
            // 
            // sERIALDataGridViewTextBoxColumn
            // 
            this.sERIALDataGridViewTextBoxColumn.DataPropertyName = "SERIAL";
            this.sERIALDataGridViewTextBoxColumn.HeaderText = "SERIAL";
            this.sERIALDataGridViewTextBoxColumn.Name = "sERIALDataGridViewTextBoxColumn";
            // 
            // oRDERDETAILSBindingSource
            // 
            this.oRDERDETAILSBindingSource.DataMember = "ORDERDETAILS";
            this.oRDERDETAILSBindingSource.DataSource = this.testDataSet;
            // 
            // oRDERDETAILSTableAdapter
            // 
            this.oRDERDETAILSTableAdapter.ClearBeforeFill = true;
            // 
            // textBoxID
            // 
            this.textBoxID.Location = new System.Drawing.Point(12, 180);
            this.textBoxID.Name = "textBoxID";
            this.textBoxID.Size = new System.Drawing.Size(107, 20);
            this.textBoxID.TabIndex = 3;
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(125, 180);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(115, 20);
            this.textBoxName.TabIndex = 4;
            // 
            // textBoxAdresa
            // 
            this.textBoxAdresa.Location = new System.Drawing.Point(246, 180);
            this.textBoxAdresa.Name = "textBoxAdresa";
            this.textBoxAdresa.Size = new System.Drawing.Size(110, 20);
            this.textBoxAdresa.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(31, 165);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "Customer ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(163, 164);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 13);
            this.label2.TabIndex = 7;
            this.label2.Text = "Name";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(278, 164);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Adresa";
            // 
            // buttonInsertCustomer
            // 
            this.buttonInsertCustomer.Location = new System.Drawing.Point(12, 206);
            this.buttonInsertCustomer.Name = "buttonInsertCustomer";
            this.buttonInsertCustomer.Size = new System.Drawing.Size(107, 23);
            this.buttonInsertCustomer.TabIndex = 9;
            this.buttonInsertCustomer.Text = "Insert Customer";
            this.buttonInsertCustomer.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1011, 408);
            this.Controls.Add(this.buttonInsertCustomer);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxAdresa);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.textBoxID);
            this.Controls.Add(this.dataGridViewDetails);
            this.Controls.Add(this.dataGridViewOrder);
            this.Controls.Add(this.dataGridViewCustomer);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewCustomer)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cUSTOMERBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.testDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewOrder)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.oRDERBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDetails)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.oRDERDETAILSBindingSource)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewCustomer;
        private TestDataSet testDataSet;
        private System.Windows.Forms.BindingSource cUSTOMERBindingSource;
        private TestDataSetTableAdapters.CUSTOMERTableAdapter cUSTOMERTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn cUSTOMERIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn nAMEDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn aDRESADataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridViewOrder;
        private System.Windows.Forms.BindingSource oRDERBindingSource;
        private TestDataSetTableAdapters.ORDERTableAdapter oRDERTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn oRDERIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dATADataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn cUSTOMERIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn vALOAREDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dataGridViewDetails;
        private System.Windows.Forms.BindingSource oRDERDETAILSBindingSource;
        private TestDataSetTableAdapters.ORDERDETAILSTableAdapter oRDERDETAILSTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn oRDERIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn pRODUSDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn vALOAREDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn sERIALDataGridViewTextBoxColumn;
        private System.Windows.Forms.TextBox textBoxID;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.TextBox textBoxAdresa;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button buttonInsertCustomer;
    }
}

