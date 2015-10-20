using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL1
{
    class Program
    {
        public enum TipCaracter
        {
            Litera = 0x0001,
            Numar = 0x0002,
            Punctuatie = 0x0004
        }

        static void Main(string[] args)
        {
            //P1
            Console.WriteLine("P1: ");
            L1 test = new L1();
            string[] info = new string[4]{"12", "Iasi", "Copou", "Berthelot 16"};
            char delimitator = ',';
            string output = test.P1_ArrayToString(info, delimitator);
            Console.WriteLine(output);

            //P2
            Console.WriteLine("\nP2: ");
            string[] info2 = test.P2_StringToArray(test.P1_ArrayToString(info, delimitator),delimitator);

            foreach (string element in info2)
            {
                Console.Write("{0} ", element);
            }

            //P3
            Console.Write("\n\nL3: ");
            string sursa = "abCd3A.dc7;arAd";
            char ceCaut = 'a';
            int maxAparitie = 0;
            bool caseSensitive = true;

            int[] rezultat = test.P3_CautCaracter(sursa, ceCaut, out maxAparitie, caseSensitive);

            Console.WriteLine("\nTextul introdus: \"{0}\" Case sensitive: {1}",sursa, caseSensitive);
            Console.Write("Caracterul '{0}' a aparut pe pozitiile: ",ceCaut);
            
            for (int i=0; i<rezultat.Length; i++)
            {
                Console.Write("{0} ",rezultat[i]);
            }

            Console.WriteLine("\nNumarul de aparitii: {0}",maxAparitie);

            //P4
            Console.WriteLine("\nP4: ");
            Console.WriteLine("In textul introdus exista doar caractere cautate? {0}", test.P4_AflaTipCaracter(TipCaracter.Litera | TipCaracter.Numar | TipCaracter.Punctuatie, sursa));

            //P5
            Console.WriteLine("\nP5: ");
            test.P5_Environment();

            Console.ReadLine();
        }
    }
}
