using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using DatabaseTablesClasses;

namespace Infrastructure
{
    [ServiceContract]
    public class Database : IDatabase
    {
        private Customer _customer;
        private List<Order> _orders = new List<Order>();
        private Order _order;
        private List<Customer> _customers = new List<Customer>();

        [OperationContract]
        public Customer GetCustomerById(int _id)
        {
            _customer = new Customer{Id = _id};
            return _customer;
        }

        [OperationContract]
        public void InsertCustomer(string _name, string _address)
        {
        }

        [OperationContract]
        public void UpdateCustomer(Customer customer)
        {
        }

        [OperationContract]
        public void DeleteCustomer(Customer customer)
        {
        }

        [OperationContract]
        public Order GetOrder(int _orderid)
        {
            _order = new Order {OrderId = _orderid};
            return _order;
        }

        [OperationContract]
        public void InsertOrder(int _customerid, DateTime dt, decimal _value)
        {
        }

        [OperationContract]
        public void UpdateOrder(Order order)
        {
        }

        [OperationContract]
        public void DeleteOrder(Order order)
        {
        }

        [OperationContract]
        public List<Customer> GetAllCustomer()
        {
            return _customers;
        }

        [OperationContract]
        public List<Order> GetAllOrdersForCustomer(int _customerid)
        {
            return _orders;
        }
    }
}
