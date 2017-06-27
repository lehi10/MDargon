#ifndef ADITIONALS_H
#define ADITIONALS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <thread>
#include <iostream>
#include <math.h>

using namespace std;

struct molecula
{
    double x;
    double y;
    double z;
    double oldx;
    double oldy;
    float radio=0.02;
    double tem;
    double velo;
    molecula ()
    {
        x=0.05;
        y=0.05;
        oldx=0.02;
        oldy=0.02;
    }

    molecula(double _x, double _y)
    {
        x=_x;
        y=_y;
        oldx=_x-0.03;
        oldy=_y-0.03;
    }

};

struct cubo
{
  vector<molecula*> vec_cubo;
  int num_moleculas=0;

  cubo(int n)
  {
     num_moleculas=n;
      vec_cubo.resize(num_moleculas);
       for(int i=0;i<num_moleculas;i++)
       {
           vec_cubo[i]= new molecula(rand()%10 /10.0,rand()%10 /10.0);
       }
  }
};




void dibujar(molecula *mol)
{
    double x=mol->x;
    double y=mol->y;
    float radio=mol->radio;

    glPushMatrix();
        glTranslatef(x,y,0);
        glColor3f(1,1,1);
        glutSolidSphere(radio,20,20);
    glPopMatrix();
    glColor3f(1,1,1);
    glutWireCube(1.8);

    //glutPostRedisplay();
    glFlush();

}

void limpiar()
{
    glClearColor(0, 0,0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


#endif // ADITIONALS_H
