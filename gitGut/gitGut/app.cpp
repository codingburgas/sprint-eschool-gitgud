#include "app.h"

void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		Update();
		BeginDrawing();
		Draw();
		EndDrawing();

		DrawTexture(menu.getBackground(appState, subjectState), 0, 0 ,WHITE);
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjectState, learningState, lessonState);
}

void App::Draw() {
	menu.Draw(appState, subjectState, learningState, lessonState);
}
