using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Schema;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa de parsare a XML-ului cu utilizatori
 * */

namespace ServerChat2
{
    class ParsareXML
    {
        public ParsareXML()
        {
        }

        static public List<MessageLibrary.Utilizator> ReadXMLDocument(string Path)
        {
            var users = new List<MessageLibrary.Utilizator>();

            var settings = new XmlReaderSettings { IgnoreComments = true, IgnoreWhitespace = true, ProhibitDtd = false, ValidationType = ValidationType.Schema };
            settings.ValidationEventHandler += settings_ValidationEventHandler;

            XmlReader reader = XmlReader.Create(Path, settings);
            var user = new MessageLibrary.Utilizator();

            while (reader.Read())
            {
                switch (reader.NodeType)
                {
                    case XmlNodeType.Element:
                        switch (reader.Name)
                        {
                            case "user":

                                if (reader.HasAttributes)
                                {
                                    try
                                    {
                                        string username = reader.GetAttribute("username");
                                        string password = reader.GetAttribute("password");
                                        string email = reader.GetAttribute("email");
                                        string nameStr = "";

                                        try
                                        {
                                            nameStr = reader.ReadString();
                                        }
                                        catch
                                        {
                                            nameStr = "";
                                        }
                                        finally
                                        {
                                            user.Name = nameStr;
                                            user.Username = username;
                                            user.Password = password;
                                            user.Email = email;
                                        }
                                        users.Add(user);
                                        user = new MessageLibrary.Utilizator();
                                    }
                                    catch
                                    {
                                        break;
                                    }
                                }

                                break;
                        }
                        break;
                }
            }
            reader.Close();
            return users;
        }

        private static void settings_ValidationEventHandler(object sender, ValidationEventArgs e)
        {
            Console.WriteLine(e.Severity + " - " + e.Message);
        }

        public static void WriteXMLFile(string Path, List<MessageLibrary.Utilizator> Users)
        {
            var settings = new XmlWriterSettings { Indent = true, Encoding = Encoding.UTF8, OmitXmlDeclaration = false };

            XmlWriter writer = XmlWriter.Create(Path, settings);
            if (writer != null)
            {
                writer.WriteStartElement("Users");

                foreach (MessageLibrary.Utilizator user in Users)
                {
                    writer.WriteStartElement("user");
                    writer.WriteAttributeString("username", user.Username);
                    writer.WriteAttributeString("password", user.Password);
                    writer.WriteAttributeString("email", user.Email);
                    writer.WriteString(user.Name);
                    writer.WriteEndElement();
                }

                writer.WriteEndElement();
                writer.WriteEndDocument();
                writer.Flush();
                writer.Close();
            }
        }
    }
}
