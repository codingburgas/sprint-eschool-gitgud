#include "app.h"

void App::Display() {
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		Update();
		BeginDrawing();
		Draw();
		EndDrawing();

		ClearBackground(DARKGRAY);
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjectState);
}

void App::Draw() {
	menu.Draw(appState, subjectState);
}
