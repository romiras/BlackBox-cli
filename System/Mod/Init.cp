MODULE Init;

	IMPORT
		Dialog,
		Converters, (* .odc *)
		HostInit,
		Console;

	PROCEDURE Init;
		VAR res: INTEGER;
	BEGIN
		Converters.Register("Documents.ImportDocument", "Documents.ExportDocument", "", "odc", {});
		Dialog.Call("Config.Setup", " ", res);
	END Init;

BEGIN
	Init;
	Console.WriteStr("Hello!"); Console.WriteLn
END Init.
