
///#include <GL/glew.h> // Include the GLEW header file
#include <GL/glut.h> // Include the GLUT header file
#include <iostream>
//#include <math.h>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;

void display (void);
void onEF (int n);
void reshape (int width, int height);

vector<double>* x_s = new vector<double>;
vector<double>* y_s = new vector<double>;


double a = 0.01;
const double x_init = -5,
             delta = 0.1,
             delta_A = 0.01,
             w = 7;
int len,
    sign = 1;
const int DOTS = 100;

struct VPoint
{
public:

	double x, y;

    VPoint(double nx, double ny)
	{
		x = nx;
		y = ny;
	}
};


int main(int argc, char **argv)
{
    double x = x_init;
    x_s->resize(DOTS);
    y_s->resize(DOTS);
    for (int i = 1; i < DOTS; ++i){
        //x_s->emplace_back(x);
        (*x_s)[i] = x;
        x += delta;
    }
    len = x_s->size();

    glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode (GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize (600, 600); // Set the width and height of the window
	glutInitWindowPosition (100, 100); // Set the position of the window
	glutCreateWindow ("Your first OpenGL Window"); // Set the title for the window

	glutIdleFunc();
	glutTimerFunc(100, onEF, 0);
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping

	glutMainLoop();

	return 0;
}

void drawParabola()
{
    a += sign * delta_A;
    if (abs(a) > 3) {sign *= -1;}
    double y;
    for (int i = 1; i < DOTS; ++i)
    {
        y = a * (*x_s)[i] * (*x_s)[i] + 1;
        //y = a * sin((*x_s)[i]);
        //y = sin((*x_s)[i] - a);
        (*y_s)[i] = y;
    }
    /**
    for (int i = 1; i < DOTS; ++i)
    {
        glBegin(GL_QUADS);
		//std::cout << (*i)->x << "\n";
		glVertex2d( (*x_s)[i] / w + 0.01, (*y_s)[i] / w + 0.01);
		glVertex2d( (*x_s)[i] / w - 0.01, (*y_s)[i] / w + 0.01);
		glVertex2d( (*x_s)[i] / w + 0.01, (*y_s)[i] / w - 0.01);
		glVertex2d( (*x_s)[i] / w - 0.01, (*y_s)[i] / w - 0.01);
		glEnd();
    }
    **/

    for (int i = 1; i < DOTS - 1; ++i)
    {
        glBegin(GL_LINES);
		//std::cout << (*i)->x << "\n";
		glVertex2d( (*x_s)[i] / w, (*y_s)[i] / w);
		glVertex2d( (*x_s)[i+1] / w, (*y_s)[i+1] / w);
		glEnd();
    }
}

void display (void)
{
	std::cout << "display\n";
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glTranslatef(0.0f, 0.0f, -5.0f);

	glClear(GL_COLOR_BUFFER_BIT);//Clear the screen
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Clear the background of our window to red

	drawParabola();
	glutSwapBuffers();
	//Draw everything to the screen

	glFlush();
}

void onEF(int n)
{
    glutPostRedisplay();
	//glutTimerFunc(20, onEF, 0);

}

void reshape (int width, int height)
{

	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	gluPerspective(22.5, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}
