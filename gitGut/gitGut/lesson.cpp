#include "lesson.h"
// Initializes the lesson text, heading, and whether the lesson includes a 3D model
Lesson::Lesson(string text, bool has3D, string heading)
{
	lessonText = text;
	lessonHeading = heading;
	include3D = has3D;
}
// Displays the lesson interface
void Lesson::Display(bool& lessonState, bool& is3Don, bool& isLessonLearnt)
{
	//Update the lesson state if 3D is on
	Update(lessonState, is3Don, isLessonLearnt);
	// Draws the lesson state
	Draw();
}

// Updates the state of the lesson interface.
void Lesson::Update(bool& lessonState, bool& is3Don, bool& isLessonLearnt)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		isLessonLearnt = true;
		lessonState = false;
		is3Don = false;
	}
	if (include3D) {
		if (Mold3D.isPressed(mousePos, isMousePressed)) is3Don = true;
	}
}
 // Draw the lesson interface
void Lesson::Draw()
{

	DrawRectangle(0, 0, 960, 500, WHITE);
	DrawTextEx(mainFont, lessonText.c_str(), { 20, 90 }, 21, 2, BLACK);
	DrawTextEx(mainFont, lessonHeading.c_str(), { 327, 30 }, 40, 2, RED);
	

	exitButton.Draw("exit");
	if (include3D) Mold3D.Draw("view 3D");



}
