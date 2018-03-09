#pragma once


#include "stateMachine.h"

class State;
class HelpStateIntro;
class HelpStatePlaceAtom;
class HelpStateGrowAtom;
class HelpStateGoCritical;
class HelpStateExplodeAtom;
class HelpStateExplodeChange;

class HelpStateExplodeChain;
class HelpStateSwing;
class HelpStateWin;
class HelpStateEnd;


enum HelpStates {	
	kHelpStateOne,kHelpStateTwo,
	kHelpStateThree,kHelpStateFour,kHelpStateFive,
	kHelpStateSix,kHelpStateSeven,
	kHelpStateEight,kHelpStateNine,kHelpStateTen
	,kHelpStateCount};


void showSprite(int screen, int obj);
void hideSprite(int screen, int obj);


class HelpState: public State
{
	public:

		HelpState();

		void enter();

		void update();

		void exit();

	private:

		stateMachine* HelpStateMachine;
		
		HelpStateIntro* IntroState;
		HelpStatePlaceAtom* PlaceState;
		HelpStateGrowAtom* GrowState;
		HelpStateGoCritical* CriticalState;
		HelpStateExplodeAtom* ExplodeState;
		HelpStateExplodeChange* ExplodeChangeState;

		HelpStateExplodeChain* ExplodeChainState;
		HelpStateSwing* SwingState;
		HelpStateWin* WinState;
		HelpStateEnd* EndState;
};



class HelpStateBase: public State
{
	public:

		HelpStateBase(int , int , bool, bool);

		void enter();

		void update();

		void exit();

	protected:

		int m_StringSize;

		int m_TextId;
		int m_nextState;

		int m_textCount;

		bool m_CanGo;

		int m_textSpeed;
		int m_textUpdate;

		bool m_repeat;
		bool m_Continue;
};


class HelpStateIntro : public HelpStateBase
{
	public:

		HelpStateIntro();

		void enter();

		void update();

		void exit();

	private:

};

class HelpStatePlaceAtom : public HelpStateBase
{
	public:

		HelpStatePlaceAtom();

		void enter();

		void update();

		void exit();

	private:
		enum PlaceAtomState {kGetInput,kAnim};

		PlaceAtomState m_currentState;
		int sprite;
};

class HelpStateGrowAtom : public HelpStateBase
{
	public:

		HelpStateGrowAtom();

		void enter();

		void update();

		void exit();

	private:
		enum PlaceAtomState {kGetInput,kAnim};

		PlaceAtomState m_currentState;
		int sprite;
};


class HelpStateGoCritical : public HelpStateBase
{
	public:

		HelpStateGoCritical();

		void enter();

		void update();

		void exit();

	private:
	
		bool ShowTable;

};

class HelpStateExplodeAtom : public HelpStateBase
{
	public:

		HelpStateExplodeAtom();

		void enter();

		void update();

		void exit();

	private:
		enum PlaceAtomState {kGetInput,kAnim,kAnim2};

		PlaceAtomState m_currentState;
		int sprite;
};


class HelpStateExplodeChange : public HelpStateBase
{
	public:

		HelpStateExplodeChange();

		void enter();

		void update();

		void exit();

	private:
		enum PlaceAtomState {kGetInput,kAnim,kAnim2};

		bool m_shown;
		PlaceAtomState m_currentState;
		int sprite;
};


class HelpStateExplodeChain : public HelpStateBase
{
	public:

		HelpStateExplodeChain();

		void enter();

		void update();

		void exit();

	private:
		enum PlaceAtomState {kGetInput,kAnim,kAnim2,kAnim3,kAnim4};

		bool m_shown;
		PlaceAtomState m_currentState;
		int sprite;
};


class HelpStateSwing : public HelpStateBase
{
	public:

		HelpStateSwing();

		void enter();

		void update();

		void exit();

	private:

};

class HelpStateWin : public HelpStateBase
{
	public:

		HelpStateWin();

		void enter();

		void update();

		void exit();

	private:

};

class HelpStateEnd : public HelpStateBase
{
	public:

		HelpStateEnd();

		void enter();

		void update();

		void exit();

	private:

};