#include "test.h"


Test::Test(string text)
{
	testText = text;

}

void Test::Display(bool& testState)
{
	Update(testState);
	Draw();
}

void Test::Update(bool& testState)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		testState = false;
	
	}
	

}

void Test::Draw()
{

	DrawRectangle(0, 0, 960, 500, BLUE);
	DrawText(testText.c_str(), 20, 100, 21, BLACK);
	exitButton.Draw("exit");
	



}
