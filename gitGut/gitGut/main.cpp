#include <raylib.h>
#include "app.h"
using namespace std;

int main() {
	App* app = new App;
	app->Display();
	delete app;
}