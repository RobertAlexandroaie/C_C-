using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PL2
{
    class Program
    {
        

        static void Main(string[] args)
        {
            Rezolvare r = new Rezolvare();
            //P2
            if (Constante.d.Count == 0)
            {
                if (File.Exists("Dictionar.bin"))
                    r.P2_Deserializeaza();
                else
                    Constante.AdaugaValori();
            }
            
            Console.WriteLine("Dictionar Initial: ");
            r.P1_AfiseazaDictionar();

            //P1
            r.P1_EfectueazaSortare(Constante.TipSortare.CrescatorKey);
            r.P1_EfectueazaSortare(Constante.TipSortare.DescrescatorKey);
            r.P1_EfectueazaSortare(Constante.TipSortare.CrescatorValori);
            r.P1_EfectueazaSortare(Constante.TipSortare.DescrescatorValori);

            //P3
            r.P3_AdaugaElemente();

            //P4
            r.P4_SegmentArray();

            //P5
            r.P5_SorteazaHeapSort();
        }
    }
}
