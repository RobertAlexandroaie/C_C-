using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL1
{
    class SubGroup : IEnumerable<Item>
    {
        public SubGroup(Item item/*, int location*/)
        {
            //subGroupItem = item;
            locations[0] = item;
        }

        //private Item subGroupItem = new Item("", 0);
        private List<Item> locations = new List<Item>();

        //public Item SubGroupItem
        //{
        //    get
        //    {
        //        return subGroupItem;
        //    }

        //    set
        //    {
        //        subGroupItem = value;
        //    }
        //}

        public Item this[int i]
        {
            get
            {
                return locations[i];
            }

            set
            {
                locations[i] = value;
            }
        }

        public IEnumerator<Item> GetEnumerator()
        {
            return locations.GetEnumerator();
        }

        IEnumerator<Item> IEnumerable<Item>.GetEnumerator()
        {
            return location.GetEnumerator();
        }
    }
}
