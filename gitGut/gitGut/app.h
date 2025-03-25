#pragma once
#include <raylib.h>
#include "menu.h"
#include "3DViewport.h"
#include "utils.h"
#include "lesson.h"
#include "homework.h"
#include "test.h"

class App {
public:
	App() : appState(MAIN_MENU),
			subjectState(NO_SUBJECT),
			learningState(NO_LEARN),
			lessonState(false),
			homeworkState(false),
			testState(false),
			is3dOn(false),
			day(NO_SCHEDULE)
	{}
	void Display();
	void Update();
	void Draw();
	void DrawLesson();
	void DrawHomework();
	void DrawTest();


private:
	ProgramStates appState;
	SubjectStates subjectState;
	LearningStates learningState;
	bool lessonState;
	int day;
	bool is3dOn;
	bool homeworkState;
	bool testState;
	Menu menu;
	ThreeDimensionalViewport V3D;
	Lesson biologyLesson = Lesson("The human heart is a muscular organ about the size of a fist, located slightly to the left in the chest. \nIt has **four chambers**: the **right atrium** and **right ventricle** pump deoxygenated blood to the lungs, while the \n **left atrium** and **left ventricle** pump oxygenated blood to the body. \n\nThe heart works in two main circuits: the **pulmonary** circuit -to the lungs, and the systemic circuit -to the rest of the body. \nThe heart has four valves to ensure blood flows in the right direction : the tricuspid, pulmonary, mitral, and aortic valves.The** cardiac cycle** includes two phases : **systole** (contraction) and **diastole** (relaxation).The heart is controlled by an electrical system, with the** SA node** acting as the natural pacemaker.Blood vessels connected to the heart include** arteries** (carry blood away), ** veins** (return blood), and **capillaries** (exchange nutrients).A healthy heart is crucial for circulation and overall health.", true);
	Lesson mathLesson = Lesson("neshto tam", true);
	Lesson englishLesson = Lesson("neshto tam", true);
	Lesson chemistryLesson = Lesson("neshto tam", true);
	Lesson physicsLesson = Lesson("neshto tam", true);
	Lesson geographyLesson = Lesson("neshto tam", true);

	Homework mathHomework = Homework("AAAAAAAAAAAAAAAAAAA");
	Homework englishHomework = Homework("neshtotam");
	Homework chemistryHomework = Homework("neshtotam");
	Homework physicsHomework = Homework("neshtotam");
	Homework geographyHomework = Homework("neshtotam");
	Homework biologyHomework = Homework("neshtotam");

	Test mathTest = Test("AAAAAAAAAAAAAAAAAAA");
	Test englishTest = Test("neshtotam");
	Test chemistryTest = Test("neshtotam");
	Test physicsTest = Test("neshtotam");
	Test geographyTest = Test("neshtotam");
	Test biologyTest = Test("neshtotam");



};