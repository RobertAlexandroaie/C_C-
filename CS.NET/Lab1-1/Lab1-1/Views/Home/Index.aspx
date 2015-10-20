<%@ Page Language="C#" MasterPageFile="~/Views/Shared/Site.Master" Inherits="System.Web.Mvc.ViewPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="TitleContent" runat="server">
    Home Page
</asp:Content>

<asp:Content ID="Content2" ContentPlaceHolderID="MainContent" runat="server">
    <form id="form1" runat="server">
    <h2><%: ViewData["Message"] %>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            DataKeyNames="CustomerID" DataSourceID="SqlDataSource1" 
            EmptyDataText="There are no data records to display.">
            <Columns>
                <asp:BoundField DataField="CustomerID" HeaderText="CustomerID" ReadOnly="True" 
                    SortExpression="CustomerID" />
                <asp:BoundField DataField="Name" HeaderText="Name" SortExpression="Name" />
                <asp:BoundField DataField="Adresa" HeaderText="Adresa" 
                    SortExpression="Adresa" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:TestConnectionString1 %>" 
            DeleteCommand="DELETE FROM [Customer] WHERE [CustomerID] = @CustomerID" 
            InsertCommand="INSERT INTO [Customer] ([CustomerID], [Name], [Adresa]) VALUES (@CustomerID, @Name, @Adresa)" 
            ProviderName="<%$ ConnectionStrings:TestConnectionString1.ProviderName %>" 
            SelectCommand="SELECT [CustomerID], [Name], [Adresa] FROM [Customer]" 
            UpdateCommand="UPDATE [Customer] SET [Name] = @Name, [Adresa] = @Adresa WHERE [CustomerID] = @CustomerID">
            <DeleteParameters>
                <asp:Parameter Name="CustomerID" Type="Int16" />
            </DeleteParameters>
            <InsertParameters>
                <asp:Parameter Name="CustomerID" Type="Int16" />
                <asp:Parameter Name="Name" Type="String" />
                <asp:Parameter Name="Adresa" Type="String" />
            </InsertParameters>
            <UpdateParameters>
                <asp:Parameter Name="Name" Type="String" />
                <asp:Parameter Name="Adresa" Type="String" />
                <asp:Parameter Name="CustomerID" Type="Int16" />
            </UpdateParameters>
        </asp:SqlDataSource>
    </h2>
    <p>
        To learn more about ASP.NET MVC visit <a href="http://asp.net/mvc" title="ASP.NET MVC Website">http://asp.net/mvc</a>.
    </p>
    <p>
        &nbsp;</p>
    </form>
</asp:Content>
