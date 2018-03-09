//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char UPnext_Sprite[24576] __attribute__ ((aligned (4))) ;  // Pal : UPnext_Pal
extern const unsigned char human_computer_Sprite[5120] __attribute__ ((aligned (4))) ;  // Pal : human_computer_Pal
extern const unsigned char helpPointer_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : helpPointer_Pal
extern const unsigned char Scalers_Sprite[6144] __attribute__ ((aligned (4))) ;  // Pal : Scalers_Pal

// Background files : 
extern const int BottomScreen_Info[3]; // BgMode, Width, Height
extern const unsigned short BottomScreen_Map[768] __attribute__ ((aligned (4))) ;  // Pal : BottomScreen_Pal
extern const unsigned char BottomScreen_Tiles[39744] __attribute__ ((aligned (4))) ;  // Pal : BottomScreen_Pal
extern PAGfx_struct BottomScreen; // background pointer

extern const int InGameProfFive_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfFive_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfFive_Pal
extern const unsigned char InGameProfFive_Tiles[10496] __attribute__ ((aligned (4))) ;  // Pal : InGameProfFive_Pal
extern PAGfx_struct InGameProfFive; // background pointer

extern const int InGameProfFour_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfFour_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfFour_Pal
extern const unsigned char InGameProfFour_Tiles[9600] __attribute__ ((aligned (4))) ;  // Pal : InGameProfFour_Pal
extern PAGfx_struct InGameProfFour; // background pointer

extern const int InGameProfOne_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfOne_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfOne_Pal
extern const unsigned char InGameProfOne_Tiles[8640] __attribute__ ((aligned (4))) ;  // Pal : InGameProfOne_Pal
extern PAGfx_struct InGameProfOne; // background pointer

extern const int InGameProfSix_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfSix_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfSix_Pal
extern const unsigned char InGameProfSix_Tiles[10944] __attribute__ ((aligned (4))) ;  // Pal : InGameProfSix_Pal
extern PAGfx_struct InGameProfSix; // background pointer

extern const int Title_topscreen_Info[3]; // BgMode, Width, Height
extern const unsigned short Title_topscreen_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Title_topscreen_Pal
extern const unsigned char Title_topscreen_Tiles[33920] __attribute__ ((aligned (4))) ;  // Pal : Title_topscreen_Pal
extern PAGfx_struct Title_topscreen; // background pointer

extern const int InGameProfThree_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfThree_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfThree_Pal
extern const unsigned char InGameProfThree_Tiles[9984] __attribute__ ((aligned (4))) ;  // Pal : InGameProfThree_Pal
extern PAGfx_struct InGameProfThree; // background pointer

extern const int InGameProfTwo_Info[3]; // BgMode, Width, Height
extern const unsigned short InGameProfTwo_Map[768] __attribute__ ((aligned (4))) ;  // Pal : InGameProfTwo_Pal
extern const unsigned char InGameProfTwo_Tiles[9536] __attribute__ ((aligned (4))) ;  // Pal : InGameProfTwo_Pal
extern PAGfx_struct InGameProfTwo; // background pointer

extern const int ingame_top_Info[3]; // BgMode, Width, Height
extern const unsigned short ingame_top_Map[768] __attribute__ ((aligned (4))) ;  // Pal : ingame_top_Pal
extern const unsigned char ingame_top_Tiles[30720] __attribute__ ((aligned (4))) ;  // Pal : ingame_top_Pal
extern PAGfx_struct ingame_top; // background pointer

extern const int players_Info[3]; // BgMode, Width, Height
extern const unsigned short players_Map[768] __attribute__ ((aligned (4))) ;  // Pal : players_Pal
extern const unsigned char players_Tiles[41408] __attribute__ ((aligned (4))) ;  // Pal : players_Pal
extern PAGfx_struct players; // background pointer

extern const int Atoms_credits_Info[3]; // BgMode, Width, Height
extern const unsigned short Atoms_credits_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Atoms_credits_Pal
extern const unsigned char Atoms_credits_Tiles[42624] __attribute__ ((aligned (4))) ;  // Pal : Atoms_credits_Pal
extern PAGfx_struct Atoms_credits; // background pointer

extern const int winner_bg_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_bg_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_bg_Pal
extern const unsigned char winner_bg_Tiles[40384] __attribute__ ((aligned (4))) ;  // Pal : winner_bg_Pal
extern PAGfx_struct winner_bg; // background pointer

extern const int winner_prof1_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof1_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof1_Pal
extern const unsigned char winner_prof1_Tiles[12288] __attribute__ ((aligned (4))) ;  // Pal : winner_prof1_Pal
extern PAGfx_struct winner_prof1; // background pointer

extern const int winner_prof6_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof6_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof6_Pal
extern const unsigned char winner_prof6_Tiles[12672] __attribute__ ((aligned (4))) ;  // Pal : winner_prof6_Pal
extern PAGfx_struct winner_prof6; // background pointer

extern const int winner_prof5_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof5_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof5_Pal
extern const unsigned char winner_prof5_Tiles[12416] __attribute__ ((aligned (4))) ;  // Pal : winner_prof5_Pal
extern PAGfx_struct winner_prof5; // background pointer

extern const int winner_prof4_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof4_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof4_Pal
extern const unsigned char winner_prof4_Tiles[11904] __attribute__ ((aligned (4))) ;  // Pal : winner_prof4_Pal
extern PAGfx_struct winner_prof4; // background pointer

extern const int winner_prof3_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof3_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof3_Pal
extern const unsigned char winner_prof3_Tiles[13184] __attribute__ ((aligned (4))) ;  // Pal : winner_prof3_Pal
extern PAGfx_struct winner_prof3; // background pointer

extern const int winner_prof2_Info[3]; // BgMode, Width, Height
extern const unsigned short winner_prof2_Map[768] __attribute__ ((aligned (4))) ;  // Pal : winner_prof2_Pal
extern const unsigned char winner_prof2_Tiles[12480] __attribute__ ((aligned (4))) ;  // Pal : winner_prof2_Pal
extern PAGfx_struct winner_prof2; // background pointer

extern const int PauseScreen_Info[3]; // BgMode, Width, Height
extern const unsigned short PauseScreen_Map[768] __attribute__ ((aligned (4))) ;  // Pal : PauseScreen_Pal
extern const unsigned char PauseScreen_Tiles[19776] __attribute__ ((aligned (4))) ;  // Pal : PauseScreen_Pal
extern PAGfx_struct PauseScreen; // background pointer

extern const int Logo_1_Info[3]; // BgMode, Width, Height
extern const unsigned short Logo_1_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Logo_1_Pal
extern const unsigned char Logo_1_Tiles[16320] __attribute__ ((aligned (4))) ;  // Pal : Logo_1_Pal
extern PAGfx_struct Logo_1; // background pointer

extern const int Logo_2_Info[3]; // BgMode, Width, Height
extern const unsigned short Logo_2_Map[768] __attribute__ ((aligned (4))) ;  // Pal : Logo_2_Pal
extern const unsigned char Logo_2_Tiles[11840] __attribute__ ((aligned (4))) ;  // Pal : Logo_2_Pal
extern PAGfx_struct Logo_2; // background pointer

extern const int playerSelect_Info[3]; // BgMode, Width, Height
extern const unsigned short playerSelect_Map[768] __attribute__ ((aligned (4))) ;  // Pal : playerSelect_Pal
extern const unsigned char playerSelect_Tiles[43328] __attribute__ ((aligned (4))) ;  // Pal : playerSelect_Pal
extern PAGfx_struct playerSelect; // background pointer

extern const int menu_Info[3]; // BgMode, Width, Height
extern const unsigned short menu_Map[768] __attribute__ ((aligned (4))) ;  // Pal : menu_Pal
extern const unsigned char menu_Tiles[23424] __attribute__ ((aligned (4))) ;  // Pal : menu_Pal
extern PAGfx_struct menu; // background pointer

extern const int HelpTopScreen_Info[3]; // BgMode, Width, Height
extern const unsigned short HelpTopScreen_Map[768] __attribute__ ((aligned (4))) ;  // Pal : HelpTopScreen_Pal
extern const unsigned char HelpTopScreen_Tiles[14784] __attribute__ ((aligned (4))) ;  // Pal : HelpTopScreen_Pal
extern PAGfx_struct HelpTopScreen; // background pointer

extern const char Atoms_Font_Height;
extern const char Atoms_Font_Sizes[256];
extern const int Atoms_Font_Info[3]; // BgMode, Width, Height
extern const unsigned short Atoms_Font_Map[1024] __attribute__ ((aligned (4))) ;  // Pal : Atoms_Font_Pal
extern const unsigned char Atoms_Font_Tiles[7616] __attribute__ ((aligned (4))) ;  // Pal : Atoms_Font_Pal
extern PAGfx_struct Atoms_Font; // background pointer


// Palette files : 
extern const unsigned short UPnext_Pal[217] __attribute__ ((aligned (4))) ;
extern const unsigned short human_computer_Pal[27] __attribute__ ((aligned (4))) ;
extern const unsigned short helpPointer_Pal[12] __attribute__ ((aligned (4))) ;
extern const unsigned short Scalers_Pal[15] __attribute__ ((aligned (4))) ;
extern const unsigned short BottomScreen_Pal[73] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfFive_Pal[226] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfFour_Pal[243] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfOne_Pal[231] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfSix_Pal[225] __attribute__ ((aligned (4))) ;
extern const unsigned short Title_topscreen_Pal[125] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfThree_Pal[237] __attribute__ ((aligned (4))) ;
extern const unsigned short InGameProfTwo_Pal[242] __attribute__ ((aligned (4))) ;
extern const unsigned short ingame_top_Pal[255] __attribute__ ((aligned (4))) ;
extern const unsigned short players_Pal[213] __attribute__ ((aligned (4))) ;
extern const unsigned short Atoms_credits_Pal[247] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_bg_Pal[130] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof1_Pal[86] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof6_Pal[89] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof5_Pal[105] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof4_Pal[104] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof3_Pal[97] __attribute__ ((aligned (4))) ;
extern const unsigned short winner_prof2_Pal[102] __attribute__ ((aligned (4))) ;
extern const unsigned short PauseScreen_Pal[255] __attribute__ ((aligned (4))) ;
extern const unsigned short Logo_1_Pal[256] __attribute__ ((aligned (4))) ;
extern const unsigned short Logo_2_Pal[165] __attribute__ ((aligned (4))) ;
extern const unsigned short playerSelect_Pal[232] __attribute__ ((aligned (4))) ;
extern const unsigned short menu_Pal[118] __attribute__ ((aligned (4))) ;
extern const unsigned short HelpTopScreen_Pal[111] __attribute__ ((aligned (4))) ;
extern const unsigned short Atoms_Font_Pal[2] __attribute__ ((aligned (4))) ;


#endif

