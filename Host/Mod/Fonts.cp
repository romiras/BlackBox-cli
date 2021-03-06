MODULE HostFonts;

	(* for Texts, HostTextConv *)

	IMPORT Fonts;

	CONST
		defTypeface = "*";
		defSize = 12 * Fonts.point;
		defW = 161925;
		defAsc = 142875;
		defDsc = 28575;

	TYPE
		Font = POINTER TO RECORD (Fonts.Font)
			alias-: Fonts.Typeface;	(* alias # typeface & typeface # "*" == alien font *)
		END;

		Directory = POINTER TO RECORD (Fonts.Directory) END;

	VAR
		defFont-: Font; (* for HostTextConv *)
		ti: Fonts.TypefaceInfo;
		dir: Directory;

	PROCEDURE (f: Font) GetBounds (OUT asc, dsc, w: INTEGER);
	BEGIN
		asc := defAsc;
		dsc := defDsc;
		w := defW
	END GetBounds;

	PROCEDURE (f: Font) StringWidth (IN s: ARRAY OF CHAR): INTEGER;
	BEGIN
		RETURN LEN(s$) * defW
	END StringWidth;

	PROCEDURE (f: Font) SStringWidth (IN s: ARRAY OF SHORTCHAR): INTEGER;
	BEGIN
		RETURN LEN(s$) * defW
	END SStringWidth;

	PROCEDURE (f: Font) IsAlien (): BOOLEAN;
	BEGIN
		RETURN TRUE
	END IsAlien;

	PROCEDURE (d: Directory) This (typeface: Fonts.Typeface; size: INTEGER; style: SET; weight: INTEGER): Font;
	BEGIN
		RETURN defFont
	END This;

	PROCEDURE (d: Directory) Default (): Font;
	BEGIN
		RETURN defFont
	END Default;

	PROCEDURE (d: Directory) TypefaceList (): Fonts.TypefaceInfo;
	BEGIN
		RETURN ti
	END TypefaceList;

	(** miscellaneous **)

	PROCEDURE InstallDir*;
	BEGIN
		Fonts.SetDir(dir)
	END InstallDir;

	PROCEDURE Init;
		VAR def: Fonts.Font; face: Fonts.Typeface;
	BEGIN
		NEW(defFont);
		defFont.Init(defTypeface, defSize, {}, Fonts.normal);
		defFont.alias := "Arial";
		NEW(ti);
		ti.typeface := defTypeface;
		NEW(dir); Fonts.SetDir(dir)
		;def := Fonts.dir.Default(); face := def.typeface$;
	END Init;

BEGIN
	Init
END HostFonts.
