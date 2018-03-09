#ifndef _SQUARE_H_
#define _SQUARE_H_


class Animator;

class square
{
	private:
		int size;
		int player;
		int Sprite;
		bool explode;
		int explodeTimer;
		const static int SpriteBankSize = 5;
		Animator * m_Anim;

	public:
		enum places{kPlaceCorner=2,kPlaceSide=3,kPlaceMiddle=4};

		square()
		{
			size =0;
			player=-1;
			explode = false;
			Sprite=0;
			m_Anim = 0;
		}


		places getPlace()
		{
			return Place;
		}

		int getPlayer()
		{
			return player;
		}

		bool getExploded()
		{
			return explode;
		}

		void setup(int,places);
		void SetAnimSystem(Animator * Anim);

		void increaseSize(int);

		void setAnim(bool quick = false);
		void resetAnim();

		void reset();

		bool explodeCheck();

		void StartIdleAnim(int CurrentPlayer);


		int getSize()
		{
			return size;
		}

	private:
		places Place;
};


#endif

