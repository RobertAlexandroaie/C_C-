using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using PersoanaLib;

namespace ProiectTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Persoana p = new Persoana(3, "Ionescu");
            p.PrintPersoana();
            p.SetAnStudiu(4);
            p.PrintPersoana();
            string nume_anterior = p.Nume;
            Console.WriteLine("Nume anterior: {0}",nume_anterior);

            p.Nume = "Va";
            p.PrintPersoana();

            p.Nume = "Popescu";
            p.PrintPersoana();
        }
    }
}
