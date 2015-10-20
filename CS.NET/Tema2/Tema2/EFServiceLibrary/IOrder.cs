using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace CustomerOrder
{
    [ServiceContract]
    interface IOrder
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
