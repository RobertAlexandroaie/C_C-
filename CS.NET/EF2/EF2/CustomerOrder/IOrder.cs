using EF2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace CustomerOrder
{
    [ServiceContract]
    public interface IOrder
    {
        [OperationContract]
        Order GetOrder(Int16 orderID);
        [OperationContract]
        void InsertOrder(Int16 customerID, DateTime dt, decimal value);
        [OperationContract]
        void UpdateOrder(Order order);
        [OperationContract]
        void DeleteOrder(Order order);
    }
}
