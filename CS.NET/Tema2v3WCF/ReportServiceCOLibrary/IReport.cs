using System.Collections.Generic;
using System.ServiceModel;
using DatabaseTablesClasses;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace ReportServiceCOLibrary
{
    [ServiceContract]
    public interface IReport
    {
        [OperationContract]
        List<Customer> GetAllCustomer();
        [OperationContract]
        List<Order> GetAllOrdersForCustomer(int _customerid);
    }
}
