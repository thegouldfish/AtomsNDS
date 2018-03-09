#include "square.h"
#include "Atoms.h"

#include "Animations.h"
#include "Animator.h"
#include <PA9.h>       // Include for PA_Lib


void square::setup(int TheSprite, places ThePlace)
{
	Sprite = TheSprite;
	Place = ThePlace;

	reset();
}

void square::SetAnimSystem(Animator * Anim)
{
	m_Anim = Anim;
}

void square::increaseSize(int NewPlayer)
{
	size++;

	if(size == Place)
	{
		explode = true;
	}

	player = NewPlayer;

	PA_SetSpritePal(kBottomScreen,Sprite,player);
}

void square::setAnim(bool quick)
{
	if(explode)
	{
//		PA_SetSpriteAnim(kBottomScreen, Sprite, Atom_Sizes[5]);
		m_Anim->AnimateSprite(Sprite,Atom_grow_anims[5][kAnimStart],Atom_grow_anims[5][kAnimEnd],Atom_grow_anims[5][kAnimSpeed]);
	}
	else
	{
		if(m_Anim)
		{
			int animspeed = Atom_grow_anims[size][kAnimSpeed];
			
			if(quick)
				animspeed *=2;

				m_Anim->AnimateSprite(Sprite,Atom_grow_anims[size][kAnimStart],Atom_grow_anims[size][kAnimEnd],animspeed);
		}
		else
		{
			PA_SetSpriteAnim(kBottomScreen, Sprite, Atom_Sizes[size]);
		}
	}
}

void square::resetAnim()
{
	PA_SetSpriteAnim(kBottomScreen, Sprite, Atom_Sizes[size]);
}

void square::reset()
{
	explodeTimer = 0;
	size = 0;
	player = -1;
	explode = false;
	PA_SetSpriteAnim(kBottomScreen, Sprite, 0);
}

bool square::explodeCheck()
{
	explodeTimer++;

	if(explodeTimer >= EXPLODETIME)
	{
		return false;
	}

	return true;
}

void square::StartIdleAnim(int CurrentPlayer)
{
	if(CurrentPlayer == player)
	{
		if(size == (int)Place-1)
		{
			m_Anim->playIdle(Sprite,atom_idle_explode_anim[size][kAnimStart],atom_idle_explode_anim[size][kAnimEnd],Atom_Sizes[size],atom_idle_explode_anim[size][kAnimSpeed]);
		}
		else
		{
			m_Anim->playIdle(Sprite,atom_idle_anim[size][kAnimStart],atom_idle_anim[size][kAnimEnd],Atom_Sizes[size],atom_idle_anim[size][kAnimSpeed]);
		}
	}
}