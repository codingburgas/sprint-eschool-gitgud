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
	void Update(ProgramStates& appState, SubjectStates& subject, LearningStates& learningState, LessonState& lessonState, bool is3dOn);
	Texture2D getBackground(ProgramStates appState, SubjectStates Subject);
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


	Texture2D menu_background = LoadTexture("images/menu_background.png");
	Texture2D maths_background = LoadTexture("images/maths_background.png");
	Texture2D english_background = LoadTexture("images/english_background.png");
	Texture2D biology_background = LoadTexture("images/biology_background.png");
	Texture2D physics_background = LoadTexture("images/physics_background.png");
	Texture2D chemistry_background = LoadTexture("images/chemistry_background.png");
	Texture2D geography_background = LoadTexture("images/geography_background.png");

};
