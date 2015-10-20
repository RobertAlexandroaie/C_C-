using System;
using System.ServiceModel;
using DatabaseTablesClasses;

namespace CustomerOrder
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
