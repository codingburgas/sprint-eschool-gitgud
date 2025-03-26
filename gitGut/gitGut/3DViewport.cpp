#include "3DViewport.h"

#include "3DViewport.h"

// Initializes the 3D viewport 
ThreeDimensionalViewport::ThreeDimensionalViewport() {
	addScene("3d_models/heart.glb");
	initializeScenes();
}

// Displays the 3D viewport based on the subject and lesson state
void ThreeDimensionalViewport::Display(SubjectStates subjectState, bool lessonState, bool& is3dOn) {
	// Updates the viewport state based on user interaction
	Update(is3dOn);
	// Draws the 3D scene
	Draw(subjectState, lessonState);
}

// Updates the viewport state and check for button interactions
void ThreeDimensionalViewport::Update(bool& is3dOn) {
	Vector2 mousePos = GetMousePosition();
	bool isMouseClicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	if (exitButton.isPressed(mousePos, isMouseClicked))
		is3dOn = false;

	if (nextFrameButton.isPressed(mousePos, isMouseClicked))
		scenes[0].setNextCameraState();

	scenes[0].switchCameraFrames(scenes[0].getCameraFrame());
}

// Draws the 3D scene based on the subject and lesson states
void ThreeDimensionalViewport::Draw(SubjectStates subjectState, bool lessonState) {
	ClearBackground(RAYWHITE);
	BeginDrawing();

	BeginMode3D(scenes[0].getCamera());

	switch (subjectState) {
	case BIOLOGY:
		switch (lessonState) {
		case true:
			scenes[0].drawModel();
			break;

		}
		break;
	case CHEMISTRY:
		break;
	case PHYSICS:
		break;
	}
	DrawGrid(0, 1.f);
	EndMode3D();

	// Display text and buttons
	DrawText("Press H to slice", 5, 470, 30, DARKGRAY);

	exitButton.Draw("Exit", 10);
	prevFrameButton.Draw("<");
	nextFrameButton.Draw(">");


	EndDrawing();
}

// Adds a 3D scene by loading the specified model
void ThreeDimensionalViewport::addScene(const char* modelPath) {
	scenes.push_back(Scene3D(modelPath));
}

// Initializes predefined camera states for the scene
void ThreeDimensionalViewport::initializeScenes() {
	scenes[0].addCameraState({ 5.f, 5.f, 0.f }, { 0.f, 0.f, 0.f });
	scenes[0].addCameraState({ 5.f, 15.f, 5.f }, { 0.f, 0.f, 0.f });
	scenes[0].addCameraState({ 10.f, -5.f, 0.f }, { 0.f, 0.f, 0.f });
	scenes[0].addCameraState({ 5.f, 15.f, 5.f }, { 0.f, 0.f, 0.f });
	scenes[0].addCameraState({ 5.f, 15.f, 5.f }, { 0.f, 0.f, 0.f });

}

// Rotates the 3D model 
void ThreeDimensionalViewport::RotateObject(size_t scene, Vector3 angle) {
	scenes[scene].RotateModel(angle);
}

// Moves the 3D model
void ThreeDimensionalViewport::MoveObject(size_t scene, Vector3 coords) {
	scenes[scene].MoveModel(coords);
}

//Initializes the 3D scene, loads the model, and sets up the default camera
Scene3D::Scene3D(const char* modelPath = "") {
	camera = { 0.f };
	model = LoadModel(modelPath);
	camera.position = { 10.f, 5.f, 0.f };
	camera.fovy = 45.f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.target = { 0.f, 5.f, 0.f };
	camera.up = { 0.f, 1.f, 0.f };
	cameraFrame = FRAME_0;
	isSliced = false;
	setX = false;
	setY = false;
	setZ = false;
}

// Adds a new camera state to the scene
void Scene3D::addCameraState(Vector3 pos, Vector3 tar) {
	cameraStates.push_back(cameraState(pos, tar));
}

// Draws the 3D model, with an option to slice certain parts when 'H' is pressed
void Scene3D::drawModel() {
	if (IsKeyPressed(KEY_H)) isSliced = !isSliced;
	for (int i = 0; i < model.meshCount; i++) {
		if (isSliced) {
			if (i == 1 || i == 3) continue;
		}
		DrawMesh(model.meshes[i], model.materials[i + 1], model.transform);
	}
	DrawGrid(30, 1.f);
}

// Updates the camera position and target based on the current camera frame
void Scene3D::switchCameraFrames(int cameraCurrentState) {
	
	camera.position = cameraStates[cameraCurrentState].position;
	camera.target = cameraStates[cameraCurrentState].target;

}

// Moves to the next predefined camera state
void Scene3D::setNextCameraState() {
	if (cameraFrame == int(cameraStates.size()) - 1) cameraFrame = 0;
	else cameraFrame++;
}

// Rotates the model using a transformation matrix
void Scene3D::RotateModel(Vector3 angle) {
	model.transform = MatrixMultiply(model.transform, MatrixRotateXYZ(angle));
}

// Moves the model by applying a translation matrix
void Scene3D::MoveModel(Vector3 coords) {
	model.transform = MatrixMultiply(model.transform, MatrixTranslate(coords.x, coords.y, coords.z));
}

// Returns the current camera frame index
int Scene3D::getCameraFrame()
{
	return cameraFrame;
}

// Returns the camera object for rendering
Camera& Scene3D::getCamera()
{
	return camera;
}

// Returns the 3D model object
Model Scene3D::getModel()
{
	return model;
}
