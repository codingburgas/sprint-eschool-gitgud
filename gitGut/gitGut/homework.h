#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
#include "menu.h"
using namespace std;


class Homework
{
public:
	Homework(string text);
	void Display(bool& homeworkState);
	void Update(bool& homeworkState);
	void Draw();
private:
	string homeworkText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
};