StarzoneSafariForest_MapScripts::
	.byte 0

StarzoneSafariForest_EventScript_ExitAttendant::
	lock
	faceplayer
	msgbox StarzoneSafariForest_Text_LeaveSafariPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StarzoneSafariForest_EventScript_ExitSafari
	msgbox StarzoneSafariForest_Text_EnjoyTheRestOfYourStay, MSGBOX_DEFAULT
	release
	end

StarzoneSafariForest_EventScript_ExitSafari::
	msgbox StarzoneSafariForest_Text_ExitingSafari, MSGBOX_DEFAULT
	closemessage
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 1
	warp MAP_STARZONE_SAFARI_ENTRANCE, 2, 5
	waitstate
	end

StarzoneSafariForest_Text_LeaveSafariPrompt:
	.string "Would you like to end your SAFARI\n"
	.string "game and return to the entrance?$"

StarzoneSafariForest_Text_EnjoyTheRestOfYourStay:
	.string "Very well. Please enjoy the rest\n"
	.string "of your stay!$"

StarzoneSafariForest_Text_ExitingSafari:
	.string "Right this way, then.$"

StarzoneSafariForest_EventScript_Kecleon::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, StarzoneSafariForest_Movement_KecleonReveal
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30, ITEM_NONE
	dowildbattle
	removeobject VAR_LAST_TALKED
	release
	end

StarzoneSafariForest_Movement_KecleonReveal:
	set_visible
	step_end

StarzoneSafariForest_Text_SomethingIsThere:
	.string "Something invisible seems to be\n"
	.string "blocking the way...$"

StarzoneSafariForest_Text_KecleonFound:
	.string "The DEVON SCOPE let you see the\n"
	.string "invisible POKéMON!\p"
	.string "The startled POKéMON attacked!$"
