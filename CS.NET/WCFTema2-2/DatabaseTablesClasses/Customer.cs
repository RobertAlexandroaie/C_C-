using System.Runtime.Serialization;

namespace DatabaseTablesClasses
{
    [DataContract]
    public class Customer
    {
        [DataMember]
        public int Id;
        [DataMember]
        public string Address;
        [DataMember]
        public string Name;
    }
}
