#include "lesson.h"

Lesson::Lesson(string text, bool has3D, string heading )
{
	lessonText = text;
	lessonHeading = heading;
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
	if (include3D) {
		if (Mold3D.isPressed(mousePos, isMousePressed)) is3Don = true;
	}
}

void Lesson::Draw()
{

	DrawRectangle(0, 0, 960, 500, WHITE);
	DrawTextEx(mainFont, lessonText.c_str(), { 20, 90 }, 21, 2, BLACK);
	DrawTextEx(mainFont, lessonHeading.c_str(), { 327, 30 }, 40, 2, RED);
	

	exitButton.Draw("exit");
	if (include3D) Mold3D.Draw("view 3D");



}
