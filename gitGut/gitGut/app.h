#pragma once
#include <raylib.h>
#include "menu.h"
#include "utils.h"

class App {
public:
	App() : appState(MAIN_MENU),
			subjectState(NONE) {}
	void Display();
	void Update();
	void Draw();
private:
	ProgramStates appState;
	SubjectStates subjectState;
	Menu menu;
};