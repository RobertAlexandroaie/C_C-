<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<asp:Content ID="indexTitle" ContentPlaceHolderID="TitleContent" runat="server">
    MVC Sample Application for File upoload.
</asp:Content>

<asp:Content ID="indexFeatured" ContentPlaceHolderID="FeaturedContent" runat="server">
  
</asp:Content>

<asp:Content ID="indexContent" ContentPlaceHolderID="MainContent" runat="server">
    

    <ol class="round">
        <li class="one">
            <h5></h5>
            Click Register to see File upload demo
        </li>
        <li class="two">
            in Account Controlller, I have done following changes
              
              <br /><b>[AcceptVerbs(HttpVerbs.Post)]</b>
              <br /><b>public ActionResult Register(RegisterModel model, IEnumerable< HttpPostedFileBase > file)</b>
              <br /> <p>
              <br />   string physicalPath = HttpContext.Server.MapPath("../") + "UploadImages" + "\\";
              <br />
               <br /> for (int i = 0; i < Request.Files.Count; i++)
              <br />  {
<br />
               <br />     Request.Files[0].SaveAs(physicalPath + System.IO.Path.GetFileName(Request.Files[i].FileName));
               <br />         
               <br /> }
               <br /></p>
        </li>
        <li class="three">
            <br />in view -> RegisterPartial.ascx
                <br />
                <br />using (Html.BeginForm((string)ViewBag.FormAction, "Account", <b> FormMethod.Post, new { enctype = "multipart/form-data" })) </b>
                <br />
                <br />
                 < li >   < b > Please select File : < / b >
                    < input type="file" id="FileUpload1"   name="FileUpload1" / >< br / >
            </li>
        </li>
        
    </ol>

</asp:Content>
