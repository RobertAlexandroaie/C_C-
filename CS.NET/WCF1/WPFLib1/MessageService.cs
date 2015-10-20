using System;
using System.Collections.Generic;
using System.ServiceModel;

namespace WPFLib1
{
    public class MessageService : IMessage
    {
        private static readonly List<IMessageCallback>
        subscribers = new List<IMessageCallback>();
        public void AddMessage(string message)
        {
            // aici se face apelul la metoda callback
            subscribers.ForEach(delegate(IMessageCallback callback)
            {
                if (((ICommunicationObject)callback).State ==
                CommunicationState.Opened)
                {
                    callback.OnMessageAdded(message, DateTime.Now);
                }
                else
                {
                    subscribers.Remove(callback);
                }
            });
        }
        public bool Subscribe()
        {
            try
            {
                IMessageCallback callback =
                OperationContext.Current.
                GetCallbackChannel<IMessageCallback>();
                // Inregistrez “tipul” ce implementeaza IMessageCallback
                // Acest tip este pe partea de client
                if (!subscribers.Contains(callback))
                    subscribers.Add(callback);
                return true;
            }
            catch
            {
                return false;
            }
        }
        public bool Unsubscribe()
        {
            try
            {
                IMessageCallback callback =
                OperationContext.Current.
                GetCallbackChannel<IMessageCallback>();
                if (!subscribers.Contains(callback))
                    subscribers.Remove(callback);
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}