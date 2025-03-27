#include "textBox.h"
#include <iostream>
using namespace std;

TextBox::TextBox(float x, float y, float width, float height, bool multiLine, int maxChars) {
	letterCounter = 0;
	textbox = { x, y, width, height};
	textboxActive = false;
	isMultiLine = multiLine;
	maxchars = maxChars;
}

// Draws the textbox on the screen
void TextBox::Draw() {
	DrawRectangleRec(textbox, LIGHTGRAY);
	if (textboxActive)
		DrawRectangleLinesEx(textbox, 4, DARKBLUE);
	else
		DrawRectangleLinesEx(textbox, 4, BLACK);
	DrawText(text, textbox.x + 5, textbox.y + 8, 20, BLACK);
}

// Updates the textbox borders when clicked and call a function to update the text string
void TextBox::Update() {
	if (CheckCollisionPointRec(GetMousePosition(), textbox)) {
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			textboxActive = true;
	}
	else
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	if (textboxActive) {
		UpdateTheText();
	}
}

// Updates the text string
void TextBox::UpdateTheText() {
	int key = GetKeyPressed();
	while (key > 0) {

		if (key >= 39 && key <= 90 && letterCounter < maxchars) {
			if (IsKeyDown(KEY_LEFT_SHIFT) && key >= 65 && key <= 90) {
				text[letterCounter] = (char)key;
			}
			else {
				text[letterCounter] = (char)key + 32;
			}
				text[letterCounter + 1] = '\0';
				letterCounter++;
		}
		else if (key == 32) {
			text[letterCounter] = (char)key;
			text[letterCounter + 1] = '\0';
			letterCounter++;
		}
		key = GetKeyPressed();
		if (isMultiLine == true)
		{
			if (letterCounter % 65 == 0) {
				text[letterCounter] = '\n';
				text[letterCounter + 1] = '\0';
				letterCounter++;
			}
		}
		
	}

	if (IsKeyPressed(KEY_BACKSPACE)) {
		letterCounter--;
		if (letterCounter < 0)
			letterCounter = 0;
		text[letterCounter] = '\0';
	}
}

bool TextBox::isSelected()
{
	return textboxActive;
}

void TextBox::Unselect() {
	textboxActive = false;
}

void TextBox::Select() {
	textboxActive = true;
}

// Clears the text within the TextBox and resets the letter counter
void TextBox::ClearText() {
	text[0] = '\0';
	letterCounter = 0;
}