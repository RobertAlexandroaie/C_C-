using System;
using System.Windows.Forms;
using Infrastructure;

namespace T1
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new DevForm());

            // let's say that we do want to programmatically create a Entity Framework Context,
            // so in order to do that, we've made a new class called DbContext that takes a
            // connection string from config, and creates our connection with the db. We can
            // now use a propper context to manipulate our tranzactions the way we want.
            var myConnection = new DbConnection();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new AppForm(myConnection));
        }
    }
}
