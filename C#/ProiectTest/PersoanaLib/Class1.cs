using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PersoanaLib
{
    public class Persoana
    {
        int anStudiu; //implicit private
        string nume;
        
        public Persoana(int an, string nume) //implicit private
        {
            this.anStudiu = an;
            this.nume = nume;
        }

        public void PrintPersoana()
        {
            Console.WriteLine("Nume: {0}, An studiu: {1}",nume,anStudiu);
        }

        public void SetAnStudiu(int an)
        {
            this.anStudiu = an;
        }

        public string Nume
        {
            get {return this.nume;}

            set 
            {
                if (value.Length <= 2)
                {
                    Console.WriteLine("Nume prea scurt ({0})!",value);
                }
                else
                {
                    this.nume = value;
                }
            }
        }
    }
}
