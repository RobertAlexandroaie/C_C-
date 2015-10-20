using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

/** Client si Server Chat
 *  @Author: Ionut Danila
 *  Clasa de Variabile publice folosite de client si server
 * */

namespace MessageLibrary
{
    public class Variabile
    {
        //un enum de variabile publice folosite atat de server, cat si de client
        public enum TipMesaj
        {
            Login, Register, ResponseLogin, RequestUsersList, UsersList, UserValidate, ResponseUserValidate,
            ResponseRegister, TitluFereastra, SendPrivateMessage, SendPublicMessage, ReceivePublicMessage,
            ReceivePrivateMessage, RequestTitleWindow, SendFile, ReceiveFile, GetUserInfo, ReceiveUserInfo
        }
    }
}
