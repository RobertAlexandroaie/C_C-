using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Transactions;

namespace EF2
{
    public class Entities
    {
        private TestEntities _context;

        public Entities() 
        {
            _context = new TestEntities();
        }

        public List<Customer> SelectCustomers()
        {
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                try
                {
                    using (var db = new TestEntities())
                    {
                        var customers = db.Customer;

                        if (customers != null)
                            return customers.ToList();
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.InnerException);
                }
                return null;
            }
        }

        public Customer SelectCustomer(Int16 id)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    var customers = db.Customer.Where(x => x.CUSTOMERID == id);

                    if (customers != null && customers.Count() > 0)
                        return customers.ToList()[0];
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
            return null;
        }

        public List<Order> SelectOrders()
        {
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                try
                {
                    using (var db = new TestEntities())
                    {
                        var orders = db.Order;

                        if (orders != null)
                            return orders.ToList();
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.InnerException);
                }
                return null;
            }
        }

        public List<Order> SelectOrdersForCustomer(Int16 customerID)
        {
            return SelectOrders().Where(x => x.CUSTOMERID == customerID).ToList();
        }

        public Order SelectOrder(Int16 id)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    var orders = db.Order.Where(x => x.ORDERID == id);

                    if (orders != null && orders.Count() > 0)
                        return orders.ToList()[0];
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
            return null;
        }

        public OrderDetails SelectOrderDetails(Int16 id)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    var orderDetail = db.OrderDetails.Where(x => x.ORDERID == id);

                    if (orderDetail != null && orderDetail.Count() > 0)
                        return orderDetail.ToList()[0];
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
            return null;
        }

        public bool InsertCustomer(string name, string adresa)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    Customer customer = new Customer();
                    customer.NAME = name;
                    customer.ADRESA = adresa;

                    db.Customer.Add(customer);
                    db.SaveChanges();
                    return true;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
                return false;
            }
        }

        public void InsertOrder(Int16 customerID, DateTime dt, decimal value)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    Order order = new Order();
                    order.CUSTOMERID = customerID;
                    order.DATA = dt;
                    order.VALOARE = value;

                    db.Order.Add(order);
                    db.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
        }

        public bool UpdateCustomer(Customer customer)
        {
            try
            {
                using(var db = new TestEntities())
                {
                    Customer cust = new Customer();
                    cust = db.Customer.First(x => x.CUSTOMERID == customer.CUSTOMERID);

                    if (cust == null)
                        return false;

                    cust.NAME = customer.NAME;
                    cust.ADRESA = customer.ADRESA;

                    db.SaveChanges();
                    return true;
                }
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.InnerException);
                return false;
            }
        }

        public void UpdateOrder(Order order)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    Order ord = db.Order.First(x => x.ORDERID == order.ORDERID);
                    ord.CUSTOMERID = order.CUSTOMERID;
                    ord.DATA = order.DATA;
                    ord.VALOARE = order.VALOARE;

                    db.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
        }

        public void DeleteCustomer(Customer customer)
        {
            try
            {
                using(var db = new TestEntities())
                {
                    //Customer cust = SelectCustomer(customer.CUSTOMERID);
                    Customer cust = db.Customer.First(x => x.CUSTOMERID == customer.CUSTOMERID);
                    db.Customer.Remove(cust);
                    db.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
        }

        public void DeleteOrder(Order order)
        {
            try
            {
                using (var db = new TestEntities())
                {
                    //Order ord = SelectOrder(order.ORDERID);
                    Order ord = db.Order.First(x => x.ORDERID == order.ORDERID);
                    db.Order.Remove(ord);
                    db.SaveChanges();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.InnerException);
            }
        }
    }
}
