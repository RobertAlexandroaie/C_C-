using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL1
{
    class L1
    {
        public L1()
        {

        }

        public string P1_ArrayToString(string [] info, char delimitator)
        {
            if ((info != null) && (delimitator.ToString() != ""))
            {
                string output = "";

                foreach (string element in info)
                {
                    output = output + element + delimitator;
                }
                output = output.Remove(output.Length - 1);
                return output;
            }
            else
            {
                Console.WriteLine("Parametri incorecti la P1!");
                return "";
            }
        }

        public string[] P2_StringToArray(string input, char delimitator)
        {
            if ((input != null) && (delimitator.ToString() != ""))
            {
                string[] info = input.Split(delimitator);
                return info;
            }
            else
            {
                Console.WriteLine("Parametri incorecti la P2!");
                return new string[0];
            }
        }

        private int[] P3_GasesteCaractere(string sursa, char ceCaut, out int maxAparitie)
        {
            int tempMax = 0;
            List<int> lista = new List<int>();

            for (int i = 0; i < sursa.Length; i++)
            {
                if (sursa[i] == ceCaut)
                {
                    lista.Add(i);
                    tempMax++;
                }
            }

            maxAparitie = tempMax;
            int[] pozitii = lista.ToArray();
            return pozitii;
        }

        public int[] P3_CautCaracter(string sursa, char ceCaut, out int maxAparitie, bool sensitive)
        {
            if ((sursa != "") && (ceCaut.ToString() != "") && (sensitive.ToString() != ""))
            {
                maxAparitie = 0;
                if (!sensitive)
                {
                    sursa = sursa.ToUpper();
                    ceCaut = ceCaut.ToString().ToUpper()[0];
                    int[] pozitii = P3_GasesteCaractere(sursa, ceCaut, out maxAparitie);
                    return pozitii;
                }
                else
                {
                    int[] pozitii = P3_GasesteCaractere(sursa, ceCaut, out maxAparitie);
                    return pozitii;
                }
            }
            else
            {
                maxAparitie = 0;
                Console.WriteLine("Parametri incorecti la P3!");
                return new int[0];
            }
        }

        public bool P4_AflaTipCaracter(Program.TipCaracter tip, string sursa)
        {
            if ((tip.ToString() != "") && (sursa != ""))
            {
                string temp1 = "";
                string temp2 = "";
                string temp3 = "";

                if ((tip & Program.TipCaracter.Litera) != 0)
                    foreach (char s in sursa)
                    {
                        if (!Char.IsLetter(s))
                            temp1 = temp1 + s;
                    }
                else
                    temp1 = sursa;

                if ((tip & Program.TipCaracter.Numar) != 0)
                    foreach (char s in temp1)
                    {
                        if (!Char.IsNumber(s))
                            temp2 = temp2 + s;
                    }
                else
                    temp2 = temp1;

                if ((tip & Program.TipCaracter.Punctuatie) != 0)
                    foreach (char s in temp2)
                    {
                        if (!Char.IsPunctuation(s))
                            temp3 = temp3 + s;
                    }
                else
                    temp3 = temp2;

                if (temp3 == "") return true;
                else return false;
            }
            else
            {
                Console.WriteLine("Parametri incorecti la P4!");
                return false;
            }
        }

        public void P5_Environment()
        {
            Console.WriteLine("Sistemul de Operare: {0}", Environment.OSVersion);
            Console.WriteLine("Numarul de procesoare: {0}", Environment.ProcessorCount);
            Console.WriteLine("Procesare pe 64 Biti: {0}", Environment.Is64BitProcess);
            Console.WriteLine("Sistem de Operare pe 64 Biti: {0}", Environment.Is64BitOperatingSystem);
            Console.WriteLine("Numele calculatorului: {0}", Environment.MachineName);
            Console.WriteLine("Versiunea .NET: {0}", Environment.Version);
            Console.WriteLine("Memoria disponibila: {0}", Environment.WorkingSet);
            Console.WriteLine("Numele Utilizatorului: {0}", Environment.UserName);
            Console.WriteLine("Numarul de milisecunde de la pornirea sistemului: {0}", Environment.TickCount);
        }
    }
}
