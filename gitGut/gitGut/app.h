#pragma once
#include <raylib.h>
#include "menu.h"
#include "3DViewport.h"
#include "utils.h"

class App {
public:
	App() : appState(MAIN_MENU),
			subjectState(NO_SUBJECT),
			learningState(NO_LEARN),
			lessonState(LESSON_1),
			is3dOn(false),
			day(NO_SCHEDULE)
	{}
	void Display();
	void Update();
	void Draw();
private:
	ProgramStates appState;
	SubjectStates subjectState;
	LearningStates learningState;
	LessonState lessonState;
	int day;
	bool is3dOn;
	Menu menu;
	ThreeDimensionalViewport V3D;
};