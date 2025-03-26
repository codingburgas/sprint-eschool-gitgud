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
	void Display(bool& testState);
	void Update(bool& testState);
	void Draw();
private:
	string testText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
};