#ifndef _BANNER_H_
#define _BANNER_H_

#include "Atoms.h"
#define ATTR0_DISABLED   (2<<8) 

class Banner
{
	public:
		Banner();
		void SetBanner(int,PlayerType Type);
		void SetBannerWinner(int);
		void HideBanner();
		void ShowBanner();

		void ClearOrderSprites();
		void CreateOrderSprites();

		void ShowPlayerRatings(bool Alive[MAXPLAYERS], int count[MAXPLAYERS], int order[MAXPLAYERS]);

		// currentPlayer sets the who playing right now (how far though the array)
		// each element in order has either a player number, or -1 to show not playing.
		void ChangeOrder(int currentPlayer,  int order[6]);

		void ShowPlayerOrder(int currentPlayer, int numberOfPlayers, int order[MAXPLAYERS], bool Alive[MAXPLAYERS]);

		void showSprite(int,int);
		void hideSprite(int,int);

		void SetTurnNumber(int);
};


#endif
