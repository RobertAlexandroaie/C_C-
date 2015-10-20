using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace ReportServiceCO
{
    class Program
    {
        static void Main(string[] args)
        {
            var reportHost = new ServiceHost(typeof(ReportServiceCOLibrary.Report), new Uri("net.tcp://localhost:2023/reportservice"));
            var behavior = new ServiceMetadataBehavior();
            reportHost.Description.Behaviors.Add(behavior);
            reportHost.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");

            reportHost.Open();
            Console.WriteLine("Report Service Started...");
            Console.ReadLine();
            reportHost.Close();
        }
    }
}
