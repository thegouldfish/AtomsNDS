#include "tappoint.h"
#include <PA9.h>

tapPoint::tapPoint()
{
	tapPoint(-1);
}

tapPoint::tapPoint(int Default)
{
	kDefault = Default;

	for(int i=0;i<TapAmount;i++)
	{
		taps[i].inUse = false;
	}

	selectedButton = kDefault;
}


bool tapPoint::addTapPoint(int TopLeftX ,int TopLeftY,int BottomRightX,int BottomRightY,int ButtonNumber)
{
	for(int i=0;i<TapAmount;i++)
	{
		if(!taps[i].inUse)
		{
			taps[i].TopLeftX = TopLeftX;
			taps[i].TopLeftY = TopLeftY;
			taps[i].BottomRightX = BottomRightX;
			taps[i].BottomRightY = BottomRightY;
			taps[i].number = ButtonNumber;
			taps[i].inUse = true;
			return true;
		}
	}

	return false;
}

void tapPoint::removeTapPoint(int ButtonNumber)
{
	for(int i=0;i<TapAmount;i++)
	{
		if(!taps[i].inUse)
		{
			if(taps[i].number == ButtonNumber)
			{
				taps[i].inUse = false;
			}
		}
	}
}

void tapPoint::update()
{
	selectedButton = kDefault;

	if(Stylus.Released)
	{
		selectedButton = findButton(Stylus.X, Stylus.Y);
		Stylus.Newpress = false;
	}

}

int tapPoint::findButton(int X, int Y)
{
	for(int i=0;i<TapAmount;i++)
	{
		if(taps[i].inUse)
		{
			if(taps[i].TopLeftX < X && taps[i].BottomRightX > X && taps[i].TopLeftY < Y && taps[i].BottomRightY > Y)
			{
				return taps[i].number;
			}
		}
	}

	return kDefault;
}

int tapPoint::checkTapPoint()
{
	return selectedButton;
}

