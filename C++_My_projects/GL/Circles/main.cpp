#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

///best - (step1, step2) - (3,12); (3,9); (3,13) - 8-flower; (3,11) - 5-flower;

const int circ1_points = 200,
          circ2_points = 400,
          pic_points = 600,
          step1 = 3,
          step2 = 11,
          rad1 = 1,
          rad2 = 2;
int       cur_pos1 = 0,
          cur_pos2 = 0,
          curr_edges = 0;
const double ps = 0.01,
             pi = 3.14159265358979323846; ///point size

vector<pair<double,double>> *circ1 = new vector<pair<double,double>>;
vector<pair<double,double>> *circ2 = new vector<pair<double,double>>;
vector<pair<double,double>> *edg_s = new vector<pair<double,double>>;
vector<pair<double,double>> *edg_f = new vector<pair<double,double>>;

void display(void);
void onEF();
void reshape(int width, int height);
void create_cirles();
void create_cirles2();
void add_edge();
void draw_pic();


void create_cirles()
{
    double x = -rad1, y, step = 0.02;//step = static_cast<double>(rad1/circ1_points) * 4;
    //cout << "\n " << step << endl;
    int half1 = (circ1_points/2), half2 = (circ2_points/2);
    for (int i = 0; i < half1; ++i)
    {
        y = sqrt(rad1*rad1 - x*x);
        circ1->push_back(make_pair(x,y));
        x += step;
    }
    for (int i = half1; i < circ1_points; ++i)
    {
        x = (*circ1)[i-half1].first;
        y = (-1)*((*circ1)[i-half1].second);
        circ1->push_back(make_pair(x,y));
    }
    //**
    x = -rad2;
    //step = double(rad2/circ2_points) * 4;
    for (int i = 0; i < half2; ++i)
    {
        y = sqrt(rad2*rad2 - x*x);
        circ2->push_back(make_pair(x,y));
        x += step;
    }
    for (int i = half2; i < circ2_points; ++i)
    {
        x = (*circ2)[i-half2].first;
        y = (-1)*((*circ2)[i-half2].second);
        circ2->push_back(make_pair(x,y));
    }   //**/
}

void create_cirles2()
{
    double ang = 0, x, y, step = double(pi/circ1_points)*2;//step = static_cast<double>(rad1/circ1_points) * 4;
    //cout << "\n " << step << endl;
    for (int i = 0; i < circ1_points; ++i)
    {
        x = sin(ang) * rad1;
        y = cos(ang) * rad1;
        circ1->push_back(make_pair(x,y));
        ang += step;
    }
    //**
    ang = 0;
    step = double(pi/circ2_points)*2;//step = double(rad2/circ2_points) * 4;
    for (int i = 0; i < circ2_points; ++i)
    {
        x = sin(ang) * rad2;
        y = cos(ang) * rad2;
        circ2->push_back(make_pair(x,y));
        ang += step;
    } //**/
}

void add_edge()
{
    if (curr_edges >= pic_points) return;
    double x, y;
    x = (*circ1)[cur_pos1].first;
    y = (*circ1)[cur_pos1].second;
    edg_s->push_back(make_pair(x,y));
    x = (*circ2)[cur_pos2].first;
    y = (*circ2)[cur_pos2].second;
    edg_f->push_back(make_pair(x,y));
    cur_pos1 += step1;
    cur_pos2 += step2;
    cur_pos1 %= circ1_points;
    cur_pos2 %= circ2_points;
    ++curr_edges;
}

int main(int argc, char *argv[])
{
    create_cirles2();
    //cout << "\n\n " << (*circ1)[5].first << endl;
    //**
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize(600, 600); // Set the width and height of the window
	glutInitWindowPosition(100, 100); // Set the position of the window
	glutCreateWindow("OpenGL Window"); // Set the title for the window
	//glEnable( GL_POINT_SMOOTH );

	glutIdleFunc(onEF);
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering

	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping

							  //glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
							  //glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events

	glutMainLoop(); // Enter GLUT's main loop
	//**/

    return 0;
}

void draw_pic()
{
    //**
    int s = edg_f->size();
    for (int i = 0; i < s; ++i)
    {
        double xs = (*edg_s)[i].first,
               ys = (*edg_s)[i].second,
               xf = (*edg_f)[i].first,
               yf = (*edg_f)[i].second;
        glBegin(GL_LINES);
        glVertex2f(xs, ys);
        glVertex2f(xf, yf);
        glEnd();
    } //**/
    /**
    for (int i = 0; i < circ1_points; ++i)
    {
        double x = (*circ1)[i].first,
               y = (*circ1)[i].second;
        glBegin(GL_QUADS);
        glVertex2f(x+ps, y+ps);
        glVertex2f(x+ps, y-ps);
        glVertex2f(x-ps, y-ps);
        glVertex2f(x-ps, y+ps);
        glEnd();
    } //**/
    /**
    for (int i = 0; i < circ2_points; ++i)
    {
        double x = (*circ2)[i].first,
               y = (*circ2)[i].second;
        glBegin(GL_QUADS);
        glVertex2f(x+ps, y+ps);
        glVertex2f(x+ps, y-ps);
        glVertex2f(x-ps, y-ps);
        glVertex2f(x-ps, y+ps);
        glEnd();
    } //**/
}

void display(void)
{
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Clear the background of our window to red
	glClear(GL_COLOR_BUFFER_BIT);//Clear the screen

	draw_pic();
	glutSwapBuffers();

	glFlush();
}

void onEF()
{
	add_edge();
	glutPostRedisplay();
}

void reshape(int width, int height)
{

	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	///glOrtho( -rad2-1, rad2+1, -rad2-1, rad2+1, -1, 10);
	glOrtho( -3, 3, -3, 3, -1, 10);
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}
