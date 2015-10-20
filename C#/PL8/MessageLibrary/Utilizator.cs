using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa serializabila Utilizator
 * */

namespace MessageLibrary
{
    [Serializable()]
    public class Utilizator
    {
        //getteri si setteri pentru proprietatile clasei: Nume, Email, Parola si Username
        private string name;
        private string username;
        private string password;
        private string email;

        public string Name
        {
            get { return this.name; }
            set { this.name = value; }
        }

        public string Username
        {
            get { return this.username; }
            set { this.username = value; }
        }

        public string Password
        {
            get { return this.password; }
            set { this.password = value; }
        }

        public string Email
        {
            get { return this.email; }
            set { this.email = value; }
        }

        //constructorul clasei
        public Utilizator(string name, string username, string password, string email)
        {
            this.name = name;
            this.username = username;
            this.password = password;
            this.email = email;
        }

        public Utilizator()
        {
        }
    }
}
