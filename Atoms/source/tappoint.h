#ifndef _TAPPOINT_H_
#define _TAPPOINT_H_

class tapPoint
{
	private:
		const static int TapAmount = 12;

		int kDefault;
		int selectedButton;

		struct button
		{
			bool inUse;
			int TopLeftX;
			int TopLeftY;

			int BottomRightX;
			int BottomRightY;

			int number;
		};

		button taps[TapAmount];

		int findButton(int X, int Y);

	public:
		tapPoint();
		tapPoint(int);

		bool addTapPoint(int TopLeftX ,int TopLeftY,int BottomRightX,int BottomRightY,int ButtonNumber);
		void removeTapPoint(int);

		void update();

		int checkTapPoint();
};

#endif

