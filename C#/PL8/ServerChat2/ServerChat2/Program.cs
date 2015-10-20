using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.Threading;
using System.Net;

/** Client si Server Chat
 * @Author: Ionut Danila
 * */

namespace ServerChat2
{
    class Program
    {
        static ServerTCP server;

        static void Main(string[] args)
        {
            server = new ServerTCP(IPAddress.Parse("10.1.14.40"), 2005);
            Console.WriteLine("--- Chat Server Started...");
            server.Start();
        }
    }
}
