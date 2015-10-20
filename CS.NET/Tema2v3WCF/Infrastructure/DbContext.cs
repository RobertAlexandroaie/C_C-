using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Objects;
using System.Linq;
using System.Transactions;
using DatabaseTablesClasses;
using IsolationLevel = System.Transactions.IsolationLevel;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace Infrastructure
{
    public partial class SNET_T1Entities : ObjectContext
    {
        #region Get Methods
        /// <summary>
        /// Used to retrieve all customers from the database
        /// </summary>
        /// <returns></returns>
        public List<CUSTOMER> GetCustomers()
        {
            IQueryable<CUSTOMER> customers;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    customers = CUSTOMERs.Select(c => c);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                Connection.Close();
            }
            return customers.ToList();
        }

        /// <summary>
        /// Used to retrieve a specific customer from the database
        /// </summary>
        /// <returns></returns>
        public Customer GetCustomer(Int16 cId)
        {
            CUSTOMER customer;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    customer = CUSTOMERs.First(c => c.CUSTOMERID == cId);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                Connection.Close();
            }

            var cust = new Customer{Address = customer.ADRESA, Id = customer.CUSTOMERID, Name = customer.NAME};
            return cust;
        }

        /// <summary>
        /// Used to retrieve all orders from a specific customer
        /// </summary>
        /// <param name="cId"></param>
        /// <returns></returns>
        public List<ORDER> GetOrders(Int16 cId)
        {
            IQueryable<ORDER> orders;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    orders = ORDERs.Where(o => o.CUSTOMERID == cId);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                Connection.Close();
            }
            return orders.ToList();
        }

        /// <summary>
        /// Used to retrieve a specifid order details
        /// </summary>
        /// <param name="oId"></param>
        /// <returns></returns>
        public ORDERDETAIL GetOrderDetails(Int16 oId)
        {
            ORDERDETAIL orderdetails;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.ReadUncommitted
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    orderdetails = ORDERDETAILS.First(od => od.ORDERID == oId);
                    transactionScope.Complete();
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                Connection.Close();
            }
            return orderdetails;
        }
        #endregion

        #region Edit Methods
        /// <summary>
        /// Used to change a specific order data
        /// </summary>
        /// <param name="data"></param>
        public void EditOrder(Dictionary<string, string> data)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    var oId = short.Parse(data["id"]);
                    var order = ORDERs.First(c => c.ORDERID == oId);
                    if (order != null)
                    {
                        order.ORDERID = oId;
                        order.DATA = DateTime.Parse(data["data"]);
                        order.VALOARE = Convert.ToDecimal((!string.IsNullOrWhiteSpace(data["valoare"])) ? data["valoare"] : "0.0");
                        SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    };
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }

        /// <summary>
        /// Used to change a specific customer data
        /// </summary>
        /// <param name="data"></param>
        public void EditCustomer(Dictionary<string, string> data)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    Int16 cId = short.Parse(data["id"]);
                    var customer = CUSTOMERs.First(c => c.CUSTOMERID == cId);
                    if (customer != null)
                    {
                        customer.ADRESA = data["address"];
                        customer.NAME = data["name"];
                        SaveChanges(SaveOptions.DetectChangesBeforeSave);
                        success = true;
                    }
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }
        #endregion

        #region Save Methods
        /// <summary>
        /// Used to save data to a new customer
        /// </summary>
        /// <param name="data"></param>
        public void SaveCustomer(Dictionary<string, string> data)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    var customer = new CUSTOMER
                    {
                        ADRESA = (!string.IsNullOrWhiteSpace(data["address"])) ? data["address"] : "[n/a]",
                        NAME = data["name"]
                    };
                    AddToCUSTOMERs(customer);
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }

        /// <summary>
        /// Used to save data to a new order
        /// </summary>
        /// <param name="data"></param>
        public void SaveOrder(Dictionary<string, string> data)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.RepeatableRead
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    var cId = short.Parse(data["id"]);
                    var order = new ORDER
                    {
                        CUSTOMERID = cId,
                        DATA = DateTime.Parse(data["data"]),
                        VALOARE = Convert.ToDecimal((!string.IsNullOrWhiteSpace(data["valoare"])) ? data["valoare"] : "0.0")
                    };
                    AddToORDERs(order);

                    //this.SaveChanges(SaveOptions.DetectChangesBeforeSave);

                    var orderdetail = new ORDERDETAIL
                    {
                        ORDERID = order.ORDERID,
                        PRODUS = (!string.IsNullOrWhiteSpace(data["produs"])) ? data["produs"] : "[n/a]",
                        VALOARE = Convert.ToDecimal((!string.IsNullOrWhiteSpace(data["valoare"])) ? data["valoare"] : "0.0"),
                        SERIAL = Convert.ToInt16((!string.IsNullOrWhiteSpace(data["serial"])) ? data["serial"] : "0")
                    };
                    AddToORDERDETAILS(orderdetail);

                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }
        #endregion

        #region Delete Methods
        /// <summary>
        /// Used to delete a customer from our database
        /// </summary>
        /// <param name="cId"></param>
        public void DeleteCustomer(Int16 cId)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.Serializable
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    var customer = CUSTOMERs.First(c => c.CUSTOMERID == cId);
                    CUSTOMERs.DeleteObject(customer);
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }

        /// <summary>
        /// Used to delete a order from our database
        /// </summary>
        /// <param name="oId"></param>
        public void DeleteOrder(Int16 oId)
        {
            bool success = false;
            var transactionOptions = new TransactionOptions
            {
                IsolationLevel = IsolationLevel.Serializable
            };
            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, transactionOptions))
            {
                Connection.Open();
                try
                {
                    var order = ORDERs.First(o => o.ORDERID == oId);
                    ORDERs.DeleteObject(order);
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (OptimisticConcurrencyException)
                {
                    // TODO: handle this exception for concurency conflicts !!!
                    // check for ex.StateEntries[0].Entity and try refreshing it using
                    // RefreshMode.ClientWins or RefreshMode.StoreWins -> choose carefully
                    //
                    // add new property to each entity - RowVersion or ModifiedTime each
                    // of them with ConcurrencyMode set to Fixed in order for this to work
                    SaveChanges(SaveOptions.DetectChangesBeforeSave);
                    success = true;
                }
                catch (Exception)
                {
                    Connection.Close();
                    throw;
                }
                finally
                {
                    if (success)
                    {
                        transactionScope.Complete();
                        AcceptAllChanges();
                    }
                }
                Connection.Close();
            }
        }
        #endregion
    }
}
