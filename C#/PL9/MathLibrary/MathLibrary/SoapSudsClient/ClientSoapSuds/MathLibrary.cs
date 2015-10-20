using System;
using System.Runtime.Remoting.Messaging;
using System.Runtime.Remoting.Metadata;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Runtime.InteropServices;

namespace ClientSoapSuds
{

    [SoapType(XmlNamespace=@"http://schemas.microsoft.com/clr/nsassem/MathLibrary/MathLibrary%2C%20Version%3D1.0.0.0%2C%20Culture%3Dneutral%2C%20PublicKeyToken%3Dnull", XmlTypeNamespace=@"http://schemas.microsoft.com/clr/nsassem/MathLibrary/MathLibrary%2C%20Version%3D1.0.0.0%2C%20Culture%3Dneutral%2C%20PublicKeyToken%3Dnull")][ComVisible(true)]
    public class Calculator : System.Runtime.Remoting.Services.RemotingClientProxy
    {
        // Constructor
        public Calculator()
        {
            base.ConfigureProxy(this.GetType(), @"http://localhost:8080/CalculatorURI.soap");
        }

        public Object RemotingReference
        {
            get{return(_tp);}
        }

        [SoapMethod(SoapAction=@"http://schemas.microsoft.com/clr/nsassem/MathLibrary.Calculator/MathLibrary#Add")]
        public Single Add(Single x, Single y)
        {
            return ((Calculator) _tp).Add(x, y);
        }
        [SoapMethod(SoapAction=@"http://schemas.microsoft.com/clr/nsassem/MathLibrary.Calculator/MathLibrary#Divide")]
        public Single Divide(Single x, Single y)
        {
            return ((Calculator) _tp).Divide(x, y);
        }

    }
}
