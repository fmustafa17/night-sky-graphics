/******************************************************************************
*
* Official Name:  Farhana Mustafa
*
* E-mail:  fmustafa@syr.edu
*
* Assignment:  Homework 2
*
* Environment/Compiler:  Visual Studio 2015
*
* Date:  February 20, 2018
*
* References:  none
*
* Interactions: 
For the stellar objects:
	Press a to select the Hubble Telescope
	Press s to see a spaceship
	Press d to wish upon a shooting star
	Press f to select Orion's Belt
	Press g to hear an awesome joke
For the moon:
	Press z to select the New Moon phase
	Press x to select the Crescent Moon phase
	Press c to select the Half Moon phase
	Press v to select the Gibbous Moon phase
	Press b to select the Full Moon phase

Press the Escape key to exit
******************************************************************************/

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265
#define INACTIVE 0
#define NEWMOON 1
#define CRESENTMOON 2
#define HALFMOON 3
#define GIBBMOON 4
#define FULLMOON 5

// Use the STL extension of C++.
using namespace std;

// Globals.
static int GUI, displaySky; // Window identifiers.
static GLsizei width, height; // OpenGL window size.
static int primitive = FULLMOON; // Current drawing primitive.

static int hubbleToggle = 0;
static int shipToggle = 0;
static int starToggle = 0;
static int beltToggle = 0;
static int badJokeToggle = 0;

static long font = (long)GLUT_BITMAP_8_BY_13; //Fonts
static float R = 6.0; // Radius of moon.
static int v = 10; // Number of longitudinal (verticle) slices.
static int h = 10; // Number of latitudinal (horizontal) slices 

static float X = 75.0; // X-coordinate of center of circle.
static float Y = 80.0; // Y-coordinate of center of circle.
static int numVertices = 30; // Number of vertices on circle.

static float stars[] =
{
	5.0, 2.0, 0.0,
	4.0, 10.0, 0.0,
	20.0, 60.0, 0.0,
	50.0, 7.0, 0.0,
	20.0, 20.0, 0.0,
	5.0, 2.0, 0.0,
};

//color array
static float colors[] =
{
	//0.0, 0.0, 0.0,
	1.0, 0.0, 0.0,
	0.0, 1.0, 0.0,
	0.0, 0.0, 1.0
};

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{
	char *c;

	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void drawMoon() {
	//double eqn0[4] = { 0.0, 0.0, -1.0, 0.25 };
	double eqn0[4] = { 100.0, -0.5, -1.0, 0.0 }; // Data for clipping plane 0.
	double eqn1[4] = { 500.0, -0.5, -1.0, 1.0 }; // Data for clipping plane 1.

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPolygonMode(GL_FRONT, GL_FILL);

	if (primitive == FULLMOON) {
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(65.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);
		glutSolidSphere(30.0, 30, 30);
	glPopMatrix();
	}

	if (primitive == NEWMOON) {
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(65.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);
		glutSolidSphere(30.0, 30, 30);
		glPopMatrix();
	}

	if (primitive == HALFMOON) {
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(65.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);

		glClipPlane(GL_CLIP_PLANE0, eqn0);
		glEnable(GL_CLIP_PLANE0);
		glutSolidSphere(30.0, 30, 30);
		glDisable(GL_CLIP_PLANE0);
		glPopMatrix();
	}

	if (primitive == GIBBMOON) {
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(65.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);

		glutSolidSphere(30.0, 30, 30);
		glPopMatrix();


		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(55.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);

		glClipPlane(GL_CLIP_PLANE1, eqn1);
		glEnable(GL_CLIP_PLANE1);
		glutSolidSphere(30.0, 30, 30);
		glDisable(GL_CLIP_PLANE1);
		glPopMatrix();
	}

	if (primitive == CRESENTMOON) {

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(65.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);

		glClipPlane(GL_CLIP_PLANE0, eqn0);
		glEnable(GL_CLIP_PLANE0);
		glutSolidSphere(30.0, 30, 30);
		glDisable(GL_CLIP_PLANE0);
		glPopMatrix();


		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslatef(63.0, 75.0, 0.0);
		glTranslatef(0.0, 10.0, -20.0);
		glRotatef(90.0, 20.0, 0.0, 0.0);
		glTranslatef(0.0, -10.0, 20.0);

		glClipPlane(GL_CLIP_PLANE1, eqn1);
		glEnable(GL_CLIP_PLANE1);
		glutSolidSphere(30.0, 30, 30);
		glDisable(GL_CLIP_PLANE1);
		glPopMatrix();
	}
	
}

void drawSelectionBoxes(void) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (int i = 0; i < 50; i += 10) {
		glBegin(GL_POLYGON);
		glVertex3f(5.0, 80.0 - i, 0.0);
		glVertex3f(7.5, 80.0 - i, 0.0);
		glVertex3f(7.5, 85.0 - i, 0.0);
		glVertex3f(5.0, 85.0 - i, 0.0);
		glEnd(); 
	}

	if (hubbleToggle) {
		//Stipple
		glEnable(GL_LINE_STIPPLE); // Enable line stippling.
		glRasterPos3f(6.0, 81.0, 0.0);
		glLineStipple(5, 0x00FF);

		glBegin(GL_LINES);
		glVertex3f(5.0, 80.0, 0.0);
		glVertex3f(7.5, 85.0, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(5.0, 85.0, 0.0);
		glVertex3f(7.5, 80.0, 0.0);
		glEnd();

		glDisable(GL_LINE_STIPPLE); // Disable line stippling.
	}

	if (shipToggle) {
		//Stipple
		glEnable(GL_LINE_STIPPLE); // Enable line stippling.
		glRasterPos3f(6.0, 81.0, 0.0);
		glLineStipple(5, 0x00FF);

		glBegin(GL_LINES);
		glVertex3f(5.0, 80.0 - 10, 0.0);
		glVertex3f(7.5, 85.0 - 10, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(5.0, 85.0 - 10, 0.0);
		glVertex3f(7.5, 80.0 - 10, 0.0);
		glEnd();

		glDisable(GL_LINE_STIPPLE); // Disable line stippling.
	}

	if (starToggle) {
		//Stipple
		glEnable(GL_LINE_STIPPLE); // Enable line stippling.
		glRasterPos3f(6.0, 81.0, 0.0);
		glLineStipple(5, 0x00FF);

		glBegin(GL_LINES);
		glVertex3f(5.0, 80.0 - 20, 0.0);
		glVertex3f(7.5, 85.0 - 20, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(5.0, 85.0 - 20, 0.0);
		glVertex3f(7.5, 80.0 - 20, 0.0);
		glEnd();

		glDisable(GL_LINE_STIPPLE); // Disable line stippling.
	}

	if (beltToggle) {
		//Stipple
		glEnable(GL_LINE_STIPPLE); // Enable line stippling.
		glRasterPos3f(6.0, 81.0, 0.0);
		glLineStipple(5, 0x00FF);

		glBegin(GL_LINES);
		glVertex3f(5.0, 80.0 - 30, 0.0);
		glVertex3f(7.5, 85.0 - 30, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(5.0, 85.0 - 30, 0.0);
		glVertex3f(7.5, 80.0 - 30, 0.0);
		glEnd();

		glDisable(GL_LINE_STIPPLE); // Disable line stippling.
	}

	if (badJokeToggle) {
		//Stipple
		glEnable(GL_LINE_STIPPLE); // Enable line stippling.
		glRasterPos3f(6.0, 81.0, 0.0);
		glLineStipple(5, 0x00FF);

		glBegin(GL_LINES);
		glVertex3f(5.0, 80.0 - 40, 0.0);
		glVertex3f(7.5, 85.0 - 40, 0.0);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(5.0, 85.0 - 40, 0.0);
		glVertex3f(7.5, 80.0 - 40, 0.0);
		glEnd();

		glDisable(GL_LINE_STIPPLE); // Disable line stippling.
	}
}

void drawEmptyRadioButtons() {
	float t = 0; // Angle parameter.
	int i;

	float p = 35.0;
	float q = 82.5;
	float radius = 1.5;

	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (int j = 0; j < 50; j += 10) {
		glBegin(GL_POLYGON);
		for (i = 0; i < numVertices; ++i)
		{
			glVertex3f(p + radius * cos(t), q + radius * sin(t) - j, 0.0);
			t += 2 * PI / numVertices;
		}
		glEnd();
	}


	//glFlush();
}

void drawSelectedRadioButton() {
	float t = 0; // Angle parameter.
	int i;

	float p = 35.0;
	float q = 0.0;
	float radius = 0.9;


	if (primitive == NEWMOON) {
		q = 82.5;
	}

	if (primitive == CRESENTMOON) {
		q = 82.5 - 10;
	}

	if (primitive == HALFMOON) {
		q = 82.5 - 20;
	}

	if (primitive == GIBBMOON) {
		q = 82.5 - 30;
	}
	
	if (primitive == FULLMOON) {
		q = 82.5 - 40;
	}

		glColor3f(0.0, 0.0, 0.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


		glBegin(GL_POLYGON);
		for (i = 0; i < numVertices; ++i)
		{
			glVertex3f(p + radius * cos(t), q + radius * sin(t), 0.0);
			t += 2 * PI / numVertices;
		}
		glEnd();

}

void addAllText() {
	glColor3f(1.0, 0.3, 0.7); // Font Color
	glRasterPos3f(33.0, 90.0, 0.0);
	writeBitmapString((void*)font, "Moon Phase");

	glRasterPos3f(39.0, 81.5, 0.0);
	writeBitmapString((void*)font, "New");
	glRasterPos3f(39.0, 71.5, 0.0);
	writeBitmapString((void*)font, "Crescent");
	glRasterPos3f(39.0, 61.5, 0.0);
	writeBitmapString((void*)font, "Half");
	glRasterPos3f(39.0, 51.5, 0.0);
	writeBitmapString((void*)font, "Gibbous");
	glRasterPos3f(39.0, 41.5, 0.0);
	writeBitmapString((void*)font, "Full");

	glRasterPos3f(9.0, 90.0, 0.0);
	writeBitmapString((void*)font, "Steller Objects");

	glRasterPos3f(9.0, 81.5, 0.0);
	writeBitmapString((void*)font, "Hubble Telescope");
	glRasterPos3f(9.0, 71.5, 0.0);
	writeBitmapString((void*)font, "ALIEN SPACESHIP SIGHTING");
	glRasterPos3f(9.0, 61.5, 0.0);
	writeBitmapString((void*)font, "Comet");
	glRasterPos3f(9.0, 51.5, 0.0);
	writeBitmapString((void*)font, "Orion's Belt");
	glRasterPos3f(9.0, 41.5, 0.0);
	writeBitmapString((void*)font, "Wanna hear a joke?");

	glRasterPos3f(19, 2, 0.0);
	writeBitmapString((void*)font, "Farhana Mustafa");
}

void drawHubble() {
	if (hubbleToggle) {
		glColor3f(0.658824, 0.658824, 0.658824);
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 90.0, 0.0);
		glVertex3f(25.0, 95.0, 0.0);
		glVertex3f(30.0, 85.0, 0.0);
		glEnd();

		glColor3f(0.184314, 0.309804, 0.309804);
		glBegin(GL_POLYGON);
		glVertex3f(20.0, 80.0, 0.0);
		glVertex3f(40.0, 80.0, 0.0);
		glVertex3f(40.0, 85.0, 0.0);
		glVertex3f(20.0, 85.0, 0.0);
		glVertex3f(20.0, 80.0, 0.0);
		glEnd();

		glColor3f(0.658824, 0.658824, 0.658824);
		glBegin(GL_POLYGON);
		glVertex3f(30.0, 80.0, 0.0);
		glVertex3f(30.0, 64.0, 0.0);
		glVertex3f(30.0, 69.0, 0.0);
		glVertex3f(35.0, 70.0, 0.0);
		glEnd();
	}
	else {

	}
}

void drawJoke() {
	if (badJokeToggle) {
		glColor3f(1.0, 1.0, 1.0);

		glPushMatrix();
		glTranslatef(3.0, 15.0, 0.0);
		glScalef(0.025, 0.025, 0.025);
		writeStrokeString(GLUT_STROKE_MONO_ROMAN, "Orion's Belt is a big waist of Space. I know, terrible Joke. I give it Three Stars.");
		glPopMatrix();

		glPushMatrix();
		glTranslatef(3.0, 11.0, 0.0);
		glScalef(0.02, 0.02, 0.02);
		writeStrokeString(GLUT_STROKE_MONO_ROMAN, "I know, terrible joke. I give it Three Stars.");
		glPopMatrix();
	}

}

void drawBelt() {
	if (beltToggle) {
		float t = 0;
		int i;

		glColor3f(1.0, 1.0, 1.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		for (int j = 0; j < 15; j += 5) {
			glBegin(GL_POLYGON);
			for (i = 0; i < numVertices; ++i)
			{
				glVertex3f(X + 0.5 * cos(t) + j, 20 + 0.5 * sin(t) + j, 0.0);
				t += 2 * PI / numVertices;
			}
			glEnd();
		}
	}
}

void drawSpaceship() {

	if (shipToggle) {
		glColor3f(1.0, 1.0, 1.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		glBegin(GL_POLYGON);

		for (int i = 0; i < 8; ++i) glArrayElement(i % 8);

		glEnd();

		glFlush();

	}

}

void drawStars() {
	float t = 0.0;
	glColor3f(1.0, 1.0, 1.0);
		if(starToggle) {
			glBegin(GL_POLYGON);
			for (int j = 0; j < 100; j += 10) {
				for (int i = 0; i < numVertices; ++i)
				{
					glVertex3f(80 + 0.5 * cos(t) + j, 80 + 0.5 * sin(t) + j, 0.0);
					t += 2 * PI / numVertices;
				}
			}

			glEnd();
				
		}
}

// The mouse callback routine.
void mouseControl(int button, int state, int x, int y)
{
	y = height - y; // Correct from mouse to OpenGL co-ordinates.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if ( x >= 335 && x <= 365 && y >= -90 && y <= -80) 
		{
			primitive = NEWMOON;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		if (x >= 335 && x <= 365 && y >= -145 && y <= -130)
		{
			primitive = CRESENTMOON;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		if (x >= 335 && x <= 365 && y >= -195 && y <= -180) {
			primitive = HALFMOON;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		if (x >= 335 && x <= 365 && y >= -245 && y <= -230)
		{
			primitive = GIBBMOON;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		if (x >= 335 && x <= 365 && y >= -295 && y <= -280)
		{
			primitive = FULLMOON;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}

		// Click on selection boxes
		if (x >= 50.0  && x <= 75 && y >= -100 && y <= -75.0)
		{
			hubbleToggle = !hubbleToggle;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}

		if (x  >= 50 && x <= 75 && y >= -150 && y <= -125)
		{
			shipToggle = !shipToggle;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}

		if (x >= 50 && x <= 75 && y >= -200 && y <= -175)
		{
			starToggle = !starToggle;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}

		if (x >= 50 && x <= 75 && y >= -250 && y <= -225)
		{
			beltToggle = !beltToggle;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		
		if (x >= 50 && x <= 75 && y >= -300 && y <= -275)
		{
			badJokeToggle = !badJokeToggle;
			glutSetWindow(displaySky);
			glutPostRedisplay();
		} 
	}

	glutSetWindow(GUI);
	glutPostRedisplay();
	
}

void top_menu(int id)
{
	if (id == 1) exit(0);
}

// The sub-menu callback function.
void sky_menu(int id)
{
	if (id == 2) //Day
	{
		glClearColor(0.196078, 0.6, 0.8, 0.0);
	}
	if (id == 3) //Night
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
	}

	glutPostRedisplay();
}

void rotateSky_menu(int id)
{
	if (id == 4) //90 Degrees
	{
		glPushMatrix();
		glRotatef(90, 0.0, 0.0, 0.0);
		glPopMatrix();
	}
	if (id == 5) //180 Degrees
	{
		glPushMatrix();
		glRotatef(180, 0.0, 0.0, 0.0);
		glPopMatrix();
	}

	glutPostRedisplay();
}

void changeMoon_menu(int id)
{
	if (id == 6) //Bigger 
	{
		glColor3f(1.0, 1.0, 1.0);
		glutSolidSphere(400.0, 30, 30);
		/*glPushMatrix();
			glTranslatef(65.0, 75.0, 0.0);
			glTranslatef(0.0, 10.0, -20.0);
			glRotatef(90.0, 20.0, 0.0, 0.0);
			glTranslatef(0.0, -10.0, 20.0);

			glScalef(0.025, 0.025, 0.025);
			glutSolidSphere(40.0, 30, 30);
		glPopMatrix();*/
	}
	if (id == 7) //Smaller 
	{

	}

	glutPostRedisplay();
}

// Routine to make the menu.
void makeMenu(void)
{
	// The sub-menu is created first (because it should be visible when the top
	// menu is created): its callback function is registered and menu entries added.
	int sub_menu;
	sub_menu = glutCreateMenu(sky_menu);
	glutAddMenuEntry("Day", 2);
	glutAddMenuEntry("Night", 3);
	
	int sub_menu1;
	sub_menu1 = glutCreateMenu(rotateSky_menu);
	glutAddMenuEntry("90 Degrees", 4);
	glutAddMenuEntry("180 Degrees", 5);

	int sub_menu2;
	sub_menu2 = glutCreateMenu(changeMoon_menu);
	glutAddMenuEntry("Bigger", 6);
	glutAddMenuEntry("Smaller", 7);

	// The top menu is created: its callback function is registered and menu entries,
	// including a submenu, added.
	glutCreateMenu(top_menu);
	glutAddSubMenu("Day Or Night", sub_menu);
	glutAddSubMenu("Rotate Sky", sub_menu1);
	glutAddSubMenu("Change Moon Size", sub_menu2);

	glutAddMenuEntry("Quit", 1);

	// The menu is attached to a mouse button.
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Drawing routine.
void drawSceneGUI(void)
{
	// Choose window.
	glutSetWindow(GUI);

	glClear(GL_COLOR_BUFFER_BIT);

	addAllText();

	//Moon
	drawEmptyRadioButtons();
	drawSelectedRadioButton();

	//Steller Objects
	drawSelectionBoxes();


	glFlush();
}

void drawSceneDisplaySky(void)
{
	// Choose window.
	glutSetWindow(displaySky);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	drawMoon();
	drawHubble();
	drawSpaceship();
	drawStars();
	drawBelt();
	drawJoke();

	glFlush();
}

// Initialization routine for first window.
void setupGUI(void)
{
	// White background.
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Initialization routine for second window.
void setupDisplaySky(void)
{
	// Black background.
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Enable two vertex arrays: co-ordinates and color.
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Specify locations for the co-ordinates and color arrays.
	glVertexPointer(3, GL_FLOAT, 0, stars);
	glColorPointer(3, GL_FLOAT, 0, colors);
}

// Reshape routine for first window.
void resizeGUI(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Non-square aspect ratio squashes the square.
	glOrtho(0.0, 50.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Reshape routine for second window.
void resizeDisplaySky(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine shared by both windows.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'a':
		glutSetWindow(GUI);
		hubbleToggle = !hubbleToggle;
		glutPostRedisplay();
		glutSetWindow(displaySky);
		glutPostRedisplay();
		break;
	case 's':
		glutSetWindow(GUI);
		shipToggle = !shipToggle;
		glutPostRedisplay();
		glutSetWindow(displaySky);
		glutPostRedisplay();
		break;
	case 'd':
		glutSetWindow(GUI);
		starToggle = !starToggle;
		glutPostRedisplay();
		glutSetWindow(displaySky);
		glutPostRedisplay();
		break;
	case 'f':
		glutSetWindow(GUI);
		beltToggle = !beltToggle;
		glutPostRedisplay();
		glutSetWindow(displaySky);
		glutPostRedisplay();
		break;
	case 'g':
		glutSetWindow(GUI);
		badJokeToggle = !badJokeToggle;
		glutPostRedisplay();
		glutSetWindow(displaySky);
		glutPostRedisplay();
		break;
	case 'z':
		if (primitive != NEWMOON)
		{
			glutSetWindow(GUI);
			primitive = NEWMOON;
			glutPostRedisplay();
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		else;
		break;
	case 'x':
		if (primitive != CRESENTMOON)
		{
			glutSetWindow(GUI);
			primitive = CRESENTMOON;
			glutPostRedisplay();
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		else;
		break;
	case 'c':
		if (primitive != HALFMOON)
		{
			glutSetWindow(GUI);
			primitive = HALFMOON;
			glutPostRedisplay();
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		else;
		break;
	case 'v':
		if (primitive != GIBBMOON)
		{
			glutSetWindow(GUI);
			primitive = GIBBMOON;
			glutPostRedisplay();
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		else;
		break;
	case 'b':
		if (primitive != FULLMOON)
		{
			glutSetWindow(GUI);
			primitive = FULLMOON;
			glutPostRedisplay();
			glutSetWindow(displaySky);
			glutPostRedisplay();
		}
		else;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	cout << "Interactions:" << endl;
	cout << "" << endl;
	cout << "For the stellar objects:" << endl;
	cout << "Press a to select the Hubble Telescope" << endl;
	cout << "Press s to see a spaceship" << endl;
	cout << "Press d to wish upon a shooting star" << endl;
	cout << "Press f to select Orion's Belt" << endl;
	cout << "Press g to hear an awesome joke" << endl;
	cout << "" << endl;
	cout << "For the moon:" << endl;
	cout << "Press z to select the New Moon phase" << endl;
	cout << "Press x to select the Crescent Moon phase" << endl;
	cout << "Press c to select the Half Moon phase" << endl;
	cout << "Press v to select the Gibbous Moon phase" << endl;
	cout << "Press b to select the Full Moon phase" << endl;
	cout << "" << endl;
	cout << "Press the Escape key to exit" << endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// First top-level window definition.
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	// Create the first window and return id.
	GUI = glutCreateWindow("The Gooey");

	// Initialization, display, and other routines of the first window. 
	setupGUI();
	glutDisplayFunc(drawSceneGUI);
	glutReshapeFunc(resizeGUI);
	glutKeyboardFunc(keyInput); // Routine is shared by both windows.
	glutMouseFunc(mouseControl);

	// Second top-level window definition.
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(610, 100);

	// Create the second window and return id.
	displaySky = glutCreateWindow("Night Sky");

	// Initialization, display, and other routines of the second window. 
	setupDisplaySky();
	glutDisplayFunc(drawSceneDisplaySky);
	glutReshapeFunc(resizeDisplaySky);
	glutKeyboardFunc(keyInput); // Routine is shared by both windows.

	makeMenu(); // Create menu.

	glutMainLoop();

	return 0;
}