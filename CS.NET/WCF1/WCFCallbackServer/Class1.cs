using System;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace WCFCallbackServer
{
    class WCFServer
    {
        static void Main(string[] args)
        {
            ServiceHost myService = new ServiceHost(typeof(WPFLib1.MessageService),
            new Uri("net.tcp://localhost:9191/WCFCallbacks/Message/"));
            ServiceDescription serviceDesciption = myService.Description;
            // enumerare endpoint-uir din serviciu - informativ
            foreach (ServiceEndpoint endpoint in serviceDesciption.Endpoints)
            {
                ConsoleColor oldColour = Console.ForegroundColor;
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine("Endpoint - address: {0}", endpoint.Address);
                Console.WriteLine(" - binding name:\t\t{0}",
                endpoint.Binding.Name);
                Console.WriteLine(" - contract name:\t\t{0}",
                endpoint.Contract.Name);
                Console.WriteLine();
                Console.ForegroundColor = oldColour;
            }
            myService.Open();
            Console.WriteLine("Press enter to stop.");
            Console.ReadKey();
            if (myService.State != CommunicationState.Closed)
                myService.Close();
        }
    }
}