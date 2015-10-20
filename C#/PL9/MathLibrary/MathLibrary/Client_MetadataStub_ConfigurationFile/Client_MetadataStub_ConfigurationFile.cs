using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;

// add reference to MathLibrary
using MathLibrary;

namespace Client_MetadataStub_ConfigurationFile
{
    class Client_MetadataStub_ConfigurationFile
    {
        static void Main(string[] args)
        {

            RemotingConfiguration.Configure("Client_MetadataStub_ConfigurationFile.exe.config", false);

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

            // alta modalitate de instantiere
            Object orem = Activator.CreateInstance(typeof(MathLibrary.Calculator));
            Calculator cm = (Calculator)orem;

            fadd = math.Add(15.2f, 3.7f);
            Console.WriteLine("math.Add(15.2f, 3.7f) = {0}", fadd);

            Console.WriteLine("Tastati Enter pentru a termina...");
            Console.ReadLine();
            
        }
    }
}
