#include "homework.h"


Homework::Homework(string text, TextBox textbox)
{
	homeworkText = text;
	textBox = textbox;
	
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
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		homeworkState = false;
	}
	// Update the text box state
	textBox.Update();
}

// Draws the homework interface.
void Homework::Draw()
{
	DrawRectangle(0, 0, 960, 500, WHITE);
	DrawTextEx(mainFont, homeworkText.c_str(), { 20, 29 }, 26, 2, BLUE);
	
	// Draw the text box for user input
	textBox.Draw();
	// Draw the exit button
	exitButton.Draw("exit");
}
