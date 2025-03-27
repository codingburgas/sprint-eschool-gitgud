#pragma once
#include <raylib.h>
#include "menu.h"
#include "3DViewport.h"
#include "utils.h"
#include "lesson.h"
#include "homework.h"
#include "test.h"

class App {
public:
	// Initializes the app state and default values
	App() : appState(MAIN_MENU),
		subjectState(NO_SUBJECT),
		lessonState(false),
		homeworkState(false),
		testState(false),
		is3dOn(false),
		day(NO_SCHEDULE)
	{
		V3D.RotateObject(0, { 1.f, 0.f, 0.f });
		V3D.MoveObject(0, { 0.f, 5.f, 0.f });

		mathTest.AddQuestion(Question(2, "What is 2 + 2?", "2", "4", "5", "7"));
		mathTest.AddQuestion(Question(3, "What is 2 + 3", "2", "4", "5", "7"));
		mathTest.AddQuestion(Question(4, "What is 5 + 2?", "2", "4", "5", "7"));
		mathTest.AddQuestion(Question(1, "What is 7 + 2?", "9", "4", "5", "7"));
		mathTest.AddQuestion(Question(3, "What is 1 + 4?", "2", "4", "5", "7"));

		englishTest.AddQuestion(Question(2, "She _____ to the store every Saturday.", "go", "goes", "going", "gone"));
		englishTest.AddQuestion(Question(3, "Which sentence is correct?", "I has a new book.", "She do not like pizza.", "We are going to the park.", "He have two dogs."));
		englishTest.AddQuestion(Question(3, "Select the correct sentence:", "He don’t like apples.", "They is very happy.", "She enjoys reading books.", "We was at the park."));
		englishTest.AddQuestion(Question(2, "I _____ my homework before dinner yesterday.", "do", "does", "did", "doing"));
		englishTest.AddQuestion(Question(4, "Which sentence is grammatically correct?", "There is many cars in the parking lot.", "He has a lot of friends.", "She have a big house.", "We was late to the meeting."));

		geographyTest.AddQuestion(Question(1, "What percentage of Earths surface is covered by water?", "71%", "90%", "30%", "85%"));
		geographyTest.AddQuestion(Question(1, "What gases make up Earth's atmosphere?", "78% nitrogen and 21% oxygen", "57% Carbon dyoxide and 53% Nitrogen", "30% Oxygen and 70% Nitrogen", "25% Oxygen and 85% Nitrogen"));
		geographyTest.AddQuestion(Question(4, "How long does it take for Earth to orbit the Sun?", "365 days", "366 days", "364 days", "365,25 days"));
		geographyTest.AddQuestion(Question(1, "How does Earth's magnetic field protect the planet?", "It stops the solar radiation", "It stabilises the temperature", "It doesn not protect our planet", "Other answer"));
		geographyTest.AddQuestion(Question(1, "How many degreees is the tilt of the Earth?", "23,5", "50", "10", "22.5"));

		physicsTest.AddQuestion(Question(1, "A car accelerates uniformly from 10 m/s to 30 m/s in 5 seconds. What is its acceleration?", "4m/s^2", "5m/s^2", "6m/s^2", "8m/s^2"));
		physicsTest.AddQuestion(Question(3, "Which of the following is NOT a fundamental force of nature?", "Gravitational Force", "Electromagnetic Force", "Frictional Force", "Weak Nuclear Force"));
		physicsTest.AddQuestion(Question(2, "A 2 kg object is lifted to a height of 10 meters. How much gravitational potential energy does it have? (Take g = 9.8 m/s^2)", "49 J", "98 J", "196 J", "20 J"));
		physicsTest.AddQuestion(Question(1, "What is the SI unit of electric resistance?", "Ohm", "Ampere", "Volt", "Farad"));
		physicsTest.AddQuestion(Question(3, "A car accelerates uniformly from 10 m/s to 30 m/s in 5 seconds. What is its acceleration?", "Newton’s First Law", "Newton’s Second Law", "Newton’s Third Law", "Law of Universal Gravitation"));

		biologyTest.AddQuestion(Question(2, "Which organelle is responsible for energy production in a cell?", "Nucleus", "Mithochondria", "Ribosome", "Golgi apparatus"));
		biologyTest.AddQuestion(Question(3, "Which of the following is NOT a characteristic of living organisms?", "Growth and development", "Response to stimuli", "Ability to photosynthesize", "Reproduction"));
		biologyTest.AddQuestion(Question(2, "What is the basic unit of structure and function in living organisms?", "Atom", "Cell", "Organ", "Tissue"));
		biologyTest.AddQuestion(Question(3, "Which biomolecule is responsible for storing genetic information?", "Lipids", "Proteins", "DNA", "Carbohydrates"));
		biologyTest.AddQuestion(Question(4, "Which blood component is responsible for oxygen transport?", "White blood cells", "Platelets", "Plasma", "Red blood cells"));

		chemistryTest.AddQuestion(Question(2, "What is the atomic number of carbon?", "Nucleus", "6", "12", "8 14"));
		chemistryTest.AddQuestion(Question(2, "Which of the following is an example of a noble gas?", "Oxygen", "Hydrogen", "Helium", "Nitrogen"));
		chemistryTest.AddQuestion(Question(2, "What type of bond is formed when two atoms share electrons?", "Ionic bond", "Covalent bond", "Hydrogen bond", "Metallic bond"));
		chemistryTest.AddQuestion(Question(2, "Which of the following substances has a pH less than 7?", "Water", "Sodium hydroxide", "Hydrochloric acid", "Ammonia"));
		chemistryTest.AddQuestion(Question(2, "Which organelle is responsible for energy production in a cell?", "Nucleus", "Mithochondria", "Ribosome", "Golgi apparatus"));

	}
	// Function to handle display logic
	void Display();
	// Function to update app state
	void Update();
	// Function to draw the current state of the app
	void Draw();
	// Function to handle drawing of lesson content
	void DrawLesson();
	// Function to handle drawing of homework assignments
	void DrawHomework();
	// Function to handle drawing of tests
	void DrawTest();


private:
	ProgramStates appState;
	SubjectStates subjectState;
	bool lessonState;
	int day;
	bool is3dOn;
	bool homeworkState;
	bool testState;
	Menu menu;
	ThreeDimensionalViewport V3D;
	Lesson biologyLesson = Lesson("The human heart is a muscular organ about the size of a fist, located slightly \n\nto the left  in the chest. It has four chambers: the right atrium and right\n\n ventricle pump  deoxygenated blood to the lungs, while the left atrium and left ventricle\n\npump  oxygenated blood to the body. \n\nThe heart works in two main circuits: the pulmonary circuit -to the lungs, and the \n\nsystemic circuit -to the rest of the body. The heart has four valves to ensure\n\n blood flows in the right direction : the tricuspid, pulmonary, mitral, and aortic valves.The \n\ncardiac cycle includes two phases:  systole(contraction) and diastole(relaxation).\n\n\nThe heart is controlled by an electrical system, with the SA node acting \n\nas the natural pacemaker.Blood vessels connected to the heart include\n\n arteries(carry blood away), veins(return blood), and capillaries(exchange nutrients). \n\n\nA healthy heart is crucial for circulation and overall health.", true, "HUMAN HEART");
	Lesson mathLesson = Lesson("A quadratic equation is a second-degree polynomial equation in a single variable, \n\n typically written in the form: ax2 + bx + c = 0, where a, b, c are constans and x \n\n represents the variable or unknown. The constant a cannot be zero, as that would \n\nmake the equation linear instead of quadratic. The graph of a quadratic equation \n\n is a parabola. If a > 0  the parabola opens upwards, and if a < 0, it opens downwards.                               \n\n\n Quadratic equations can have: two real roots (solutions) if the discriminant(b2 - 4ac) is \n\n positive. One real root if the discriminant is zero. No real roots, but two complex roots, \n\nif the discriminant is negative. The most general and widely applicable method for \n\nsolving quadratic equations is using the quadratic formula: x = (-b +|- cqr(D))/2a.\n\n\n The solutions to a quadratic equation correspond to the points where the\n\n parabola crosses the x-axis. These points can be found by graphing the equation and \n\nobserving the x-intercepts.  ", false, "QUADRATIC EQUATIONS");
	Lesson englishLesson = Lesson("The past perfect tense is used to describe an action that was completed before \n\n another action or point in the past. It’s often used to indicate which of two past events \n\nhappened first. The past perfect is formed with the following structure: \n\nSubject + had + past participle \n\n\n Usage: to show the first of two past actions, for reported speech, in conditional \n\nsentences, with time expressions like: By the time, before, after, when, already,\n\n yet, never, ever. \n\n\n Example: \n\n She had visited the museum before it closed. \n\n By the time I got to the party, everyone had gone home.", false, "PAST PERFECT TENSE");
	Lesson chemistryLesson = Lesson("Covalent bonds occur when two atoms share electrons to achieve a more stable \n\nelectron configuration.They typically form between nonmetals and can be classified into \n\nthree types : \n\n 1. Single Bond: One pair of electrons shared (e.g., H2). \n\n 2.Double Bond: Two pairs of electrons shared (e.g., O2). \n\n 3.Triple Bond: Three pairs of electrons shared (e.g., N2). \n\n\n Covalent bonds can be: Nonpolar - Electrons are shared equally (e.g., H2) or \n\n Polar - Electrons are shared unequally, creating a dipole (e.g., H2O). \n\n\n These bonds form molecules with low melting/boiling points and poor electrical \n\n conductivity. Examples include water (H?O) and methane (CH4).", true, "COVALENT BONDS");
	Lesson geographyLesson = Lesson("Earth is the third planet from the Sun, and the only one known to support life. \n\nIt has a radius of 6,371 km and is covered 71% by water. Its atmosphere consists \n\nmainly of nitrogen (78%) and oxygen (21%). \n\n\n Earth's surface is made up of continents and oceans, with a diverse range of \n\necosystems and climates, from tropical rainforests to polar ice caps. It rotates\n\n every 24 hours and orbits the Sun in about 365.25 days. \n\n\n The planet's geology is shaped by tectonic plates, and its core is made of iron \n\nand nickel, creating a magnetic field. Human activities are impacting Earth’s environment,\n\n leading to challenges like climate change. \n\n\nEarth has one natural satellite, the Moon, which affects tides and stabilizes \n\nthe planet’s tilt, contributing to a stable climate.", true, "PLANET EARTH");
	Lesson physicsLesson = Lesson("Electricity is the flow of electric charge, typically carried by electrons. Flow \n\nof charge, measured in amperes (A).  The push that drives current, measured in \n\nvolts (V). Opposition to current, measured in ohms (?). Rate of energy use, measured in \n\n watts (W) (P = VxI) \n\n\nTypes: \n\n Static Electricity: Buildup of charge (e.g., rubbing a balloon).\n\n Current Electricity: Flow of charge through conductors (e.g., in power lines).\n\n\n Sources: \n\n Batteries: Provide DC electricity. \n\n Power Plants: Produce AC electricity for long-distance transmission.\n\n\n Electricity powers everything from lights to machines! ", true, "ELECTRICITY");

	Homework mathHomework = Homework("Triangle ABC is a right triangle. Its leg AB is 3 cm and its hypotenuse is 5 cm.\n\n Find the second leg of the triangle.", { TextBox(130, 94, 250, 50, false, 10) });
	Homework englishHomework = Homework("Write me an essay about: The impact of social media, using past \n\nperfect tense. Maximum words:120-150", { TextBox(130, 94, 800, 380, true) });
	Homework chemistryHomework = Homework("Solve the chemical equations:", 
		{	TextBox(440, 160, 100, 35, false, 10),
			TextBox(418, 215, 100, 35, false, 10),
			TextBox(445, 265, 100, 35, false, 10),
			TextBox(435, 315, 100, 35, false, 10), },
		{LoadTexture("images/chemistryEx1.png"),
		LoadTexture("images/chemistryEx2.png"),
		LoadTexture("images/chemistryEx3.png"), 
		LoadTexture("images/chemistryEx4.png"),},
		{ {300, 100}, {300, 150},{300, 200},{300, 250} }
	);
	Homework physicsHomework = Homework("Name the parts of the scheme:", {
		TextBox(650, 100, 150, 30, false, 12),
		TextBox(530, 160, 150, 30, false, 12),
		TextBox(620, 260, 150, 30, false, 12),
		TextBox(530, 295, 150, 30, false, 12),
		TextBox(605, 380, 110, 30, false, 8) },
		{ LoadTexture("images/physicsScheme.png")},
		{ { 400.f, 100.f }}
	);
	Homework geographyHomework = Homework("Write me an essay about the global warming and why it is happening.\n\n Maximum words:120-150", { TextBox(130, 94, 800, 380, true) });
	Homework biologyHomework = Homework("Explain the different parts of the human heart.\n\n Maximum words:120-150 ", { TextBox(130, 94, 800, 380, true) });

	Test mathTest = Test();
	Test englishTest = Test();
	Test chemistryTest = Test();
	Test physicsTest = Test();
	Test geographyTest = Test();
	Test biologyTest = Test();



};