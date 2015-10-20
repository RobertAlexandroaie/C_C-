using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa principala a aplicatiei
 * */

namespace ClientChat2
{
    static class Program
    {
        //se creaza obiecte de tipul ferestrelor folosite in aplicatie
        public static ChatWindow chatw;
        public static Register regw;
        public static Login logw;

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Connect());
            //se instantiaza obiectele create
            chatw = new ChatWindow();
            regw = new Register();
            logw = new Login();
        }

        
    }
}
