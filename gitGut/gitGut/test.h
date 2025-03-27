#pragma once
#include "raylib.h"
#include <string>
#include "button.h"
#include "utils.h"
#include "menu.h"
using namespace std;

class Question {
public:
	Question(int correctAnswer, string q, string answer1, string answer2, string answer3, string answer4);
	void Draw();
	bool isAnswered(Vector2 mousePos, bool mousePressed);
	bool isAnsweredRight(Vector2 mousePos, bool mousePressed);
private:
	std::vector<Button> answers;
	std::vector<string> answersStr;
	string question;
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
	int rightAnswer;
};

class Test
{
public:
	Test();
	// Calls the Update method for handling interactions and the Draw method for rendering the visuals.
	void Display(bool& testState);
	// Handles user interactions and updates the state of the tests interface
	void Update(bool& testState);
	// Includes the background, test text, and the "exit" button
	void Draw();
	void AddQuestion(Question q);
	void Reset();
private:
	string testText;
	Button exitButton = Button(810, 450, 150, 50, { 255, 0, 0, 255 });
	Font mainFont = LoadFontEx("fonts/Roboto-Regular.ttf", 100, 0, 250);
	std::vector<Question> questions;
	TestQuestions questionNum;
	int points;
};