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

	DrawTexture(menu.getBackground(), 0, 0, WHITE);
		
	}
	CloseWindow();
}

void App::Update() {
	menu.Update(appState, subjects);
}

void App::Draw() {
	menu.Draw(appState, subjects);
}
