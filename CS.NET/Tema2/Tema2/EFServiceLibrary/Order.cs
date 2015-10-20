using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CustomerOrder
{
    public class Order : IOrder
    {
        public Order GetOrder(int _orderid)
        {
            throw new NotImplementedException();
        }

        public void InsertOrder(int _customerid, DateTime dt, decimal _value)
        {
            throw new NotImplementedException();
        }

        public void UpdateOrder(Order order)
        {
            throw new NotImplementedException();
        }

        public void DeleteOrder(Order order)
        {
            throw new NotImplementedException();
        }
    }
}
