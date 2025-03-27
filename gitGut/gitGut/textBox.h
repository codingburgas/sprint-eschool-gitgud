#pragma once
#include "raylib.h"

// Class that has all the needed values for the textbox
class TextBox {
public:
	TextBox(float x, float y, float width, float height, bool multiLine, int maxChars = 1500);
	TextBox() {};
	// Renders the TextBox on the screen
	void Draw();
	// Updates the TextBox state based on user interaction
	void Update();
	// Clears the text within the TextBox and resets the letter counter
	void ClearText();
	// Updates the text within the TextBox based on user input
	void UpdateTheText();
	bool isSelected();
	void Unselect();
	void Select();
private:
	char text[1500] = "\0";
	int letterCounter;
	Rectangle textbox;
	bool textboxActive;
	bool isMultiLine;
	int maxchars;
};