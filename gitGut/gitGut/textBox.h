#pragma once
#include "raylib.h"
constexpr int MAX_INPUT_CHARS = 1500;

// Class that has all the needed values for the textbox
class TextBox {
public:
	TextBox(float x, float y, float width, float height);
	void Draw();
	void Update();
	void ClearText();
	void UpdateTheText();
	char text[MAX_INPUT_CHARS + 1] = "\0";
	int letterCounter;
	Rectangle textbox;
	bool textboxActive;
private:
};