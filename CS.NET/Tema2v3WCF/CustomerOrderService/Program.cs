using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;
using CustomerOrderLibrary;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace WcfServer
{
    class Program
    {
        static void Main(string[] args)
        {
            var host = new ServiceHost(typeof(CustomerOrder), new Uri("net.tcp://localhost:2022/customerorder"));
            var behavior = new ServiceMetadataBehavior();
            host.Description.Behaviors.Add(behavior);
            host.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");
            
            var serviceHost = new ServiceHost(typeof(Infrastructure.Database), new Uri("net.tcp://localhost:2021/database"));
            serviceHost.Description.Behaviors.Add(behavior);
            serviceHost.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");

            var reportHost = new ServiceHost(typeof(ReportServiceCOLibrary.Report), new Uri("net.tcp://localhost:2023/reportservice"));
            reportHost.Description.Behaviors.Add(behavior);
            reportHost.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");

            reportHost.Open();
            Console.WriteLine("Report Service Started...");

            serviceHost.Open();
            Console.WriteLine("Database Service Started...");

            host.Open();
            Console.WriteLine("Customer Service Started..."+ "\nPress <Enter> to stop Services...");
            Console.ReadLine();
            
            host.Close();
            serviceHost.Close();
            reportHost.Close();
        }
    }
}
