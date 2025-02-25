#include "app.h"

App::App() {
	appState = MAIN_MENU;
}

void App::Display() {

	InitWindow(960, 500, "Title");

	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();
		Draw();
		EndDrawing();

		ClearBackground(DARKGRAY);
	}
	CloseWindow();
}

void App::Update() {
	
}

void App::Draw() {
	menu.Draw(appState);
}
