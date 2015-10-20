using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL2
{
    class P5_HeapSortList
    {
        // list of integers to hold values
        private List<int> lista = new List<int>();
        
        // number of elements in array
        private int x;

        public P5_HeapSortList(List<int> input)
        {
            this.lista = input;
            this.x = lista.Count();
        }

        public void AfiseazaLista()
        {
            foreach (int element in this.lista)
            {
                Console.Write("{0} ",element.ToString());
            }
        }

        // Heap Sort Algorithm
        public void sortList()
        {
            int i;
            int temp1, temp2;

            for (i = (x / 2) - 1; i >= 0; i--)
            {
                siftDown(i, x);
            }

            for (i = x - 1; i >= 1; i--)
            {
                temp1 = lista.ElementAt(0);
                temp2 = lista.ElementAt(i);
                lista.RemoveAt(0);
                lista.RemoveAt(i-1);
                lista.Insert(0, temp2);
                lista.Insert(i, temp1);
                siftDown(0, i - 1);
            }
        }

        public void siftDown(int root, int bottom)
        {
            bool done = false;
            int maxChild;
            int temp1, temp2;

            while ((root * 2 <= bottom) && (!done))
            {
                if (root * 2 == bottom)
                    maxChild = root * 2;
                else if (lista.ElementAt(root * 2) > lista.ElementAt(root * 2 + 1))
                    maxChild = root * 2;
                else
                    maxChild = root * 2 + 1;

                if (lista.ElementAt(root) < lista.ElementAt(maxChild))
                {
                    temp1 = lista.ElementAt(root);
                    temp2 = lista.ElementAt(maxChild);
                    lista.RemoveAt(root);
                    lista.RemoveAt(maxChild-1);
                    lista.Insert(root, temp2);
                    lista.Insert(maxChild, temp1);
                    root = maxChild;
                }
                else
                {
                    done = true;
                }
            }
        }
    }
}
