using System;
using System.Collections.Generic;
using System.Globalization;
using System.Windows.Forms;
using Infrastructure;

namespace T1
{
    public partial class DevForm : Form
    {
        private readonly SNET_T1Entities _context;

        public DevForm()
        {
            this._context = new SNET_T1Entities();
            InitializeComponent();
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            this.listBox1.DataSource = this._context.GetCustomersDev();
            this.listBox1.DisplayMember = "NAME";
            this.listBox1.ValueMember = "CUSTOMERID";
        }

        #region Buttons

        #region EditCustomer Box
        private void edit_customer_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
            this.ordersGBox.Location = new System.Drawing.Point(199, 123);
            this.ordersGBox.Size = new System.Drawing.Size(351, 141);
            this.editcustomerGBox.Visible = true;

            var customer = this._context.GetCustomerDev(short.Parse(this.listBox1.SelectedValue.ToString()));

            this.ecAddress.Text = customer.ADRESA.Trim();
            this.ecName.Text = customer.NAME.Trim();
        }

        private void cancel_save_customer_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
        }

        private void save_customer_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"id", this.listBox1.SelectedValue.ToString()},
                               {"address", this.ecAddress.Text},
                               {"name", this.ecName.Text}
                           };
            try
            {
                this._context.EditCustomerDev(data);
                this.resetLayout();

                this.listBox1.DataSource = this._context.GetCustomersDev();
                ((CurrencyManager)this.BindingContext[this.listBox1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Edit Customer", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion
        #region NewCustomer Box
        private void new_customer_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
            this.ordersGBox.Location = new System.Drawing.Point(199, 123);
            this.ordersGBox.Size = new System.Drawing.Size(351, 141);
            this.newcustomerGBox.Visible = true;
        }

        private void cancel_add_customer_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
        }

        private void add_customer_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"address", this.ncAddress.Text},
                               {"name", this.ncName.Text}
                           };
            try
            {
                this._context.SaveCustomerDev(data);
                this.resetLayout();

                this.listBox1.DataSource = this._context.GetCustomersDev();
                ((CurrencyManager)this.BindingContext[this.listBox1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "New Customer", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion

        #region OrderDetails Box
        private void view_order_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
            this.ordersGBox.Location = new System.Drawing.Point(199, 12);
            this.ordersGBox.Size = new System.Drawing.Size(351, 111);
            this.orderdetailsGBox.Visible = true;

            var order = this.dataGridView1.SelectedRows[0].DataBoundItem;
            var od = this._context.GetOrderDetailsDev(((ORDER)order).ORDERID);

            this.odProdus.Text = od.PRODUS.Trim();
            this.odSerial.Text = od.SERIAL.ToString(CultureInfo.InvariantCulture).Trim();
            this.odValoare.Text = od.VALOARE.ToString(CultureInfo.InvariantCulture).Trim();
        }

        private void cancel_order_details_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
        }
        #endregion
        #region NewOrder Box
        private void new_order_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
            this.ordersGBox.Location = new System.Drawing.Point(199, 12);
            this.ordersGBox.Size = new System.Drawing.Size(351, 111);
            this.neworderGBox.Visible = true;
        }

        private void cancel_new_order_Click(object sender, System.EventArgs e)
        {
            this.resetLayout();
        }

        private void add_order_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"produs", this.noProdus.Text},
                               {"valoare", this.noValoare.Text},
                               {"serial", this.noSerial.Text},
                               {"data", DateTime.Now.ToString(CultureInfo.InvariantCulture)},
                               {"id", this.listBox1.SelectedValue.ToString()}
                           };
            try
            {
                this._context.SaveOrderDev(data);
                this.resetLayout();

                this.dataGridView1.DataSource = this._context.GetOrdersDev(short.Parse(this.listBox1.SelectedValue.ToString()));
                ((CurrencyManager)this.BindingContext[this.dataGridView1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "New Order", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion

        private void delete_customer_Click(object sender, System.EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to delete the selected item?", "Customer", MessageBoxButtons.YesNo, MessageBoxIcon.Question).Equals(DialogResult.Yes))
            {
                try
                {
                    this._context.DeleteCustomerDev(short.Parse(this.listBox1.SelectedValue.ToString()));
                    this.resetLayout();

                    this.listBox1.DataSource = this._context.GetCustomersDev();
                    ((CurrencyManager)this.BindingContext[this.listBox1.DataSource]).Refresh();
                    this.dataGridView1.DataSource = this._context.GetOrdersDev(short.Parse(this.listBox1.SelectedValue.ToString()));
                    ((CurrencyManager)this.BindingContext[this.dataGridView1.DataSource]).Refresh();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "New Order", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void delete_order_Click(object sender, System.EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to delete the selected item?", "Order", MessageBoxButtons.YesNo, MessageBoxIcon.Question).Equals(DialogResult.Yes))
            {
                try
                {
                    var order = this.dataGridView1.SelectedRows[0].DataBoundItem;
                    this._context.DeleteOrderDev(((ORDER)order).ORDERID);

                    this.resetLayout();

                    this.dataGridView1.DataSource = this._context.GetOrdersDev(short.Parse(this.listBox1.SelectedValue.ToString()));
                    ((CurrencyManager)this.BindingContext[this.dataGridView1.DataSource]).Refresh();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "New Order", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        #endregion

        #region Methods

        /// <summary>
        /// Used to reset the layout at its natural behaviour
        /// </summary>
        private void resetLayout()
        {
            this.editcustomerGBox.Visible = false;
            this.newcustomerGBox.Visible = false;

            this.orderdetailsGBox.Visible = false;
            this.neworderGBox.Visible = false;

            this.ordersGBox.Location = new System.Drawing.Point(199, 12);
            this.ordersGBox.Size = new System.Drawing.Size(351, 252);
        }
        #endregion

        #region Events

        /// <summary>
        /// Selected Index Changed Event for listbox
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void listBox1_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            this.resetLayout();

            this.listBox1.ValueMember = "CUSTOMERID";
            this.dataGridView1.DataSource = this._context.GetOrdersDev(short.Parse(this.listBox1.SelectedValue.ToString()));
            ((CurrencyManager)this.BindingContext[this.dataGridView1.DataSource]).Refresh();

            if (this.listBox1.SelectedItems.Count > 0)
            {
                this.edit_customer.Enabled = true;
                this.delete_customer.Enabled = true;
            }
            else
            {
                this.edit_customer.Enabled = false;
                this.delete_customer.Enabled = false;
            }
        }

        /// <summary>
        /// Selection Changed Event for datagridview
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dataGridView1_SelectionChanged(object sender, System.EventArgs e)
        {
            this.resetLayout();
            if (this.dataGridView1.SelectedRows.Count > 0)
            {
                this.view_order.Enabled = true;
                this.delete_order.Enabled = true;
            }
            else
            {
                this.view_order.Enabled = false;
                this.delete_order.Enabled = false;
            }
        }

        #endregion

    }
}
