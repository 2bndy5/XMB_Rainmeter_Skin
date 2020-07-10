#NoTrayIcon
#include <FileConstants.au3>
#include <MsgBoxConstants.au3>

;$CmdLine[1] = type of dialog to use
;$CmdLine[2] = primary name of variable to change
;$CmdLine[3] = secondary (optional) name of variable to change. Both $CmdLine[1] & $CmdLine[2] are used withou spaces between them.

   Local $sEnvVar1 = EnvGet("ProgramFiles(x86)")
   Local $sEnvVar2 = EnvGet("USERPROFILE")
   Local Const $XMBsvariables = @ScriptDir & "\Variables.inc"

   ; Display an open dialog to select a list of file(s).
   Local $UserSelection
   If $CmdLine[1] = "drive" Then
	  $UserSelection = FileSelectFolder ( "Please Select " & $CmdLine[1] & " for " & $CmdLine[2], "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}" )
	  If @error Then
		IniWrite ( $XMBsvariables, "Variables", $CmdLine[2], "none" )
	  Else
		 IniWrite ( $XMBsvariables, "Variables", $CmdLine[2], $UserSelection )
	  EndIf
   ElseIf $CmdLine[1] = "exe" Then
	  $UserSelection = FileOpenDialog ( "Please Select " & $CmdLine[2] & " Exe File", $sEnvVar1 & "\", "Executable (*.exe)", $FD_FILEMUSTEXIST )
	  If @error Then
		 ; Display the error message.
		 MsgBox($MB_SYSTEMMODAL, "OOPS", "Something went wrong." & @CRLF & "Error = " & @error)
	  ElseIf $CmdLine[3] = "Dir" Then
		 IniWrite ( $XMBsvariables, "Variables", $CmdLine[2] & $CmdLine[3], StringRegExp($UserSelection, '(^.*\\)' & '.*' & '\.' & $CmdLine[1]) )
	  Else
		 IniWrite ( $XMBsvariables, "Variables", $CmdLine[2] & $CmdLine[3], $UserSelection )
	  EndIf
   ElseIf $CmdLine[1] = "folder" Then
	  $UserSelection = FileSelectFolder ( "Please Select " & $CmdLine[2] & " Folder" , $sEnvVar2 & "\" )
	  If @error Then
		 If $CmdLine[3] = "Library2" Then
			;set variable to "none"
			IniWrite ( $XMBsvariables, "Variables", $CmdLine[2] & $CmdLine[3], "none" )
		 Else
			; Display the error message.
			MsgBox($MB_SYSTEMMODAL, "OOPS", "Something went wrong." & @CRLF & "Error = " & $CmdLine[0])
		 EndIf
	  Else
		 IniWrite ( $XMBsvariables, "Variables", $CmdLine[2] & $CmdLine[3], $UserSelection )
	  EndIf
   ElseIf $CmdLine[1] = "drive" Then
	  $UserSelection = FileSelectFolder ( "Please Select " & $CmdLine[1] & " for " & $CmdLine[2], "::{20D04FE0-3AEA-1069-A2D8-08002B30309D}" )
	  If @error Then
		IniWrite ( $XMBsvariables, "Variables", $CmdLine[2], "none" )
	  Else
		 IniWrite ( $XMBsvariables, "Variables", $CmdLine[2], $UserSelection )
	  EndIf
   EndIf

;   Run ( $CmdLine[4] & " !RainmeterRefresh " & $CmdLine[5] )
;   MsgBox($MB_SYSTEMMODAL, "", "You chose the following folder:" & @CRLF & $UserSelection)
;	MsgBox($MB_SYSTEMMODAL, "", "Variables location is:" & @CRLF & $XMBsvariables)
