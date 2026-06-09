#include "Led.h"
#include "Keyboard.h"

//Zaliczam gita 
void Delay(unsigned int uiMs) 
{
	
	unsigned int uiLoopCounter;
	uiMs = uiMs*12000;
	
	for (uiLoopCounter=0; uiLoopCounter < uiMs; uiLoopCounter++) {}
}

int main() {
	
enum LedState{LedState_Right, LedState_Left, LedState_Stop};
enum LedState eLedState = LedState_Stop;
	
LedInit();
KeyboardInit();
	
while(1) 
{
	
	switch (eLedState)
	{
		case (LedState_Stop):
			
			if(eKeyboardRead() == BUTTON_0)
			{
				eLedState = LedState_Left;
			}
			else if (eKeyboardRead() == BUTTON_2)
			{
				eLedState = LedState_Right;
			}
			else
			{
				eLedState = LedState_Stop;
			}
			break;
			
		case (LedState_Left):
			
			if (eKeyboardRead() == BUTTON_1)
			{
				eLedState =LedState_Stop;
			}
			else
			{
				LedStepLeft();
				eLedState = LedState_Left;
			}
			break;
			
		case (LedState_Right):
			
			if (eKeyboardRead() == BUTTON_1)
			{
				eLedState = LedState_Stop;
			}
			else
			{
				LedStepRight();
				eLedState = LedState_Right;
			}
			break;
	}
	Delay(100);	
}
}
