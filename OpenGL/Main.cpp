#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

//MCB

/* Initialize OpenGL Graphics */
void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
	glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
	glLoadIdentity();                // Reset the model-view matrix

	glTranslatef(-0.5f, 0.4f, 0.0f); // Translate left and up
	glBegin(GL_QUADS);               // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);  // Red
	glVertex2f(-0.3f, -0.3f);     // Define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);     //  so that the normal (front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glTranslatef(0.1f, -0.7f, 0.0f); // Translate right and down
	glBegin(GL_QUADS);               // Each set of 4 vertices form a quad
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex2f(-0.3f, -0.3f);
	glVertex2f(0.3f, -0.3f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();

	glTranslatef(-0.3f, -0.2f, 0.0f); // Translate left and down
	glBegin(GL_QUADS);                // Each set of 4 vertices form a quad
	glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
	glVertex2f(-0.2f, -0.2f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(0.2f, -0.2f);
	glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
	glVertex2f(0.2f, 0.2f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(-0.2f, 0.2f);
	glEnd();

	glTranslatef(1.1f, 0.2f, 0.0f); // Translate right and up
	glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(-0.3f, -0.2f);
	glVertex2f(0.3f, -0.2f);
	glVertex2f(0.0f, 0.3f);
	glEnd();

	glTranslatef(0.2f, -0.3f, 0.0f);     // Translate right and down
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f); // Rotate 180 degree
	glBegin(GL_TRIANGLES);               // Each set of 3 vertices form a triangle
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.3f, -0.2f);
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex2f(0.3f, -0.2f);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(0.0f, 0.3f);
	glEnd();

	glRotatef(-180.0f, 0.0f, 0.0f, 1.0f); // Undo previous rotate
	glTranslatef(-0.1f, 1.0f, 0.0f);      // Translate right and down
	glBegin(GL_POLYGON);                  // The vertices form one closed polygon
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.1f, 0.2f);
	glVertex2f(-0.1f, 0.2f);
	glVertex2f(-0.2f, 0.0f);
	glEnd();

	glFlush();   // Render now
}

void showOff() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.4f, -0.4f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(-0.4f, 0.4f);
	glEnd();

	glTranslatef(0.5f, -0.4f, 0.0f); // Translate left and up
	glBegin(GL_QUADS);               // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);  // Red
	glVertex2f(-0.3f, -0.3f);     // Define vertices in counter-clockwise (CCW) order
	glVertex2f(0.3f, -0.3f);     //  so that the normal (front-face) is facing you
	glVertex2f(0.3f, 0.3f);
	glVertex2f(-0.3f, 0.3f);
	glEnd();


	glFlush();
}

//MCA

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);	// Initialize GLUT
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// Set up some memory buffers for our display
	glutInitWindowSize(800, 600);	// Set the window size
	glutInitWindowPosition(350, 100);	// Set the window position
	glutCreateWindow("OpenGL"); // Create the window with the title "Hello,GL"
	// Bind the two functions (above) to respond when necessary
	//glutReshapeFunc(changeViewPort);
	glutDisplayFunc(showOff);

	initGL();

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}