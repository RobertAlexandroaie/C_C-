using System.Runtime.Serialization;

/**
 * BLAGA Alexandru, Grupa 1A, Anul 3
 * DANILA Ionut, Grupa 1A, Anul 3
 */

namespace DatabaseTablesClasses
{
    [DataContract]
    public class Customer
    {
        [DataMember]
        public string Address { get; set; }
        [DataMember]
        public string Name { get; set; }
        [DataMember]
        public int Id { get; set; }
    }
}
