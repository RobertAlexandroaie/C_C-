using System;
using System.Collections.Generic;
using System.Globalization;
using System.Windows.Forms;
using Infrastructure;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace T1
{
    public partial class AppForm : Form
    {
        private readonly DbConnection _connection;
        private readonly SNET_T1Entities _context;

        public AppForm(DbConnection myConnection)
        {
            _connection = myConnection;
            _context = _connection.Context;

            InitializeComponent();
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            // populate the listbox with our customers
            listBox1.DataSource = _context.GetCustomers();
            listBox1.DisplayMember = "NAME";
            listBox1.ValueMember = "CUSTOMERID";
        }

        #region Buttons

        #region EditCustomer Box
        private void edit_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
            ordersGBox.Location = new System.Drawing.Point(199, 123);
            ordersGBox.Size = new System.Drawing.Size(351, 141);
            editcustomerGBox.Visible = true;

            var customer = _context.GetCustomer(short.Parse(listBox1.SelectedValue.ToString()));

            ecAddress.Text = customer.ADRESA.Trim();
            ecName.Text = customer.NAME.Trim();
        }

        private void cancel_save_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
        }

        private void save_customer_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"id", listBox1.SelectedValue.ToString()},
                               {"address", ecAddress.Text},
                               {"name", ecName.Text}
                           };
            try
            {
                _context.EditCustomer(data);

                resetLayout();
                listBox1.DataSource = _context.GetCustomers();
                ((CurrencyManager)BindingContext[listBox1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, caption: "Edit Customer", buttons: MessageBoxButtons.OK, icon: MessageBoxIcon.Error);
            }
        }
        #endregion
        #region NewCustomer Box
        private void new_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
            ordersGBox.Location = new System.Drawing.Point(199, 123);
            ordersGBox.Size = new System.Drawing.Size(351, 141);
            newcustomerGBox.Visible = true;
        }

        private void cancel_add_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
        }

        private void add_customer_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"address", ncAddress.Text},
                               {"name", ncName.Text}
                           };
            try
            {
                _context.SaveCustomer(data);

                resetLayout();
                listBox1.DataSource = _context.GetCustomers();
                ((CurrencyManager)BindingContext[listBox1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, caption: "New Customer", buttons: MessageBoxButtons.OK, icon: MessageBoxIcon.Error);
            }
        }
        #endregion

        #region OrderDetails Box
        private void view_order_Click(object sender, System.EventArgs e)
        {
            resetLayout();
            ordersGBox.Location = new System.Drawing.Point(199, 12);
            ordersGBox.Size = new System.Drawing.Size(351, 111);
            orderdetailsGBox.Visible = true;

            var order = dataGridView1.SelectedRows[0].DataBoundItem;
            var od = _context.GetOrderDetails(((ORDER)order).ORDERID);

            odProdus.Text = od.PRODUS.Trim();
            odSerial.Text = od.SERIAL.ToString(CultureInfo.InvariantCulture).Trim();
            odValoare.Text = od.VALOARE.ToString(CultureInfo.InvariantCulture).Trim();
        }

        private void cancel_order_details_Click(object sender, System.EventArgs e)
        {
            resetLayout();
        }
        #endregion
        #region NewOrder Box
        private void new_order_Click(object sender, System.EventArgs e)
        {
            resetLayout();
            ordersGBox.Location = new System.Drawing.Point(199, 12);
            ordersGBox.Size = new System.Drawing.Size(351, 111);
            neworderGBox.Visible = true;
        }

        private void cancel_new_order_Click(object sender, System.EventArgs e)
        {
            resetLayout();
        }

        private void add_order_Click(object sender, System.EventArgs e)
        {
            var data = new Dictionary<string, string>
                           {
                               {"produs", noProdus.Text},
                               {"valoare", noValoare.Text},
                               {"serial", noSerial.Text},
                               {"data", DateTime.Now.ToString(CultureInfo.InvariantCulture)},
                               {"id", listBox1.SelectedValue.ToString()}
                           };
            try
            {
                _context.SaveOrder(data);

                resetLayout();
                dataGridView1.DataSource = _context.GetOrders(short.Parse(listBox1.SelectedValue.ToString()));
                ((CurrencyManager)BindingContext[dataGridView1.DataSource]).Refresh();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, caption: "New Order", buttons: MessageBoxButtons.OK, icon: MessageBoxIcon.Error);
            }
        }
        #endregion

        private void delete_customer_Click(object sender, System.EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to delete the selected item?", caption: "Customer", buttons: MessageBoxButtons.YesNo, icon: MessageBoxIcon.Question).Equals(DialogResult.Yes))
            {
                try
                {
                    _context.DeleteCustomer(short.Parse(listBox1.SelectedValue.ToString()));

                    resetLayout();
                    listBox1.DataSource = _context.GetCustomers();
                    ((CurrencyManager)BindingContext[listBox1.DataSource]).Refresh();
                    dataGridView1.DataSource = _context.GetOrders(short.Parse(listBox1.SelectedValue.ToString()));
                    ((CurrencyManager)BindingContext[dataGridView1.DataSource]).Refresh();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, caption: "New Order", buttons: MessageBoxButtons.OK, icon: MessageBoxIcon.Error);
                }
            }
        }

        private void delete_order_Click(object sender, System.EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to delete the selected item?", caption: "Order", buttons: MessageBoxButtons.YesNo, icon: MessageBoxIcon.Question).Equals(DialogResult.Yes))
            {
                try
                {
                    var order = dataGridView1.SelectedRows[0].DataBoundItem;
                    var od = ((ORDER)order).ORDERID;
                    _context.DeleteOrder(od);

                    resetLayout();
                    dataGridView1.DataSource = _context.GetOrders(short.Parse(listBox1.SelectedValue.ToString()));
                    ((CurrencyManager)BindingContext[dataGridView1.DataSource]).Refresh();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, caption: "New Order", buttons: MessageBoxButtons.OK, icon: MessageBoxIcon.Error);
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
            editcustomerGBox.Visible = false;
            newcustomerGBox.Visible = false;

            orderdetailsGBox.Visible = false;
            neworderGBox.Visible = false;

            ordersGBox.Location = new System.Drawing.Point(199, 12);
            ordersGBox.Size = new System.Drawing.Size(351, 252);
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
            resetLayout();
            listBox1.ValueMember = "CUSTOMERID";
            // populate the datagridview with our orders
            dataGridView1.DataSource = _context.GetOrders(short.Parse(listBox1.SelectedValue.ToString()));
            ((CurrencyManager)BindingContext[dataGridView1.DataSource]).Refresh();

            if (listBox1.SelectedItems.Count > 0)
            {
                edit_customer.Enabled = true;
                delete_customer.Enabled = true;
            }
            else
            {
                edit_customer.Enabled = false;
                delete_customer.Enabled = false;
            }
        }

        /// <summary>
        /// Selection Changed Event for datagridview
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dataGridView1_SelectionChanged(object sender, System.EventArgs e)
        {
            resetLayout();
            if (dataGridView1.SelectedRows.Count > 0)
            {
                view_order.Enabled = true;
                delete_order.Enabled = true;
            }
            else
            {
                view_order.Enabled = false;
                delete_order.Enabled = false;
            }
        }

        #endregion

    }
}
