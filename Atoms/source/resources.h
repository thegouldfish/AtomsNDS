#ifndef _RESOURCES_H_
#define _RESOURCES_H_

#include "Atoms.h"

class resources
{
	public:
		int playerCount;
		int m_AICount;

		PlayerType m_PlayerDetails[MAXPLAYERS];
		AiLevels m_AiDetails[MAXPLAYERS];

		resources()
		{
			playerCount = 0;
		}

		void reset()
		{
			for(int i=0;i<MAXPLAYERS;i++)
			{
				m_PlayerDetails[i] = kPlayerTypeNone;
			}
		}

};

#endif

