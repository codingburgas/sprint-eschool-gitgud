#include "homework.h"


Homework::Homework(string text)
{
	homeworkText = text;
	
}

void Homework::Display(bool& homeworkState)
{
	Update(homeworkState);
	Draw();
}

void Homework::Update(bool& homeworkState)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		homeworkState = false;
	}
	textBox.Update();
}

void Homework::Draw()
{
	DrawRectangle(0, 0, 960, 500, GREEN);
	DrawTextEx(mainFont, homeworkText.c_str(), { 20, 100 }, 21, 2, WHITE);
	textBox.Draw();
	exitButton.Draw("exit");
}
