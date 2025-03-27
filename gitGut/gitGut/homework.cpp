#include "homework.h"


Homework::Homework(string text, std::vector<TextBox> textboxes) {
	homeworkText = text;
	homeworkText = text;
	textBoxes = textboxes;
	isHomeworkCompleted = false;
}

Homework::Homework(string text, std::vector<TextBox> textboxes, std::vector<Texture2D> image, std::vector<Vector2> imagePos)
{
	homeworkText = text;
	textBoxes = textboxes;
	tex = image;
	texPos = imagePos;
	isHomeworkCompleted = false;
}

// Displays the homework interface
void Homework::Display(bool& homeworkState)
{
	// Update the homework state
	Update(homeworkState);
	// Draw the homework components on the screen.
	Draw();
}

// Updates the homework state and handles users interaction
void Homework::Update(bool& homeworkState)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (!isHomeworkCompleted) {
		if (exitButton.isPressed(mousePos, isMousePressed))
		{
			homeworkState = false;
			ClearTextBoxes();
		}
		// Update the text box state
		for (TextBox& tb : textBoxes) {
			tb.Update();
			if (tb.isSelected()) {
				for (TextBox& tb2 : textBoxes)
					tb2.Unselect();
				tb.Select();
			}
		}
	}
}

// Draws the homework interface.
void Homework::Draw()
{
	DrawRectangle(0, 0, 960, 500, WHITE);
	DrawTextEx(mainFont, homeworkText.c_str(), { 20, 29 }, 26, 2, BLUE);
	
	for (size_t i = 0; i < tex.size(); i++) {
		DrawTexture(tex[i], texPos[i].x, texPos[i].y, WHITE);
	}

	// Draw the text box for user input
	for (TextBox tb : textBoxes)
		tb.Draw();
	// Draw the exit button
	exitButton.Draw();
}

void Homework::ClearTextBoxes() {
	for (TextBox& tb : textBoxes)
		tb.ClearText();
}
