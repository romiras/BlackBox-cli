MODULE HostInit;

	IMPORT
		HostConsole (* Console.SetHook *),
		HostFonts (* Fonts.SetHook; required for Texts *),
		HostWindows (* Windows.SetHook *),
		HostDates (* Dates.SetHook *),
		HostDialog (* Dialog.SetShowHook *),
		HostEnv,
		StdInterpreter (* Dialog.SetCallHook *) ,
		StdDialog (* Views.SetViewHook *),
		StdLog, ConsLog; (* Log.Hook *)

END HostInit.
