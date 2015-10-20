using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace CustomerOrder
{
    public class Customer : ICustomer
    {
        public Customer GetCustomerById(int _id)
        {
            throw new NotImplementedException();
        }

        public void InsertCustomer(string _name, string _address)
        {
            throw new NotImplementedException();
        }

        public void UpdateCustomer(Customer customer)
        {
            throw new NotImplementedException();
        }

        public void DeleteCustomer(Customer customer)
        {
            throw new NotImplementedException();
        }

        public List<Order> GetAllOrders(int _customerId)
        {
            throw new NotImplementedException();
        }
    }
}
