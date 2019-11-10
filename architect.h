#ifndef ARCHITECT_H
#define ARCHITECT_H
#ifndef GLUT_H
#include <GL/glut.h>
#endif /* GLUT_H */

#include "assets.h"
#include "firstfloor.h"

extern __housedimension __house;

void drawAxis(void);
void initHouse(void);
void initWindow(void);
void drawsquare(void);
void initChimney(void);
void drawfirstfloor(void);

// void drawRoof(void);
// void drawCeil(void);
// void drawFloor(void);
// void drawWalls(void);
 
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


void initWindow(void)
{
        __window.width = 20;
        __window.height = 8;
        __window.thickness = 1;
}

void initChimney(void)
{
        __chimney.height = 80;
        __chimney.width = 15;
        __chimney.thickness = 2;
}

void
drawFirstFloor(void)
{
        // drawStructure();
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

