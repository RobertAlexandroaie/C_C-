using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace WCFService
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceHost hostCustomerOrder = new ServiceHost(typeof(CustomerOrder.CustomerOrder));
            ServiceHost hostReport = new ServiceHost(typeof(ReportServiceCO.ReportService));
            ServiceHost hostSubscribe = new ServiceHost(typeof(Subscribe.SubscribeMessage));

            hostCustomerOrder.Open();
            hostReport.Open();
            hostSubscribe.Open();

            Console.WriteLine("Press <Enter> to stop server");
            Console.ReadLine();

            hostSubscribe.Close();
            hostReport.Close();
            hostCustomerOrder.Close();
        }
    }
}
