using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using WCFClient.ProxyReport;

namespace WCFClient
{
    public partial class Form1 : Form
    {
        List<Customer> customers = null;
        List<Order> orders = null;
        Int16 currentID = -1;
        Int16 currentSerial = -1;
        Int16 currentOrderId = -1;
        public Form1()
        {
            InitializeComponent();
            BindCustomers();
        }

        private void buttonCustomerNew_Click(object sender, EventArgs e)
        {
            if (textBoxCustomerName.Text == "" || textBoxCustomerAddress.Text == "")
            {
                MessageBox.Show("Name and address are required!");
            }
            else
            {
                Proxy.CustomerClient customer = new Proxy.CustomerClient();
                customer.InsertCustomer(textBoxCustomerName.Text, textBoxCustomerAddress.Text);

                BindCustomers();
            }
        }

        private void BindCustomers()
        {
            customers = new ProxyReport.ReportServiceClient().GetAllCustomers();
            dataGridView1.DataSource = customers;
        }

        private void buttonCustomerEdit_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentID == -1)
                    MessageBox.Show("Select Customer!");
                else
                {
                    if (textBoxCustomerName.Text == "" && textBoxCustomerAddress.Text == "")
                        MessageBox.Show("Name or address should be modified!");
                    else
                    {
                        Proxy.Customer cust = new Proxy.Customer();
                        ProxyReport.Customer custReport = customers.First(x => x.CUSTOMERID == currentID);
                        cust.ADRESA = textBoxCustomerAddress.Text;
                        cust.CUSTOMERID = custReport.CUSTOMERID;
                        cust.NAME = textBoxCustomerName.Text;
                        foreach (var order in custReport.Order)
                        {
                            Proxy.Order ord = new Proxy.Order();
                            ord.CUSTOMERID = order.CUSTOMERID;
                            ord.DATA = order.DATA;
                            ord.ORDERID = order.ORDERID;
                            ord.VALOARE = order.VALOARE;
                            
                            foreach(var orderDetails in order.OrderDetails)
                            {
                                Proxy.OrderDetails ordDet = new Proxy.OrderDetails();
                                ordDet.ORDERID = orderDetails.ORDERID;
                                ordDet.PRODUS = orderDetails.PRODUS;
                                ordDet.SERIAL = orderDetails.SERIAL;
                                ordDet.VALOARE = orderDetails.VALOARE;

                                ord.OrderDetails.Add(ordDet);
                            }

                            cust.Order.Add(ord);
                        }

                        new Proxy.CustomerClient().UpdateCustomer(cust);
                        BindCustomers();
                    }
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void buttonOrderNew_Click(object sender, EventArgs e)
        {
            if (textBoxOrderValoare.Text == "")
            {
                MessageBox.Show("Order details required!");
            }
            else
                if (currentID == -1)
                    MessageBox.Show("Select a customer!");
            else
            {
                decimal value = -1;
                decimal.TryParse(textBoxOrderValoare.Text, out value);

                if (value == -1)
                {
                    MessageBox.Show("Order details are not correct! Please try again!");
                }
                else
                {
                    Proxy.OrderClient order = new Proxy.OrderClient();
                    order.InsertOrder(currentID, DateTime.Now, value);
                }

                BindOrders(currentID);
            }
        }

        private void BindOrders(short customerID)
        {
            dataGridView2.DataSource = new Proxy.CustomerClient().GetAllOrders(customerID);
        }

        private void ShowOrdersOnClick(object sender, DataGridViewCellEventArgs e)
        {
            if (customers == null || e.RowIndex == -1)
            {
                return;
            }
            BindOrders(customers[e.RowIndex].CUSTOMERID);
            currentID = customers[e.RowIndex].CUSTOMERID;
        }

        private void GetID(object sender, DataGridViewCellEventArgs e)
        {
            currentID = customers[e.RowIndex].CUSTOMERID;
        }

        private void buttonCustomerDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentID == -1)
                    MessageBox.Show("Select a customer!");
                else
                {
                    //Proxy.Customer cust = new Proxy.Customer();
                    //ProxyReport.Customer custReport = customers.First(x => x.CUSTOMERID == currentID);
                    //cust.ADRESA = textBoxCustomerAddress.Text;
                    //cust.CUSTOMERID = custReport.CUSTOMERID;
                    //cust.NAME = textBoxCustomerName.Text;
                    //foreach (var order in custReport.Order)
                    //{
                    //    Proxy.Order ord = new Proxy.Order();
                    //    ord.CUSTOMERID = order.CUSTOMERID;
                    //    ord.DATA = order.DATA;
                    //    ord.ORDERID = order.ORDERID;
                    //    ord.VALOARE = order.VALOARE;

                    //    foreach (var orderDetails in order.OrderDetails)
                    //    {
                    //        Proxy.OrderDetails ordDet = new Proxy.OrderDetails();
                    //        ordDet.ORDERID = orderDetails.ORDERID;
                    //        ordDet.PRODUS = orderDetails.PRODUS;
                    //        ordDet.SERIAL = orderDetails.SERIAL;
                    //        ordDet.VALOARE = orderDetails.VALOARE;

                    //        ord.OrderDetails.Add(ordDet);
                    //    }

                    //    cust.Order.Add(ord);
                    //}


                    new Proxy.CustomerClient().DeleteCustomer(new Proxy.CustomerClient().GetCustomerById(currentID));
                    BindCustomers();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void GetOrderID(object sender, DataGridViewCellEventArgs e)
        {
            //currentOrderId = customers.First(x => x.CUSTOMERID == currentID).Order[e.RowIndex].ORDERID;
            currentOrderId = new Proxy.CustomerClient().GetAllOrders(currentID)[e.RowIndex].ORDERID;
        }

        private void buttonUpdateOrder_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentOrderId == -1)
                    MessageBox.Show("Select Order!");
                else
                {
                    if (textBoxOrderValoare.Text == "")
                        MessageBox.Show("Change Value!");
                    else
                    {
                        Proxy.Order order = new Proxy.OrderClient().GetOrder(currentOrderId);
                        decimal value = -1;
                        decimal.TryParse(textBoxOrderValoare.Text, out value);
                        order.VALOARE = value;

                        new Proxy.OrderClient().UpdateOrder(order);
                        BindOrders(currentID);
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void buttonOrderDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentOrderId == -1)
                    MessageBox.Show("Select order!");
                else
                {
                    Proxy.Order order = new Proxy.OrderClient().GetOrder(currentOrderId);
                    new Proxy.OrderClient().DeleteOrder(order);
                    BindOrders(currentID);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void buttonOrderDetailNew_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentOrderId == -1)
                    MessageBox.Show("Select order!");
                else
                {
                    if (textBoxOrderSerial.Text == "" ||  textBoxOrderProdus.Text == "")
                        MessageBox.Show("Serial and value are required!");
                    else
                    {
                        Proxy.Order order = new Proxy.OrderClient().GetOrder(currentOrderId);
                        Proxy.OrderDetails ordDet = new Proxy.OrderDetails();
                        ordDet.ORDERID = order.ORDERID;
                        ordDet.PRODUS = textBoxOrderProdus.Text;
                        Int16 value = -1;
                        Int16.TryParse(textBoxOrderSerial.Text, out value);
                        if (value == -1)
                            MessageBox.Show("Introduce a number!");
                        else
                            ordDet.SERIAL = value;
                        ordDet.VALOARE = decimal.Parse(order.VALOARE.ToString());

                        order.OrderDetails.Add(ordDet);
                        new Proxy.OrderClient().UpdateOrder(order);
                        BindOrderDetails();
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void ShowOrderDetails(object sender, DataGridViewCellEventArgs e)
        {
            if (currentOrderId == -1 || e.RowIndex == -1)
            {
                return;
            }
            BindOrderDetails();
        }

        private void BindOrderDetails()
        {
            dataGridView3.DataSource = new Proxy.CustomerClient().GetAllOrders(currentID).First(x => x.ORDERID == currentOrderId).OrderDetails;
        }

        private void buttonOrderDetailUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentOrderId == -1)
                    MessageBox.Show("Select Order!");
                else
                {
                    if (textBoxOrderSerial.Text == "" && textBoxOrderProdus.Text == "")
                        MessageBox.Show("Introduce a serial AND a product!");
                    else
                    {
                        Proxy.Order order = new Proxy.OrderClient().GetOrder(currentOrderId);
                        Proxy.OrderDetails ordDet = new Proxy.OrderDetails();
                        Int16 value = -1;
                        Int16.TryParse(textBoxOrderSerial.Text, out value);
                        if (value == -1)
                            MessageBox.Show("Introduce a number!");
                        else
                        {
                            ordDet = order.OrderDetails.First(x => x.SERIAL == value);
                            order.OrderDetails.Remove(ordDet);
                            ordDet.PRODUS = textBoxOrderProdus.Text;
                            order.OrderDetails.Add(ordDet);
                            BindOrderDetails();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }

        private void GetSerial(object sender, DataGridViewCellEventArgs e)
        {
            currentSerial = customers.First(x => x.CUSTOMERID == currentID).Order.First(x => x.ORDERID == currentOrderId).OrderDetails[e.RowIndex].SERIAL;
        }

        private void buttonOrderDetailsDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (currentSerial == -1)
                    MessageBox.Show("Select order detail!");
                else
                {
                    Proxy.Order order = new Proxy.OrderClient().GetOrder(currentOrderId);
                    Proxy.OrderDetails ordDet = order.OrderDetails.First(x => x.SERIAL == currentSerial);
                    order.OrderDetails.Remove(ordDet);
                    new Proxy.OrderClient().UpdateOrder(order);
                    BindOrderDetails();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.InnerException.ToString());
            }
        }
    }
}
