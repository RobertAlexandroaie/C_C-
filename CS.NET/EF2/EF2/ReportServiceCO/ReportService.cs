using EF2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace ReportServiceCO
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class ReportService : IReportService
    {
        public List<Customer> GetAllCustomers()
        {
            return new EF2.Entities().SelectCustomers();
        }

        public List<Order> GetAllOrdersForCustomer(short _customerId)
        {
            return new EF2.Entities().SelectOrdersForCustomer(_customerId).ToList();
        }
    }
}
