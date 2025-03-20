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
	BIOLOGY,
	CHEMISTRY,
	PHYSICS,
	MATHS,
	ENGLISH,
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
	LESSON_0,
	LESSON_1,
	LESSON_2
};

enum cameraFrames3D {
	FRAME_0,
	FRAME_1,
	FRAME_3,
	FRAME_4,
	FRAME_5
};