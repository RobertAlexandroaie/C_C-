using EF2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace CustomerOrder
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the interface name "IService1" in both code and config file together.
    [ServiceContract]
    public interface ICustomer
    {
        [OperationContract]
        Customer GetCustomerById(Int16 id);
        [OperationContract]
        bool InsertCustomer(string name, string address);
        [OperationContract]
        bool UpdateCustomer(Customer customer);
        [OperationContract]
        void DeleteCustomer(Customer customer);
        [OperationContract]
        List<Order> GetAllOrders(Int16 customerID);
    }
}
