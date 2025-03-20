#pragma once
#include "raylib.h"
#include "utils.h"
#include <vector>

#define NUM_LESSONS_IN_ONE_SUBJECT 5

struct cameraState {
	cameraState(Vector3 pos, Vector3 tar) :
		position(pos),
		target(tar)
	{}
	Vector3 position;
	Vector3 target;
};

class Scene3D {
public:
	Scene3D(const char* modelPath);
	void addCameraState(Vector3 pos, Vector3 tar);
	void drawModel();
	Camera& getCamera();
	Model getModel();
private:
	Camera camera; 
	Model model;
	cameraFrames3D cameraFrame;
	std::vector<cameraState> cameraStates;
};

class ThreeDimensionalViewport {
public:
	ThreeDimensionalViewport();
	void Display(SubjectStates subjectState, LessonState lessonState, bool is3dOn);
	void addScene(const char* modelPath);
	void initializeScenes();
private:
	std::vector<Scene3D> scenes;
};