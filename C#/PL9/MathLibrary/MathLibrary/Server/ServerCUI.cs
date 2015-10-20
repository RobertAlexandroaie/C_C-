using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Net.Configuration;
using System.Runtime.Remoting;

using System.Runtime.Remoting.Channels; // Channel Services

// Adaug referinat la System.Runtime.Remoting
// Project->Add Reference -> Net -> ... si selectam System.Runtime.Remoting
using System.Runtime.Remoting.Channels.Http;

// adaug referinta la MathLibrary
// Project->Add Reference -> Projects -> ...
// 

using MathLibrary;

namespace Server
{
    /// <summary>
    /// Host pentru obiectul remote: MathLibrary.Calculator
    /// Aplicatie tip consola
    /// </summary>
    class ServerCUI
    {
        static void Main(string[] args)
        {
            //
            // Configurare protocol si port "Hard coded"
            //

            // Creare canal specificand numarul de port 
            HttpChannel channel = new HttpChannel(8080);

            // Inregistrare canal cu serviciile runtime remoting
            // 
            ChannelServices.RegisterChannel(channel, false);

            /* In .NET 2.0
             public static void RegisterChannel (
	                IChannel chnl,
	                bool ensureSecurity
                    )
 
            Parameters
            chnl    The channel to register.
            ensureSecurity true ensures that security is enabled; otherwise false. 
              Setting the value to false will not nullify the security setting done on the TCP or IPC channel.
             * 
             * If the ensureSecurity parameter is set to true, the remoting system determines whether the channel 
             * implements ISecurableChannel, and if so, enables encryption and digital signatures. 
             * An exception is thrown if the channel does not implement ISecurableChannel.

               Setting ensureSecurity to true throws a RemotingException for the TcpServerChannel on Windows 98 
             * (Since secure tcp channels are not supported on Windows 9x), 
             * and for the HttpServerChannel on all platforms 
             * (You must host your service in IIS if you want to use a secure http channel). 
             */

            // Inregistram tipul ca fiind well-known si Singleton

            RemotingConfiguration.RegisterWellKnownServiceType(
               typeof(MathLibrary.Calculator), // Tipul pe care-l inregistram in server 
               "CalculatorURI.soap",                   // Numele sub care este inregistrat
               WellKnownObjectMode.Singleton   // Well-known: SingleCall sau Singleton
            );

            /*
             * Pentru a folosi fisier de configurare comentati liniile de cod de mai sus 
             * si decomentati linia urmatoare de cod:
             * */
            
            //    RemotingConfiguration.Configure("ServerConfigurationFile.config", false);

            // Serverul ruleaza si asteapta clienti...
            Console.WriteLine("Server lansat in executie...\nPress Enter to end");
            Console.ReadLine();

        }
    }
}
