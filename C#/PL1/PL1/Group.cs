using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL1
{
    class Group : IEnumerable<SubGroup>
    {
        public Group(SubGroup subGroup/*, int location*/)
        {
            //groupSubGroup = subGroup;
            groupLocation[0] = subGroup;
        }

        //private SubGroup groupSubGroup = new SubGroup(new Item("Dan", 0), 0);
        private List<SubGroup> groupLocation = new List<SubGroup>();

        //public SubGroup GroupName
        //{
        //    get
        //    {
        //        return groupSubGroup;
        //    }

        //    set
        //    {
        //        groupSubGroup = value;
        //    }
        //}

        public SubGroup this[int i]
        {
            get
            {
                return groupLocation[i]; 
            }

            set
            {
                groupLocation[i] = value;
            }
        }

        public IEnumerator<SubGroup> GetEnumerator()
        {
            return groupLocation.GetEnumerator();
        }

        IEnumerator<SubGroup> IEnumerable<SubGroup>.GetEnumerator()
        {
            return GetEnumerator();
        }        
    }
}
