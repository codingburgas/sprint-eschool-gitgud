#include "test.h"


// Initializes the test text with the string.
Test::Test()
{
	questionNum = START_TEST;
	points = 0;
}

// Combines the update method to handle interactions and the draw method to render the visuals.
void Test::Display(bool& testState)
{
	// Updates the state of the test
	Update(testState);
	// Draws the test interface
	Draw();
}

// Updates the test state.
void Test::Update(bool& testState)
{
	Vector2 mousePos = GetMousePosition();
	bool isMousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	if (exitButton.isPressed(mousePos, isMousePressed))
	{
		Reset();
		testState = false;
	}
	switch (questionNum)
	{
	case START_TEST:
		if (startButton.isPressed(mousePos, isMousePressed)) questionNum = QUESTION_1;
	break;
	case QUESTION_1:
		if (questions[0].isAnswered(mousePos, isMousePressed)) {
			if (questions[0].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_2;
		}
		break;
	case QUESTION_2:
		if (questions[1].isAnswered(mousePos, isMousePressed)) {
			if (questions[1].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_3;
		}
		break;
	case QUESTION_3:
		if (questions[2].isAnswered(mousePos, isMousePressed)) {
			if (questions[2].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_4;
		}
		break;
	case QUESTION_4:
		if (questions[3].isAnswered(mousePos, isMousePressed)) {
			if (questions[3].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_5;
		}
		break;
	case QUESTION_5:
		if (questions[4].isAnswered(mousePos, isMousePressed)) {
			if (questions[4].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_0;
		}
		
	}
}

// Displays the background, test text, and the "exit" button
void Test::Draw()
{
	DrawRectangle(0, 0, 960, 500, GREEN);
	DrawTextEx(mainFont, testText.c_str(), { 20, 100 }, 21, 2, WHITE);
	exitButton.Draw("exit");

	switch (questionNum)
	{
	case START_TEST:
		startButton.Draw("Start", 10);
		break;
	case QUESTION_0: DrawTextEx(mainFont, "Score:", {400.f, 0.f}, 50, 2, WHITE);
		DrawTextEx(mainFont, to_string(points).c_str(), { 400.f, 50.f }, 50, 2, WHITE);
		DrawTextEx(mainFont, "/10", {450.f, 50.f}, 50, 2, WHITE);
		break;
	case QUESTION_1: questions[0].Draw();
		break;
	case QUESTION_2: questions[1].Draw();
		break;
	case QUESTION_3: questions[2].Draw();
		break;
	case QUESTION_4: questions[3].Draw();
		break;
	case QUESTION_5: questions[4].Draw();
	}
}

void Test::AddQuestion(Question q) {
	questions.push_back(q);
}

void Test::Reset() {
	points = 0;
	questionNum = START_TEST;
}

Question::Question(int correctAnswer, string q, string question1, string question2, string question3, string question4) {
	rightAnswer = correctAnswer;
	answers = { Button(0, 75, 600, 75, {0, 0, 0, 255}),
				Button(0, 185, 600, 75, {0, 0, 0, 255}),
				Button(0, 295, 600, 75, {0, 0, 0, 255}),
				Button(0, 405, 600, 75, {0, 0, 0, 255})};
	answersStr = { question1, question2, question3, question4 };
	question = q;
}

void Question::Draw() {
	DrawTextEx(mainFont, question.c_str(), {0.f, 0.f}, 30, 2, WHITE);
	for (size_t i = 0; i < 4; i++)
		answers[i].Draw(answersStr[i].c_str(), 15);
}

bool Question::isAnswered(Vector2 mousePos, bool mousePressed) {
	for (size_t i = 0; i < 4; i++) {
		if (answers[i].isPressed(mousePos, mousePressed)) {
			return true;
		}
	}
	return false;
}

bool Question::isAnsweredRight(Vector2 mousePos, bool mousePressed) {
	
	if (answers[rightAnswer - 1].isPressed(mousePos, mousePressed))
		return true;
	return false;
}

