using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace PL2
{
    class Constante
    {
        public enum TipSortare
        {
            CrescatorKey = 1,
            DescrescatorKey = 2,
            CrescatorValori = 3,
            DescrescatorValori = 4
        }

        public static Dictionary<string, int> d = new Dictionary<string, int>();

        public static void AdaugaValori()
        {
            d.Clear();
            d.Add("luni", 1);
            d.Add("sambata", 6);
            d.Add("marti", 2);
            d.Add("vineri", 5);
            d.Add("miercuri", 3);
            d.Add("joi", 4);
            d.Add("duminica", 7);
        }

        public static List<int> ListaNumere = new List<int>();

        public static void AdaugaLista()
        {
            ListaNumere.Add(2);
            ListaNumere.Add(4);
            ListaNumere.Add(90);
            ListaNumere.Add(-6);
            ListaNumere.Add(12);
            ListaNumere.Add(73);
        }

        public class Segment : IComparable
        {
            public int x1,y1,x2,y2;

            public Segment(int x1, int y1, int x2, int y2)
            {
                this.x1 = x1;
                this.y1 = y1;
                this.x2 = x2;
                this.y2 = y2;
            }

            override public string ToString()
            {
                StringWriter output = new StringWriter();
                output.Write("X1: {0}, Y1: {1}, X2: {2}, Y2: {3}",x1,y1,x2,y2);
                return output.ToString();
            }

            public class sorteazaDupaPerechi : IComparer
            {
                int IComparer.Compare(object a, object b)
                {
                    Segment s1 = (Segment)a;
                    Segment s2 = (Segment)b;

                    if (s1.x1 <= s2.x1)
                    {
                        if (s1.y1 < s2.y1)
                            return 11;
                        else
                            return 12;
                    }
                    else
                        if (s1.x1 > s2.x1)
                        {
                            return 21;
                        }

                    return 0;
                }
            }

            // Implement IComparable CompareTo to provide default sort order.
            int IComparable.CompareTo(object obj)
            {
                Segment s = (Segment)obj;
                return String.Compare(this.x1.ToString(), s.x1.ToString());
            }

            // Method to return IComparer object for sort helper.
            public static IComparer sorteazaPerechile()
            {
                return (IComparer)new sorteazaDupaPerechi();
            }
        }

    }
            
}
