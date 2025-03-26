#pragma once
#include "raylib.h"
constexpr int MAX_INPUT_CHARS = 1500;

// Class that has all the needed values for the textbox
class TextBox {
public:
	TextBox(float x, float y, float width, float height, bool multiLine);
	TextBox() {};
	// Renders the TextBox on the screen
	void Draw();
	// Updates the TextBox state based on user interaction
	void Update();
	// Clears the text within the TextBox and resets the letter counter
	void ClearText();
	// Updates the text within the TextBox based on user input
	void UpdateTheText();
	
private:
	char text[MAX_INPUT_CHARS + 1] = "\0";
	int letterCounter;
	Rectangle textbox;
	bool textboxActive;
	bool isMultiLine;
};