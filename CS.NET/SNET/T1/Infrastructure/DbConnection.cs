
using System;
using System.Configuration;
using System.Data.EntityClient;

namespace Infrastructure
{
    public class DbConnection
    {
        private SNET_T1Entities _context;
        private bool _isDisposed;

        /// <summary>
        /// Getter & Setter for application's DBcontext
        /// </summary>
        public SNET_T1Entities Context
        {
            get
            {
                if (this._context == null)
                {
                    this.CreateConnection();
                }
                return this._context;
            }
        }

        /// <summary>
        /// Constructor
        /// </summary>
        public DbConnection()
        {
            this.CreateConnection();
        }

        /// <summary>
        /// Create the database connection
        /// </summary>
        private void CreateConnection()
        {
            // get the database information from our config file and creates a new connectionString based on them
            // then select our metadata path for the stringbuilder. it's easier and this way if we want to change
            // the connectionString or metadata that resides in different locations.

            //var connectionString = ConfigurationManager.ConnectionStrings["SNET_T1Entities"].ConnectionString;
            var connectionString = ConfigurationManager.AppSettings["ConnectionString"];
            var connectionStringBuilder = new EntityConnectionStringBuilder(connectionString);
            connectionStringBuilder.Metadata = ConfigurationManager.AppSettings["MetadataFilesPath"];

            this._context = new SNET_T1Entities(connectionStringBuilder.ConnectionString);
        }

        /// <summary>
        /// Commit all changes to database
        /// </summary>
        public void Commit()
        {
            try
            {
                this._context.SaveChanges();
            }
            catch (Exception ex)
            {
                throw (ex);
            }
        }

        /// <summary>
        /// Releases unmanaged resources and performs other cleanup operations before the
        /// <see cref="DbConnection"/> is reclaimed by garbage collection.
        /// </summary>
        ~DbConnection()
        {
            this.Dispose(false);
        }

        /// <summary>
        /// Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.
        /// </summary>
        public void Dispose()
        {
            this.Dispose(true);
            GC.SuppressFinalize(this);
        }

        /// <summary>
        /// Releases unmanaged and optionally managed resources
        /// </summary>
        /// <param name="disposing"></param>
        private void Dispose(bool disposing)
        {
            if (!this._isDisposed && disposing)
            {
                if (this._context != null)
                {
                    this._context.Dispose();
                }
            }

            this._isDisposed = true;
        }

    }
}
