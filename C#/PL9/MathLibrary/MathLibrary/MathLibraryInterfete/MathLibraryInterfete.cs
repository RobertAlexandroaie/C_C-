using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Remoting;

// add reference to ...
//using MathLibraryInterfete;
using MetadataInterfete;

// Proiect de tip ClassLibrary
// Acest dll va fi distribuit pe server. 
//
// Acest tip va fi gazduit pe server ca un obiect remote
// Este construit folosind interfete si acest lucru face posibila
// distributia metadatei pe client cu ajutorul interfetelor

// Atentie: Are ctor implicit.
// Pentru tipurile ce au ctor cu parametri aceasta tehnica nu poate fi aplicata
//
namespace MathLibraryInterfete
{
    
    /*
    public interface ICalculator
    {
        float Add(float x, float y);
        float Divide(float x, float y);
    }
    */

    public class Calculator: MarshalByRefObject, ICalculator
    {

        #region ICalculator Members

        float ICalculator.Add(float x, float y)
        {
            return x + y;
        }

        float ICalculator.Divide(float x, float y)
        {
            if (y != 0)
                return x / y;
            else
                throw new RemotingException("Impartire prin zero: Imposibil");
        }

        #endregion
    }
}
