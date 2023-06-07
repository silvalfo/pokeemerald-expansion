PetalburgWoods2_MapScripts::
	.byte 0
	
PetalburgWoods2_EventScript_Sudowoodo::
	lockall
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUDOWOODO, 20
	setvar VAR_0x8009, 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods2_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PetalburgWoods2_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods2_EventScript_RanFromSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods2_EventScript_RanFromSudowoodo
	releaseall
	end

PetalburgWoods2_EventScript_DefeatedSudowoodo::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	releaseall
	end

PetalburgWoods2_EventScript_RanFromSudowoodo::
	setvar VAR_0x8004, SPECIES_SUDOWOODO
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	releaseall
	end
