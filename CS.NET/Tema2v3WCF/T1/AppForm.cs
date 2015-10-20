using System;
using System.Collections.Generic;
using System.Globalization;
using System.ServiceModel;
using System.Windows.Forms;
//using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace WcfClient
{
    [CallbackBehavior(ConcurrencyMode = ConcurrencyMode.Reentrant)] 
    public partial class AppForm : Form, ISubscribeCallback
    {
        private readonly ChannelFactory<ICustomer> channelCustomer;
        private readonly ICustomer wcfCustomer;

        private readonly ChannelFactory<IOrder> channelOrder;
        private readonly IOrder wcfOrder;

        private readonly ChannelFactory<IReport> channelReport;
        private readonly IReport wcfReport;

        private readonly SubscribeClient subscribe;

        public AppForm()
        {
            channelCustomer = new ChannelFactory<ICustomer>(new NetTcpBinding(), new EndpointAddress("net.tcp://localhost:2022/customerorder"));
            channelOrder = new ChannelFactory<IOrder>(new NetTcpBinding(), new EndpointAddress("net.tcp://localhost:2022/customerorder"));
            channelReport = new ChannelFactory<IReport>(new NetTcpBinding(), new EndpointAddress("net.tcp://localhost:2023/reportservice"));
            
            // Instanta tipului din serviciu
            wcfCustomer = channelCustomer.CreateChannel();
            wcfOrder = channelOrder.CreateChannel();
            wcfReport = channelReport.CreateChannel();

            var context = new InstanceContext(this);
            subscribe = new SubscribeClient(context, "NetTcpBinding_ISubscribe");
            subscribe.Subscribe();

            InitializeComponent();
        }

        private void Form1_Load(object sender, System.EventArgs e)
        {
            // populate the listbox with our customers
            var lista = wcfReport.GetAllCustomer();
            listBox1.DataSource = lista;
            listBox1.DisplayMember = "Name";
            listBox1.ValueMember = "Id";
        }

        #region Buttons

        #region EditCustomer Box
        private void edit_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
            ordersGBox.Location = new System.Drawing.Point(199, 123);
            ordersGBox.Size = new System.Drawing.Size(351, 141);
            editcustomerGBox.Visible = true;

            var customer = wcfCustomer.GetCustomerById(short.Parse(listBox1.SelectedValue.ToString()));

            ecAddress.Text = customer.Address.Trim();
            ecName.Text = customer.Name.Trim();
        }

        private void cancel_save_customer_Click(object sender, System.EventArgs e)
        {
            resetLayout();
        }

        private void save_customer_Click(object sender, System.EventArgs e)
        {
            try
            {
                wcfCustomer.UpdateCustomer(new Customer
                                               {
                                                   Address = ecAddress.Text,
                                                   Id = Convert.ToInt32(listBox1.SelectedValue.ToString()),
                                                   Name = ecName.Text
                                               });

                resetLayout();
                listBox1.DataSource = wcfReport.GetAllCustomer();
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
            try
            {
                wcfCustomer.InsertCustomer(ncName.Text, ncAddress.Text);

                resetLayout();
                listBox1.DataSource = wcfReport.GetAllCustomer();
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
            var od = wcfOrder.GetOrder(((Order)order).OrderId);

            odProdus.Text = od.Produs;
            odSerial.Text = od.Serial.ToString(CultureInfo.InvariantCulture);
            odValoare.Text = od.Valoare.ToString(CultureInfo.InvariantCulture).Trim();
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
                wcfOrder.InsertOrder(short.Parse(listBox1.SelectedValue.ToString()),DateTime.Now,decimal.Parse(noValoare.Text));

                resetLayout();
                dataGridView1.DataSource = wcfCustomer.GetAllOrders(short.Parse(listBox1.SelectedValue.ToString()));
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
                    wcfCustomer.DeleteCustomer(wcfCustomer.GetCustomerById(short.Parse(listBox1.SelectedValue.ToString())));

                    resetLayout();
                    listBox1.DataSource = wcfReport.GetAllCustomer();
                    ((CurrencyManager)BindingContext[listBox1.DataSource]).Refresh();
                    dataGridView1.DataSource = wcfCustomer.GetAllOrders(short.Parse(listBox1.SelectedValue.ToString()));
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
                    var od = ((Order)order).OrderId;
                    wcfOrder.DeleteOrder(wcfOrder.GetOrder(od));

                    resetLayout();
                    dataGridView1.DataSource = wcfCustomer.GetAllOrders(short.Parse(listBox1.SelectedValue.ToString()));
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
            listBox1.ValueMember = "Id";
            // populate the datagridview with our orders
            var lista = wcfCustomer.GetAllOrders(short.Parse(listBox1.SelectedValue.ToString()));

            dataGridView1.DataSource = lista;
            ((CurrencyManager)BindingContext[dataGridView1.DataSource]).Refresh();
            dataGridView1.Columns.Remove("ExtensionData");

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

        public void OnInsertUpdateDelete(string message)
        {
            MessageBox.Show(message);
        }
    }
}
