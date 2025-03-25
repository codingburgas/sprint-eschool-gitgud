#include "app.h"

void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
	
			if (is3dOn) {
			V3D.Display(subjectState, lessonState, is3dOn);
			continue;
		}

		Update();

		BeginDrawing();
		Draw();
		if (lessonState == true)
		{
			DrawLesson(subjectState);
			
			//biologyLesson.Display(lessonState, is3dOn);

		}
		if (homeworkState == true)
		{
			DrawHomework(subjectState);
		}
		if (testState == true)
		{
			DrawTest(subjectState);
		}
		EndDrawing();

		DrawTexture(menu.getBackground(appState, subjectState, day), 0, 0 ,WHITE);
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjectState, learningState, lessonState, is3dOn, homeworkState,testState, day);
}

void App::Draw() {
	menu.Draw(appState, subjectState, learningState, lessonState, homeworkState, testState, day);
}

void App::DrawLesson(SubjectStates subjectState)
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

void App::DrawHomework(SubjectStates subjectState)
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

void App::DrawTest(SubjectStates subjectState)
{
	//switch za testovete
}
