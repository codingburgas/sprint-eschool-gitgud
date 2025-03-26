#include "test.h"


// Initializes the test text with the string.
Test::Test(string text)
{
	testText = text;

}

// Combines the update method to handle interactions and the draw method to render the visuals.
void Test::Display(bool& testState)
{
	// Update the state of the test
	Update(testState);
	// Draws the test interface
	Draw();
}

// Updates the test state.
void Test::Update(bool& testState)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		testState = false;
	}
}

// Displays the background, test text, and the "exit" button
void Test::Draw()
{

	DrawRectangle(0, 0, 960, 500, GREEN);
	DrawTextEx(mainFont, testText.c_str(), { 20, 100 }, 21, 2, WHITE);
	exitButton.Draw("exit");
}
