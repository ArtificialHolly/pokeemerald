StarzoneSafariEntrance_MapScripts::
	.byte 0

StarzoneSafariEntrance_EventScript_Attendant::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_STARZONE_SAFARI_ATTEMPTED, StarzoneSafariEntrance_EventScript_AlreadyPlayed
	msgbox StarzoneSafariEntrance_Text_WelcomeToStarzoneSafari, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StarzoneSafariEntrance_EventScript_TryEnterSafari
	msgbox StarzoneSafariEntrance_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

StarzoneSafariEntrance_EventScript_TryEnterSafari::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, StarzoneSafariEntrance_EventScript_EnterSafari
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 0, StarzoneSafariEntrance_EventScript_PCFull
StarzoneSafariEntrance_EventScript_EnterSafari::
	setflag FLAG_DAILY_STARZONE_SAFARI_ATTEMPTED
	msgbox StarzoneSafariEntrance_Text_HereAreYourBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message StarzoneSafariEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox StarzoneSafariEntrance_Text_EnjoyYourStay, MSGBOX_DEFAULT
	closemessage
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	applymovement LOCALID_PLAYER, Starzone_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	random 4
	goto_if_eq VAR_RESULT, 0, StarzoneSafariEntrance_EventScript_WarpSpooky
	goto_if_eq VAR_RESULT, 1, StarzoneSafariEntrance_EventScript_WarpDesert
	goto_if_eq VAR_RESULT, 2, StarzoneSafariEntrance_EventScript_WarpBeach
	goto_if_eq VAR_RESULT, 3, StarzoneSafariEntrance_EventScript_WarpForest
	waitstate
	end

StarzoneSafariEntrance_EventScript_WarpBeach::
	msgbox StarzoneSafariEntrance_Text_WarpingToBeach, MSGBOX_DEFAULT
	closemessage
	warp MAP_STARZONE_SAFARI_BEACH, 11, 7
	waitstate
	end

StarzoneSafariEntrance_EventScript_WarpSpooky::
	msgbox StarzoneSafariEntrance_Text_WarpingToSpooky, MSGBOX_DEFAULT
	closemessage
	warp MAP_STARZONE_SAFARI_SPOOKY, 13, 15
	waitstate
	end

StarzoneSafariEntrance_EventScript_WarpDesert::
	msgbox StarzoneSafariEntrance_Text_WarpingToDesert, MSGBOX_DEFAULT
	closemessage
	warp MAP_STARZONE_SAFARI_DESERT, 10, 5
	waitstate
	end

StarzoneSafariEntrance_EventScript_WarpForest::
	msgbox StarzoneSafariEntrance_Text_WarpingToForest, MSGBOX_DEFAULT
	closemessage
	warp MAP_STARZONE_SAFARI_FOREST, 14, 3
	waitstate
	end

Starzone_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

StarzoneSafariEntrance_EventScript_AlreadyPlayed::
	msgbox StarzoneSafariEntrance_Text_AlreadyPlayedToday, MSGBOX_DEFAULT
	release
	end

StarzoneSafariEntrance_EventScript_PCFull::
	msgbox StarzoneSafariEntrance_Text_PCFull, MSGBOX_DEFAULT
	release
	end

StarzoneSafariEntrance_Text_WelcomeToStarzoneSafari:
	.string "Welcome to the STARZONE SAFARI!\n"
	.string "Would you like to enter?$"

StarzoneSafariEntrance_Text_ComeAgain:
	.string "We hope to see you again!$"

StarzoneSafariEntrance_Text_HereAreYourBalls:
	.string "Excellent. Here are your SAFARI BALLS.$"

StarzoneSafariEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} received 30 SAFARI BALLS.$"

StarzoneSafariEntrance_Text_EnjoyYourStay:
	.string "Please enjoy your stay!$"

StarzoneSafariEntrance_Text_AlreadyPlayedToday:
	.string "I'm sorry, you can only enter the\n"
	.string "STARZONE SAFARI once per day.$"

StarzoneSafariEntrance_Text_PCFull:
	.string "I'm sorry, your PARTY and your PC\n"
	.string "are both full. You have no room!$"


StarzoneSafariEntrance_Text_WarpingToBeach:
	.string "You're heading to the BEACH area!$"

StarzoneSafariEntrance_Text_WarpingToSpooky:
	.string "You're heading to the SPOOKY area!$"

StarzoneSafariEntrance_Text_WarpingToDesert:
	.string "You're heading to the DESERT area!$"

StarzoneSafariEntrance_Text_WarpingToForest:
	.string "You're heading to the FOREST area!$"
