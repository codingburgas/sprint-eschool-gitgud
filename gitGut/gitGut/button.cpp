#include "button.h"
#include <iostream>

// Returns the font size which is perfect to fit a particular text in a certain container.
float findPerfectFontSize(Rectangle container, const char* text, int textPadding) {
	float fontSize = container.width;
	Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 5.f);

	for (int i = fontSize; i >= 1; i--) {
		textSize = MeasureTextEx(GetFontDefault(), text, i, 5.f);
		if (textSize.x < container.width - textPadding && textSize.y < container.height) {
			return (float)i;
		}

	}
	return 0.f;
}

Button::Button(int x, int y, int width, int height, Color col) {
	rec = { (float)x, (float)y, (float)width, (float)height};
	color = col;
	hasTexture = false;
}

Button::Button(const char *filePath, Vector2 position) {
	texture = LoadTexture(filePath);
	rec = { (float)position.x, (float)position.y, (float)texture.width, (float)texture.height };
	std::cout << rec.x << " " << rec.y << " " << rec.width << " " << rec.height << std::endl;
	hasTexture = true;
}

void Button::Draw() {
	if (hasTexture)
		DrawTexture(texture, rec.x, rec.y, WHITE);
	else
		DrawRectangleRec(rec, color);

}

void Button::Draw(const char* text, int textPadding) {
	DrawRectangleRec(rec, color);
	float fontSize = findPerfectFontSize(rec, text, textPadding);
	Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 5.f);
	DrawTextEx(GetFontDefault(), text, { rec.x + ((rec.width - textSize.x) / 2), rec.y + ((rec.height - textSize.y) / 2) }, fontSize, 5.f, WHITE);
}


bool Button::isPressed(Vector2 mousePos, bool isMousePressed) {
	if (CheckCollisionPointRec(mousePos, rec) && isMousePressed)
		return true;
	return false;
}

