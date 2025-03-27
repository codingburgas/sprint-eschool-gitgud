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
	Homework(string text, std::vector<TextBox> textboxes);
	Homework(string text, std::vector<TextBox> textboxes, std::vector<Texture2D> image, std::vector<Vector2> imagePos);
	// Combines updating the interface state and rendering the visual components on the screen.
	void Display(bool& homeworkState);
	// Updates the state of the homework interface.
	void Update(bool& homeworkState);
	// Draws the homework interface components on the screen.
	void Draw();
	void ClearTextBoxes();
private:
	string homeworkText;
	Button exitButton = Button("images/exitButton.png", { 810, 390 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
	std::vector<TextBox> textBoxes;
	std::vector<Texture2D> tex;
	std::vector<Vector2> texPos;
	bool isHomeworkCompleted;
};