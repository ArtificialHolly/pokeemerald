StarzoneSafariBeach_MapScripts::
	.byte 0

StarzoneSafariBeach_EventScript_ExitAttendant::
	lock
	faceplayer
	msgbox StarzoneSafariBeach_Text_LeaveSafariPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StarzoneSafariBeach_EventScript_ExitSafari
	msgbox StarzoneSafariBeach_Text_EnjoyTheRestOfYourStay, MSGBOX_DEFAULT
	release
	end

StarzoneSafariBeach_EventScript_ExitSafari::
	msgbox StarzoneSafariBeach_Text_ExitingSafari, MSGBOX_DEFAULT
	closemessage
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	warp MAP_STARZONE_SAFARI_ENTRANCE, 2, 5
	waitstate
	end

StarzoneSafariBeach_Text_LeaveSafariPrompt:
	.string "Would you like to end your SAFARI\n"
	.string "game and return to the entrance?$"

StarzoneSafariBeach_Text_EnjoyTheRestOfYourStay:
	.string "Very well. Please enjoy the rest\n"
	.string "of your stay!$"

StarzoneSafariBeach_Text_ExitingSafari:
	.string "Right this way, then.$"
