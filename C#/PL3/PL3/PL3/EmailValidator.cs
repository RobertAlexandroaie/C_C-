using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.NetworkInformation;
using System.Text.RegularExpressions;

namespace PL3
{
    [System.AttributeUsage(System.AttributeTargets.Field)]
    public class EmailValidator : System.Attribute
    {
        private string email;
        private Match m;
        private string server = "";

        public EmailValidator(string email)
        {
            this.email = email;
            validareDate();
            validareServer();
        }

        private bool validareDate()
        {
            Regex emailregex = new Regex("(?<user>[^@]+)@(?<host>.+)");
            m = emailregex.Match(email);

            if (m.Success)
            {
                server = this.email.Split('@')[1];
                return true;
            }
            else
            {
                return false;
            }
        }

        private bool validareServer()
        {
            Ping pingSender = new Ping();
            PingOptions options = new PingOptions();

            // Use the default Ttl value which is 128,
            // but change the fragmentation behavior.
            options.DontFragment = true;

            // Create a buffer of 32 bytes of data to be transmitted.
            string data = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
            byte[] buffer = Encoding.ASCII.GetBytes(data);
            int timeout = 120;
            PingReply reply = pingSender.Send(this.server, timeout, buffer, options);
            if (reply.Status == IPStatus.Success)
            {
                Console.WriteLine("Address: {0}", reply.Address.ToString());
                Console.WriteLine("RoundTrip time: {0}", reply.RoundtripTime);
                Console.WriteLine("Time to live: {0}", reply.Options.Ttl);
                Console.WriteLine("Don't fragment: {0}", reply.Options.DontFragment);
                Console.WriteLine("Buffer size: {0}", reply.Buffer.Length);
            }

            return false;
        }
    }

    [System.AttributeUsage(System.AttributeTargets.Field)]
    public class PasswordValidator : System.Attribute
    {
        private string parola;

        public PasswordValidator(string parola)
        {
            this.parola = parola;
            validareParola();
        }

        private bool validareParola()
        {
            if ((this.parola.Length >= 8) && (this.parola.Length <= 16))
                return true;
            return false;
        }
    }
}
