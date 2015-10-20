using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using DatabaseTablesClasses;

namespace Infrastructure
{
    
    public interface IDatabase
    {
        Customer GetCustomerById(int _id);
        void InsertCustomer(string _name, string _address);
        void UpdateCustomer(Customer customer);
        void DeleteCustomer(Customer customer);
        Order GetOrder(int _orderid);
        void InsertOrder(int _customerid, DateTime dt, decimal _value);
        void UpdateOrder(Order order);
        void DeleteOrder(Order order);
        List<Customer> GetAllCustomer();
        List<Order> GetAllOrdersForCustomer(int _customerid);
    }
}
