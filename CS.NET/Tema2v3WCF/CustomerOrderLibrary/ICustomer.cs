using System.Collections.Generic;
using System.ServiceModel;
using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace CustomerOrderLibrary
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
