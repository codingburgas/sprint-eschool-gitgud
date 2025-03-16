#pragma once
#include "raylib.h"
#include "button.h"

class Menu {
public:
	Menu();
	void Draw(int appState, int subjects);
	void Update(int& appState, int& subjects);
	Texture2D getBackground();
private:

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

	/////////////////////////////////////////////////////////
	//background colors

	Texture2D menu_background = LoadTexture("images/menu_background.png");
	Texture2D english_background = LoadTexture("images/english_background.png");
	Texture2D maths_background = LoadTexture("images/maths_background.png");
	Texture2D biology_background = LoadTexture("images/biology_background.png");
	Texture2D chemistry_background = LoadTexture("images/chemistry_background.png");
	Texture2D physics_background = LoadTexture("images/physics_background.png");
	Texture2D geography_background = LoadTexture("images/geography_background.png");





};
