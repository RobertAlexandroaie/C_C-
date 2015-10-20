using System.ServiceModel;

namespace WPFLib1
{
    [ServiceContract(CallbackContract = typeof(IMessageCallback))]
    public interface IMessage
    {
        [OperationContract]
        void AddMessage(string message);
        [OperationContract]
        bool Subscribe();
        [OperationContract]
        bool Unsubscribe();
    }
}