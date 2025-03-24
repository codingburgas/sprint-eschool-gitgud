#pragma once
#include <raylib.h>
#include "menu.h"
#include "3DViewport.h"
#include "utils.h"
#include "lesson.h"

class App {
public:
	App() : appState(MAIN_MENU),
			subjectState(NO_SUBJECT),
			learningState(NO_LEARN),
			lessonState(false),
			is3dOn(false),
			day(NO_SCHEDULE)
	{}
	void Display();
	void Update();
	void Draw();
	void DrawLesson(SubjectStates subjectState );
private:
	ProgramStates appState;
	SubjectStates subjectState;
	LearningStates learningState;
	bool lessonState;
	int day;
	bool is3dOn;
	Menu menu;
	ThreeDimensionalViewport V3D;
	Lesson biologyLesson = Lesson("neshto tam", true);

};