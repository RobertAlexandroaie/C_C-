using System;
using System.ServiceModel;

namespace WCF1
{
    // Serviciul
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
    // end serviciu
    // host pentru serviciu. Aplicatie consola.
    public class MainHostService
    {
        public static void Main()
        {
            ServiceHost serviceHost = new ServiceHost(typeof(StockService), new Uri("net.tcp://localhost:8000/StockWcf"));
            serviceHost.AddServiceEndpoint(typeof(IStockService), new NetTcpBinding(), "");
            serviceHost.Open();
            Console.WriteLine("Serviciu lansat. " + "\nAsteptare conexiuni. " + "\nApasati <Enter> pentru a inchide serviciul");
            Console.ReadLine();
            serviceHost.Close();
        }
    }
}