using System;
using System.Collections.Generic;
using System.ServiceModel;
using DatabaseTablesClasses;
using SubscribeLibrary;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace CustomerOrderLibrary
{
    //Serviciul CustomerOrder va permite concurenta multipla la nivel de sesiune. 
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession, ConcurrencyMode = ConcurrencyMode.Multiple)]
    public class CustomerOrder : ICustomer, IOrder, ISubscribe
    {
        private static readonly List<IReportSuccessOrError> subscribers = new List<IReportSuccessOrError>();

        public Customer GetCustomerById(int _id)
        {
            using (var dc = new DatabaseClient())
            {
                return dc.GetCustomerById(_id);
            }
        }

        public void NotifyUsers(string message)
        {
            foreach (var subscriber in subscribers)
            {
                subscriber.OnInsertUpdateDelete(message);
            }
        }

        public void InsertCustomer(string _name, string _address)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("UserInsert");
                dc.InsertCustomer(_name, _address);
            }
        }

        public void UpdateCustomer(Customer customer)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("UserUpdate");
                dc.UpdateCustomer(customer);
            }
        }

        public void DeleteCustomer(Customer customer)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("UserDelete");
                dc.DeleteCustomer(customer);
            }
        }

        public List<Order> GetAllOrders(int _customerId)
        {
            using (var dc = new ReportClient())
            {
                return new List<Order>(dc.GetAllOrdersForCustomer(_customerId));
            }
        }

        public Order GetOrder(int _orderid)
        {
            using (var dc = new DatabaseClient())
            {
                return dc.GetOrder(_orderid);
            }
        }

        public void InsertOrder(int _customerid, DateTime dt, decimal _value)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("OrderInsert");
                dc.InsertOrder(_customerid, dt, _value);
            }
        }

        public void UpdateOrder(Order order)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("OrderUpdate");
                dc.UpdateOrder(order);
            }
        }

        public void DeleteOrder(Order order)
        {
            using (var dc = new DatabaseClient())
            {
                NotifyUsers("OrderDelete");
                dc.DeleteOrder(order);
            }
        }

        public void Subscribe()
        {
            try
            {
                var callback = OperationContext.Current.GetCallbackChannel<IReportSuccessOrError>();
                // Inregistrez “tipul” ce implementeaza IReportSuccessOrError
                // Acest tip este pe partea de client
                if (!subscribers.Contains(callback))
                    subscribers.Add(callback);
            }
            catch
            {
                Console.WriteLine("FALSE SUBSCRIBE");
            }
        }

        public void Unsubscribe()
        {
            try
            {
                var callback = OperationContext.Current.GetCallbackChannel<IReportSuccessOrError>();
                if (!subscribers.Contains(callback))
                    subscribers.Remove(callback);
            }
            catch
            {
                Console.WriteLine("FALSE UNSUBSCRIBE");
            }
        }
    }
}
