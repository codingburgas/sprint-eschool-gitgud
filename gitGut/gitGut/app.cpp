#include "app.h"

void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		Update();

		if (is3dOn) {
			V3D.Display(subjectState, lessonState, is3dOn);
			continue;
		}

		BeginDrawing();
		Draw();
		EndDrawing();

		DrawTexture(menu.getBackground(appState, subjectState), 0, 0 ,WHITE);
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjectState, learningState, lessonState, is3dOn);
}

void App::Draw() {
	menu.Draw(appState, subjectState, learningState, lessonState);
}
