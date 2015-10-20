using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL1
{
    class Item
    {
        public Item(string name, int location)
        {
            itemName = name;
            itemLocation = location;
        }

        private string itemName = "";
        private int itemLocation = 0;

        public string ItemName
        {
            get
            {
                return itemName;
            }

            set
            {
                itemName = value;
            }
        }

        public int ItemLocation
        {
            get
            {
                return itemLocation;
            }

            set
            {
                itemLocation = value;
            }
        }
    }
}
