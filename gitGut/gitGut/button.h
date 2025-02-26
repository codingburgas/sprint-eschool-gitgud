#pragma once
#include "raylib.h"
#include <string>

float findPerfectFontSize(Rectangle container, const char* text, int textPadding);

class Button {
public:
	Button(int x, int y, int width, int height, Color col);
	Button(const char* filePath, Vector2 position);
	void Draw();
	void Draw(const char* text, int textPadding);
	bool isPressed(Vector2 mousePos, bool isMousePressed);
private:
	Rectangle rec;
	Color color;
	Texture2D texture;
	bool hasTexture;
};