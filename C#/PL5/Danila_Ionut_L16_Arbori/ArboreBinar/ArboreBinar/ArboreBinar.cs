using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

/* Autor: Ionut Danila, Grupa 1A
 * Data: 14.11.2011
 */
namespace ArboreBinar
{
    class ArboreBinar<T> 
    {
        public NodArbore<T> radacina;
        private int elementGasit = -1;
        public List<T> arbore = new List<T>();
        public T[] arboreArray;
        private string file = "Arbore.bin";

        //crearea arborelui pornind de la vector
        public ArboreBinar(T[] vector)
        {
            creazaArbore(vector);
        }

        //crearea arborelui prin deserializare
        public ArboreBinar(string File)
        {
            this.file = File;
            Deserializeaza();
        }

        //serializarea arborelui
        public void Serializeaza()
        {
            Stream WriteStream = File.Create(this.file);
            BinaryFormatter BinaryWrite = new BinaryFormatter();
            BinaryWrite.Serialize(WriteStream, radacina);
            WriteStream.Close();
        }

        //deserializarea arborelui
        public void Deserializeaza()
        {
            Stream ReadStream = File.OpenRead(file);
            BinaryFormatter BinaryRead = new BinaryFormatter();

            NodArbore<T> arbore = (NodArbore<T>)BinaryRead.Deserialize(ReadStream);
            radacina = arbore;

            ReadStream.Close();
        }

        private NodArbore<T> divide(int li, int ls, T[] a, NodArbore<T> t) //imparte vectorul de fiecare data in 2 parti pentru a face arbore AVL
        { 
		    int m = (li+ls)/2;
		    if(ls>=li)
            {   
			    t=insereaza (t, a[m]); //insereaza de fiecare data elementul din mijlocul vectorului
		        divide(li, m-1, a, t);
		        t=divide(m+1, ls,a,t);
		    }
          return t;       
        }

        private NodArbore<T> creazaArbore(T[] vector)
        { //crearea unui arbore binar de cautare pentru elementele tabloului primit ca parametru
            radacina = divide(0, vector.Length - 1, vector, radacina); //foloseste functia pentru a imparti vectorul 

            return radacina;
        }

        public NodArbore<T> insereaza(NodArbore<T> t, T e)
        {
            if (t == null)//daca nodul accesat este NULL
            {
                t = new NodArbore<T>(e); //alocarea valorii elementului din vector in Informatie
                t.Stang = t.Drept = null; //adaugarea valorii NULL celor doua noduri
            }
            else //daca nodul accesat nu este NULL
                if (e.ToString().CompareTo(t.Informatie.ToString()) < 0) t.Stang = insereaza(t.Stang, e); //verifica daca elementul care trebuie inserat este mai mic decat informatia din radacina.
                else
                t.Drept = insereaza(t.Drept, e); //daca elementul este mai mic, elementul se insereaza in stanga, altfel in dreapta 
            
            return t; //return noul arbore creat
        }

        public void AfiseazaArbore(NodArbore<T> t)
        {
            afiseazaInordine(t);
        }

        private void afiseazaInordine(NodArbore<T> t) //afisarea arborelui inordine
        {
            if (t == null) ;//daca nodul accesat este NULL
            else //daca nodul nu este NULL, 
            {
                afiseazaInordine(t.Stang); //se parcurge nodul stang
                Console.Write("{0} ", t.Informatie); //se afiseaza informatia din radacina
                afiseazaInordine(t.Drept); //se parcurge nodul drept
            }
        }

        public void toArray(NodArbore<T> t)
        {
            ListArray(t);
            arboreArray = arbore.ToArray();
        }

        public void ListArray(NodArbore<T> t)
        {
            if (t == null) ;//daca nodul accesat este NULL
            else //daca nodul nu este NULL, 
            {
                ListArray(t.Stang); //se parcurge nodul stang
                arbore.Add(t.Informatie); //se introduce in array informatia din radacina
                ListArray(t.Drept); //se parcurge nodul drept
            }
        }

        public void cautaArbore(NodArbore<T> t, T k)
        {
            elementGasit = -1;
            cautare(t, k);
            
            if (elementGasit == 1)
                Console.WriteLine("Elementul " + k + " a fost gasit!");
            else
                Console.WriteLine("Elementul " + k + " NU a fost gasit!");
        }

        public void cautare(NodArbore<T> t, T k) //cautarea unui element in arbore
        {
            if (t == null) ; //daca nodul nu este gasit se returneaza valoarea -1
            else
                if (k.Equals(t.Informatie))
                {
                    elementGasit = 1; //daca nodul este gasit se returneaza valoarea 1
                }
                else
                    if (k.ToString().CompareTo(t.Informatie.ToString()) < 0)
                    {
                        cautare(t.Stang, k); //daca valoarea cautata este mai mare decat valoarea nodului curent se cauta in nodul stang
                    }
                    else
                    {
                        cautare(t.Drept, k); //altfel se cauta in nodul drept
                    }
        }

        public NodArbore<T> sterge(NodArbore<T> t, T a) //stergerea unui element din arbore
        { 
            NodArbore<T> p = null; //folosirea a altor 2 arbori temporali
            NodArbore<T> q = null;

            if (t == null) ;
            else 
	            if(t.Informatie.ToString().CompareTo(a.ToString()) > 0) t.Stang = sterge(t.Stang,a); //daca valoarea este mai mica decat valoarea nodului se sterge elementul din nodul stang
                else 
		            if(t.Informatie.ToString().CompareTo(a.ToString()) < 0) t.Drept = sterge(t.Drept,a); //altfel se sterge informatia din nodul drept
		            else 
			            if(t.Stang == null) //daca nodul din stanga este NULL
			            { 
				            p = t; //arborele t este copiat in arborele p
				            t = t.Drept; //arborele t ia valoarea arborelui din dreapta ramas
			            }
			            else //daca nodul din stanga NU este NULL
				            if (t.Stang.Drept == null) //se verifica daca nodul fiu al nodului din stanga este NULL
				            { 
					            t.Informatie = t.Stang.Informatie; //daca este adevarat nodul actual ia valoarea nodului fiu din stanga
					            p = t.Stang; //arborele p ia valoarea arborelui fiu din stanga ramas
					            t.Stang = t.Stang.Stang; //nodul din stanga ia valoarea nodului fiu din stanga
				            }
				            else //daca fiul nodului din stanga NU este NULL
				            { 
					            p = t.Stang; //arborele p ia valoarea arborelui t din stanga ramas
					            while(p.Drept != null) //intr-o structura repetitiva se verifica daca se ajunge la sfarsitul ramurei din dreapta
					            { 
						            q = p; //arborele q ia valoarea arborelui p
						            p = p.Drept; //arborele p ia valoarea ramurei din dreapta
					            }
					            t.Informatie = p.Informatie; //valoarea din t devine valoarea din p
					            q.Drept = p.Stang; //arborele din dreapta lui q ia valoarea arborelui din stanga a lui p
				            }
          
            return t; //return noul arbore
        }

        private int inaltime(NodArbore<T> t) //se calculeaza inaltimea arborelui pentru a printa pe nivele
        {
            int i, j, k;
            if (t == null) i = 0; //daca arborele este vid atunci i ia valoarea 0
            else //altfel se calculeaza inaltimea din ramura stanga a arborelui ramas si inaltimea din ramura dreapta a arborelui ramas
            {
                j = inaltime(t.Stang);
                k = inaltime(t.Drept);
                if (j > k) i = 1 + j; else i = 1 + k; //se calculeaza inaltimea
            }
            return i; //return valoarea calculata
        }

    }
}
