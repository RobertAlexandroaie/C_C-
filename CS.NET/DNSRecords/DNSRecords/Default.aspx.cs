using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace DNSRecords
{
    public partial class _Default : System.Web.UI.Page
    {
        #region Variables
        private List<DnsEntity> listData;
        private List<DnsEntity> tempList;
        private List<DnsEntity> searchList;
        private const string ScriptDofocus = @"window.setTimeout('DoFocus()', 1); function DoFocus(){try {document.getElementById('REQUEST_LASTFOCUS').focus();} catch (ex) {}}";
        #endregion

        #region Initialization
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                GetDataSqlSource();
                AdaugaFocus(Page);
            }
            else
            {
                UpdatePostbackData();
                Page.ClientScript.RegisterStartupScript(GetType(), "ScriptDoFocus", ScriptDofocus.Replace("REQUEST_LASTFOCUS", Request["__LASTFOCUS"]), true);
            }

            DnsGridViewer.DataSource = listData;
            DnsGridViewer.DataBind();
        }

        private void AdaugaFocus(Control currentControl)
        {
            if ((currentControl is TextBox) || (currentControl is DropDownList) || (currentControl is Button))
                (currentControl as WebControl).Attributes.Add("onfocus", "try{document.getElementById('__LASTFOCUS').value=this.id} catch(e) {}");

            if (currentControl.HasControls())
                foreach (Control currentChildControl in currentControl.Controls)
                    AdaugaFocus(currentChildControl);
        }
        #endregion

        #region DataMethods
        private void UpdatePostbackData()
        {
            tempList = (List<DnsEntity>)Session["tempList"];
            listData = (List<DnsEntity>)Session["ListData"];
            searchList = (List<DnsEntity>)Session["SearchList"];

            for (var i = 0; i < DnsGridViewer.Rows.Count; i++)
            {
                var nameBox = (TextBox)DnsGridViewer.Rows[i].Cells[1].FindControl("Name");
                if (listData[i].Name != nameBox.Text)
                {
                    listData[i].Name = nameBox.Text;
                    Session["ListData"] = listData;

                    UpdateTempList(listData[i]);
                }

                var typeDrop = (DropDownList)DnsGridViewer.Rows[i].Cells[2].FindControl("Type");
                if (listData[i].Type != typeDrop.SelectedItem.Text)
                {
                    listData[i].Type = typeDrop.SelectedItem.Text;
                    Session["ListData"] = listData;

                    UpdateTempList(listData[i]);
                }

                var valueBox = (TextBox)DnsGridViewer.Rows[i].Cells[3].FindControl("Value");
                if (listData[i].Value != valueBox.Text)
                {
                    listData[i].Value = valueBox.Text;
                    if (VerifyIpHostname(valueBox.Text))
                    {
                        UpdateTempList(listData[i]);
                        listData[i].IsWrong = "";
                    }
                    else
                    {
                        listData[i].IsWrong = "Value \"" + listData[i].Value + "\" is wrong! Try again!";
                    }
                    Session["ListData"] = listData;
                }
            }
        }

        private void UpdateTempList(DnsEntity inputEntity)
        {
            var entity = tempList.Find(p => p.DomainID == inputEntity.DomainID);
            if (entity != null)
            {
                tempList[tempList.IndexOf(entity)] = inputEntity;
                if (inputEntity.IsDeleted && inputEntity.IsNew) tempList.Remove(entity);
            }
            else
                tempList.Add(inputEntity);

            Session["tempList"] = tempList;
        }

        private void GetDataSqlSource()
        {
            listData = new List<DnsEntity>();
            tempList = new List<DnsEntity>();
            searchList = new List<DnsEntity>();

            var results = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
            DataTable tabel = results.ToTable();

            for (var i = 0; i < results.Count; i++)
            {
                var entity = new DnsEntity
                {
                    DomainID = (Guid)tabel.Rows[i].ItemArray[0],
                    Name = tabel.Rows[i].ItemArray[1].ToString(),
                    Type = tabel.Rows[i].ItemArray[2].ToString(),
                    Value = tabel.Rows[i].ItemArray[3].ToString()
                };
                listData.Add(entity);
            }

            Session["ListData"] = listData;
            Session["tempList"] = new List<DnsEntity>();

            searchList = listData;
            Session["SearchList"] = searchList;
        }

        private bool VerifyIpHostname(string value)
        {
            var ipRegex = new Regex(@"^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
            var hostnameRegex = new Regex(@"^(([a-zA-Z]|[a-zA-Z][a-zA-Z0-9\-]*[a-zA-Z0-9])\.)*([A-Za-z]|[A-Za-z][A-Za-z0-9\-]*[A-Za-z0-9])$");

            bool valid = false;

            if (value == "") return false;

            if (ipRegex.IsMatch(value))
                valid = true;
            else
            {
                if (hostnameRegex.IsMatch(value))
                    valid = true;
            }

            return valid;
        }
        #endregion

        #region Events
        protected void OnDeleteCommand(object sender, CommandEventArgs e)
        {
            var entity = listData.Find(p => p.DomainID == new Guid(e.CommandArgument.ToString()));
            entity.IsDeleted = true;
            UpdateTempList(entity);

            listData.Remove(entity);

            Session["ListData"] = listData;
            DnsGridViewer.DataBind();
        }

        protected void AddNewRecord(object sender, EventArgs e)
        {
            var newGuid = Guid.NewGuid();
            var entity = new DnsEntity { DomainID = newGuid, Name = "", Type = "A", Value = "" };
            listData.Add(entity);
            entity.IsNew = true;
            UpdateTempList(entity);
            Session["ListData"] = listData;

            DnsGridViewer.DataBind();
        }

        protected void SaveAll_OnClick(object sender, EventArgs e)
        {
            foreach (var dnsEntity in tempList)
            {
                if (dnsEntity.IsDeleted)
                {
                    SqlDataSource1.DeleteParameters[0].DefaultValue = dnsEntity.DomainID.ToString();
                    SqlDataSource1.Delete();
                }
                else
                    if (dnsEntity.IsNew)
                    {
                        SqlDataSource1.InsertParameters["DomainID"].DefaultValue = dnsEntity.DomainID.ToString();
                        SqlDataSource1.InsertParameters["Name"].DefaultValue = dnsEntity.Name;
                        SqlDataSource1.InsertParameters["Type"].DefaultValue = dnsEntity.Type;
                        SqlDataSource1.InsertParameters["Value"].DefaultValue = dnsEntity.Value;
                        SqlDataSource1.Insert();
                    }
                    else
                    {
                        SqlDataSource1.UpdateParameters["DomainID"].DefaultValue = dnsEntity.DomainID.ToString();
                        SqlDataSource1.UpdateParameters["Name"].DefaultValue = dnsEntity.Name;
                        SqlDataSource1.UpdateParameters["Type"].DefaultValue = dnsEntity.Type;
                        SqlDataSource1.UpdateParameters["Value"].DefaultValue = dnsEntity.Value;
                        SqlDataSource1.Update();
                    }
            }

            GetDataSqlSource();
            DnsGridViewer.DataSource = listData;
            DnsGridViewer.DataBind();
        }

        protected void FindRecordsOnClick(object sender, EventArgs e)
        {
            var entities = searchList.FindAll(p => p.Name.ToUpper() == FindRecordTextBox.Text.ToUpper());
            RecordsSearch.DataSource = entities;
            RecordsSearch.DataBind();
        }
        #endregion
    }
}
