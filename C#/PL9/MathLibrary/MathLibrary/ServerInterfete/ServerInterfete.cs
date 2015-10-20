using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;

// add reference to MathLibraryInterfete project

using MathLibraryInterfete;

namespace ServerInterfete
{
    class ServerInterfete
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Incercare lansare server ...");
            RemotingConfiguration.Configure("ServerInterfete.config", false);
            Console.WriteLine("Server lansat. Astept clienti...");
            Console.ReadLine();

        }
    }
}
