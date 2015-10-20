using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/** Client si Server Chat
 * @Author: Ionut Danila
 * */

namespace ServerChat2
{
    class Variabile
    {
        private static string textAfisat;

        public static string TextAfisat
        {
            get { return textAfisat; }
            set { textAfisat = value; }
        }
    }
}
