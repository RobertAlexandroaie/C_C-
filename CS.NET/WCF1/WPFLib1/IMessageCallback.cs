using System;
using System.ServiceModel;

namespace WPFLib1
{
    interface IMessageCallback
    {
        [OperationContract(IsOneWay = true)]
        void OnMessageAdded(string message, DateTime timestamp);
    }
}