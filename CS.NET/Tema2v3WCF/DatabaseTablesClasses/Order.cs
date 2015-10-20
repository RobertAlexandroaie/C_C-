using System;
using System.Runtime.Serialization;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace DatabaseTablesClasses
{
    [DataContract]
    public class Order
    {
        [DataMember]
        public int OrderId { get; set; }
        [DataMember]
        public DateTime Data { get; set; }
        [DataMember]
        public int CustomerId { get; set; }
        [DataMember]
        public decimal Valoare { get; set; }
        [DataMember]
        public string Produs { get; set; }
        [DataMember]
        public int Serial { get; set; }
    }
}
