#pragma once
#include "raylib.h"
#include "utils.h"
#include "button.h"
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
	void switchCameraFrames(int cameraCurrentState);
	void setNextCameraState();
	int getCameraFrame();
	Camera getCamera();
	Model getModel();
private:
	Camera camera; 
	Model model;
	int cameraFrame;
	std::vector<cameraState> cameraStates;
};

class ThreeDimensionalViewport {
public:
	ThreeDimensionalViewport();
	void Display(SubjectStates subjectState, LessonState lessonState, bool& is3dOn);
	void Update(bool& is3dOn);
	void Draw(SubjectStates subjectState, LessonState lessonState);
	void addScene(const char* modelPath);
	void initializeScenes();
private:
	std::vector<Scene3D> scenes;
	Button exitButton = Button(1, 1, 60, 30, {255, 0, 0, 255});
	Button prevFrameButton = Button(0, 220, 30, 60, { 0, 255, 0, 255 });
	Button nextFrameButton = Button(930, 220, 30, 60, { 0, 255, 0, 255 });
};