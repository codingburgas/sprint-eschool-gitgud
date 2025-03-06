#include "app.h"

App::App() {
	appState = MAIN_MENU;
}

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
	menu.Update(appState);
}

void App::Draw() {
	menu.Draw(appState);
}
