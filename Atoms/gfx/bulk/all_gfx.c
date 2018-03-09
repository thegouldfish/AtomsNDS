//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "UPnext.c"
#include "human_computer.c"
#include "helpPointer.c"
#include "Scalers.c"

// Background files : 
#include "BottomScreen.c"
#include "InGameProfFive.c"
#include "InGameProfFour.c"
#include "InGameProfOne.c"
#include "InGameProfSix.c"
#include "Title_topscreen.c"
#include "InGameProfThree.c"
#include "InGameProfTwo.c"
#include "ingame_top.c"
#include "players.c"
#include "Atoms_credits.c"
#include "winner_bg.c"
#include "winner_prof1.c"
#include "winner_prof6.c"
#include "winner_prof5.c"
#include "winner_prof4.c"
#include "winner_prof3.c"
#include "winner_prof2.c"
#include "PauseScreen.c"
#include "Logo_1.c"
#include "Logo_2.c"
#include "playerSelect.c"
#include "menu.c"
#include "HelpTopScreen.c"
#include "Atoms_Font.c"

// Palette files : 
#include "UPnext.pal.c"
#include "human_computer.pal.c"
#include "helpPointer.pal.c"
#include "Scalers.pal.c"
#include "BottomScreen.pal.c"
#include "InGameProfFive.pal.c"
#include "InGameProfFour.pal.c"
#include "InGameProfOne.pal.c"
#include "InGameProfSix.pal.c"
#include "Title_topscreen.pal.c"
#include "InGameProfThree.pal.c"
#include "InGameProfTwo.pal.c"
#include "ingame_top.pal.c"
#include "players.pal.c"
#include "Atoms_credits.pal.c"
#include "winner_bg.pal.c"
#include "winner_prof1.pal.c"
#include "winner_prof6.pal.c"
#include "winner_prof5.pal.c"
#include "winner_prof4.pal.c"
#include "winner_prof3.pal.c"
#include "winner_prof2.pal.c"
#include "PauseScreen.pal.c"
#include "Logo_1.pal.c"
#include "Logo_2.pal.c"
#include "playerSelect.pal.c"
#include "menu.pal.c"
#include "HelpTopScreen.pal.c"
#include "Atoms_Font.pal.c"

// Background Pointers :
PAGfx_struct BottomScreen = {(void*)BottomScreen_Map, 768, (void*)BottomScreen_Tiles, 39744, (void*)BottomScreen_Pal, (int*)BottomScreen_Info };
PAGfx_struct InGameProfFive = {(void*)InGameProfFive_Map, 768, (void*)InGameProfFive_Tiles, 10496, (void*)InGameProfFive_Pal, (int*)InGameProfFive_Info };
PAGfx_struct InGameProfFour = {(void*)InGameProfFour_Map, 768, (void*)InGameProfFour_Tiles, 9600, (void*)InGameProfFour_Pal, (int*)InGameProfFour_Info };
PAGfx_struct InGameProfOne = {(void*)InGameProfOne_Map, 768, (void*)InGameProfOne_Tiles, 8640, (void*)InGameProfOne_Pal, (int*)InGameProfOne_Info };
PAGfx_struct InGameProfSix = {(void*)InGameProfSix_Map, 768, (void*)InGameProfSix_Tiles, 10944, (void*)InGameProfSix_Pal, (int*)InGameProfSix_Info };
PAGfx_struct Title_topscreen = {(void*)Title_topscreen_Map, 768, (void*)Title_topscreen_Tiles, 33920, (void*)Title_topscreen_Pal, (int*)Title_topscreen_Info };
PAGfx_struct InGameProfThree = {(void*)InGameProfThree_Map, 768, (void*)InGameProfThree_Tiles, 9984, (void*)InGameProfThree_Pal, (int*)InGameProfThree_Info };
PAGfx_struct InGameProfTwo = {(void*)InGameProfTwo_Map, 768, (void*)InGameProfTwo_Tiles, 9536, (void*)InGameProfTwo_Pal, (int*)InGameProfTwo_Info };
PAGfx_struct ingame_top = {(void*)ingame_top_Map, 768, (void*)ingame_top_Tiles, 30720, (void*)ingame_top_Pal, (int*)ingame_top_Info };
PAGfx_struct players = {(void*)players_Map, 768, (void*)players_Tiles, 41408, (void*)players_Pal, (int*)players_Info };
PAGfx_struct Atoms_credits = {(void*)Atoms_credits_Map, 768, (void*)Atoms_credits_Tiles, 42624, (void*)Atoms_credits_Pal, (int*)Atoms_credits_Info };
PAGfx_struct winner_bg = {(void*)winner_bg_Map, 768, (void*)winner_bg_Tiles, 40384, (void*)winner_bg_Pal, (int*)winner_bg_Info };
PAGfx_struct winner_prof1 = {(void*)winner_prof1_Map, 768, (void*)winner_prof1_Tiles, 12288, (void*)winner_prof1_Pal, (int*)winner_prof1_Info };
PAGfx_struct winner_prof6 = {(void*)winner_prof6_Map, 768, (void*)winner_prof6_Tiles, 12672, (void*)winner_prof6_Pal, (int*)winner_prof6_Info };
PAGfx_struct winner_prof5 = {(void*)winner_prof5_Map, 768, (void*)winner_prof5_Tiles, 12416, (void*)winner_prof5_Pal, (int*)winner_prof5_Info };
PAGfx_struct winner_prof4 = {(void*)winner_prof4_Map, 768, (void*)winner_prof4_Tiles, 11904, (void*)winner_prof4_Pal, (int*)winner_prof4_Info };
PAGfx_struct winner_prof3 = {(void*)winner_prof3_Map, 768, (void*)winner_prof3_Tiles, 13184, (void*)winner_prof3_Pal, (int*)winner_prof3_Info };
PAGfx_struct winner_prof2 = {(void*)winner_prof2_Map, 768, (void*)winner_prof2_Tiles, 12480, (void*)winner_prof2_Pal, (int*)winner_prof2_Info };
PAGfx_struct PauseScreen = {(void*)PauseScreen_Map, 768, (void*)PauseScreen_Tiles, 19776, (void*)PauseScreen_Pal, (int*)PauseScreen_Info };
PAGfx_struct Logo_1 = {(void*)Logo_1_Map, 768, (void*)Logo_1_Tiles, 16320, (void*)Logo_1_Pal, (int*)Logo_1_Info };
PAGfx_struct Logo_2 = {(void*)Logo_2_Map, 768, (void*)Logo_2_Tiles, 11840, (void*)Logo_2_Pal, (int*)Logo_2_Info };
PAGfx_struct playerSelect = {(void*)playerSelect_Map, 768, (void*)playerSelect_Tiles, 43328, (void*)playerSelect_Pal, (int*)playerSelect_Info };
PAGfx_struct menu = {(void*)menu_Map, 768, (void*)menu_Tiles, 23424, (void*)menu_Pal, (int*)menu_Info };
PAGfx_struct HelpTopScreen = {(void*)HelpTopScreen_Map, 768, (void*)HelpTopScreen_Tiles, 14784, (void*)HelpTopScreen_Pal, (int*)HelpTopScreen_Info };
PAGfx_struct Atoms_Font = {(void*)Atoms_Font_Map, 1024, (void*)Atoms_Font_Tiles, 7616, (void*)Atoms_Font_Pal, (int*)Atoms_Font_Info };


#ifdef __cplusplus
}
#endif

