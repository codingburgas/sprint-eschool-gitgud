#pragma once
#include "raylib.h"
#include "button.h"
#include "utils.h"
#include <iostream>

class Menu {
public:
	Menu() {};
	void Draw(ProgramStates appState, SubjectStates subject);
	void Update(ProgramStates &appState, SubjectStates &subject);
private:

	Button returnButton = Button(810, 450, 150, 50, { 30, 146, 235, 255 });

	// main menu elements
	Button button1 = Button("images/Lessons_button.png", { 25, 213 });
	Button button2 = Button("images/Assignments_button.png", { 330, 213 });
	Button button3 = Button("images/Schedule_button.png", { 640, 213 });

	///////////////////////////////////////////////////////////////////
	// subjects menu elements

	Button subject1 = Button("images/maths_button.png", { 20, 10 });
	Button subject2 = Button("images/english_button.png", { 20, 90 });
	Button subject3 = Button("images/biology_button.png", { 20, 170 });
	Button subject4 = Button("images/chemistry_button.png", { 20, 250 });
	Button subject5 = Button("images/physics_button.png", { 20, 330 });
	Button subject6 = Button("images/geography_button.png", { 20, 410 });

	Rectangle subjectsBackground = { 0, 0, 190, 500 };

	Rectangle subjectTitle = { 187, 0, 775, 100 };

	Button option1 = Button(230, 120, 300, 75, { 30, 146, 235, 255 });
	Button option2 = Button(230, 215, 300, 75, { 30, 146, 235, 255 });
	Button option3 = Button(230, 310, 300, 75, { 30, 146, 235, 255 });
	Button option4 = Button(230, 405, 300, 75, { 30, 146, 235, 255 });
};
