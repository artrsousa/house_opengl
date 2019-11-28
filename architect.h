#ifndef ARCHITECT_H
#define ARCHITECT_H
#ifndef GLUT_H
#include <GL/glut.h>
#endif /* GLUT_H */

#include "assets.h"
#include "firstfloor.h"

//extern __housedimension __house;

void drawAxis(void);
void initHouse(void);
void initWindow(void);
void drawsquare(void);
void initGarage(void);
void initChimney(void);
void drawfirstfloor(void);

 
void
initHouse(void)
{
        __house.width = 200; 
        __house.height = 50;
        __house.length = 100;
        __house.thickness = 1;

        __house.windowY = 50 * 0.4;
        __house.chimneyX = 40;
}


void 
initWindow(void)
{
        __window.width = 25;
        __window.height = 22;
        __window.thickness = 1;
}

void 
initChimney(void)
{
        __chimney.height = 110;
        __chimney.width = 15;
        __chimney.thickness = 2;
}

void
initGarage(void)
{
        __garage.height = __house.height;
        __garage.width = 100;
        __garage.thickness = 1;
}

void
initAngles(void)
{
        __angles.doortetha = 0;
        __angles.windowtetha = 0;
        __angles.garagetetha = 0;
}


void
drawFirstFloor()
{
        drawAll();
}

void
drawAxis(void)
{
        glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                        glVertex3f(0.0, 0.0, 0.0);
                        glVertex3f(0.0, 75.0, 0.0);
                glEnd(); 
        glPopMatrix();

        glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                        glVertex3f(0.0, 0.0, 0.0);
                        glVertex3f(75.0, 0.0, 0.0);
                glEnd(); 
        glPopMatrix();

        glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                glBegin(GL_LINES);
                        glVertex3f(0.0, 0.0, 0.0);
                        glVertex3f(0.0, 0.0, 75.0);
                glEnd(); 
        glPopMatrix();    
}

#endif /* ARCHITECT_H */

