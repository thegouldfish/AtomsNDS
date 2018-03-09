#pragma once



class Animator
{
	int m_Animating[7*10];
	int m_NumberOfAnims;

	int m_LoopingAnims[7*10];
	int m_LoopingAnimEnd[7*10];
	int m_NumberOfLoopingAnim;

	public:

	Animator();

	void Reset();

	void AnimateSprite(int SpriteNumber, int startFrame, int endFrame, int speed);


	void playIdle(int SpriteNumber, int startFrame, int endFrame, int EndAnim, int speed);

	void PauseAll();
	void unPauseAll();

	bool isAnimating();

	void KillAnims();

	void StopLoopingAnims();

	int getActiveIdle(int);
};