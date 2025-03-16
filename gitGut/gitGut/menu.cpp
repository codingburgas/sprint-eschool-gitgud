#include "menu.h"
#include <iostream>



Menu::Menu() {
}

// Visualizes the main menu elements
void Menu::Draw(int appState, int subjects) {
	switch (appState) {
	case 1:
		button1.Draw();
		button2.Draw();
		button3.Draw();
		break;
	case 2:
		
		DrawRectangleRec(subjectsBackground, { 52, 52, 52, 255 });
		DrawRectangleLinesEx(subjectsBackground, 3, BLACK);
		subject1.Draw();
		subject2.Draw();
		subject3.Draw();
		subject4.Draw();
		subject5.Draw();
		subject6.Draw();

		DrawRectangleLinesEx(subjectTitle, 3, BLACK);
		option1.Draw("Lessons", 60);
		option2.Draw("Exercises", 60);
		option3.Draw("Homework", 60);
		option4.Draw("Tests", 100);
		

		break;
		switch (subjects)
		{
		case 0: DrawTexture(maths_background, 0, 0, WHITE);
		case 1: DrawTexture(english_background, 0, 0, WHITE);
		case 2: DrawTexture(biology_background, 0, 0, WHITE);
		case 3: DrawTexture(physics_background, 0, 0, WHITE);
		case 4: DrawTexture(chemistry_background, 0, 0, WHITE);
		case 5: DrawTexture(geography_background, 0, 0, WHITE);


		}
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(int &appState, int &subjects) {
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	switch (appState) {
	case 1:
		if (button1.isPressed(mousePos, isMousePressed))
			appState = 2;
		break;
	case 2:
		if (subject1.isPressed(mousePos, isMousePressed))
			DrawTexture(maths_background, 0, 0, WHITE);
		subjects = 0;
		if (subject2.isPressed(mousePos, isMousePressed))
			//subjects = 1;
			std::cout << "ENGLISH" << std::endl;
		if (subject3.isPressed(mousePos, isMousePressed))
			//subjects = 2;
			std::cout << "BIOLOGY" << std::endl;
		if (subject4.isPressed(mousePos, isMousePressed))
			//subjects = 3;
			std::cout << "CHEMISTRY" << std::endl;
		if (subject5.isPressed(mousePos, isMousePressed))
			//subjects = 4;
			std::cout << "PHYSICS" << std::endl;
		if (subject6.isPressed(mousePos, isMousePressed))
			//subjects = 5;
			std::cout << "GEOGRAPHY" << std::endl;

		
		break;
	}
}

Texture2D Menu::getBackground()
{
	
	return menu_background;
}

