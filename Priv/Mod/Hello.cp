MODULE PrivHello;

	IMPORT Kernel, Console;

	PROCEDURE SayHello*;
	BEGIN
		Console.WriteStr("Hello from PrivHello!"); Console.WriteLn;
		Kernel.Quit(0)
	END SayHello;

END PrivHello.
