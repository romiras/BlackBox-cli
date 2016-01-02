MODULE HostConsole;

	(*
	A. V. Shiryaev, 2012.10

	Console implementation for Windows
	*)

	
	IMPORT SYSTEM, Console, WinApi;

	TYPE
		Cons = POINTER TO RECORD (Console.Console) END;

	CONST
		inBufLen = 128; (* > 0 *)

	VAR
		cons: Cons;
		out, in: WinApi.HANDLE;

		ss: ARRAY 1024 OF SHORTCHAR;

		inBuf: ARRAY[untagged] inBufLen OF SHORTCHAR;
		inBufW, inBufR: INTEGER; (* 0 <= inBufR <= inBufW <= inBufLen *)

	PROCEDURE (cons: Cons) ReadLn (OUT text: ARRAY OF CHAR);
		VAR
			W: INTEGER;
			res: WinApi.BOOL;
			i: INTEGER;
			done: BOOLEAN;
			res1: INTEGER;
	BEGIN
		(* ReadLine -> ss, W *)
		W := 0;
		done := FALSE;
		REPEAT
			i := inBufR;
			WHILE (i < inBufW) & (inBuf[i] # 0AX) & (W < LEN(ss)) DO
				ss[W] := inBuf[i];
				INC(W);
				INC(i)
			END;
			IF i = inBufW THEN
				inBufW := 0; inBufR := 0;
				res := WinApi.ReadFile(in, SYSTEM.ADR(inBuf[0]), inBufLen, i, NIL);
				IF res # 0 THEN (* TRUE *)
					inBufW := i
				ELSE
					(* W := 0; *) done := TRUE
				END
			ELSIF inBuf[i] = 0AX THEN
				ss[W] := 0AX; INC(W); done := TRUE;
				inBufR := i + 1
			ELSE (* ss is too small *)
				W := 0; done := TRUE
			END
		UNTIL done;

		IF W > 0 THEN
			res1 := WinApi.MultiByteToWideChar(65001 (*WinApi.CP_UTF8*), {}, ss, W, text, LEN(text) - 1);
			IF (res1 > 0) & (res1 < LEN(text)) THEN
				text[res1] := 0X
			ELSE
				text[0] := 0X
			END
		ELSE
			text[0] := 0X
		END
	END ReadLn;

	PROCEDURE Print (IN s: ARRAY OF CHAR; len: INTEGER);
		VAR res, written: INTEGER;
	BEGIN
		IF len > 0 THEN
			res := WinApi.WideCharToMultiByte(WinApi.CP_OEMCP, {}, s, len, ss, LEN(ss), NIL, NIL);
			IF (res > 0) & (res <= LEN(ss)) THEN
				res := WinApi.WriteFile(out, SYSTEM.ADR(ss[0]), res, written, NIL)
			END
		END
	END Print;

	PROCEDURE (cons: Cons) WriteChar (c: CHAR);
		VAR ss: ARRAY 1 OF CHAR;
	BEGIN
		ss[0] := c;
		Print(ss, 1)
	END WriteChar;

	PROCEDURE (cons: Cons) WriteStr (IN text: ARRAY OF CHAR);
	BEGIN
		Print(text, LEN(text$))
	END WriteStr;

	PROCEDURE (cons: Cons) WriteLn;
	BEGIN
		Print(0DX + 0AX, 2)
	END WriteLn;

	PROCEDURE Init;
		VAR res: WinApi.BOOL;
	BEGIN
		NEW(cons);
		
		(*  this solution needs WinApi update
		res := WinApi.AttachConsole(WinApi.ATTACH_PARENT_PROCESS);
		IF res = WinApi.ERROR_ACCESS_DENIED THEN (* already attached )
		ELSIF res = WinApi.ERROR_INVALID_HANDLE THEN
			res := WinApi.AllocConsole()
		ELSE ( error *)
		END;
		*)

		out := WinApi.GetStdHandle(WinApi.STD_OUTPUT_HANDLE);
		in := WinApi.GetStdHandle(WinApi.STD_INPUT_HANDLE);

		inBufW := 0; inBufR := 0;

		Console.SetConsole(cons)
	END Init;

BEGIN
	Init
END HostConsole.
