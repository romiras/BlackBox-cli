MODULE HostEnv;

	IMPORT
		SYSTEM,
		WinApi;

	VAR
		szArglist: WinApi.RetCommandLineToArgvW;
		res: INTEGER;
		argCount-: INTEGER;

	PROCEDURE GetArg* (n: INTEGER; VAR arg: ARRAY OF CHAR);
		VAR 
	BEGIN
		arg := szArglist[n]$
	END GetArg;
	
BEGIN	
	szArglist := WinApi.CommandLineToArgvW(WinApi.GetCommandLineW(), argCount)
CLOSE
	res := WinApi.LocalFree(SYSTEM.VAL(WinApi.HLOCAL, szArglist))
END HostEnv.
