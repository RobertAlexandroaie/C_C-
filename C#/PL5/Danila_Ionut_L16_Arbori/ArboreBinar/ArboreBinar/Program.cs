using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

/* Autor: Ionut Danila, Grupa 1A
 * Data: 14.11.2011
 */
namespace ArboreBinar
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

            //am creat un arbore nou
            ArboreBinar<int> arbore;
            
            //verific fisierul pentru deserializare
            string file = "Arbore.bin";
            
            if (File.Exists(file))
                arbore = new ArboreBinar<int>(file);//daca exista fisierul deserializeaza arborele
            else
                arbore = new ArboreBinar<int>(vector);//daca exista fisierul deserializeaza arborele; //daca nu exista fisierul creaza arborele
            

            Console.WriteLine("Arborele Inline: ");
            arbore.AfiseazaArbore(arbore.radacina);

            Console.WriteLine("\n\nSe cauta elementele:");
            arbore.cautaArbore(arbore.radacina,9);
            arbore.cautaArbore(arbore.radacina,123);

            Console.WriteLine("\nArborele dupa stergerea elementului 7:");
            arbore.sterge(arbore.radacina, 7);
            arbore.AfiseazaArbore(arbore.radacina);

            arbore.toArray(arbore.radacina);
            Console.WriteLine("\n\nArborele transformat in Array: ");
            foreach (int element in arbore.arboreArray)
            {
                Console.Write("{0} ", element);
            }
        }
    }
}
