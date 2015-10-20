using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace Subscribe
{
    [ServiceContract(CallbackContract = typeof(IReportSuccessOrError))]
    interface ISubscribe
    {
        [OperationContract]
        void AddMessage(string message);
        [OperationContract]
        void Subscribe();
        [OperationContract]
        void Unsubscribe();
    }
}
