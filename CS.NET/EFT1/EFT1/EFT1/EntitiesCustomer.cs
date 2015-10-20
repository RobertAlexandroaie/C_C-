using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.Objects;
using IsolationLevel = System.Transactions.IsolationLevel;
using System.Transactions;
using System.Data.EntityClient;
using System.Data;

namespace EFT1
{
    public class EntitiesCustomer
    {
        private const int _maxAttempts = 5;
        private TestEntities _context;

        public EntitiesCustomer()
        {
            _context = new TestEntities();
        }

        #region Read Methods
        ///<summmary>
        ///Select all customers
        ///</summary>
        public List<CUSTOMER> SelectCustomers()
        {
            List<CUSTOMER> customers = new List<CUSTOMER>();
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();

                try
                {
                    foreach (CUSTOMER c in _context.CUSTOMERs.Select(c => c))
                    {
                        customers.Add(c);
                    }
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                    throw;
                }
                _context.Connection.Close();
            }
            return customers;
        }

        public CUSTOMER SelectCustomer(Int16 id)
        {
            CUSTOMER customer;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();

                try
                {
                    customer = _context.CUSTOMERs.First(c => c.CUSTOMERID == id);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                    throw;
                }
                _context.Connection.Close();
            }
            return customer;
        }

        public List<ORDER> SelectOrders()
        {
            List<ORDER> orders = new List<ORDER>();
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();

                try
                {
                    foreach (ORDER o in _context.ORDERs.Select(o => o))
                    {
                        orders.Add(o);
                    }
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                    throw;
                }
                _context.Connection.Close();
            }
            return orders;
        }

        public ORDER SelectOrder(Int16 id)
        {
            ORDER order;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();

                try
                {
                    order = _context.ORDERs.First(o => o.ORDERID == id);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                    throw;
                }
                _context.Connection.Close();
            }
            return order;
        }

        public ORDERDETAILS SelectOrderDetails(Int16 id)
        {
            ORDERDETAILS orderDetails;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();

                try
                {
                    orderDetails = _context.ORDERDETAILSs.First(od => od.ORDERID == id);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                    throw;
                }
                _context.Connection.Close();
            }
            return orderDetails;
        }
        #endregion

        #region Create Methods
        public void InsertCustomer(Int16 id, string name, string adresa)
        {
            //TestEntities context = new TestEntities();
            //_context = new TestEntities();
            //CUSTOMER customer = new CUSTOMER
            //{
            //    CUSTOMERID = id,
            //    NAME = name,
            //    ADRESA = adresa
            //};
            //_context.CUSTOMERs.AddObject(customer);
            //_context.SaveChanges();
            //_context.AcceptAllChanges();

            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead // blocam baza de date la read si write
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();


                CUSTOMER customer = new CUSTOMER
                {
                    CUSTOMERID = id,
                    NAME = name,
                    ADRESA = adresa
                };

                _context.CUSTOMERs.AddObject(customer);
                for (int i = 0; i < _maxAttempts && !success; i++)
                {
                    try
                    {
                        _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                    catch (OptimisticConcurrencyException)
                    {
                        _context.Refresh(RefreshMode.ClientWins, customer);
                    }
                    catch (Exception)
                    {
                        _context.Connection.Close();
                    }
                    finally
                    {
                        if (success)
                        {
                            transactionScope.Complete();
                            _context.AcceptAllChanges();
                        }
                    }
                }
                _context.Connection.Close();
            }
        }

        public void InsertOrder(Int16 orderID, Int16 customerID, DateTime date, decimal valoare)
        {
            //TestEntities context = new TestEntities();

            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();


                var customer = from c in _context.CUSTOMERs
                               where c.CUSTOMERID == customerID
                               select c;

                var order = new ORDER()
                {
                    ORDERID = orderID,
                    CUSTOMERID = customerID,
                    DATA = date,
                    VALOARE = valoare,
                    CUSTOMER = customer.First()
                };

                _context.ORDERs.AddObject(order);
                for (int i = 0; i < _maxAttempts && !success; i++)
                {
                    try
                    {
                        _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                    catch (OptimisticConcurrencyException)
                    {
                        _context.Refresh(RefreshMode.ClientWins, order);
                    }
                    catch (Exception)
                    {
                        _context.Connection.Close();
                    }
                    finally
                    {
                        if (success)
                        {
                            transactionScope.Complete();
                            _context.AcceptAllChanges();
                        }
                    }
                }
                _context.Connection.Close();
            }
        }

        public void InsertOrderDetails(Int16 orderID, string product, decimal valoare, Int16 serial)
        {
            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();


                var orderDetails = new ORDERDETAILS()
                {
                    ORDERID = orderID,
                    PRODUS = product,
                    VALOARE = valoare,
                    SERIAL = serial
                };

                try
                {
                    var order = from o in _context.ORDERs
                                where o.ORDERID == orderID
                                select o;

                    ORDER ord = order.First();
                    ord.ORDERDETAILS.Add(orderDetails);
                }
                catch (Exception)
                {
                    Console.WriteLine("Nu exista comanda!");
                }
                _context.ORDERDETAILSs.AddObject(orderDetails);
                for (int i = 0; i < _maxAttempts && !success; i++)
                {
                    try
                    {
                        _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                    catch (OptimisticConcurrencyException)
                    {
                        _context.Refresh(RefreshMode.ClientWins, orderDetails);
                    }
                    catch (Exception)
                    {
                        _context.Connection.Close();
                    }
                    finally
                    {
                        if (success)
                        {
                            transactionScope.Complete();
                            _context.AcceptAllChanges();
                        }
                    }
                }
                _context.Connection.Close();
            }
        }
        #endregion

        #region Update Methods
        public void UpdateCustomer(Int16 id, string name, string address)
        {
            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();


                var customer = _context.CUSTOMERs.First(c => c.CUSTOMERID == id);
                if (customer != null)
                {
                    if (name != null)
                        customer.NAME = name;
                    if (address != null)
                        customer.ADRESA = address;
                    for (int i = 0; i < _maxAttempts && !success; i++)
                    {
                        try
                        {
                            _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                            success = true;
                        }

                        catch (OptimisticConcurrencyException)
                        {
                            //SaveChanges(SaveOptions.DetectChangesBeforeSave);
                            _context.Refresh(RefreshMode.ClientWins, customer);
                            success = true;
                        }
                        catch (Exception)
                        {
                            _context.Connection.Close();
                        }
                        finally
                        {
                            if (success)
                            {
                                transactionScope.Complete();
                                _context.AcceptAllChanges();
                            }
                        }
                    }
                    _context.Connection.Close();
                }
            }
        }
        #endregion

        #region Delete Methods
        public void DeleteCustomer(Int16 id)
        {
            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.Serializable
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                _context.Connection.Open();


                var customer = _context.CUSTOMERs.First(c => c.CUSTOMERID == id);
                _context.CUSTOMERs.DeleteObject(customer);
                for (int i = 0; i < _maxAttempts && !success; i++)
                {
                    try
                    {
                        _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                    catch (OptimisticConcurrencyException)
                    {
                        //SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        _context.Refresh(RefreshMode.ClientWins, customer);
                        success = true;
                    }
                    catch (Exception)
                    {
                        _context.Connection.Close();
                    }
                    finally
                    {
                        if (success)
                        {
                            transactionScope.Complete();
                            _context.AcceptAllChanges();
                        }
                    }
                }
                _context.Connection.Close();
            }
        }

        public void DeleteOrder(Int16 id)
        {
            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.Serializable
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {

                _context.Connection.Open();

                foreach (ORDERDETAILS d in _context.ORDERDETAILSs)
                {
                    if (d.ORDERID == id)
                        _context.ORDERDETAILSs.DeleteObject(d);
                }

                var order = _context.ORDERs.First(o => o.ORDERID == id);
                order.ORDERDETAILS.Clear();
                _context.ORDERs.DeleteObject(order);
                for (int i = 0; i < _maxAttempts && !success; i++)
                {
                    try
                    {
                        _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                    catch (OptimisticConcurrencyException)
                    {
                        //SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        _context.Refresh(RefreshMode.ClientWins, order);
                        success = true;
                    }
                    catch (Exception)
                    {
                        _context.Connection.Close();
                        throw;
                    }
                    finally
                    {
                        if (success)
                        {
                            transactionScope.Complete();
                            _context.AcceptAllChanges();
                        }
                    }
                }
                _context.Connection.Close();
            }
        }

        public void DeleteOrderDetails(Int16 idOrder, Int16 idDetail)
        {
            _context = new TestEntities();

            bool success = false;

            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.Serializable
            };

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {

                _context.Connection.Open();

                try
                {
                    var order = _context.ORDERs.First(o => o.ORDERID == idOrder);


                    foreach (ORDERDETAILS d in order.ORDERDETAILS)
                    {
                        if (d.SERIAL == idDetail)
                        {
                            _context.ORDERDETAILSs.DeleteObject(d);
                            order.ORDERDETAILS.Remove(d);
                        }
                    }


                    _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (OptimisticConcurrencyException)
                {
                    _context.SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    _context.Connection.Close();
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        _context.AcceptAllChanges();
                    }
                }
                _context.Connection.Close();
            }
        }
        #endregion

        public void Display()
        {
            List<CUSTOMER> cust = SelectCustomers();
            List<ORDER> order = SelectOrders();
            foreach (CUSTOMER c in cust)
            {
                Console.WriteLine("Customer:\n" + c.CUSTOMERID.ToString() + " " + c.NAME + " " + c.ADRESA);

                foreach (ORDER o in order)
                {
                    if (c.CUSTOMERID == o.CUSTOMERID)
                        Console.WriteLine("Order:\n" + o.ORDERID + " " + o.DATA + " " + o.VALOARE);
                    if(o.ORDERDETAILS.Count != 0)
                        Console.WriteLine("Order details:");
                    foreach (ORDERDETAILS d in o.ORDERDETAILS)
                    {
                        if (o.ORDERID == d.ORDERID && o.CUSTOMERID == c.CUSTOMERID)
                            Console.WriteLine(d.SERIAL + " " + d.PRODUS + " " + d.VALOARE);
                    }
                }
            }
        }
    }
}
