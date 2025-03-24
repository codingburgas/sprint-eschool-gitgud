#pragma once
#include "raylib.h"
#include "button.h"
#include "utils.h"
#include <string>
#include <vector>
#include <iostream>

class Menu {
public:
	Menu() {};
	void Draw(ProgramStates appState, SubjectStates subject, LearningStates learningState, bool lessonState, int day);
	void Update(ProgramStates& appState, SubjectStates& subject, LearningStates& learningState, bool& lessonState, bool &is3dOn, int& day);
	Texture2D getBackground(ProgramStates& appState, SubjectStates& Subject, int& day);
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


	Texture2D menuBackground = LoadTexture("images/menu_background.png");
	Texture2D mathsBackground = LoadTexture("images/maths_background.png");
	Texture2D englishBackground = LoadTexture("images/english_background.png");
	Texture2D biologyBackground = LoadTexture("images/biology_background.png");
	Texture2D physicsBackground = LoadTexture("images/physics_background.png");
	Texture2D chemistryBackground = LoadTexture("images/chemistry_background.png");
	Texture2D geographyBackground = LoadTexture("images/geography_background.png");

	Texture2D mondaySchedule = LoadTexture("images/monday_schedule.png");
	Texture2D tuesdaySchedule = LoadTexture("images/tuesday_schedule.png");
	Texture2D wednesdaySchedule = LoadTexture("images/wednesday_schedule.png");
	Texture2D thursdaySchedule = LoadTexture("images/thursday_schedule.png");
	Texture2D fridaySchedule = LoadTexture("images/friday_schedule.png");
	Texture2D saturdaySchedule = LoadTexture("images/saturday_schedule.png");
	Texture2D sundaySchedule = LoadTexture("images/sunday_schedule.png");

	Button nextButton =Button("images/next_button.png", {810, 0});
	Button backButton = Button("images/back_button.png", {0, 0});

	Button scheduleReturnButton = Button(810, 450, 150, 50, {0,0,255,255});

};
