namespace WCFClient
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonCustomerEdit = new System.Windows.Forms.Button();
            this.buttonCustomerDelete = new System.Windows.Forms.Button();
            this.buttonCustomerNew = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxCustomerAddress = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxCustomerName = new System.Windows.Forms.TextBox();
            this.groupBoxOrderSerial = new System.Windows.Forms.GroupBox();
            this.buttonOrderDelete = new System.Windows.Forms.Button();
            this.buttonUpdateOrder = new System.Windows.Forms.Button();
            this.buttonOrderNew = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.textBoxOrderSerial = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxOrderValoare = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxOrderProdus = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.buttonOrderDetailNew = new System.Windows.Forms.Button();
            this.buttonOrderDetailUpdate = new System.Windows.Forms.Button();
            this.buttonOrderDetailsDelete = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBoxOrderSerial.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonCustomerEdit);
            this.groupBox1.Controls.Add(this.buttonCustomerDelete);
            this.groupBox1.Controls.Add(this.buttonCustomerNew);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.textBoxCustomerAddress);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.textBoxCustomerName);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(235, 130);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Customer";
            // 
            // buttonCustomerEdit
            // 
            this.buttonCustomerEdit.Location = new System.Drawing.Point(93, 101);
            this.buttonCustomerEdit.Name = "buttonCustomerEdit";
            this.buttonCustomerEdit.Size = new System.Drawing.Size(52, 23);
            this.buttonCustomerEdit.TabIndex = 1;
            this.buttonCustomerEdit.Text = "Edit";
            this.buttonCustomerEdit.UseVisualStyleBackColor = true;
            this.buttonCustomerEdit.Click += new System.EventHandler(this.buttonCustomerEdit_Click);
            // 
            // buttonCustomerDelete
            // 
            this.buttonCustomerDelete.Location = new System.Drawing.Point(176, 101);
            this.buttonCustomerDelete.Name = "buttonCustomerDelete";
            this.buttonCustomerDelete.Size = new System.Drawing.Size(53, 23);
            this.buttonCustomerDelete.TabIndex = 1;
            this.buttonCustomerDelete.Text = "Delete";
            this.buttonCustomerDelete.UseVisualStyleBackColor = true;
            this.buttonCustomerDelete.Click += new System.EventHandler(this.buttonCustomerDelete_Click);
            // 
            // buttonCustomerNew
            // 
            this.buttonCustomerNew.Location = new System.Drawing.Point(6, 101);
            this.buttonCustomerNew.Name = "buttonCustomerNew";
            this.buttonCustomerNew.Size = new System.Drawing.Size(57, 23);
            this.buttonCustomerNew.TabIndex = 1;
            this.buttonCustomerNew.Text = "New";
            this.buttonCustomerNew.UseVisualStyleBackColor = true;
            this.buttonCustomerNew.Click += new System.EventHandler(this.buttonCustomerNew_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(78, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Address";
            // 
            // textBoxCustomerAddress
            // 
            this.textBoxCustomerAddress.Location = new System.Drawing.Point(129, 45);
            this.textBoxCustomerAddress.Name = "textBoxCustomerAddress";
            this.textBoxCustomerAddress.Size = new System.Drawing.Size(100, 20);
            this.textBoxCustomerAddress.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(90, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name";
            // 
            // textBoxCustomerName
            // 
            this.textBoxCustomerName.Location = new System.Drawing.Point(129, 19);
            this.textBoxCustomerName.Name = "textBoxCustomerName";
            this.textBoxCustomerName.Size = new System.Drawing.Size(100, 20);
            this.textBoxCustomerName.TabIndex = 1;
            // 
            // groupBoxOrderSerial
            // 
            this.groupBoxOrderSerial.Controls.Add(this.buttonOrderDelete);
            this.groupBoxOrderSerial.Controls.Add(this.buttonUpdateOrder);
            this.groupBoxOrderSerial.Controls.Add(this.buttonOrderNew);
            this.groupBoxOrderSerial.Controls.Add(this.label5);
            this.groupBoxOrderSerial.Controls.Add(this.textBoxOrderValoare);
            this.groupBoxOrderSerial.Location = new System.Drawing.Point(18, 148);
            this.groupBoxOrderSerial.Name = "groupBoxOrderSerial";
            this.groupBoxOrderSerial.Size = new System.Drawing.Size(229, 154);
            this.groupBoxOrderSerial.TabIndex = 1;
            this.groupBoxOrderSerial.TabStop = false;
            this.groupBoxOrderSerial.Text = "Oder";
            // 
            // buttonOrderDelete
            // 
            this.buttonOrderDelete.Location = new System.Drawing.Point(156, 125);
            this.buttonOrderDelete.Name = "buttonOrderDelete";
            this.buttonOrderDelete.Size = new System.Drawing.Size(67, 23);
            this.buttonOrderDelete.TabIndex = 2;
            this.buttonOrderDelete.Text = "Delete";
            this.buttonOrderDelete.UseVisualStyleBackColor = true;
            this.buttonOrderDelete.Click += new System.EventHandler(this.buttonOrderDelete_Click);
            // 
            // buttonUpdateOrder
            // 
            this.buttonUpdateOrder.Location = new System.Drawing.Point(63, 125);
            this.buttonUpdateOrder.Name = "buttonUpdateOrder";
            this.buttonUpdateOrder.Size = new System.Drawing.Size(87, 23);
            this.buttonUpdateOrder.TabIndex = 2;
            this.buttonUpdateOrder.Text = "Update";
            this.buttonUpdateOrder.UseVisualStyleBackColor = true;
            this.buttonUpdateOrder.Click += new System.EventHandler(this.buttonUpdateOrder_Click);
            // 
            // buttonOrderNew
            // 
            this.buttonOrderNew.Location = new System.Drawing.Point(7, 125);
            this.buttonOrderNew.Name = "buttonOrderNew";
            this.buttonOrderNew.Size = new System.Drawing.Size(50, 23);
            this.buttonOrderNew.TabIndex = 2;
            this.buttonOrderNew.Text = "New";
            this.buttonOrderNew.UseVisualStyleBackColor = true;
            this.buttonOrderNew.Click += new System.EventHandler(this.buttonOrderNew_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(90, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(33, 13);
            this.label6.TabIndex = 2;
            this.label6.Text = "Serial";
            // 
            // textBoxOrderSerial
            // 
            this.textBoxOrderSerial.Location = new System.Drawing.Point(129, 45);
            this.textBoxOrderSerial.Name = "textBoxOrderSerial";
            this.textBoxOrderSerial.Size = new System.Drawing.Size(100, 20);
            this.textBoxOrderSerial.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(83, 22);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(34, 13);
            this.label5.TabIndex = 2;
            this.label5.Text = "Value";
            // 
            // textBoxOrderValoare
            // 
            this.textBoxOrderValoare.Location = new System.Drawing.Point(123, 19);
            this.textBoxOrderValoare.Name = "textBoxOrderValoare";
            this.textBoxOrderValoare.Size = new System.Drawing.Size(100, 20);
            this.textBoxOrderValoare.TabIndex = 2;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(79, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(44, 13);
            this.label4.TabIndex = 2;
            this.label4.Text = "Product";
            // 
            // textBoxOrderProdus
            // 
            this.textBoxOrderProdus.Location = new System.Drawing.Point(129, 19);
            this.textBoxOrderProdus.Name = "textBoxOrderProdus";
            this.textBoxOrderProdus.Size = new System.Drawing.Size(100, 20);
            this.textBoxOrderProdus.TabIndex = 2;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.dataGridView1);
            this.groupBox2.Location = new System.Drawing.Point(253, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(351, 290);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Customer";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(6, 19);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(343, 265);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.ShowOrdersOnClick);
            this.dataGridView1.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GetID);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.dataGridView2);
            this.groupBox3.Location = new System.Drawing.Point(608, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(421, 290);
            this.groupBox3.TabIndex = 3;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Order";
            // 
            // dataGridView2
            // 
            this.dataGridView2.AllowUserToAddRows = false;
            this.dataGridView2.AllowUserToDeleteRows = false;
            this.dataGridView2.AllowUserToOrderColumns = true;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(6, 19);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.ReadOnly = true;
            this.dataGridView2.Size = new System.Drawing.Size(413, 265);
            this.dataGridView2.TabIndex = 0;
            this.dataGridView2.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.ShowOrderDetails);
            this.dataGridView2.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GetOrderID);
            // 
            // dataGridView3
            // 
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Location = new System.Drawing.Point(8, 19);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.Size = new System.Drawing.Size(760, 213);
            this.dataGridView3.TabIndex = 4;
            this.dataGridView3.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.GetSerial);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.dataGridView3);
            this.groupBox4.Location = new System.Drawing.Point(253, 308);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(774, 238);
            this.groupBox4.TabIndex = 5;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Order Details";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.buttonOrderDetailsDelete);
            this.groupBox5.Controls.Add(this.buttonOrderDetailUpdate);
            this.groupBox5.Controls.Add(this.buttonOrderDetailNew);
            this.groupBox5.Controls.Add(this.textBoxOrderProdus);
            this.groupBox5.Controls.Add(this.label4);
            this.groupBox5.Controls.Add(this.textBoxOrderSerial);
            this.groupBox5.Controls.Add(this.label6);
            this.groupBox5.Location = new System.Drawing.Point(12, 308);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(235, 144);
            this.groupBox5.TabIndex = 1;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Order Details";
            // 
            // buttonOrderDetailNew
            // 
            this.buttonOrderDetailNew.Location = new System.Drawing.Point(6, 115);
            this.buttonOrderDetailNew.Name = "buttonOrderDetailNew";
            this.buttonOrderDetailNew.Size = new System.Drawing.Size(57, 23);
            this.buttonOrderDetailNew.TabIndex = 1;
            this.buttonOrderDetailNew.Text = "New";
            this.buttonOrderDetailNew.UseVisualStyleBackColor = true;
            this.buttonOrderDetailNew.Click += new System.EventHandler(this.buttonOrderDetailNew_Click);
            // 
            // buttonOrderDetailUpdate
            // 
            this.buttonOrderDetailUpdate.Location = new System.Drawing.Point(69, 115);
            this.buttonOrderDetailUpdate.Name = "buttonOrderDetailUpdate";
            this.buttonOrderDetailUpdate.Size = new System.Drawing.Size(75, 23);
            this.buttonOrderDetailUpdate.TabIndex = 1;
            this.buttonOrderDetailUpdate.Text = "Update";
            this.buttonOrderDetailUpdate.UseVisualStyleBackColor = true;
            this.buttonOrderDetailUpdate.Click += new System.EventHandler(this.buttonOrderDetailUpdate_Click);
            // 
            // buttonOrderDetailsDelete
            // 
            this.buttonOrderDetailsDelete.Location = new System.Drawing.Point(150, 115);
            this.buttonOrderDetailsDelete.Name = "buttonOrderDetailsDelete";
            this.buttonOrderDetailsDelete.Size = new System.Drawing.Size(75, 23);
            this.buttonOrderDetailsDelete.TabIndex = 1;
            this.buttonOrderDetailsDelete.Text = "Delete";
            this.buttonOrderDetailsDelete.UseVisualStyleBackColor = true;
            this.buttonOrderDetailsDelete.Click += new System.EventHandler(this.buttonOrderDetailsDelete_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 730);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBoxOrderSerial);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBoxOrderSerial.ResumeLayout(false);
            this.groupBoxOrderSerial.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonCustomerEdit;
        private System.Windows.Forms.Button buttonCustomerDelete;
        private System.Windows.Forms.Button buttonCustomerNew;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxCustomerAddress;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxCustomerName;
        private System.Windows.Forms.GroupBox groupBoxOrderSerial;
        private System.Windows.Forms.Button buttonOrderDelete;
        private System.Windows.Forms.Button buttonUpdateOrder;
        private System.Windows.Forms.Button buttonOrderNew;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBoxOrderSerial;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxOrderValoare;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxOrderProdus;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.DataGridView dataGridView3;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.Button buttonOrderDetailNew;
        private System.Windows.Forms.Button buttonOrderDetailUpdate;
        private System.Windows.Forms.Button buttonOrderDetailsDelete;
    }
}

