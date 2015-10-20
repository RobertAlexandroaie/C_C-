using System;
using System.ServiceModel;
using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace CustomerOrderLibrary
{
    [ServiceContract]
    public interface IOrder
    {
        [OperationContract]
        Order GetOrder(int _orderid);
        [OperationContract]
        void InsertOrder(int _customerid, DateTime dt, decimal _value);
        [OperationContract]
        void UpdateOrder(Order order);
        [OperationContract]
        void DeleteOrder(Order order);
    }
}
