#include "lesson.h"

Lesson::Lesson(string text, bool has3D)
{
	lessonText = text;
	include3D = has3D;
}

void Lesson::Display(bool& lessonState, bool& is3Don)
{
	Update(lessonState, is3Don);
	Draw();
}

void Lesson::Update(bool& lessonState, bool& is3Don)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		lessonState = false;
		is3Don = false;
	}
	if (Mold3D.isPressed(mousePos, isMousePressed))
	{
		is3Don = true;
	}

}

void Lesson::Draw()
{

	DrawRectangle(0, 0, 960, 500, BLUE);
	DrawTextEx(mainFont, lessonText.c_str(), { 20, 100 }, 21, 2, WHITE);
	exitButton.Draw("exit");
	if (include3D) Mold3D.Draw("view 3D");



}
