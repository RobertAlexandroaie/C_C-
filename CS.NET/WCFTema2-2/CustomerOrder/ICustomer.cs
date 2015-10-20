using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using DatabaseTablesClasses;

namespace CustomerOrder
{
    [ServiceContract]
    public interface ICustomer
    {
        [OperationContract]
        Customer GetCustomerById(int _id);
        [OperationContract]
        void InsertCustomer(string _name, string _address);
        [OperationContract]
        void UpdateCustomer(Customer customer);
        [OperationContract]
        void DeleteCustomer(Customer customer);
        [OperationContract]
        List<Order> GetAllOrders(int _customerId); 
    }
}
