using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EFT1
{
    class Program
    {
        static void Main(string[] args)
        {
            EntitiesCustomer te = new EntitiesCustomer();

            te.Display();

            te.InsertCustomer(8, "Alexandra", "Iasi");
            
            //te.InsertOrder(1, 1, DateTime.Now, Decimal.Parse("2319,99"));
            Console.WriteLine();
            te.Display();
            //te.InsertOrderDetails(1, "laptop", Decimal.Parse("2299,99"), 5);
            //te.InsertOrderDetails(1, "mouse", Decimal.Parse("20,00"), 6);
            //te.InsertOrder(2, 2, DateTime.Now, Decimal.Parse("50,00"));
            //te.InsertOrderDetails(2, "keyboard", Decimal.Parse("25,00"), 7);
            //te.InsertOrderDetails(2, "Mouse", Decimal.Parse("25,00"), 8);
            
            //Console.WriteLine();
            //te.Display();
            
           // te.DeleteOrder(3);

            //Console.WriteLine();
            //te.Display();
            //te.DeleteOrderDetails(1, 5);
            //Console.WriteLine("\nDupa stergere detalii oferta");
            //te.Display();
            //te.DeleteCustomer(2);
            //Console.WriteLine("\nDupa stergere customer:");
            //te.Display();
        }
    }
}
