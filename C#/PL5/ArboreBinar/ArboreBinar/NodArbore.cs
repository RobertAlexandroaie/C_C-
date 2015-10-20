using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/* Autor: Ionut Danila, Grupa 1A
 * Data: 14.11.2011
 */
namespace ArboreBinar
{
    class NodArbore<T>
    {
        //subarbore stang, subarbore drept si informatia din nod
        protected NodArbore<T> drept = null;
        protected NodArbore<T> stang = null;
        protected T informatie;

        //constructor nod arbore
        public NodArbore(T info)
        {
            this.informatie = info;
        }

        //setter si getter informatie din nod
        public T Informatie
        {
            get { return this.informatie; }
            set { this.informatie = value; }
        }

        //nodul drept al arborelui
        public NodArbore<T> Drept
        {
            get { return this.drept; }
            set { this.drept = value; }
        }

        //nodul stang al arborelui
        public NodArbore<T> Stang
        {
            get { return this.stang; }
            set { this.stang = value; }
        }
    }
}
