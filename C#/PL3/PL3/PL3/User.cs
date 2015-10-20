using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PL3
{
    [Author("Ionut Danila", "asdasd", numeMasina= "asdasd")]
    class User
    {
        //P1
        [EmailValidator("ionut.danila.mail@gmail.com")]
        public string email;

        [PasswordValidator("12345678")]
        public string parola;
    }
}
