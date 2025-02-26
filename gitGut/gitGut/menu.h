#pragma once
#include "raylib.h"
#include "button.h"

class Menu {
public:
	Menu();
	void Draw(int appState);
	void Update(int* appState);
};