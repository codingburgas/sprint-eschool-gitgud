#include "menu.h"

// Visualizes the main menu elements
void Menu::Draw(ProgramStates appState, SubjectStates subject, bool lessonState, bool homeworkState, bool testState, int day) {

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
	case SCHEDULE:
		
		switch (day)
		{
		case MONDAY: DrawTexture(mondaySchedule, 0, 0, WHITE);
			break;
		case TUESDAY: DrawTexture(tuesdaySchedule, 0, 0, WHITE);
			break;
		case WEDNESDAY: DrawTexture(wednesdaySchedule, 0, 0, WHITE);
			break;
		case THURSDAY: DrawTexture(thursdaySchedule, 0, 0, WHITE);
			break;
		case FRIDAY: DrawTexture(fridaySchedule, 0, 0, WHITE);
			break;
		case SATURDAY: DrawTexture(saturdaySchedule, 0, 0, WHITE);
			break;
		case SUNDAY: DrawTexture(sundaySchedule, 0, 0, WHITE);
			break;
			default: DrawTexture(mondaySchedule, 0, 0, WHITE);
				break;
		}
		nextButton.Draw();
		backButton.Draw();
		scheduleReturnButton.Draw("Main menu", 10);
	}
}

// Updates the app state when a certain action happens (e.g. When a button is pressed)
void Menu::Update(ProgramStates& appState, SubjectStates& subject, bool& lessonState, bool& is3dOn, bool& homeworkState, bool& testState, int& day) {
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (appState == SCHEDULE) {
		if (nextButton.isPressed(mousePos, isMousePressed)) {
			day++;
			if (day >= 7)
			{
				day = 0;
			}
		}
		else if (backButton.isPressed(mousePos, isMousePressed)) {
			day--;
			if (day < 0)
			{
				day = 6;
			}
		}
	}
	
	switch (appState) {
	case MAIN_MENU:
		if (mainMenuButtons[0].isPressed(mousePos, isMousePressed))
			appState = SUBJECTS_MENU;
		if (mainMenuButtons[1].isPressed(mousePos, isMousePressed))
			appState = ASSIGMENTS;
		if (mainMenuButtons[2].isPressed(mousePos, isMousePressed)) {
			appState = SCHEDULE;
			day = MONDAY;
		}
		break;

	case SUBJECTS_MENU:

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
			lessonState = false;
			homeworkState = false;
			testState = false;
		}

		if (subject != NO_SUBJECT) {
			if (optionsButtons[0].isPressed(mousePos, isMousePressed) && !homeworkState && !testState) {
				lessonState = true;
			}
			else if (optionsButtons[2].isPressed(mousePos, isMousePressed) && !lessonState && !testState)
			{
				homeworkState = true;
			}
			else if (optionsButtons[3].isPressed(mousePos, isMousePressed) && !lessonState && !homeworkState)
			{
				testState = true;
			}

		}
	}
}

Texture2D Menu::getBackground(ProgramStates& appState, SubjectStates& Subject, int& day)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	switch (appState)
	{
	case MAIN_MENU: return menuBackground; 
		break;
	case SUBJECTS_MENU: 
		switch (Subject)
		{
		case MATHS: return mathsBackground;
			break;
		case ENGLISH: return englishBackground;
			break;
		case BIOLOGY: return biologyBackground;
			break;
		case CHEMISTRY: return chemistryBackground;
			break;
		case PHYSICS: return physicsBackground;
			break;
		case GEOGRAPHY: return geographyBackground;
			break;
		}
	case SCHEDULE: 
		if (scheduleReturnButton.isPressed(mousePos, isMousePressed)) {
			day = NO_SCHEDULE;
			appState = MAIN_MENU;
		}
		switch (day)
		{
		case MONDAY: return mondaySchedule;
			break;
		case TUESDAY: return tuesdaySchedule;
			break;
		case WEDNESDAY: return wednesdaySchedule;
			break;
		case THURSDAY: return thursdaySchedule;
			break;
		case FRIDAY: return fridaySchedule;
			break;
		case SATURDAY: return saturdaySchedule;
			break;
		case SUNDAY: return sundaySchedule;
			break;

	
		}
	}
	return menuBackground;
}

