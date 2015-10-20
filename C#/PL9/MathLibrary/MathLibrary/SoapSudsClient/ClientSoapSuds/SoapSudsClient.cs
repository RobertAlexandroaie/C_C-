using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

// Add reference to System.Runtime.Remoting
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;

namespace ClientSoapSuds
{
    class SoapSudsClient
    {
        static void Main(string[] args)
        {
            //
            // Configurare client "Hard coded"
            //

            HttpChannel channel = new HttpChannel();

            ChannelServices.RegisterChannel(channel, false);

            // Obtin proxy la obiectul remote
            Object remoteObj = Activator.GetObject(
                                  typeof(MathLibrary.Calculator),
                                  "http://localhost:8080/CalculatorURI.soap"
                               );

            // Cast tip returnat la tipul Calculator
            Calculator math = (Calculator)remoteObj;

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
            //Console.WriteLine("5 - 2 = {0}", math.Subtract(5, 2));
            //Console.WriteLine(" 5 * 2 = {0}", math.Multiply(5, 2));

            // Ask user to press Enter
            Console.Write("Press enter to end");
            Console.ReadLine();

        }
    }
}
