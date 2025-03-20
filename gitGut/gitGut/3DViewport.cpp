#include "3DViewport.h"

ThreeDimensionalViewport::ThreeDimensionalViewport() {
	addScene("3d models/heart.glb");
	initializeScenes();
}

void ThreeDimensionalViewport::Display(SubjectStates subjectState, LessonState lessonState, bool is3dOn) {
	if (is3dOn) {
		UpdateCamera(&scenes[subjectState].getCamera(), CAMERA_FREE);
		ClearBackground(RAYWHITE);
		BeginDrawing();
		BeginMode3D(scenes[subjectState].getCamera());

		switch (subjectState) {
		case BIOLOGY:
			switch (lessonState) {
			case LESSON_1:
				scenes[subjectState * lessonState].drawModel();
				break;
			case LESSON_2:
				break;
			default:
				break;
			}
			break;
		case CHEMISTRY:
			break;
		case PHYSICS:
			break;
		}
		DrawGrid(0, 1.f);
		EndDrawing();
		EndMode3D();
	}
}

void ThreeDimensionalViewport::addScene(const char* modelPath) {
	scenes.push_back(Scene3D(modelPath));
}

void ThreeDimensionalViewport::initializeScenes() {
	scenes[0].addCameraState({ 5.f, 5.f, 5.f }, { 0.f, 0.f, 0.f });
}

Scene3D::Scene3D(const char* modelPath) {
	camera = { 0.f };
	model = LoadModel(modelPath);
	camera.position = {5.f, 5.f, 5.f};
	camera.fovy = 45.f;
	camera.projection = CAMERA_PERSPECTIVE;
	camera.target = { 0.f, 0.f, 0.f };
	camera.up = { 0.f, 1.f, 0.f };
	cameraFrame = FRAME_0;
}

void Scene3D::addCameraState(Vector3 pos, Vector3 tar) {
	cameraStates.push_back(cameraState(pos, tar));
}

void Scene3D::drawModel() {
	for (int i = 0; i < model.meshCount; i++) {
		DrawMesh(model.meshes[i], model.materials[i + 1], model.transform);
	}
}

Camera& Scene3D::getCamera()
{
	return camera;
}

Model Scene3D::getModel()
{
	return model;
}
