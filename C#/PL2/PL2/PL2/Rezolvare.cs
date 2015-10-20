using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections;

namespace PL2
{
    class Rezolvare
    {
        private Dictionary<string, int> P1_SorteazaChei(Constante.TipSortare tip)
        {
            Dictionary<string, int> sortat = new Dictionary<string,int>();
            Dictionary<string, int> d = Constante.d;

            switch ((int)tip)
            {
                case 1:
                    sortat = (from entry in d orderby entry.Key ascending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
                    break;
                case 2:
                    sortat = (from entry in d orderby entry.Key descending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
                    break;
                case 3:
                    sortat = (from entry in d orderby entry.Value ascending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
                    break;
                case 4:
                    sortat = (from entry in d orderby entry.Value descending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
                    break;
                default: 
                    Console.WriteLine("Sortarea nu se poate executa!");
                    break;
            }

            return sortat;
        }

        public void P1_EfectueazaSortare(Constante.TipSortare tip)
        {
            Constante.d = P1_SorteazaChei(tip);
            Console.WriteLine("\nDictionar Sortat de tip {0}: ", tip);
            P1_AfiseazaDictionar();
            P2_Serializeaza();
        }

        public void P1_AfiseazaDictionar()
        {
            foreach (KeyValuePair<string, int> element in Constante.d)
            {
                Console.WriteLine("Key: {0} --> Valoare: {1}", element.Key, element.Value);
            }
        }

        public void P2_Serializeaza()
        {
            Stream WriteStream = File.Create("Dictionar.bin");
            BinaryFormatter BinaryWrite = new BinaryFormatter();
            BinaryWrite.Serialize(WriteStream, Constante.d);
            WriteStream.Close();
        }

        public void P2_Deserializeaza()
        {
            Stream ReadStream = File.OpenRead("Dictionar.bin");
            BinaryFormatter BinaryRead = new BinaryFormatter();

            Dictionary<string, int> dict = new Dictionary<string, int>();
            dict = (Dictionary<string, int>)BinaryRead.Deserialize(ReadStream);
            Constante.d = dict;

            ReadStream.Close();
        }

        public void P3_AdaugaElemente()
        {
            List<Info> numere = new List<Info>();
            numere.Add(new Info(5));
            numere.Add(new Info(7));
            numere.Add(new Info(24));
            numere.Add(new Info(81));
            numere.Add(new Info(12));

            Console.WriteLine("\nNumere in Lista:");
            foreach (Info element in numere)
            {
                Console.Write("{0} ",element.n);
                element.AdaugaValoare(10);
            }

            Console.WriteLine("\nNumere modificate in Lista:");
            foreach (Info element in numere)
            {
                Console.Write("{0} ", element.n);
            }

            Console.WriteLine("\nNumere impare in Lista:");
            foreach (Info element in numere)
            {
                if (element.n % 2 == 1)
                    Console.Write("{0} ", element.n);
            }
        }

        public void P4_SegmentArray()
        {
            ArrayList segmente = new ArrayList();
            segmente.Add(new Constante.Segment(1, 1, 2, 2));
            segmente.Add(new Constante.Segment(0, 3, 5, 9));
            segmente.Add(new Constante.Segment(4, 1, 6, 7));
            segmente.Add(new Constante.Segment(8, 2, 3, 4));

            Console.WriteLine("\n\nArray nesortat: ");
            foreach (Constante.Segment element in segmente)
            {
                Console.WriteLine("{0} ", element);
            }

            Constante.Segment.sorteazaDupaPerechi sort = new Constante.Segment.sorteazaDupaPerechi();

            segmente.Sort(sort);

            Console.WriteLine("\n\nArray sortat: ");
            foreach (Constante.Segment element in segmente)
            {
                Console.WriteLine("{0} ",element);
            }
        }

        public void P5_SorteazaHeapSort()
        {
            Constante.AdaugaLista();
            P5_HeapSortList sorteaza = new P5_HeapSortList(Constante.ListaNumere);
            Console.WriteLine("\n\nLista de numere initiala");
            sorteaza.AfiseazaLista();
            Console.WriteLine("\n\nLista de numere sortata");
            sorteaza.sortList();
            sorteaza.AfiseazaLista();
        }

   }
}
