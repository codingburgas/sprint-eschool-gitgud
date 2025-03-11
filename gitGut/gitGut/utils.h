#pragma once

enum ProgramStates {
	EXIT = 0,
	MAIN_MENU,
	SUBJECTS_MENU,
	ASSIGMENTS,
	SCHEDULE,
};

enum SubjectStates {
	NO_SUBJECT = 0,
	MATHS,
	ENGLISH,
	BIOLOGY,
	CHEMISTRY,
	PHYSICS,
	GEOGRAPHY
};

enum LearningStates {
	NO_LEARN = 0,
	LESSONS,
	EXERCISES,
	HOMEWORK,
	TESTS,
};

enum LessonState {
	LESSON_1,
	LESSON_2
};