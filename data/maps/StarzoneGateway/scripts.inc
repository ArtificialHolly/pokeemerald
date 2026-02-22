StarzoneGateway_MapScripts::
	.byte 0

StarzoneGateway_EventScript_BerryWoman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_STARZONE_BERRY_RECEIVED, StarzoneGateway_EventScript_AlreadyReceivedBerries
	msgbox StarzoneGateway_Text_WelcomeToGateway, MSGBOX_DEFAULT
	random 5
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT @ Number of berries to give (1-5)
	msgbox StarzoneGateway_Text_HaveSomeBerries, MSGBOX_DEFAULT
StarzoneGateway_EventScript_GiveBerriesLoop::
	random 10
	addvar VAR_RESULT, ITEM_CHERI_BERRY
	copyvar VAR_0x8005, VAR_RESULT
	giveitem VAR_0x8005
	subvar VAR_0x8004, 1
	goto_if_ne VAR_0x8004, 0, StarzoneGateway_EventScript_GiveBerriesLoop
	setflag FLAG_DAILY_STARZONE_BERRY_RECEIVED
	msgbox StarzoneGateway_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

StarzoneGateway_EventScript_AlreadyReceivedBerries::
	msgbox StarzoneGateway_Text_HopeBerriesWereUseful, MSGBOX_DEFAULT
	release
	end

StarzoneGateway_Text_WelcomeToGateway:
	.string "Hello there, traveler! It's a long\n"
	.string "walk through the gateway.\p"
	.string "I like to help out passing TRAINERS\n"
	.string "with the fruits of my garden.$"

StarzoneGateway_Text_HaveSomeBerries:
	.string "Here, please take these berries!$"

StarzoneGateway_Text_ComeBackTomorrow:
	.string "I should have some more ripe and\n"
	.string "ready for you tomorrow!$"

StarzoneGateway_Text_HopeBerriesWereUseful:
	.string "I hope those berries were useful\n"
	.string "on your journey.\p"
	.string "Come see me again tomorrow!$"

StarzoneGateway_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_ENCOUNTER
	msgbox StarzoneGateway_Text_SkittyMeow, MSGBOX_DEFAULT
	waitmoncry
	setwildbattle SPECIES_SKITTY, 10, ITEM_NONE
	dowildbattle
	removeobject VAR_LAST_TALKED
	release
	end

StarzoneGateway_Text_SkittyMeow:
	.string "SKITTY: Miya-meow!$"

StarzoneGateway_EventScript_SketchyShopkeeper::
	lock
	faceplayer
	msgbox StarzoneGateway_Text_PsstWannaBuyBalls, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarzoneGateway_EventScript_SketchyShopDecline
	message StarzoneGateway_Text_KeepItOnTheDownLow
	waitmessage
	pokemart StarzoneGateway_SketchyBallShop
	msgbox StarzoneGateway_Text_PleasureDoingBusiness, MSGBOX_DEFAULT
	release
	end

StarzoneGateway_EventScript_SketchyShopDecline::
	msgbox StarzoneGateway_Text_SketchyShopDecline, MSGBOX_DEFAULT
	release
	end

	.align 2
StarzoneGateway_SketchyBallShop:
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_BEAST_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_NONE
	release
	end

StarzoneGateway_Text_PsstWannaBuyBalls:
	.string "Psst... Hey, kid.\n"
	.string "You look like you're going places.\p"
	.string "I've got some... exotic merchandise.\n"
	.string "Wanna see some rare POKé BALLS?$"

StarzoneGateway_Text_KeepItOnTheDownLow:
	.string "Keep it on the down-low, alright?$"

StarzoneGateway_Text_SketchyShopDecline:
	.string "Suit yourself.\n"
	.string "You didn't see nothing, capiche?$"

StarzoneGateway_Text_PleasureDoingBusiness:
	.string "Pleasure doing business with ya.\n"
	.string "Don't be a stranger.$"

