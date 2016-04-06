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
		Dialog.Call("ConsInterp.Run", " ", res)
	END Init;

BEGIN
	(*Console.WriteStr("Running as command interpreter. Waiting for input from stdin..."); Console.WriteLn;*)
	Init
END Init.
