using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace CustomerOrderService
{
    class Program
    {
        static void Main(string[] args)
        {
            var host = new ServiceHost(typeof(CustomerOrder.CustomerOrder), new Uri("net.tcp://localhost:8182/customer"));
            host.AddServiceEndpoint(typeof(CustomerOrder.ICustomer), new NetTcpBinding(), "");
            host.AddServiceEndpoint(typeof(CustomerOrder.IOrder), new NetTcpBinding(), "");
            host.AddServiceEndpoint(typeof(CustomerOrder.CustomerOrder), new NetTcpBinding(), "");
            var behavior = new ServiceMetadataBehavior();
            host.Description.Behaviors.Add(behavior);
            host.AddServiceEndpoint(typeof(IMetadataExchange),MetadataExchangeBindings.CreateMexTcpBinding(), "mex");
            host.Open();
            Console.WriteLine("Server extern started...");
            Console.ReadLine();
            host.Close();



        }
    }
}
