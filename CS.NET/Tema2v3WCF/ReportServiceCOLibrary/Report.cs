using System.Collections.Generic;
using System.ServiceModel;
using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace ReportServiceCOLibrary
{
    //Serviciul ReportServiceCO va crea cate o instanta pentru fiecare apel de la clienti, dupa care o va distruge (garbage collector). 
    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerCall, ConcurrencyMode = ConcurrencyMode.Multiple)]
    public class Report : IReport
    {
        public List<Customer> GetAllCustomer()
        {
            using (var dc = new DatabaseClient())
            {
                return new List<Customer>(dc.GetAllCustomer());
            }
        }

        public List<Order> GetAllOrdersForCustomer(int _customerid)
        {
            using (var dc = new DatabaseClient())
            {
                return new List<Order>(dc.GetAllOrdersForCustomer(_customerid));
            }
        }
    }
}
