#include "app.h"

int main() {
	InitWindow(960, 500, "Title");

	App* app = new App;
	// Call the Display method of the App instance 
	app->Display();
	delete app;
}