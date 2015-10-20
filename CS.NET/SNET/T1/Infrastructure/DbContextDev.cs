using System;
using System.Collections.Generic;
using System.Data.Objects;
using System.Linq;

namespace Infrastructure
{
    public partial class SNET_T1Entities : ObjectContext
    {
        #region Get Methods
        /// <summary>
        /// Used to retrieve all customers from the database
        /// </summary>
        /// <returns></returns>
        public List<CUSTOMER> GetCustomersDev()
        {
            return this.CUSTOMERs.Select(c => c).ToList();
        }

        /// <summary>
        /// Used to retrieve a specific customer from the database
        /// </summary>
        /// <returns></returns>
        public CUSTOMER GetCustomerDev(global::System.Int16 cID)
        {
            return this.CUSTOMERs.First(c => c.CUSTOMERID == cID);
        }

        /// <summary>
        /// Used to retrieve all orders from a specific customer
        /// </summary>
        /// <param name="cID"></param>
        /// <returns></returns>
        public List<ORDER> GetOrdersDev(global::System.Int16 cID)
        {
            return this.ORDERs.Where(o => o.CUSTOMERID == cID).ToList();
        }

        /// <summary>
        /// Used to retrieve a specifid order details
        /// </summary>
        /// <param name="oID"></param>
        /// <returns></returns>
        public ORDERDETAIL GetOrderDetailsDev(global::System.Int16 oID)
        {
            return this.ORDERDETAILS.First(od => od.ORDERID == oID);
        }
        #endregion

        #region Edit Methods
        /// <summary>
        /// Used to change a specific customer data
        /// </summary>
        /// <param name="data"></param>
        public void EditCustomerDev(Dictionary<string, string> data)
        {
            global::System.Int16 cId = short.Parse(data["id"]);
            var customer = this.CUSTOMERs.First(c => c.CUSTOMERID == cId);
            customer.ADRESA = data["address"];
            customer.NAME = data["name"];
            this.SaveChanges();
        }
        #endregion

        #region Save Methods
        /// <summary>
        /// Used to save data to a new customer
        /// </summary>
        /// <param name="data"></param>
        public void SaveCustomerDev(Dictionary<string, string> data)
        {
            var customer = new CUSTOMER
            {
                ADRESA = (!string.IsNullOrWhiteSpace(data["address"])) ? data["address"] : "[n/a]",
                NAME = data["name"]
            };
            this.AddToCUSTOMERs(customer);
            this.SaveChanges();
        }

        /// <summary>
        /// Used to save data to a new order
        /// </summary>
        /// <param name="data"></param>
        public void SaveOrderDev(Dictionary<string, string> data)
        {
            global::System.Int16 cId = short.Parse(data["id"]);
            var order = new ORDER
            {
                CUSTOMERID = cId,
                DATA = DateTime.Parse(data["data"]),
                VALOARE = Convert.ToDecimal((!string.IsNullOrWhiteSpace(data["valoare"])) ? data["valoare"] : "0.0")
            };
            this.AddToORDERs(order);

            var orderdetail = new ORDERDETAIL
            {
                ORDERID = order.ORDERID,
                PRODUS = (!string.IsNullOrWhiteSpace(data["produs"])) ? data["produs"] : "[n/a]",
                VALOARE = Convert.ToDecimal((!string.IsNullOrWhiteSpace(data["valoare"])) ? data["valoare"] : "0.0"),
                SERIAL = Convert.ToInt16((!string.IsNullOrWhiteSpace(data["serial"])) ? data["serial"] : "0")
            };
            this.AddToORDERDETAILS(orderdetail);
            this.SaveChanges();
        }
        #endregion

        #region Delete Methods
        /// <summary>
        /// Used to delete a customer from our database
        /// </summary>
        /// <param name="cID"></param>
        public void DeleteCustomerDev(global::System.Int16 cID)
        {
            var customer = this.CUSTOMERs.First(c => c.CUSTOMERID == cID);
            this.CUSTOMERs.DeleteObject(customer);
            this.SaveChanges();
        }

        /// <summary>
        /// Used to delete a order from our database
        /// </summary>
        /// <param name="oID"></param>
        public void DeleteOrderDev(global::System.Int16 oID)
        {
            var order = this.ORDERs.First(o => o.ORDERID == oID);
            this.ORDERs.DeleteObject(order);
            this.SaveChanges();
        }
        #endregion
    }
}
