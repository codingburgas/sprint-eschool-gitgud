#pragma once
#include <iostream>
#include "raylib.h"
#include "vector"

class Menu {
public:
	Menu();
	void Draw(int appState);
	void Update(int* appState);
};