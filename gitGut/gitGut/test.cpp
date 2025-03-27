#include "test.h"


// Initializes the test text with the string.
Test::Test()
{
	questionNum = QUESTION_1;
	points = 0;
}

// Combines the update method to handle interactions and the draw method to render the visuals.
void Test::Display(bool& testState)
{
	// Update the state of the test
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
			questionNum = QUESTION_6;
		}
		break;
	case QUESTION_6:
		if (questions[5].isAnswered(mousePos, isMousePressed)) {
			if (questions[5].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_7;
		}
		break;
	case QUESTION_7:
		if (questions[6].isAnswered(mousePos, isMousePressed)) {
			if (questions[6].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_8;
		}
		break;
	case QUESTION_8:
		if (questions[7].isAnswered(mousePos, isMousePressed)) {
			if (questions[7].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_9;
		}
		break;
	case QUESTION_9:
		if (questions[8].isAnswered(mousePos, isMousePressed)) {
			if (questions[8].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_10;
		}
		break;
	case QUESTION_10:
		if (questions[9].isAnswered(mousePos, isMousePressed)) {
			if (questions[9].isAnsweredRight(mousePos, isMousePressed)) points++;
			questionNum = QUESTION_0;
		}
		break;
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
		break;
	case QUESTION_6: questions[5].Draw();
		break;
	case QUESTION_7: questions[6].Draw();
		break;
	case QUESTION_8: questions[7].Draw();
		break;
	case QUESTION_9: questions[8].Draw();
		break;
	case QUESTION_10: questions[9].Draw();
	}
}

void Test::AddQuestion(Question q) {
	questions.push_back(q);
}

void Test::Reset() {
	points = 0;
	questionNum = QUESTION_1;
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

