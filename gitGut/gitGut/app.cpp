#include "app.h"

void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
	
			if (is3dOn) {
			V3D.Display(subjectState, lessonState, is3dOn);
			continue;
		}

		Update();
		cout << "Lesson: " << lessonState << " homework: " << homeworkState << " Test: " << testState << endl;

		Draw();
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
		EndDrawing();

		DrawTexture(menu.getBackground(appState, subjectState, day), 0, 0 ,WHITE);
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjectState, lessonState, is3dOn, homeworkState, testState, day);
}

void App::Draw() {
	menu.Draw(appState, subjectState, lessonState, homeworkState, testState, day);
}

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

void App::DrawTest()
{
	//switch za testovete
}
