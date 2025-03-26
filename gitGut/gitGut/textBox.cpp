#include "textBox.h"
#include <iostream>
using namespace std;

TextBox::TextBox(float x, float y, float width, float height) {
	letterCounter = 0;
	textbox = { (GetScreenWidth() / 2.f) - (width / 2), y, width, height };
	textboxActive = false;
}

// Draws the textbox on the screen
void TextBox::Draw() {
	DrawRectangleRec(textbox, LIGHTGRAY);
	if (textboxActive)
		DrawRectangleLinesEx(textbox, 4, RED);
	else
		DrawRectangleLinesEx(textbox, 4, BLACK);
	DrawText(text, textbox.x + 5, textbox.y + 8, 20, BLACK);
	cout << text << endl;
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

		if (key >= 39 and key <= 90 and letterCounter < MAX_INPUT_CHARS) {
			if (IsKeyDown(KEY_LEFT_SHIFT)) {
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

		if (letterCounter % 70 == 0) {
			text[letterCounter] = '\n';
			text[letterCounter + 1] = '\0';
			letterCounter++;
		}
	}

	if (IsKeyPressed(KEY_BACKSPACE)) {
		letterCounter--;
		if (letterCounter < 0)
			letterCounter = 0;
		text[letterCounter] = '\0';
	}
}

void TextBox::ClearText() {
	text[0] = '\0';
	letterCounter = 0;
}