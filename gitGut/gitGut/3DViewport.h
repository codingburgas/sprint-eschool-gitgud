#pragma once
#include "raylib.h"
#include "raymath.h"
#include "utils.h"
#include "button.h"
#include <vector>
#include <iostream>

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
	void RotateModel(Vector3 angle);
	void MoveModel(Vector3 coords);
	int getCameraFrame();
	Camera& getCamera();
	Model getModel();
private:
	Camera camera;
	Model model;
	int cameraFrame;
	bool isSliced;
	bool setX;
	bool setY;
	bool setZ;
	std::vector<cameraState> cameraStates;
};

class ThreeDimensionalViewport {
public:
	ThreeDimensionalViewport();
	void Display(SubjectStates subjectState, bool lessonState, bool& is3dOn);
	void Update(bool& is3dOn);
	void Draw(SubjectStates subjectState, bool lessonState);
	void addScene(const char* modelPath);
	void initializeScenes();
	void RotateObject(size_t scene, Vector3 angle);
	void MoveObject(size_t scene, Vector3 coords);
private:
	std::vector<Scene3D> scenes;
	Button exitButton = Button(1, 1, 60, 30, { 255, 0, 0, 255 });
	Button prevFrameButton = Button(0, 220, 30, 60, { 0, 255, 0, 255 });
	Button nextFrameButton = Button(930, 220, 30, 60, { 0, 255, 0, 255 });
};