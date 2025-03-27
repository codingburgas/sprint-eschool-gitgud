#include "app.h"

// Main display function 
void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
	
			if (is3dOn) {
			V3D.Display(subjectState, lessonState, is3dOn);
			continue;
		}

		// Updates the app states
		Update();
		BeginDrawing();
		// Draws the general components
		Draw();
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
		EndDrawing();

		DrawTexture(menu.getBackground(appState, subjectState, day), 0, 0 ,WHITE);
	}
	CloseWindow();
}

// Updates the app state based on user input
void App::Update() {
	menu.Update(appState, subjectState, lessonState, is3dOn, homeworkState, testState, day);
}

// Draws the general components
void App::Draw() {
	menu.Draw(appState, subjectState, lessonState, homeworkState, testState, day, lessonsCompleted, homeworksCompleted, testsCompleted, getNumCompletedLessons(), getCompletedLessons());
}

// Draws the lesson content based on the selected subject
void App::DrawLesson()
{
		switch(subjectState)
		{
		case MATHS: mathLesson.Display(lessonState, is3dOn, lessonsCompleted[0]);
			break;
		case ENGLISH: englishLesson.Display(lessonState, is3dOn, lessonsCompleted[1]);
			break;
		case BIOLOGY: biologyLesson.Display(lessonState, is3dOn, lessonsCompleted[2]);
			break;
		case PHYSICS: physicsLesson.Display(lessonState, is3dOn, lessonsCompleted[3]);
			break;
		case CHEMISTRY: chemistryLesson.Display(lessonState, is3dOn, lessonsCompleted[4]);
			break;
		case GEOGRAPHY: geographyLesson.Display(lessonState, is3dOn, lessonsCompleted[5]);
			break;
		}
	
}

// Draws the homework content based on the selected subject
void App::DrawHomework()
{
	switch (subjectState)
	{
	case MATHS: mathHomework.Display(homeworkState, homeworksCompleted[0]);
		break;
	case ENGLISH: englishHomework.Display(homeworkState, homeworksCompleted[1]);
		break;
	case BIOLOGY: biologyHomework.Display(homeworkState, homeworksCompleted[2]);
		break;
	case PHYSICS: physicsHomework.Display(homeworkState, homeworksCompleted[3]);
		break;
	case CHEMISTRY: chemistryHomework.Display(homeworkState, homeworksCompleted[4]);
		break;
	case GEOGRAPHY: geographyHomework.Display(homeworkState, homeworksCompleted[5]);
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

int App::getNumCompletedLessons() {
	int sum = 0;
	for (bool lesson : lessonsCompleted) {
		if (lesson == true) sum++;
	}
	return sum;
}

int App::getNumCompletedHomeworks() {
	int sum = 0;
	for (bool homework : homeworksCompleted) {
		if (homework == true) sum++;
	}
	return sum;
}

int App::getNumCompletedTests() {
	int sum = 0;
	for (bool test : testsCompleted) {
		if (test == true) sum++;
	}
	return sum;
}

std::vector<std::string> App::getCompletedLessons()
{
	std::vector<std::string> result;
	if (lessonsCompleted[0]) result.push_back("Maths");
	if (lessonsCompleted[0]) result.push_back("English");
	if (lessonsCompleted[0]) result.push_back("Biology");
	if (lessonsCompleted[0]) result.push_back("Chemistry");
	if (lessonsCompleted[0]) result.push_back("Physics");
	if (lessonsCompleted[0]) result.push_back("Geography");
	return result;
}
