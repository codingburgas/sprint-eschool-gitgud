#include "app.h"

// Main display function 
void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
	
			if (is3dOn) {
			V3D.Display(subjectState, lessonState, is3dOn);
			continue;
		}

		// Update the app state
		Update();
		// Draw the general components
		Draw();
		// Start drawing frame
		BeginDrawing();
		if (lessonState == true)
		{
			DrawLesson();
			EndDrawing(); continue;
		}
		if (homeworkState == true)
		{
			DrawHomework();
			EndDrawing(); continue;
		}
		if (testState == true)
		{
			DrawTest();
			EndDrawing(); continue;
		}
		// End drawing frame
		EndDrawing();

		// Draw the background 
		DrawTexture(menu.getBackground(appState, subjectState, day), 0, 0 ,WHITE);
	}
	// Close the app window
	CloseWindow();
}

// Updates the app state based on user input
void App::Update() {
	menu.Update(appState, subjectState, lessonState, is3dOn, homeworkState, testState, day);
}

// Draws the general components
void App::Draw() {
	menu.Draw(appState, subjectState, lessonState, homeworkState, testState, day);
}

// Draws the lesson content based on the selected subject
void App::DrawLesson()
{
		switch(subjectState)
		{
		case MATHS: mathLesson.Display(lessonState, is3dOn);
			break;
		case ENGLISH: englishLesson.Display(lessonState, is3dOn);
			break;
		case BIOLOGY: biologyLesson.Display(lessonState, is3dOn);
			break;
		case PHYSICS: physicsLesson.Display(lessonState, is3dOn);
			break;
		case CHEMISTRY: chemistryLesson.Display(lessonState, is3dOn);
			break;
		case GEOGRAPHY: geographyLesson.Display(lessonState, is3dOn);
			break;
		}
		
	
}

// Draws the homework content based on the selected subject
void App::DrawHomework()
{
	switch (subjectState)
	{
	case MATHS: mathHomework.Display(homeworkState);
		break;
	case ENGLISH: englishHomework.Display(homeworkState);
		break;
	case BIOLOGY: biologyHomework.Display(homeworkState);
		break;
	case PHYSICS: physicsHomework.Display(homeworkState);
		break;
	case CHEMISTRY: chemistryHomework.Display(homeworkState);
		break;
	case GEOGRAPHY: geographyHomework.Display(homeworkState);
		break;
	}
}

// Draws the test content based on the selected subject
void App::DrawTest()
{
	switch (subjectState)
	{
	case MATHS: mathTest.Display(testState);
		break;
	case ENGLISH: englishTest.Display(testState);
		break;
	case BIOLOGY: biologyTest.Display(testState);
		break;
	case PHYSICS: physicsTest.Display(testState);
		break;
	case CHEMISTRY: chemistryTest.Display(testState);
		break;
	case GEOGRAPHY: geographyTest.Display(testState);
		break;
	}
}
