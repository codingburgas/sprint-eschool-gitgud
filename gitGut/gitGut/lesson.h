#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
#include "menu.h"
using namespace std;


class Lesson
{
public:
	// Constructor for the Lesson class
	Lesson(string text, bool has3D, string heading);
	// Handles the display of the lesson interface.
	void Display(bool& lessonState, bool& is3Don);
	// Updates the state of the lesson interface.
	void Update(bool& lessonState, bool& is3Don);
	// Draws the lesson interface components.
	void Draw();
private:
	string lessonText;
	string lessonHeading;
	Button Mold3D = Button(630, 450, 150, 50, { 0,255,0,255 });
	bool include3D;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });

	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
};