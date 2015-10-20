namespace T1
{
    partial class AppForm
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
            this.customersGBox = new System.Windows.Forms.GroupBox();
            this.edit_customer = new System.Windows.Forms.Button();
            this.delete_customer = new System.Windows.Forms.Button();
            this.new_customer = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.ordersGBox = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.order_date = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.order_value = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.order_id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.order_customerid = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.order_customer = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.order_orderdetails = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.delete_order = new System.Windows.Forms.Button();
            this.new_order = new System.Windows.Forms.Button();
            this.view_order = new System.Windows.Forms.Button();
            this.editcustomerGBox = new System.Windows.Forms.GroupBox();
            this.cancel_save_customer = new System.Windows.Forms.Button();
            this.save_customer = new System.Windows.Forms.Button();
            this.ecAddress = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.ecName = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.newcustomerGBox = new System.Windows.Forms.GroupBox();
            this.cancel_add_customer = new System.Windows.Forms.Button();
            this.add_customer = new System.Windows.Forms.Button();
            this.ncAddress = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.ncName = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.orderdetailsGBox = new System.Windows.Forms.GroupBox();
            this.odSerial = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.cancel_order_details = new System.Windows.Forms.Button();
            this.odValoare = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.odProdus = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.neworderGBox = new System.Windows.Forms.GroupBox();
            this.add_order = new System.Windows.Forms.Button();
            this.noSerial = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.cancel_new_order = new System.Windows.Forms.Button();
            this.noValoare = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.noProdus = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.customersGBox.SuspendLayout();
            this.ordersGBox.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.editcustomerGBox.SuspendLayout();
            this.newcustomerGBox.SuspendLayout();
            this.orderdetailsGBox.SuspendLayout();
            this.neworderGBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // customersGBox
            // 
            this.customersGBox.Controls.Add(this.edit_customer);
            this.customersGBox.Controls.Add(this.delete_customer);
            this.customersGBox.Controls.Add(this.new_customer);
            this.customersGBox.Controls.Add(this.listBox1);
            this.customersGBox.Location = new System.Drawing.Point(12, 12);
            this.customersGBox.Name = "customersGBox";
            this.customersGBox.Size = new System.Drawing.Size(181, 252);
            this.customersGBox.TabIndex = 0;
            this.customersGBox.TabStop = false;
            this.customersGBox.Text = "Customers";
            // 
            // edit_customer
            // 
            this.edit_customer.Enabled = false;
            this.edit_customer.Location = new System.Drawing.Point(64, 223);
            this.edit_customer.Name = "edit_customer";
            this.edit_customer.Size = new System.Drawing.Size(52, 23);
            this.edit_customer.TabIndex = 3;
            this.edit_customer.Text = "Edit";
            this.edit_customer.UseVisualStyleBackColor = true;
            this.edit_customer.Click += new System.EventHandler(this.edit_customer_Click);
            // 
            // delete_customer
            // 
            this.delete_customer.Enabled = false;
            this.delete_customer.Location = new System.Drawing.Point(122, 223);
            this.delete_customer.Name = "delete_customer";
            this.delete_customer.Size = new System.Drawing.Size(53, 23);
            this.delete_customer.TabIndex = 2;
            this.delete_customer.Text = "Delete";
            this.delete_customer.UseVisualStyleBackColor = true;
            this.delete_customer.Click += new System.EventHandler(this.delete_customer_Click);
            // 
            // new_customer
            // 
            this.new_customer.Location = new System.Drawing.Point(6, 223);
            this.new_customer.Name = "new_customer";
            this.new_customer.Size = new System.Drawing.Size(52, 23);
            this.new_customer.TabIndex = 1;
            this.new_customer.Text = "New";
            this.new_customer.UseVisualStyleBackColor = true;
            this.new_customer.Click += new System.EventHandler(this.new_customer_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(6, 19);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(169, 199);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // ordersGBox
            // 
            this.ordersGBox.Controls.Add(this.tableLayoutPanel1);
            this.ordersGBox.Location = new System.Drawing.Point(199, 12);
            this.ordersGBox.Name = "ordersGBox";
            this.ordersGBox.Padding = new System.Windows.Forms.Padding(1, 1, 1, 3);
            this.ordersGBox.Size = new System.Drawing.Size(351, 252);
            this.ordersGBox.TabIndex = 1;
            this.ordersGBox.TabStop = false;
            this.ordersGBox.Text = "Orders";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 97F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.delete_order, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.new_order, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.dataGridView1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.view_order, 1, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(1, 14);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 29F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(349, 235);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.order_date,
            this.order_value,
            this.order_id,
            this.order_customerid,
            this.order_customer,
            this.order_orderdetails});
            this.tableLayoutPanel1.SetColumnSpan(this.dataGridView1, 3);
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView1.Location = new System.Drawing.Point(3, 3);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(3, 3, 3, 2);
            this.dataGridView1.MultiSelect = false;
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowHeadersVisible = false;
            this.dataGridView1.RowTemplate.Height = 18;
            this.dataGridView1.RowTemplate.Resizable = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridView1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView1.ShowCellToolTips = false;
            this.dataGridView1.ShowEditingIcon = false;
            this.dataGridView1.Size = new System.Drawing.Size(343, 201);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.SelectionChanged += new System.EventHandler(this.dataGridView1_SelectionChanged);
            // 
            // order_date
            // 
            this.order_date.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.order_date.DataPropertyName = "DATA";
            this.order_date.HeaderText = "Date";
            this.order_date.Name = "order_date";
            this.order_date.ReadOnly = true;
            // 
            // order_value
            // 
            this.order_value.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.order_value.DataPropertyName = "VALOARE";
            this.order_value.HeaderText = "Value";
            this.order_value.Name = "order_value";
            this.order_value.ReadOnly = true;
            // 
            // order_id
            // 
            this.order_id.DataPropertyName = "ORDERID";
            this.order_id.HeaderText = "Id";
            this.order_id.Name = "order_id";
            this.order_id.ReadOnly = true;
            this.order_id.Visible = false;
            this.order_id.Width = 5;
            // 
            // order_customerid
            // 
            this.order_customerid.DataPropertyName = "CUSTOMERID";
            this.order_customerid.HeaderText = "CustomerId";
            this.order_customerid.Name = "order_customerid";
            this.order_customerid.ReadOnly = true;
            this.order_customerid.Visible = false;
            this.order_customerid.Width = 5;
            // 
            // order_customer
            // 
            this.order_customer.DataPropertyName = "CUSTOMER";
            this.order_customer.HeaderText = "Customer";
            this.order_customer.Name = "order_customer";
            this.order_customer.ReadOnly = true;
            this.order_customer.Visible = false;
            this.order_customer.Width = 5;
            // 
            // order_orderdetails
            // 
            this.order_orderdetails.DataPropertyName = "ORDERDETAILS";
            this.order_orderdetails.HeaderText = "Orderdetails";
            this.order_orderdetails.Name = "order_orderdetails";
            this.order_orderdetails.ReadOnly = true;
            this.order_orderdetails.Visible = false;
            this.order_orderdetails.Width = 5;
            // 
            // delete_order
            // 
            this.delete_order.Dock = System.Windows.Forms.DockStyle.Right;
            this.delete_order.Enabled = false;
            this.delete_order.Location = new System.Drawing.Point(271, 209);
            this.delete_order.Name = "delete_order";
            this.delete_order.Size = new System.Drawing.Size(75, 23);
            this.delete_order.TabIndex = 3;
            this.delete_order.Text = "Delete";
            this.delete_order.UseVisualStyleBackColor = true;
            this.delete_order.Click += new System.EventHandler(this.delete_order_Click);
            // 
            // new_order
            // 
            this.new_order.Location = new System.Drawing.Point(3, 209);
            this.new_order.Name = "new_order";
            this.new_order.Size = new System.Drawing.Size(75, 23);
            this.new_order.TabIndex = 1;
            this.new_order.Text = "New";
            this.new_order.UseVisualStyleBackColor = true;
            this.new_order.Click += new System.EventHandler(this.new_order_Click);
            // 
            // view_order
            // 
            this.view_order.Enabled = false;
            this.view_order.Location = new System.Drawing.Point(129, 209);
            this.view_order.Name = "view_order";
            this.view_order.Size = new System.Drawing.Size(91, 23);
            this.view_order.TabIndex = 2;
            this.view_order.Text = "View Details";
            this.view_order.UseVisualStyleBackColor = true;
            this.view_order.Click += new System.EventHandler(this.view_order_Click);
            // 
            // editcustomerGBox
            // 
            this.editcustomerGBox.Controls.Add(this.cancel_save_customer);
            this.editcustomerGBox.Controls.Add(this.save_customer);
            this.editcustomerGBox.Controls.Add(this.ecAddress);
            this.editcustomerGBox.Controls.Add(this.label2);
            this.editcustomerGBox.Controls.Add(this.ecName);
            this.editcustomerGBox.Controls.Add(this.label1);
            this.editcustomerGBox.Location = new System.Drawing.Point(199, 12);
            this.editcustomerGBox.Name = "editcustomerGBox";
            this.editcustomerGBox.Size = new System.Drawing.Size(351, 105);
            this.editcustomerGBox.TabIndex = 2;
            this.editcustomerGBox.TabStop = false;
            this.editcustomerGBox.Text = "Edit Customer";
            this.editcustomerGBox.Visible = false;
            // 
            // cancel_save_customer
            // 
            this.cancel_save_customer.Location = new System.Drawing.Point(270, 75);
            this.cancel_save_customer.Name = "cancel_save_customer";
            this.cancel_save_customer.Size = new System.Drawing.Size(75, 23);
            this.cancel_save_customer.TabIndex = 5;
            this.cancel_save_customer.Text = "Cancel";
            this.cancel_save_customer.UseVisualStyleBackColor = true;
            this.cancel_save_customer.Click += new System.EventHandler(this.cancel_save_customer_Click);
            // 
            // save_customer
            // 
            this.save_customer.Location = new System.Drawing.Point(9, 75);
            this.save_customer.Name = "save_customer";
            this.save_customer.Size = new System.Drawing.Size(75, 23);
            this.save_customer.TabIndex = 4;
            this.save_customer.Text = "Save";
            this.save_customer.UseVisualStyleBackColor = true;
            this.save_customer.Click += new System.EventHandler(this.save_customer_Click);
            // 
            // ecAddress
            // 
            this.ecAddress.Location = new System.Drawing.Point(60, 49);
            this.ecAddress.Name = "ecAddress";
            this.ecAddress.Size = new System.Drawing.Size(285, 20);
            this.ecAddress.TabIndex = 3;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 52);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(48, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Address:";
            // 
            // ecName
            // 
            this.ecName.Location = new System.Drawing.Point(60, 19);
            this.ecName.Name = "ecName";
            this.ecName.Size = new System.Drawing.Size(285, 20);
            this.ecName.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Name:";
            // 
            // newcustomerGBox
            // 
            this.newcustomerGBox.Controls.Add(this.cancel_add_customer);
            this.newcustomerGBox.Controls.Add(this.add_customer);
            this.newcustomerGBox.Controls.Add(this.ncAddress);
            this.newcustomerGBox.Controls.Add(this.label3);
            this.newcustomerGBox.Controls.Add(this.ncName);
            this.newcustomerGBox.Controls.Add(this.label4);
            this.newcustomerGBox.Location = new System.Drawing.Point(199, 12);
            this.newcustomerGBox.Name = "newcustomerGBox";
            this.newcustomerGBox.Size = new System.Drawing.Size(351, 105);
            this.newcustomerGBox.TabIndex = 3;
            this.newcustomerGBox.TabStop = false;
            this.newcustomerGBox.Text = "New Customer";
            this.newcustomerGBox.Visible = false;
            // 
            // cancel_add_customer
            // 
            this.cancel_add_customer.Location = new System.Drawing.Point(270, 75);
            this.cancel_add_customer.Name = "cancel_add_customer";
            this.cancel_add_customer.Size = new System.Drawing.Size(75, 23);
            this.cancel_add_customer.TabIndex = 11;
            this.cancel_add_customer.Text = "Cancel";
            this.cancel_add_customer.UseVisualStyleBackColor = true;
            this.cancel_add_customer.Click += new System.EventHandler(this.cancel_add_customer_Click);
            // 
            // add_customer
            // 
            this.add_customer.Location = new System.Drawing.Point(9, 75);
            this.add_customer.Name = "add_customer";
            this.add_customer.Size = new System.Drawing.Size(75, 23);
            this.add_customer.TabIndex = 10;
            this.add_customer.Text = "Add";
            this.add_customer.UseVisualStyleBackColor = true;
            this.add_customer.Click += new System.EventHandler(this.add_customer_Click);
            // 
            // ncAddress
            // 
            this.ncAddress.Location = new System.Drawing.Point(60, 49);
            this.ncAddress.Name = "ncAddress";
            this.ncAddress.Size = new System.Drawing.Size(285, 20);
            this.ncAddress.TabIndex = 9;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 52);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "Address:";
            // 
            // ncName
            // 
            this.ncName.Location = new System.Drawing.Point(60, 19);
            this.ncName.Name = "ncName";
            this.ncName.Size = new System.Drawing.Size(285, 20);
            this.ncName.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(38, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Name:";
            // 
            // orderdetailsGBox
            // 
            this.orderdetailsGBox.Controls.Add(this.odSerial);
            this.orderdetailsGBox.Controls.Add(this.label7);
            this.orderdetailsGBox.Controls.Add(this.cancel_order_details);
            this.orderdetailsGBox.Controls.Add(this.odValoare);
            this.orderdetailsGBox.Controls.Add(this.label5);
            this.orderdetailsGBox.Controls.Add(this.odProdus);
            this.orderdetailsGBox.Controls.Add(this.label6);
            this.orderdetailsGBox.Location = new System.Drawing.Point(199, 129);
            this.orderdetailsGBox.Name = "orderdetailsGBox";
            this.orderdetailsGBox.Size = new System.Drawing.Size(351, 135);
            this.orderdetailsGBox.TabIndex = 3;
            this.orderdetailsGBox.TabStop = false;
            this.orderdetailsGBox.Text = "Order Details";
            // 
            // odSerial
            // 
            this.odSerial.Location = new System.Drawing.Point(60, 79);
            this.odSerial.Name = "odSerial";
            this.odSerial.ReadOnly = true;
            this.odSerial.Size = new System.Drawing.Size(285, 20);
            this.odSerial.TabIndex = 18;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 82);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(36, 13);
            this.label7.TabIndex = 17;
            this.label7.Text = "Serial:";
            // 
            // cancel_order_details
            // 
            this.cancel_order_details.Location = new System.Drawing.Point(270, 105);
            this.cancel_order_details.Name = "cancel_order_details";
            this.cancel_order_details.Size = new System.Drawing.Size(75, 23);
            this.cancel_order_details.TabIndex = 16;
            this.cancel_order_details.Text = "Cancel";
            this.cancel_order_details.UseVisualStyleBackColor = true;
            this.cancel_order_details.Click += new System.EventHandler(this.cancel_order_details_Click);
            // 
            // odValoare
            // 
            this.odValoare.Location = new System.Drawing.Point(60, 49);
            this.odValoare.Name = "odValoare";
            this.odValoare.ReadOnly = true;
            this.odValoare.Size = new System.Drawing.Size(285, 20);
            this.odValoare.TabIndex = 15;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 52);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(46, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "Valoare:";
            // 
            // odProdus
            // 
            this.odProdus.Location = new System.Drawing.Point(60, 19);
            this.odProdus.Name = "odProdus";
            this.odProdus.ReadOnly = true;
            this.odProdus.Size = new System.Drawing.Size(285, 20);
            this.odProdus.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(43, 13);
            this.label6.TabIndex = 12;
            this.label6.Text = "Produs:";
            // 
            // neworderGBox
            // 
            this.neworderGBox.Controls.Add(this.add_order);
            this.neworderGBox.Controls.Add(this.noSerial);
            this.neworderGBox.Controls.Add(this.label8);
            this.neworderGBox.Controls.Add(this.cancel_new_order);
            this.neworderGBox.Controls.Add(this.noValoare);
            this.neworderGBox.Controls.Add(this.label9);
            this.neworderGBox.Controls.Add(this.noProdus);
            this.neworderGBox.Controls.Add(this.label10);
            this.neworderGBox.Location = new System.Drawing.Point(199, 129);
            this.neworderGBox.Name = "neworderGBox";
            this.neworderGBox.Size = new System.Drawing.Size(351, 135);
            this.neworderGBox.TabIndex = 19;
            this.neworderGBox.TabStop = false;
            this.neworderGBox.Text = "New Order";
            this.neworderGBox.Visible = false;
            // 
            // add_order
            // 
            this.add_order.Location = new System.Drawing.Point(6, 105);
            this.add_order.Name = "add_order";
            this.add_order.Size = new System.Drawing.Size(75, 23);
            this.add_order.TabIndex = 26;
            this.add_order.Text = "Add";
            this.add_order.UseVisualStyleBackColor = true;
            this.add_order.Click += new System.EventHandler(this.add_order_Click);
            // 
            // noSerial
            // 
            this.noSerial.Location = new System.Drawing.Point(60, 79);
            this.noSerial.Name = "noSerial";
            this.noSerial.Size = new System.Drawing.Size(285, 20);
            this.noSerial.TabIndex = 25;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(6, 82);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(36, 13);
            this.label8.TabIndex = 24;
            this.label8.Text = "Serial:";
            // 
            // cancel_new_order
            // 
            this.cancel_new_order.Location = new System.Drawing.Point(270, 105);
            this.cancel_new_order.Name = "cancel_new_order";
            this.cancel_new_order.Size = new System.Drawing.Size(75, 23);
            this.cancel_new_order.TabIndex = 23;
            this.cancel_new_order.Text = "Cancel";
            this.cancel_new_order.UseVisualStyleBackColor = true;
            this.cancel_new_order.Click += new System.EventHandler(this.cancel_new_order_Click);
            // 
            // noValoare
            // 
            this.noValoare.Location = new System.Drawing.Point(60, 49);
            this.noValoare.Name = "noValoare";
            this.noValoare.Size = new System.Drawing.Size(285, 20);
            this.noValoare.TabIndex = 22;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 52);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(46, 13);
            this.label9.TabIndex = 21;
            this.label9.Text = "Valoare:";
            // 
            // noProdus
            // 
            this.noProdus.Location = new System.Drawing.Point(60, 19);
            this.noProdus.Name = "noProdus";
            this.noProdus.Size = new System.Drawing.Size(285, 20);
            this.noProdus.TabIndex = 20;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(6, 22);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(43, 13);
            this.label10.TabIndex = 19;
            this.label10.Text = "Produs:";
            // 
            // AppForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(562, 276);
            this.Controls.Add(this.ordersGBox);
            this.Controls.Add(this.customersGBox);
            this.Controls.Add(this.orderdetailsGBox);
            this.Controls.Add(this.newcustomerGBox);
            this.Controls.Add(this.editcustomerGBox);
            this.Controls.Add(this.neworderGBox);
            this.MaximumSize = new System.Drawing.Size(572, 308);
            this.MinimumSize = new System.Drawing.Size(572, 308);
            this.Name = "AppForm";
            this.Text = "AppForm";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.customersGBox.ResumeLayout(false);
            this.ordersGBox.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.editcustomerGBox.ResumeLayout(false);
            this.editcustomerGBox.PerformLayout();
            this.newcustomerGBox.ResumeLayout(false);
            this.newcustomerGBox.PerformLayout();
            this.orderdetailsGBox.ResumeLayout(false);
            this.orderdetailsGBox.PerformLayout();
            this.neworderGBox.ResumeLayout(false);
            this.neworderGBox.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox customersGBox;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.GroupBox ordersGBox;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button edit_customer;
        private System.Windows.Forms.Button delete_customer;
        private System.Windows.Forms.Button new_customer;
        private System.Windows.Forms.Button delete_order;
        private System.Windows.Forms.Button view_order;
        private System.Windows.Forms.Button new_order;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_date;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_value;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_id;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_customerid;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_customer;
        private System.Windows.Forms.DataGridViewTextBoxColumn order_orderdetails;
        private System.Windows.Forms.GroupBox editcustomerGBox;
        private System.Windows.Forms.Button cancel_save_customer;
        private System.Windows.Forms.Button save_customer;
        private System.Windows.Forms.TextBox ecAddress;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ecName;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox newcustomerGBox;
        private System.Windows.Forms.Button cancel_add_customer;
        private System.Windows.Forms.Button add_customer;
        private System.Windows.Forms.TextBox ncAddress;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox ncName;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox orderdetailsGBox;
        private System.Windows.Forms.TextBox odSerial;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button cancel_order_details;
        private System.Windows.Forms.TextBox odValoare;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox odProdus;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox neworderGBox;
        private System.Windows.Forms.TextBox noSerial;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button cancel_new_order;
        private System.Windows.Forms.TextBox noValoare;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox noProdus;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button add_order;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
    }
}

