#include "menu.h"

// Visualizes the main menu elements
void Menu::Draw(ProgramStates appState, SubjectStates subject) {
	switch (appState) {
	case MAIN_MENU:
		button1.Draw();
		button2.Draw();
		button3.Draw();
		break;
	case SUBJECTS_MENU:
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

		returnButton.Draw("Back", 1);
		switch (subject) {
		case MATHS:
			DrawText("Mathematics", 407, 30, 50, WHITE);
			break;
		case ENGLISH:
			DrawText("English", 457, 30, 50, WHITE);
			break;
		case BIOLOGY:
			DrawText("Biology", 457, 30, 50, WHITE);
			break;
		case CHEMISTRY:
			DrawText("Chemistry", 437, 30, 50, WHITE);
			break;
		case PHYSICS:
			DrawText("Physics", 457, 30, 50, WHITE);
			break;
		case GEOGRAPHY:
			DrawText("Geography", 437, 30, 50, WHITE);
			break;
		}
		break;
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(ProgramStates &appState, SubjectStates &subject) {
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	switch (appState) {
	case MAIN_MENU:
		if (button1.isPressed(mousePos, isMousePressed))
			appState = SUBJECTS_MENU;
		if (button2.isPressed(mousePos, isMousePressed))
			appState = SUBJECTS_MENU;
		break;
	case SUBJECTS_MENU:
		if (subject1.isPressed(mousePos, isMousePressed))
			subject = MATHS;
		else if (subject2.isPressed(mousePos, isMousePressed))
			subject = ENGLISH;
		else if (subject3.isPressed(mousePos, isMousePressed))
			subject = BIOLOGY;
		else if (subject4.isPressed(mousePos, isMousePressed)) 
			subject = CHEMISTRY;
		else if (subject5.isPressed(mousePos, isMousePressed))
			subject = PHYSICS;
		else if (subject6.isPressed(mousePos, isMousePressed))
			subject = GEOGRAPHY;
		else if (returnButton.isPressed(mousePos, isMousePressed)) {
			appState = MAIN_MENU;
			subject = NONE;
		}
		else if (isMousePressed)
			subject = NONE;
	}
}

