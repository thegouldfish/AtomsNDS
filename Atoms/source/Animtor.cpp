
#include <PA9.h>
#include "Atoms.h"
#include "Animator.h"


Animator::Animator()
{
	Reset();

	for(int i=0;i<70;i++)
	{
		m_LoopingAnims[i] = -1;
		m_LoopingAnimEnd[i] = 0;
	}
	
	m_NumberOfLoopingAnim = 0;
}

void Animator::Reset()
{
	for(int i=0;i<70;i++)
	{
		m_Animating[i] = -1;
	}

	m_NumberOfAnims = 0;

}

void Animator::AnimateSprite(int SpriteNumber, int startFrame, int endFrame, int speed)
{
	if(m_NumberOfAnims < 70)
	{
		m_Animating[m_NumberOfAnims] = SpriteNumber;
		m_NumberOfAnims++;
		PA_StopSpriteAnim(kBottomScreen,SpriteNumber);
		PA_StartSpriteAnimEx(kBottomScreen,SpriteNumber,startFrame,endFrame,speed,ANIM_UPDOWN,1);
	}
}



bool Animator::isAnimating()
{
	if(m_NumberOfAnims > 0)
	{
		bool animating = false;
		for(int i=0;i<m_NumberOfAnims;i++)
		{
			if(PA_GetSpriteNCycles(kBottomScreen,m_Animating[i]) > 0)
			{
				animating = true;
			}
		}
		return animating;
	}
	else
	{
		return false;
	}
}

void Animator::KillAnims()
{
	for(int i=0;i<70;i++)
	{
		if(m_Animating[i] != -1)
			PA_StopSpriteAnim(kBottomScreen,m_Animating[i]);
	}
}


void Animator::PauseAll()
{
		for(int i=0;i<m_NumberOfAnims;i++)
		{
			PA_SpriteAnimPause(kBottomScreen,m_Animating[i],1);
		}

		for(int i=0;i<m_NumberOfLoopingAnim;i++)
		{
			PA_SpriteAnimPause(kBottomScreen,m_LoopingAnims[i],1);
		}
}

void Animator::unPauseAll()
{
	for(int i=0;i<m_NumberOfAnims;i++)
	{
		PA_SpriteAnimPause(kBottomScreen,m_Animating[i],0);
	}

	for(int i=0;i<m_NumberOfLoopingAnim;i++)
	{
		PA_SpriteAnimPause(kBottomScreen,m_LoopingAnims[i],0);
	}
}

void Animator::playIdle(int SpriteNumber, int startFrame, int endFrame, int EndAnim, int speed)
{
	if(m_NumberOfLoopingAnim < 70)
	{
		m_LoopingAnims[m_NumberOfLoopingAnim] = SpriteNumber;
		m_LoopingAnimEnd[m_NumberOfLoopingAnim] = EndAnim;
		m_NumberOfLoopingAnim++;

		PA_StopSpriteAnim(kBottomScreen,SpriteNumber);
		PA_StartSpriteAnim(kBottomScreen,SpriteNumber,startFrame,endFrame,speed);
	}
}



void Animator::StopLoopingAnims()
{
	for(int i=0;i<m_NumberOfLoopingAnim;i++)
	{		
		m_LoopingAnims[i] = -1;
		m_LoopingAnimEnd[i] = 0;
	}
	m_NumberOfLoopingAnim = 0;
}

int Animator::getActiveIdle(int place)
{
	if(place < 70)
	{
		return m_LoopingAnims[place];
	}
	else
	{
		return -1;
	}
}