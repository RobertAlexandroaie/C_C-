// Tip distribuit pe client

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//
// Proiect tip: ClassLibrary
// Am modificat numele fisierului rezultat in MathLibrary.dll
// Project -> Properties -> Application ... Assembly si Namespace
//
// Trebuie sa aiba acelasi nume cu cel distribuit in ServerCUI
// Trebuie sa fie acelasi namespace

namespace MathLibrary
{
    // Acest tip va fi distribuit pe client
    // Project -> Add Reference ... urmat de using MathLibrary

    public class Calculator: MarshalByRefObject
    {
        public float Add(float x, float y)
        {
            throw new InvalidOperationException("Metoda nu poate fi executata local!");
        }

        public float Divide(float x, float y)
        {
            throw new InvalidOperationException("Metoda nu poate fi executata local!");
        }

    }
}
