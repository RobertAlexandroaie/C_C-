using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace DNSRecords
{
    [Serializable]
    public class DnsEntity
    {
        public Guid DomainID { get; set; }
        public string Name { get; set; }
        public string Type { get; set; }
        public string Value { get; set; }
        public bool IsDeleted { get; set; }
        public bool IsNew { get; set; }
        public string IsWrong { get; set; }

        public DnsEntity(Guid DomainID, string Name, string Type, string Value)
        {
            this.DomainID = DomainID;
            this.Name = Name;
            this.Type = Type;
            this.Value = Value;
        }

        public DnsEntity()
        {
            IsDeleted = false;
            IsNew = false;
            IsWrong = "";
        }
    }
}