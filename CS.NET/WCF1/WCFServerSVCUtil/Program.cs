using System;
using System.ServiceModel.Description;
using System.ServiceModel;

namespace WCFServerSVCUtil
{
    [ServiceContract]
    public interface IStockService
    {
        [OperationContract]
        double GetPrice(string _text);
    }
    public class StockService : IStockService
    {
        public double GetPrice(string _text)
        {
            return 12.13;
        }
    }
    public class MainHostService
    {
        public static void Main()
        {
            ServiceHost serviceHost = new ServiceHost(typeof(StockService), new Uri("net.tcp://localhost:8000/StockWcf"));
            serviceHost.AddServiceEndpoint(typeof(IStockService),new NetTcpBinding(), "");
            // endpoint pentru metadata
            ServiceMetadataBehavior behavior = new ServiceMetadataBehavior();
            //behavior.HttpGetEnabled = true;
            serviceHost.Description.Behaviors.Add(behavior);
            serviceHost.AddServiceEndpoint(typeof(IMetadataExchange),
            MetadataExchangeBindings.CreateMexTcpBinding(),"mex");
            //
            serviceHost.Open();
            Console.WriteLine("Serviciu lansat. " + "\nAsteptare conexiuni. " + "\nApasati <Enter> pentru a inchide serviciul");
            Console.ReadLine();
            serviceHost.Close();
        }
    }
}