using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/** Client si Server Chat
 * @Author: Ionut Danila
 * */

namespace ClientChat2
{
    class Variabile
    {
        private static ClientChat clientChat = new ClientChat();

        public static ClientChat ClientChat
        {
            get { return clientChat; }
            set { clientChat = value; }
        }

        private static string identitate;

        public static string Identitate
        {
            get { return identitate; }
            set { identitate = value; }
        }

        private static string parola;

        public static string Parola
        {
            get { return parola; }
            set { parola = value; }
        }

        public static string[] Utilizatori
        {
            get;
            set;
        }

        public static string Nume { get; set; }
    }
}
