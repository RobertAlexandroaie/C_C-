using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab4
{
    class Program
    {
        static void Main(string[] args)
        {
            DblQueue<int> lista = new DblQueue<int>();
            lista.EnqueueHead(4);
            lista.EnqueueTail(7);
            lista.EnqueueHead(5);
            lista.EnqueueHead(14);
            lista.EnqueueTail(13);

            Console.WriteLine("Lista este: ");
            for (int i = 0; i < lista.Count; i++)
                Console.WriteLine(lista.ElementAt(i));

            Console.WriteLine("Peak Head: "+lista.PeekHead());
            Console.WriteLine("Peak Tail: " + lista.PeekTail());

            Console.WriteLine("DequeueHead: " + lista.DequeueHead());
            Console.WriteLine("DequeueTail: " + lista.DequeueTail());

            Console.WriteLine("Lista este: ");
            foreach (int element in lista)
                Console.WriteLine(element);

            DblQueue<int> listaNoua = new DblQueue<int>();
            //listaNoua = lista.Clone();

            lista.Clear();
            Console.WriteLine("Golirea cozii... numarul de elemente: " +lista.Count);
        }
    }
}
