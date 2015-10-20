using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using DatabaseTablesClasses;

namespace CustomerOrder
{
    public class CustomerOrder : ICustomer, IOrder
    {
        private Customer _customer;
        private List<Order> _orders = new List<Order>();
        private Order _order;

        public Customer GetCustomerById(int _id)
        {
            _customer = new Customer {Id = _id};
            return new Customer();
        }

        public void InsertCustomer(string _name, string _address)
        {
            _customer = new Customer {Id = 1, Name = _name, Address = _address};
        }

        public void UpdateCustomer(Customer customer)
        {
            _customer = customer;
        }

        public void DeleteCustomer(Customer customer)
        {
            _customer = customer;
        }

        public List<Order> GetAllOrders(int _customerId)
        {
            return _orders;
        }

        public Order GetOrder(int _orderid)
        {
            _order = new Order { OrderId = _orderid };
            return _order;
        }

        public void InsertOrder(int _customerid, DateTime dt, decimal _value)
        {
            _order = new Order { CustomerId = _customerid, Data = dt, Valoare = _value, OrderId = 23 };
        }

        public void UpdateOrder(Order order)
        {
            _order = order;
        }

        public void DeleteOrder(Order order)
        {
            _order = order;
        }
    }
}
