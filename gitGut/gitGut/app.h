#pragma once
#include <raylib.h>
#include "menu.h"

enum ProgramStates {
	EXIT = 0,
	MAIN_MENU,
};

class App {
public:
	App();
	void Display();
	void Update();
	void Draw();
private:
	int appState;
	Menu menu;
};