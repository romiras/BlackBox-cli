MODULE HostEnv;

	IMPORT
		SYSTEM,
		WinApi;

	VAR
		szArglist: WinApi.RetCommandLineToArgvW;
		argNumber, res: INTEGER;

	PROCEDURE GetArg* (n: INTEGER; VAR arg: ARRAY OF CHAR);
		VAR 
	BEGIN
		arg := szArglist[n]$
	END GetArg;

	PROCEDURE ArgNumber* (): INTEGER;
	BEGIN
		RETURN argNumber
	END ArgNumber;

BEGIN	
	szArglist := WinApi.CommandLineToArgvW(WinApi.GetCommandLineW(), argNumber)
CLOSE
	res := WinApi.LocalFree(SYSTEM.VAL(WinApi.HLOCAL, szArglist))
END HostEnv.
