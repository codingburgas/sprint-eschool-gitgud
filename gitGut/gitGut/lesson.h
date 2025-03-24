
#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
using namespace std;


class Lesson
{
public:
	Lesson(string text, bool has3D);
	void Display(bool& lessonState, bool& is3Don);
	void Update(bool& lessonState, bool& is3Don);
	void Draw();
private:
	string lessonText;
	Button Mold3D = Button(400, 0, 150, 50, { 0,255,0,255 });
	bool include3D;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
};