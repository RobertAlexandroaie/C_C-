using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;

namespace MetadataInterfete
{
    public interface ICalculator
    {
        float Add(float x, float y);
        float Divide(float x, float y);
    }
}
