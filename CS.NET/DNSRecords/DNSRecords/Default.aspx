<%@ Page Title="DNS Records" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="DNSRecords._Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <asp:GridView ID="DnsGridViewer" runat="server" AutoGenerateColumns="False" DataKeyNames="DomainID"
        EmptyDataText="There are no data records to display." ShowHeader="False" GridLines="None">
        <Columns>
            <asp:TemplateField HeaderText="DomainID" Visible="False">
                <ItemTemplate>
                    <asp:Label runat="server" ID="DomainIdLabel" Text="DomainID"></asp:Label>
                    <asp:TextBox ID="DomainID" runat="server" Text='<%# Eval("DomainID") %>'></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Name">
                <ItemTemplate>
                    <asp:Label runat="server" ID="NameLabel" Text="Name"></asp:Label>
                    <asp:TextBox ID="Name" runat="server" AutoPostBack="true" Text='<%# Eval("Name") %>'
                        ClientIDMode="Static"></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Type">
                <ItemTemplate>
                    <asp:Label runat="server" ID="TypeLabel" Text="Type"></asp:Label>
                    <asp:DropDownList ID="Type" runat="server" AutoPostBack="True" SelectedValue='<%# Bind("Type") %>'>
                        <asp:ListItem Value="A">A</asp:ListItem>
                        <asp:ListItem Value="MX">MX</asp:ListItem>
                    </asp:DropDownList>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Value">
                <ItemTemplate>
                    <asp:Label runat="server" ID="ValueLabel" Text="Value"></asp:Label>
                    <asp:TextBox ID="Value" runat="server" AutoPostBack="True" Text='<%# Eval("Value") %>'></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="DeleteButton">
                <ItemTemplate>
                    <asp:LinkButton runat="server" Text="Delete Entry" CommandArgument='<%# Eval("DomainID") %>'
                        OnCommand="OnDeleteCommand"></asp:LinkButton>
                    <asp:Label runat="server" ID="WrongValue" Text='<%# Eval("IsWrong") %>' ForeColor="red"></asp:Label>
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>
    <hr />
    <asp:Button runat="server" OnClick="AddNewRecord" Text="Add Record" UseSubmitBehavior="False" />
    <asp:Button ID="SaveAll" runat="server" OnClick="SaveAll_OnClick" Text="Save" UseSubmitBehavior="False" />
    <hr />
    <hr />
    <asp:Label runat="server" Text="Write Record Name"></asp:Label>
    <asp:TextBox runat="server" ID="FindRecordTextBox"></asp:TextBox>
    <asp:Button runat="server" Text="Find Records" OnClick="FindRecordsOnClick" />
    <hr />
    <asp:GridView ID="RecordsSearch" runat="server" AutoGenerateColumns="False" DataKeyNames="DomainID"
        EmptyDataText="There are no data records to display." ShowHeader="False" GridLines="None">
        <Columns>
            <asp:TemplateField HeaderText="DomainID" Visible="False">
                <ItemTemplate>
                    <asp:Label runat="server" ID="DomainIdLabel" Text="DomainID"></asp:Label>
                    <asp:TextBox ID="DomainID" runat="server" Text='<%# Eval("DomainID") %>' ReadOnly="True"></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Name">
                <ItemTemplate>
                    <asp:Label runat="server" ID="NameLabel" Text="Name"></asp:Label>
                    <asp:TextBox ID="Name" runat="server" Text='<%# Eval("Name") %>' ClientIDMode="Static"
                        ReadOnly="True"></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Type">
                <ItemTemplate>
                    <asp:Label runat="server" ID="TypeLabel" Text="Type"></asp:Label>
                    <asp:DropDownList ID="Type" runat="server" SelectedValue='<%# Bind("Type") %>' Enabled="False">
                        <asp:ListItem Value="A">A</asp:ListItem>
                        <asp:ListItem Value="MX">MX</asp:ListItem>
                    </asp:DropDownList>
                </ItemTemplate>
            </asp:TemplateField>
            <asp:TemplateField HeaderText="Value">
                <ItemTemplate>
                    <asp:Label runat="server" ID="ValueLabel" Text="Value"></asp:Label>
                    <asp:TextBox ID="Value" runat="server" Text='<%# Eval("Value") %>' ReadOnly="True"></asp:TextBox>
                </ItemTemplate>
            </asp:TemplateField>
        </Columns>
    </asp:GridView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:ASPDnsRecordsConnectionString1 %>"
        DeleteCommand="DELETE FROM [DomainDNS] WHERE [DomainID] = CONVERT(uniqueidentifier, @DomainID)"
        InsertCommand="INSERT INTO [DomainDNS] ([DomainID], [Name], [Type], [Value]) VALUES (CONVERT(uniqueidentifier, @DomainID), @Name, @Type, @Value)"
        ProviderName="<%$ ConnectionStrings:ASPDnsRecordsConnectionString1.ProviderName %>"
        SelectCommand="SELECT [DomainID], [Name], [Type], [Value] FROM [DomainDNS]" UpdateCommand="UPDATE [DomainDNS] SET [Name] = @Name, [Type] = @Type, [Value] = @Value WHERE [DomainID] = CONVERT(uniqueidentifier, @DomainID)">
        <DeleteParameters>
            <asp:Parameter Name="DomainID" Type="Object" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="DomainID" Type="Object" />
            <asp:Parameter Name="Name" Type="String" />
            <asp:Parameter Name="Type" Type="String" />
            <asp:Parameter Name="Value" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="Name" Type="String" />
            <asp:Parameter Name="Type" Type="String" />
            <asp:Parameter Name="Value" Type="String" />
            <asp:Parameter Name="DomainID" Type="Object" />
        </UpdateParameters>
    </asp:SqlDataSource>
</asp:Content>
