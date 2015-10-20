using System;
using System.ServiceModel;

namespace WCF1Client
{
    // Metadata pentru serviciu
    [ServiceContract]
    public interface IStockService
    {
        [OperationContract]
        double GetPrice(string _text);
    }
    // end metadata
    class ClientWcf
    {
        static void Main(string[] args)
        {
            ChannelFactory<IStockService> channel = new ChannelFactory<IStockService>(new NetTcpBinding(),new EndpointAddress("net.tcp://localhost:8000/StockWcf"));
            // Instanta tipului din serviciu
            IStockService wcfClient = channel.CreateChannel();
            double price = wcfClient.GetPrice("wcf");
            Console.WriteLine("Price = {0}", price);
            Console.ReadLine();
        }
    }
}