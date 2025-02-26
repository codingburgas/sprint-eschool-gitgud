#include "menu.h"

// Contains the buttons and other elements of the main menu.
namespace mainMenu {
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
		DrawRectangleRec(mainMenu::subjectsBackground, { 52, 52, 52, 255 });
		DrawRectangleLinesEx(mainMenu::subjectsBackground, 3, BLACK);
		mainMenu::subject1.Draw("Maths", 20);
		mainMenu::subject2.Draw("English", 10);
		mainMenu::subject3.Draw("Biology", 10);
		mainMenu::subject4.Draw("Chemistry", 10);
		mainMenu::subject5.Draw("Physics", 10);
		mainMenu::subject6.Draw("Geography", 10);

		DrawRectangleLinesEx(mainMenu::subjectTitle, 3, BLACK);
		mainMenu::option1.Draw("Lessons", 60);
		mainMenu::option2.Draw("Exercises", 60);
		mainMenu::option3.Draw("Homework", 60);
		mainMenu::option4.Draw("Tests", 100);

		break;
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(int* appState) {
	
}

