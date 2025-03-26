#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
#include "menu.h"
#include "textBox.h"
using namespace std;


class Homework
{
public:
	Homework(string text, TextBox textbox);
	// Combines updating the interface state and rendering the visual components on the screen.
	void Display(bool& homeworkState);
	// Updates the state of the homework interface.
	void Update(bool& homeworkState);
	// Draws the homework interface components on the screen.
	void Draw();
private:
	string homeworkText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
	TextBox textBox;

};