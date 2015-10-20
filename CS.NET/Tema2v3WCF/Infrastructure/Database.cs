using System;
using System.Collections.Generic;
using System.Globalization;
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

    public class Database : IDatabase
    {
        readonly DbConnection _connection = new DbConnection();

        public Customer GetCustomerById(int _id)
        {
            return _connection.Context.GetCustomer((short)_id);
        }

        public void InsertCustomer(string _name, string _address)
        {
            _connection.Context.AddToCUSTOMERs(new CUSTOMER { ADRESA = _address, NAME = _name });
            _connection.Commit();
        }

        public void UpdateCustomer(Customer customer)
        {
            var data = new Dictionary<string, string>
                           {
                               {"id",customer.Id.ToString(CultureInfo.InvariantCulture)},
                               {"address", customer.Address},
                               {"name", customer.Name}
                           };

            _connection.Context.EditCustomer(data);
            _connection.Commit();
        }

        public void DeleteCustomer(Customer customer)
        {
            _connection.Context.DeleteCustomer((short)customer.Id);
            _connection.Commit();
        }

        public Order GetOrder(int _orderid)
        {
            var order = _connection.Context.ORDERs.First(c => c.ORDERID == _orderid);
            var newOrder = new Order
                               {
                                   CustomerId = order.CUSTOMERID,
                                   Data = order.DATA,
                                   OrderId = order.ORDERID,
                                   Valoare = order.VALOARE
                               };
            return newOrder;
        }

        public void InsertOrder(int _customerid, DateTime dt, decimal _value)
        {
            _connection.Context.AddToORDERs(new ORDER{CUSTOMERID = (short)_customerid, DATA = dt, VALOARE = _value});
            _connection.Commit();
        }

        public void UpdateOrder(Order order)
        {
            var data = new Dictionary<string, string>
                           {
                               {"id",order.OrderId.ToString(CultureInfo.InvariantCulture)},
                               {"data", order.Data.ToString(CultureInfo.InvariantCulture)},
                               {"valoare", order.Valoare.ToString(CultureInfo.InvariantCulture)}
                           };

            _connection.Context.EditOrder(data);
            _connection.Commit();
        }

        public void DeleteOrder(Order order)
        {
            _connection.Context.DeleteOrder((short)order.OrderId);
            _connection.Commit();
        }

        public List<Customer> GetAllCustomer()
        {
            var customersDB = _connection.Context.CUSTOMERs;
            var customersLocal = customersDB.Select(customer => new Customer { Address = customer.ADRESA, Id = customer.CUSTOMERID, Name = customer.NAME }).ToList();
            return customersLocal;
        }

        public List<Order> GetAllOrdersForCustomer(int _customerid)
        {
            var ordersDb = _connection.Context.GetOrders((short) _customerid);
            var ordersLocal = ordersDb.Select(order => new Order {CustomerId = order.CUSTOMERID, Data = order.DATA, OrderId = order.ORDERID, Valoare = order.VALOARE, Produs = "TBA", Serial = 0}).ToList();
            return ordersLocal;
        }
    }
}
