StarzoneSafariSpooky_MapScripts::
	.byte 0

StarzoneSafariSpooky_EventScript_ExitAttendant::
	lock
	faceplayer
	msgbox StarzoneSafariSpooky_Text_LeaveSafariPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StarzoneSafariSpooky_EventScript_ExitSafari
	msgbox StarzoneSafariSpooky_Text_EnjoyTheRestOfYourStay, MSGBOX_DEFAULT
	release
	end

StarzoneSafariSpooky_EventScript_ExitSafari::
	msgbox StarzoneSafariSpooky_Text_ExitingSafari, MSGBOX_DEFAULT
	closemessage
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	warp MAP_STARZONE_SAFARI_ENTRANCE, 2, 5
	waitstate
	end

StarzoneSafariSpooky_Text_LeaveSafariPrompt:
	.string "Would you like to end your SAFARI\n"
	.string "game and return to the entrance?$"

StarzoneSafariSpooky_Text_EnjoyTheRestOfYourStay:
	.string "Very well. Please enjoy the rest\n"
	.string "of your stay!$"

StarzoneSafariSpooky_Text_ExitingSafari:
	.string "Right this way, then.$"

StarzoneSafariSpooky_EventScript_SpookyWoman::
	lock
	faceplayer
	msgbox StarzoneSafariSpooky_Text_SpookyWomanGreeting, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_WARP_IN
	applymovement VAR_LAST_TALKED, StarzoneSafariSpooky_Movement_ZoruaReveal
	waitmovement 0
	waitse
	playmoncry SPECIES_ZORUA_HISUI, CRY_MODE_ENCOUNTER
	delay 20
	setwildbattle SPECIES_ZORUA_HISUI, 10, ITEM_NONE
	dowildbattle
	removeobject VAR_LAST_TALKED
	release
	end

StarzoneSafariSpooky_Movement_ZoruaReveal:
	set_invisible
	step_end

StarzoneSafariSpooky_Text_SpookyWomanGreeting:
	.string "It's so quiet here...\n"
	.string "Perfect for playing tricks, don't\l"
	.string "you think?\p"
	.string "Hehehe... You've seen right\n"
	.string "through my illusion!$"
