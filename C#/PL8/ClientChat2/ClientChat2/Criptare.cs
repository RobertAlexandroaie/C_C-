using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Security.Cryptography;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa de criptare a parolei
 * */

namespace ClientChat2
{
    class Criptare
    {
        public static string Hashing(string input)
        {
            //se realizeaza un hash al parolei introduse pentru a nu transmite parola reala la server
            UTF8Encoding encoding = new UTF8Encoding();
            SHA1 sha = new SHA1CryptoServiceProvider();
            string result = Convert.ToBase64String(sha.ComputeHash(encoding.GetBytes(input)));
            return result;
        }
        
    }
}
