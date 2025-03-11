#pragma once
#include <raylib.h>
#include "menu.h"
#include "utils.h"

class App {
public:
	App() : appState(MAIN_MENU),
			subjectState(NO_SUBJECT) {}
	void Display();
	void Update();
	void Draw();
private:
	ProgramStates appState;
	SubjectStates subjectState;
	LearningStates learningState;
	LessonState lessonState;
	Menu menu;
};