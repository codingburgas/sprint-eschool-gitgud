#include <raylib.h>
#include "app.h"

int main() {
	InitWindow(960, 500, "Title");

	App* app = new App;
	app->Display();
	delete app;
}