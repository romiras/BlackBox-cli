MODULE Init;

	IMPORT
		Dialog,
		Converters, (* .odc *)
		HostInit;

	PROCEDURE Init;
		VAR res: INTEGER;
	BEGIN
		Converters.Register("Documents.ImportDocument", "Documents.ExportDocument", "", "odc", {});
		Dialog.Call("Config.Setup", " ", res);
	END Init;

BEGIN
	Init
END Init.
