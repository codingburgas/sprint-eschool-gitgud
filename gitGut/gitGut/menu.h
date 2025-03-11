#pragma once
#include "raylib.h"
#include "button.h"
#include "utils.h"
#include <string>
#include <vector>

class Menu {
public:
	Menu() {};
	void Draw(ProgramStates appState, SubjectStates subject, LearningStates learningState, LessonState lessonState);
	void Update(ProgramStates& appState, SubjectStates& subject, LearningStates& learningState, LessonState& lessonState);
private:

	Button returnButton = Button(810, 450, 150, 50, { 30, 146, 235, 255 });

	// main menu elements

	std::vector<Button> mainMenuButtons = {
	Button("images/Lessons_button.png", { 25, 213 }),
	Button("images/Assignments_button.png", { 330, 213 }),
	Button("images/Schedule_button.png", { 640, 213 })
	};

	///////////////////////////////////////////////////////////////////
	// subjects menu elements

	std::vector<Button> subjectMenuButtons = {
	Button("images/maths_button.png", { 20, 10 }),
	Button("images/english_button.png", { 20, 90 }),
	Button("images/biology_button.png", { 20, 170 }),
	Button("images/chemistry_button.png", { 20, 250 }),
	Button("images/physics_button.png", { 20, 330 }),
	Button("images/geography_button.png", { 20, 410 })
	};

	Rectangle subjectsBackground = { 0, 0, 190, 500 };

	Rectangle subjectTitle = { 187, 0, 775, 100 };

	std::vector<int> optionsPaddings = { 60, 60, 60, 100 };
	std::vector<const char*> optionsTitles = {
		"Lessons",
		"Exercises",
		"Homework",
		"Tests",
	};

	std::vector<Button> optionsButtons = {
	Button(230, 120, 300, 75, { 30, 146, 235, 255 }),
	Button(230, 215, 300, 75, { 30, 146, 235, 255 }),
	Button(230, 310, 300, 75, { 30, 146, 235, 255 }),
	Button(230, 405, 300, 75, { 30, 146, 235, 255 })
	};
};
