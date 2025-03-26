#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
#include "menu.h"
using namespace std;

class Test
{
public:
	Test(string text);
	// Calls the Update method for handling interactions and the Draw method for rendering the visuals.
	void Display(bool& testState);
	// Handles user interactions and updates the state of the tests interface
	void Update(bool& testState);
	// Includes the background, test text, and the "exit" button
	void Draw();
private:
	string testText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
};