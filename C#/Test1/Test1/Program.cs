using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test1
{
    class Student
    {
	    private string nume;
	    private string prenume;
	    private int varsta;
	    //lista cursuri

	    // camp static. 
	    // implicit valoarea “Pamant”
	    private static string planeta = "Pamant";
	
	    public Student() {}
	
	    // proprietate pentru nume
	    public string Nume
	    {
		    get { return nume;}
		    set { nume = value; }
	    }

        public int Varsta
        {
            get { return varsta; }
            set { varsta = value; }
        }

	    // proprietate pentru prenume
        public string Prenume{
		    get { return prenume;}
		    set { prenume = value; }
	    }

	    // metoda a instantei
	    public string GetNumeComplet()
	    {
		    return nume + " " + prenume;
	    }

	    // returneaza numele complet plus varsta
	    public string GetNumeCompletVarsta()
	    { 
            return GetNumeComplet() + " " + varsta.ToString();
        }

	    // metoda statica ce va returna valaorea datei membru planeta
	    public string GetPlaneta()
	    {
            return planeta;
        }
    }

    public class Singleton
    {
        private static Singleton instance;

        private Singleton() { }

        public static Singleton Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new Singleton();
                }
                return instance;
            }
        }
    }

    public class Program
    {
        public static void Main()
        {
            Student stud = new Student();
            Console.WriteLine("Cum te numesti?");
            String [] nume_pren = Console.ReadLine().Split(' ');
            stud.Nume = nume_pren[0].ToUpper();
            stud.Prenume = nume_pren[1].ToUpperInvariant();

            Console.WriteLine ("Bine ai venit, {0} {1}!",stud.Nume,stud.Prenume);

            Console.WriteLine("Ce varsta ai?");
            try
            {
                stud.Varsta = Convert.ToInt32(Console.ReadLine());
                Console.Write("Ai {0} de ani!", stud.Varsta);
            }
            catch (FormatException e)
            {
                Console.WriteLine("Input string is not a sequence of digits.");
            }
            catch (OverflowException e)
            {
                Console.WriteLine("The number cannot fit in an Int32.");
            }

            Console.WriteLine(" Locuiesti pe planeta {0}!",stud.GetPlaneta());

            Console.ReadLine();
        }
    }
}
