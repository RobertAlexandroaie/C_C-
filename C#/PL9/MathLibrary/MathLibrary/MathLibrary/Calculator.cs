using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.Remoting;

namespace MathLibrary
{
    /// <summary>
    /// Tipurile ce vor fi expuse prin remoting
    /// Clasa contine doua metode: Add si Divide ce vor fi executate in procesul serverului
    /// </summary>
    public class Calculator: MarshalByRefObject
    {
        public float Add(float x, float y)
        {
            return x + y;
        }

        public float Divide(float x, float y)
        {
            if (y != 0)
                return x / y;
            else
                throw new RemotingException("Impartirea prin zero este imposibila");
        }
    }
}
