using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

// pt remoting
using System.Runtime.Remoting;
using System.Runtime.Remoting.Services;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;

// add reference to MetadataInterfete_Client
using MetadataInterfete;


namespace ClientInterfete
{
    class ClientInterfete
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Client ce foloseste metadata furnizata prin interfete...");

            HttpChannel channel = new HttpChannel();

            ChannelServices.RegisterChannel(channel, false);

            // Obtin proxy la obiectul remote
            Object remoteObj = Activator.GetObject(
                                  typeof(MetadataInterfete.ICalculator),
                                  "http://localhost:8080/CalculatorURI.soap"
                               );

            // Cast tip returnat la tipul Calculator
            ICalculator math = (ICalculator)remoteObj;

            // Utilizare obiect remote
            float fadd = math.Add(15.2f, 3.7f);
            Console.WriteLine("math.Add(15.2f, 3.7f) = {0}", fadd);

            try
            {
                float fdiv = math.Divide(12.0f, 0.0f);
                Console.WriteLine("math.Divide(12.0f, 0.0f) = {0}", fdiv);
            }
            catch (Exception ic)
            {
                Console.WriteLine("Eroare : \n(message) {0} \n(stack trace) {1} \n(inner) {2}",
                    ic.Message, ic.StackTrace, ic.InnerException);
            }

            Console.Write("Press enter to end");
            Console.ReadLine();


        }
    }
}
