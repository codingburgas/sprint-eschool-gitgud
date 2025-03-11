#pragma once
#include "raylib.h"

float findPerfectFontSize(Rectangle container, const char* text, int textPadding);

class Button {
public:
	Button(int x, int y, int width, int height, Color col):
		rec{ (float)x, (float)y, (float)width, (float)height },
		color(col), hasTexture(false) {}

	Button(const char* filePath, Vector2 position);
	void Draw(const char* text = nullptr, int textPadding = 0) const;
	bool isPressed(Vector2 mousePos, bool isMousePressed);
private:
	Rectangle rec;
	Color color;
	Texture2D texture;
	bool hasTexture;
};