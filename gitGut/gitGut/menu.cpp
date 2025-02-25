#include "menu.h"

namespace mainMenu {
	Rectangle subject1 = { 20, 10, 150, 50 };
	Rectangle subject2 = { 20, 90, 150, 50 };
	Rectangle subject3 = { 20, 170, 150, 50 };
	Rectangle subject4 = { 20, 250, 150, 50 };
	Rectangle subject5 = { 20, 330, 150, 50 };
	Rectangle subject6 = { 20, 410, 150, 50 };
	Rectangle subjectsBackground = { 0, 0, 190, 500 };
	
	Rectangle subjectTitle = { 187, 0, 775, 100 };

	Rectangle option1 = { 230, 120, 300, 75 };
	Rectangle option2 = { 230, 215, 300, 75 };
	Rectangle option3 = { 230, 310, 300, 75 };
	Rectangle option4 = { 230, 405, 300, 75 };

}

// Defines all the textures, buttons, windows, etc.
Menu::Menu() {
}

void Menu::Draw(int appState) {
	switch (appState) {
	case 1:
		DrawRectangleRec(mainMenu::subjectsBackground, { 52, 52, 52, 255 });
		DrawRectangleLinesEx(mainMenu::subjectsBackground, 3, BLACK);
		DrawRectangleRec(mainMenu::subject1, ORANGE);
		DrawRectangleRec(mainMenu::subject2, ORANGE);
		DrawRectangleRec(mainMenu::subject3, ORANGE);
		DrawRectangleRec(mainMenu::subject4, ORANGE);
		DrawRectangleRec(mainMenu::subject5, ORANGE);
		DrawRectangleRec(mainMenu::subject6, ORANGE);
		DrawRectangleLinesEx(mainMenu::subjectTitle, 3, BLACK);
		DrawRectangleRec(mainMenu::option1, { 30, 146, 235, 255 });
		DrawRectangleRec(mainMenu::option2, { 30, 146, 235, 255 });
		DrawRectangleRec(mainMenu::option3, { 30, 146, 235, 255 });
		DrawRectangleRec(mainMenu::option4, { 30, 146, 235, 255 });

		break;
	}
}

void Menu::Update(int* appState) {
	
}

