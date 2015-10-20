using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace Subscribe
{
    // NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "Service1" in both code and config file together.
    public class SubscribeMessage : ISubscribe
    {
        private static readonly List<IReportSuccessOrError> subscribers = new List<IReportSuccessOrError>();

        public void AddMessage(string message)
        {
            // aici se face apelul la metoda callback
            subscribers.ForEach(delegate(IReportSuccessOrError callback)
            {
                if (((ICommunicationObject)callback).State == CommunicationState.Opened)
                {
                    callback.OnInsertUpdateDelete(message);
                }
                else
                {
                    subscribers.Remove(callback);
                }
            });
        }

        public void Subscribe()
        {
            try
            {
                var callback = OperationContext.Current.GetCallbackChannel<IReportSuccessOrError>();
                // Inregistrez “tipul” ce implementeaza IMessageCallback
                // Acest tip este pe partea de client
                if (!subscribers.Contains(callback))
                    subscribers.Add(callback);
            }
            catch
            {
                Console.WriteLine("FALSE SUBSCRIBE");
            }
        }

        public void Unsubscribe()
        {
            try
            {
                var callback = OperationContext.Current.GetCallbackChannel<IReportSuccessOrError>();
                if (!subscribers.Contains(callback))
                    subscribers.Remove(callback);
            }
            catch
            {
                Console.WriteLine("FALSE UNSUBSCRIBE");
            }
        }
    }
}
