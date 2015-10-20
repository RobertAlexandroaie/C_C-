using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL3
{
    [AttributeUsage(System.AttributeTargets.Class | System.AttributeTargets.Struct)]
    public class Author : Attribute
    {
        private string name;
        public DateTime data;
        public string numeMasina;

        public Author(string name, string bal)
        {
            this.name = name;
            this.data = DateTime.Now;
            this.numeMasina = Environment.MachineName;
        }
    }

}
