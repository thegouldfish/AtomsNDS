#pragma once

#include "Atoms.h"

static const int HelpStringSize = 512;


// Strings for the help.
enum HelpStringNames 
{	
	kHelpIntro,
	kHelpPlaceAnAtom,kHelpAtomGrow,
	kHelpGoCritical,kHelpCriticalAnim,
	kHelpExplodeAnim,kHelpExplodeChange,
	kHelpChaining, kHelpChainSwing,
	kHelpHowToWin, kHelpEnd,

	kHelpContinue, kHelpRepeat,kHelpQuit,
	kHelpStringCount
};

const char HelpStrings[kHelpStringCount][kLangCount][HelpStringSize]=
{
	{"I'm Professor white and I'm going to show you how to play Atoms:DS"},
	{"You can place an atom on any empty square...\n\nPlease place an atom on the highlighted square"},
	{"You can also place atoms on top of your own atoms...\n\nPlace an atom on top of the previous atom..."},
	{"For an atom to go critical you need to put enough atoms onto a single square...\n\nThe table below shows the number of atoms needed for critical mass!"},

	{"When an atom goes critical it will send atoms horizontal and virtically away from it...\n\nPlace an atom to make it go critical"},
	{"Now that you have seen atoms going critical, I will show you why this is useful...\n\nExplode the atom bellow..."},
	{"Not only do the atoms increase in size but they also switch to the players colour...\n\nUse this to capture other player's atoms bellow..."},
	
	{"The final trick is a chaining reaction...\none explostion can set off another...\nUse this to set off the atoms bellow..."},
	{"Chaining is a powerful techinique that can quickly swing a game..."},
	{"To win a game you must capture all the other players atoms..."},
	{"These are the basic rules of the game...\n\nHave fun and try not to blow up the universe!"},

	{"A to continue"},
	{"X to repeat"},
	{"B to Quit"},
};


// Professor names to be shown on screen.

enum ProfessorNames
{
	kProfWhite,
	kProfYellow,
	kProfGreen,
	kProfRed,
	kProfBlue,
	kProfPurple,
	kProfNameCount
};

const int ProfessorToColour[] = {1,7,3,2,6,5};

const char ProfessorNameString[kProfNameCount][kLangCount][HelpStringSize]=
{
	{"Prof White"},
	{"Prof Yellow"},
	{"Prof Green"},
	{"Prof Red"},
	{"Prof Blue"},
	{"Prof Purple"}
};


// Misc strings

enum MiscStringsNames
{
	kMiscTurns,
	kMiscPlayerSelectInfo,
	kMiscCreditsMenu,
	kMiscStringsCount
};

const char MiscStrings[kMiscStringsCount][kLangCount][HelpStringSize]=
{
	{"Turn %d"},
	{"Tap the professor you want to play, Tap again to set to AI\n\n <- Return to menu \n\n -> Start game"},
	{"Back"},
};


// Menu Strings

enum MenuStringsNames
{
	kMenuLocalGame,
	kMenuWiFiGame,
	kMenuHelp,
	kMenuCredits,
	kMenuStringCount
};

const char MenuStrings[kMenuStringCount][kLangCount][HelpStringSize]=
{
	{"Local"},
	{"WiFi"},
	{"Help"},
	{"Credits"}
};

