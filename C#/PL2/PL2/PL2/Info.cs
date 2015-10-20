using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL2
{
    class Info
    {
        public Info(int n)
        { 
            this.n = n; 
        }

        public int n = 0;

        public void AdaugaValoare(int val)
        {
            this.n = this.n + val;
        }
    }
}
