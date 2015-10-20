using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using DatabaseTablesClasses;

namespace ClientTest
{
    // Metadata pentru serviciu
    [ServiceContract]
    public interface ICustomer
    {
        [OperationContract]
        Customer GetCustomerById(int _id);
        [OperationContract]
        void InsertCustomer(string _name, string _address);
        [OperationContract]
        void UpdateCustomer(Customer customer);
    }
    // end metadata


    class ClientWcf
    {
        static void Main(string[] args)
        {
            var channel = new ChannelFactory<ICustomer>(new NetTcpBinding(), new EndpointAddress("net.tcp://localhost:2022/customerorder"));
            // Instanta tipului din serviciu
            var wcfClient = channel.CreateChannel();
            Customer cust = wcfClient.GetCustomerById(2);
            Console.WriteLine("Name = {0}", cust.Name);

            //wcfClient.InsertCustomer("Ionel","Str. Capsunilor");
            wcfClient.UpdateCustomer(new Customer { Address = "Adresa Noua", Id = 14, Name = "Florin" });
            Console.WriteLine("Am udatat");
            Console.ReadLine();
        }
    }
}
