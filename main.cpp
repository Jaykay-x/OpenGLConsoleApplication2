#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include <iostream>

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0);
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
	{
		std::cout << " GLEW Version is 4.5 \n";
	}
	else
	{
		std::cout << " GLEW Version 4.5 is not supported \n";
	}

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(renderScene);

	glutMainLoop();
	return 0;
}

/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("First_GL!");
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
*/

/*这是洋人的例子*/
/*
void init();
void display(void);
void centerOnScreen();
void drawObject();

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 480;
int window_height = 480;

//  variable representing the window title
char *window_title = "Sample OpenGL FreeGlut App";

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();

	// Set the callback functions
	glutDisplayFunc(display);

	//  Start GLUT event processing loop
	glutMainLoop();
}

//-------------------------------------------------------------------------
//  Set OpenGL program initial state.
//-------------------------------------------------------------------------
void init()
{
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
//  This function is passed to glutDisplayFunc in order to display 
//  OpenGL contents on the window.
//-------------------------------------------------------------------------
void display(void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT);

	//  Draw object
	drawObject();

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

//-------------------------------------------------------------------------
//  Draws our object.
//-------------------------------------------------------------------------
void drawObject()
{
	//  Draw Icosahedron
	glutWireIcosahedron();
}

//-------------------------------------------------------------------------
//  This function sets the window x and y coordinates
//  such that the window becomes centered
//-------------------------------------------------------------------------
void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}
*/