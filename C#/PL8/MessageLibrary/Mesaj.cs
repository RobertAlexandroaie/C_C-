using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa Serializabila Mesaj, care este transmisa intre client si server
 * */

namespace MessageLibrary
{
    [Serializable()]
    public class Mesaj
    {
        //getteri si setteri pentru proprietatile clasei: Textul, Identitatea si tipul mesajului
        private string mesajText;

        public string MesajText
        {
            get { return this.mesajText; }
            set { this.mesajText = value; }
        }

        private string identitate;

        public string Identitate
        {
            get { return this.identitate; }
            set { this.identitate = value; }
        }

        private Variabile.TipMesaj tipM;

        public Variabile.TipMesaj TipM
        {
            get { return this.tipM; }
            set { this.tipM = value; }
        }

        //constructorul clasei
        public Mesaj(string identitate, Variabile.TipMesaj tipMesaj, string mesajText)
        {
            this.Identitate = identitate;
            this.MesajText = mesajText;
            this.tipM = tipMesaj;
        }
    }
}
