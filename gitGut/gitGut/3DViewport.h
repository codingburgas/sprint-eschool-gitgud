#pragma once
#include "raylib.h"
#include "raymath.h"
#include "utils.h"
#include "button.h"
#include <vector>
#include <iostream>

// Structure to store camera position and target coordinates
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
	// Loads the 3D model and initializes the scene
	Scene3D(const char* modelPath);
	// Adds a new camera position and target to the scene
	void addCameraState(Vector3 pos, Vector3 tar);
	// Draws the 3D model in the viewport
	void drawModel();
	// Switches the camera to a specific frame 
	void switchCameraFrames(int cameraCurrentState);
	// Moves to the next camera state in the sequence
	void setNextCameraState();
	// Rotates the 3D model by a given angle
	void RotateModel(Vector3 angle);
	// Moves the 3D model to a new position 
	void MoveModel(Vector3 coords);
	// Returns the current camera frame index
	int getCameraFrame();
	// Provides access to the camera object for rendering
	Camera& getCamera();
	// Returns the 3D model object
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
	// Initializes the viewport and loads the 3D scene
	ThreeDimensionalViewport();
    // Displays the 3D viewport based on subject and lesson states
	void Display(SubjectStates subjectState, bool lessonState, bool& is3dOn);
    // Updates the viewport state, handling user interactions
	void Update(bool& is3dOn);
    // Draws the 3D scene and elements
	void Draw(SubjectStates subjectState, bool lessonState);
    // Adds a new 3D scene with a specified model
	void addScene(const char* modelPath);
    // Sets up camera positions for the scenes
	void initializeScenes();
    // Rotates the 3D model in the scene
	void RotateObject(size_t scene, Vector3 angle);
    // Moves the 3D model in the scene
	void MoveObject(size_t scene, Vector3 coords);
private:
	std::vector<Scene3D> scenes;
	Button exitButton = Button(1, 1, 60, 30, { 255, 0, 0, 255 });
	Button prevFrameButton = Button(0, 220, 30, 60, { 0, 255, 0, 255 });
	Button nextFrameButton = Button(930, 220, 30, 60, { 0, 255, 0, 255 });
};