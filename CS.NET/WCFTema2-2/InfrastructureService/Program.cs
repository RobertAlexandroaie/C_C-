using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace InfrastructureService
{
    class Program
    {
        static void Main(string[] args)
        {
            var serviceHost = new ServiceHost(typeof(Infrastructure.Database), new Uri("net.tcp://localhost:8181/database"));
            serviceHost.AddServiceEndpoint(typeof(Infrastructure.Database), new NetTcpBinding(), "");
            // endpoint pentru metadata
            var behavior = new ServiceMetadataBehavior();
            serviceHost.Description.Behaviors.Add(behavior);
            serviceHost.AddServiceEndpoint(typeof(IMetadataExchange),
            MetadataExchangeBindings.CreateMexTcpBinding(), "mex");
            serviceHost.Open();
            Console.WriteLine("Intern Service Started..." + "\nPress <Enter> to stop Service...");
            Console.ReadLine();
            serviceHost.Close();
        }
    }
}
