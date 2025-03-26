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
	void Display(bool& homeworkState);
	void Update(bool& homeworkState);
	void Draw();
private:
	string homeworkText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
	TextBox textBox;

};