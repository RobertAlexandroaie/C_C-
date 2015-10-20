using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace Infrastructure
{
    [ServiceContract]
    public interface IDatabase
    {
        [OperationContract]
        DatabaseTablesClasses.Customer GetCustomerById(int _id);
        [OperationContract]
        void InsertCustomer(string _name, string _address);
        [OperationContract]
        void UpdateCustomer(DatabaseTablesClasses.Customer customer);
        [OperationContract]
        void DeleteCustomer(DatabaseTablesClasses.Customer customer);
        [OperationContract]
        DatabaseTablesClasses.Order GetOrder(int _orderid);
        [OperationContract]
        void InsertOrder(int _customerid, DateTime dt, decimal _value);
        [OperationContract]
        void UpdateOrder(DatabaseTablesClasses.Order order);
        [OperationContract]
        void DeleteOrder(DatabaseTablesClasses.Order order);
        [OperationContract]
        List<DatabaseTablesClasses.Customer> GetAllCustomer();
        [OperationContract]
        List<DatabaseTablesClasses.Order> GetAllOrdersForCustomer(int _customerid);
    }
}
