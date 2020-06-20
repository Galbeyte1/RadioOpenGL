#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize the GL settings
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport based on the screen dimentions
//Function is called implicitly by initializeGL and when screen is resized
void GLobj::resizeGL( int w, int h )
{
    //algorithm to keep scene "square" (preserve aspect ratio)
    //even if screen is streached
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    //setup the projection and switch to model view for transformations
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -3, 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //implicit call to paintGL after resized

}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.99f, 1.0f); // make this vertex purple
      glVertex2f(-4, 4);
      glColor3f(1.0f, 0.99f, 0.0f); // make this vertex red
      glVertex2f(-4, -4);
      glColor3f(0.0f, 0.99f, 0.0f); // make this vertex green
      glVertex2f(4, -4);
      glColor3f(1.0f, 1.1f, 0.0f); // make this vertex yellow
      glVertex2f(4, 4);
    glEnd();

    glColor3f(1, 0.5, 0.5);
    glBegin(GL_LINES);
        glVertex2f(-2, -2);
        glVertex2f(2, 2);
    glEnd();
    glColor3f(1, 0.5, 0.5);
    glBegin(GL_LINES);
        glVertex2f(-2, 2);
        glVertex2f(2, -2);
    glEnd();

    //Draw a quad
    glColor3f(0, 0, 1);
    ngon(4, -2, 0);
    //Draw a triangle
    glColor3f(0, 1, 0);
    ngon(3, -2, -2);
    //Draw a triangle
    glColor3f(0, 0, 0.5);
    ngon(3, 2, -2);
    //Draw a Pentagon
    glColor3f(0, 1, 1);
    ngon(5, -2, 2);
    //Draw a Hexagon
    glColor3f(1, 0, 0);
    ngon(6, 0, 2);
    //Draw a Heptagon
    glColor3f(1, 0, 1);
    ngon(7, 2, 2);
    //Draw a Octagon
    glColor3f(1, 1, 0);
    ngon(8, 2, 0);
    //Draw a nonagon
    glColor3f(1, 1, 0);
    ngon(8, 2, 0);
    //Draw a circle
    glColor3f(1, 0.5, 0.5);
    ngon(100, 0, -2);



    glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, 1.5f, 0.0f);
      glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, -0.75f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f(0.0f, 0.5f, 0.0f);
      glVertex3f(-1.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, -0.75f, 0.0f);
    glEnd();

    glFlush ();
}

void GLobj::ngon(int n, int x, int y){
  float degree, vertx, verty, rotate, degToRad;
  rotate = 360.0/n;//Vertex rotation increment
  degree = rotate/2 + 180;//Current degree of vertex (starts rotated to make object upright)
  degToRad = 180/3.14159; //Conversion factor from degrees to radians
  glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++, degree += rotate) {
      vertx = 0.5 * sin(degree/degToRad); //next vertex's x coordinate
      verty = 0.5 * sin((90 - degree)/degToRad); //next vertex's y coordinate
      glVertex3f(vertx + x, verty + y, 0);
    }
  glEnd();

}
