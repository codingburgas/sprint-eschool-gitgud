#include "button.h"

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
Button::Button(const char* filePath, Vector2 position) :
	texture(LoadTexture(filePath)),
	rec{ (float)position.x, (float)position.y, (float)texture.width, (float)texture.height },
	hasTexture(true)
{
	rec.width = texture.width;
	rec.height = texture.height;
}
void Button::Draw(const char* text, int textPadding) const {

	if (this->hasTexture)
		DrawTexture(this->texture, this->rec.x, this->rec.y, WHITE);
	else {
		DrawRectangleRec(this->rec, this->color);
	float fontSize = findPerfectFontSize(rec, text, textPadding);
	Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 5.f);
	Vector2 textPos = { this->rec.x + ((this->rec.width - textSize.x) / 2),
						this->rec.y + ((this->rec.height - textSize.y) / 2) };

	DrawTextEx(GetFontDefault(), text, textPos, fontSize, 5.f, WHITE);
	}
}


bool Button::isPressed(Vector2 mousePos, bool isMousePressed) {
	if (CheckCollisionPointRec(mousePos, rec) && isMousePressed)
		return true;
	return false;
}

