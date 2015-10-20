using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace SubscribeService
{
    class Program
    {
        static void Main()
        {
            var myService = new ServiceHost(typeof (SubscribeLibrary.SubscribeMessage),
                                                    new Uri("net.tcp://localhost:2033/callbackmessage"));
            myService.Open();
            Console.WriteLine("Press enter to stop.");
            Console.ReadKey();
            if (myService.State != CommunicationState.Closed)
                myService.Close(); 
        }
    }
}
