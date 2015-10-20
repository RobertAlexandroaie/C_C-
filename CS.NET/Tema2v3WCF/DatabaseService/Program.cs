using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseService
{
    class Program
    {
        static void Main(string[] args)
        {
            var serviceHost = new ServiceHost(typeof(Infrastructure.Database), new Uri("net.tcp://localhost:2021/database"));
            var behavior = new ServiceMetadataBehavior();
            serviceHost.Description.Behaviors.Add(behavior);
            serviceHost.AddServiceEndpoint(typeof(IMetadataExchange), MetadataExchangeBindings.CreateMexTcpBinding(), "mex");
           serviceHost.Open();
            Console.WriteLine("Database Service Started...");
            Console.ReadLine();
            serviceHost.Close();
        }
    }
}
