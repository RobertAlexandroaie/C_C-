using System;
using System.Runtime.Serialization;

namespace DatabaseTablesClasses
{
    [DataContract]
    public class Order
    {
        [DataMember]
        public int OrderId;
        [DataMember]
        public DateTime Data;
        [DataMember]
        public int CustomerId;
        [DataMember]
        public decimal Valoare;
    }
}
