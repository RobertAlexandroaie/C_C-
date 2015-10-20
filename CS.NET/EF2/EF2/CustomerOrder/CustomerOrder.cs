using EF2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace CustomerOrder
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class CustomerOrder : ICustomer, IOrder
    {
        public Customer GetCustomerById(short id)
        {
            EF2.Customer result = new EF2.Entities().SelectCustomer(id);
            if (result == null)
                return new Customer();

            return result;
        }

        public bool InsertCustomer(string name, string address)
        {
            return new EF2.Entities().InsertCustomer(name, address);
        }

        public bool UpdateCustomer(Customer customer)
        {
            return new EF2.Entities().UpdateCustomer(customer);
        }

        public void DeleteCustomer(Customer customer)
        {
            new EF2.Entities().DeleteCustomer(customer);
        }

        public List<Order> GetAllOrders(short customerID)
        {
            return new ReportService.ReportServiceClient().GetAllOrdersForCustomer(customerID);
        }

        public Order GetOrder(short orderID)
        {
            return new EF2.Entities().SelectOrder(orderID);
        }

        public void InsertOrder(short customerID, DateTime dt, decimal value)
        {
            new EF2.Entities().InsertOrder(customerID, dt, value);
        }

        public void UpdateOrder(Order order)
        {
            new EF2.Entities().UpdateOrder(order);
        }

        public void DeleteOrder(Order order)
        {
            new EF2.Entities().DeleteOrder(order);
        }
    }
}
