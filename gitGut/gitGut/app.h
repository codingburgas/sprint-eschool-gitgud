#pragma once
#include <raylib.h>
#include "menu.h"

enum ProgramStates {
	EXIT = 0,
	MAIN_MENU,
	SUBJECTS_MENU
	


};
enum subjects
{
	MATHS,
	ENGLISH,
	BIOLOGY,
	PHYSICS,
	CHEMISTRY,
	GEOGRAPHY
	
};

class App {
public:
	App();
	void Display();
	void Update();
	void Draw();
private:
	int appState;
	int subjects;
	Menu menu;
	
};