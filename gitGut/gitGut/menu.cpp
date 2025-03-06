#include "menu.h"
#include <iostream>

// Namespaces that contain all the information about the elements of a certain part of the menu.
namespace mainMenu {
	Button button1(25, 213, 280, 75, { 255, 161, 0, 255 });
	Button button2(330, 213, 280, 75, { 255, 161, 0, 255 });
	Button button3(640, 213, 280, 75, { 255, 161, 0, 255 });

}

namespace subjectsMenu {
	Button subject1(20, 10, 150, 50, {255, 161, 0, 255});
	Button subject2(20, 90, 150, 50, { 255, 161, 0, 255 });
	Button subject3(20, 170, 150, 50, { 255, 161, 0, 255 });
	Button subject4(20, 250, 150, 50, { 255, 161, 0, 255 });
	Button subject5(20, 330, 150, 50, { 255, 161, 0, 255 });
	Button subject6(20, 410, 150, 50, { 255, 161, 0, 255 });

	Rectangle subjectsBackground = { 0, 0, 190, 500 };
	
	Rectangle subjectTitle = { 187, 0, 775, 100 };

	Button option1(230, 120, 300, 75, { 30, 146, 235, 255 });
	Button option2(230, 215, 300, 75, { 30, 146, 235, 255 });
	Button option3(230, 310, 300, 75, { 30, 146, 235, 255 });
	Button option4(230, 405, 300, 75, { 30, 146, 235, 255 });

}

Menu::Menu() {
	
}

// Visualizes the main menu elements
void Menu::Draw(int appState) {
	switch (appState) {
	case 1:
		mainMenu::button1.Draw("Lessons", 10);
		mainMenu::button2.Draw("Assigments", 10);
		mainMenu::button3.Draw("Programa", 10);
		break;
	case 2:
		DrawRectangleRec(subjectsMenu::subjectsBackground, { 52, 52, 52, 255 });
		DrawRectangleLinesEx(subjectsMenu::subjectsBackground, 3, BLACK);
		subjectsMenu::subject1.Draw("Maths", 20);
		subjectsMenu::subject2.Draw("English", 10);
		subjectsMenu::subject3.Draw("Biology", 10);
		subjectsMenu::subject4.Draw("Chemistry", 10);
		subjectsMenu::subject5.Draw("Physics", 10);
		subjectsMenu::subject6.Draw("Geography", 10);

		DrawRectangleLinesEx(subjectsMenu::subjectTitle, 3, BLACK);
		subjectsMenu::option1.Draw("Lessons", 60);
		subjectsMenu::option2.Draw("Exercises", 60);
		subjectsMenu::option3.Draw("Homework", 60);
		subjectsMenu::option4.Draw("Tests", 100);

		break;
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(int &appState) {
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	switch (appState) {
	case 1:
		if (mainMenu::button1.isPressed(mousePos, isMousePressed))
			appState = 2;
		break;
	case 2:
		if (subjectsMenu::subject1.isPressed(mousePos, isMousePressed))
		
		if (subjectsMenu::subject2.isPressed(mousePos, isMousePressed))
			std::cout << "ENGLISH" << std::endl;
		if (subjectsMenu::subject3.isPressed(mousePos, isMousePressed))
			std::cout << "BIOLOGY" << std::endl;
		if (subjectsMenu::subject4.isPressed(mousePos, isMousePressed))
			std::cout << "CHEMISTRY" << std::endl;
		if (subjectsMenu::subject5.isPressed(mousePos, isMousePressed))
			std::cout << "PHYSICS" << std::endl;
		if (subjectsMenu::subject6.isPressed(mousePos, isMousePressed))
			std::cout << "GEOGRAPHY" << std::endl;
		break;
	}
}

