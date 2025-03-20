#include "menu.h"

// Visualizes the main menu elements
void Menu::Draw(ProgramStates appState, SubjectStates subject, LearningStates learningState, LessonState lessonState) {

	switch (appState) {
	case MAIN_MENU:
		for (const Button& button : mainMenuButtons) {
			button.Draw();
		}
		break;
	case SUBJECTS_MENU:
		DrawRectangleRec(subjectsBackground, { 52, 52, 52, 255 });
		DrawRectangleLinesEx(subjectsBackground, 3, BLACK);

		for (const Button& button : subjectMenuButtons) {
			button.Draw();
		}

		DrawRectangleLinesEx(subjectTitle, 3, BLACK);

		if (subject != NO_SUBJECT) {
			for (size_t i = 0; i < optionsButtons.size(); i++) {
				optionsButtons[i].Draw(optionsTitles[i], optionsPaddings[i]);
			}
		}

		returnButton.Draw("Back", 1);
		switch (subject) {
		case NO_SUBJECT:
			DrawText("Select a subject", 367, 30, 50, BLACK);
			break;
		case MATHS:
			DrawText("Mathematics", 407, 30, 50, BLACK);
			break;
		case ENGLISH:
			DrawText("English", 457, 30, 50, BLACK);
			break;
		case BIOLOGY:
			DrawText("Biology", 457, 30, 50, BLACK);
			break;
		case CHEMISTRY:
			DrawText("Chemistry", 437, 30, 50, BLACK);
			break;
		case PHYSICS:
			DrawText("Physics", 457, 30, 50, BLACK);
			break;
		case GEOGRAPHY:
			DrawText("Geography", 437, 30, 50, BLACK);
			break;
		}
		break;
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(ProgramStates &appState, SubjectStates &subject, LearningStates &learningState, LessonState &lessonState, bool &is3dOn) {
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	switch (appState) {
	case MAIN_MENU:
		if (mainMenuButtons[0].isPressed(mousePos, isMousePressed))
			appState = SUBJECTS_MENU;
		if (mainMenuButtons[1].isPressed(mousePos, isMousePressed))
			appState = ASSIGMENTS;
		if (mainMenuButtons[2].isPressed(mousePos, isMousePressed))
			appState = SCHEDULE;
		break;
	case SUBJECTS_MENU:
		if (subject != NO_SUBJECT) {
			if (optionsButtons[0].isPressed(mousePos, isMousePressed))
				learningState = LESSONS;
			else if (optionsButtons[1].isPressed(mousePos, isMousePressed))
				learningState = EXERCISES;
			else if (optionsButtons[2].isPressed(mousePos, isMousePressed))
				learningState = HOMEWORK;
			else if (optionsButtons[3].isPressed(mousePos, isMousePressed))
				learningState = TESTS;
		}

		if (subjectMenuButtons[0].isPressed(mousePos, isMousePressed))
			subject = MATHS;
		else if (subjectMenuButtons[1].isPressed(mousePos, isMousePressed))
			subject = ENGLISH;
		else if (subjectMenuButtons[2].isPressed(mousePos, isMousePressed))
			subject = BIOLOGY;
		else if (subjectMenuButtons[3].isPressed(mousePos, isMousePressed))
			subject = CHEMISTRY;
		else if (subjectMenuButtons[4].isPressed(mousePos, isMousePressed))
			subject = PHYSICS;
		else if (subjectMenuButtons[5].isPressed(mousePos, isMousePressed))
			subject = GEOGRAPHY;
		else if (returnButton.isPressed(mousePos, isMousePressed)) {
			appState = MAIN_MENU;
			subject = NO_SUBJECT;
		}

		switch (subject) {
		case MATHS:
			break;
		case ENGLISH:
			break;
		case BIOLOGY:
			if (optionsButtons[0].isPressed(mousePos, isMousePressed)) {
				lessonState = LESSON_1;
				is3dOn = true;
			}
			break;
		}
		break;
	}
}

Texture2D Menu::getBackground(ProgramStates appState, SubjectStates Subject)
{
	switch (appState)
	{
	case MAIN_MENU: return menu_background; 
		break;
	case SUBJECTS_MENU: 
		switch (Subject)
		{
		case MATHS: return maths_background;
			break;
		case ENGLISH: return english_background;
			break;
		case BIOLOGY: return biology_background;
			break;
		case CHEMISTRY: return chemistry_background;
			break;
		case PHYSICS: return physics_background;
			break;
		case GEOGRAPHY: return geography_background;
			break;
		}
	}
	return menu_background;
}

