using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;
using CustomerOrderLibrary;

namespace CustomerOrderService2
{
    class Program
    {
        static void Main(string[] args)
        {
            var host = new ServiceHost(typeof(CustomerOrder), new Uri("net.tcp://localhost:2022/customerorder"));
            var behavior = new ServiceMetadataBehavior();
            host.Description.Behaviors.Add(behavior);
            host.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");

            host.Open();
            Console.WriteLine("Customer Service Started..." + "\nPress <Enter> to stop Services...");
            Console.ReadLine();

            host.Close();
        }
    }
}
