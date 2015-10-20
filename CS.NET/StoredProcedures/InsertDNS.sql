SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE InsertDnsRecord (
@DomainID uniqueidentifier,
@Name varchar(MAX),
@Type varchar(MAX),
@Value varchar(MAX)
)
AS
BEGIN
	SET NOCOUNT ON;

	INSERT INTO DomainDNS (DomainID, Name, Type, Value) 
	VALUES (@DomainID, @Name, @Type, @Value)
END
GO
