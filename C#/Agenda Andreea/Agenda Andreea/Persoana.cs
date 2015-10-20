using System;
using System.Collections.Generic;

namespace Agenda_Andreea
{
    [Serializable()]
    public class Persoana //creem clasa persoana serializabila
    {
        public string Nume { get; set; }

        public string Email { get; set; }

        public string Telefon { get; set; }

        public string AlteInformatii { get; set; }

        public DateTime DataNasterii { get; set; }

        public Persoana(string nume, string email, string telefon, string others, DateTime data)
        {
            Nume = nume;
            Email = email;
            Telefon = telefon;
            AlteInformatii = others;
            DataNasterii = data;
        }
        
    }
}