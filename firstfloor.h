#ifndef FIRSTFLOOR_H
#define FIRSTFLOOR_H

#include "assets.h"
#include "worker.h"

#ifndef GLUT_H
#include <GL/glut.h>
#endif /* GLUT_H */

extern __housedimension __house;
extern __windowdimension __window;
extern __chimneydimension __chimney;

void drawAll(void);

void drawChimney(GLfloat chimneyPosition);
void drawGarage(GLfloat chimneyPosition, GLfloat mainHalllength);
void drawCeilAndFloor(GLfloat mainHalllength, GLfloat chimneyPosition);
void drawWalls(GLfloat window1Position, GLfloat window2Position, GLfloat windowf1Position, GLfloat windowf2Position, GLfloat chimneyPosition, GLfloat mainHalllength);


void
drawAll(void)
{
        GLfloat window1Position = __house.width * 0.07;
        GLfloat window2Position = __house.width * 0.5;

        GLfloat windowf1Position = __house.width * 0.14;
        GLfloat windowf2Position = __house.width * 0.25;

        GLfloat chimneyPosition = __house.length * 0.43;
        GLfloat mainHalllength = __house.width * 0.15; 

        drawWalls(
                window1Position,
                window2Position,
                windowf1Position,
                windowf2Position,
                chimneyPosition,
                mainHalllength
        );

        drawChimney(chimneyPosition);
        drawCeilAndFloor(mainHalllength, chimneyPosition);
        drawGarage(chimneyPosition, mainHalllength);
}

void
drawWalls
(
        GLfloat window1Position,
        GLfloat window2Position,
        GLfloat windowf1Position,
        GLfloat windowf2Position,
        GLfloat chimneyPosition,
        GLfloat mainHalllength
)
{
        glPushMatrix(); //back
                glColor3f(1.0, 0.0, 0.0); 
                buildFace(1, 0, 0, 0.0, 0.0, 0.0, window1Position, __house.height);
                // buildFace(1, 0, 0, window1Position + __window.width, 0.0, 0.0, window2Position - (window1Position + __window.width), __house.height);
                buildFace(1, 0, 0, window2Position + __window.width, 0.0, 0.0, __house.width - (window2Position + __window.width), __house.height);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 0.0, 0.0);
                buildFace(0, 1, 0, 0.0, 0.0, 0.0, chimneyPosition, __house.height);
                buildFace(0, 1, 0, 0.0, 0.0, chimneyPosition + __chimney.width, (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __house.height);
                buildFace(1, 0, 0, 0.0, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), window1Position * 0.85, __house.height);

                buildFace(0, 1, 0, window1Position * 0.6, 0.0, chimneyPosition + __chimney.width + mainHalllength, __house.length - (chimneyPosition + __chimney.width + mainHalllength), __house.height);
                buildFace(0, 1, 0, window1Position * 0.85, 0.0, chimneyPosition + __chimney.width + mainHalllength, __house.length - (chimneyPosition + __chimney.width + mainHalllength), __house.height);
        glPopMatrix();

        glPushMatrix();
                glTranslatef(__house.width / 4.05, 0.0, 0.0);
                        buildFace(0, 1, 0, 0.0, 0.0, chimneyPosition + __chimney.width + mainHalllength, __house.length - (chimneyPosition + __chimney.width + mainHalllength), __house.height);
        glPopMatrix();

        glPushMatrix();
                glTranslatef(__house.width / 3.785, 0.0, 0.0);
                        buildFace(0, 1, 0, 0.0, 0.0, chimneyPosition + __chimney.width + mainHalllength, __house.length - (chimneyPosition + __chimney.width + mainHalllength), __house.height);
        glPopMatrix();

        glPushMatrix();
                buildFace(0, 0, 1, window1Position * 0.6, 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), window1Position * 0.85 - window1Position * 0.6, __house.length - (chimneyPosition + __chimney.width + mainHalllength));
                buildFace(1, 0, 0, window1Position * 0.6, 0.0, __house.length, window1Position * 0.85 - window1Position * 0.6, __house.height);
                glTranslatef(0.0, __house.height, 0.0);
                        buildFace(0, 0, 1, window1Position * 0.6, 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), window1Position * 0.85 - window1Position * 0.6, __house.length - (chimneyPosition + __chimney.width + mainHalllength));
        glPopMatrix();

        glPushMatrix();
                buildFace(0, 0, 1, (__house.width / 4.05), 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), window1Position * 0.85 - window1Position * 0.6, __house.length - (chimneyPosition + __chimney.width + mainHalllength));
                buildFace(1, 0, 0, (__house.width / 4.05), 0.0, __house.length, window1Position * 0.85 - window1Position * 0.6, __house.height);
                glTranslatef(0.0, __house.height, 0.0);
                        buildFace(0, 0, 1, (__house.width / 4.05), 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), window1Position * 0.85 - window1Position * 0.6, __house.length - (chimneyPosition + __chimney.width + mainHalllength));
        glPopMatrix();

        GLfloat wallSize = __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength));
        GLfloat garageDoorPosition = wallSize * 0.3;
        GLfloat garageDoorWidth = 20;

        glPushMatrix();
                glColor3f(0.0, 0.0, 1.0);
                buildFace(1, 0, 0, (__house.width / 4.05), 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), windowf1Position, __house.height);
                buildFace(1, 0, 0, (__house.width / 3.8) + windowf1Position + __window.width, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), windowf2Position, __house.height);
                buildFace(1, 0, 0, (__house.width / 3.8) + windowf1Position + __window.width + windowf2Position + __window.width, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __house.width - ((__house.width / 3.8) + windowf1Position + __window.width + windowf2Position + __window.width), __house.height);
                
                buildFace(0, 1, 0, __house.width, 0.0, 0.0, garageDoorPosition, __house.height);
                buildFace(0, 1, 0, __house.width, 0.0, garageDoorPosition + garageDoorWidth, (__house.length - (garageDoorPosition + garageDoorWidth)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __house.height);
        glPopMatrix();    
};

void
drawChimney
(
        GLfloat chimneyPosition
)
{
        glPushMatrix();
                glColor3f(0.0, 1.0, 0.0);
                buildFace(0, 1, 0, -__chimney.width / 2, 0, chimneyPosition, __chimney.width, __chimney.height);
                buildFace(1, 0, 0, -__chimney.width / 2, 0, chimneyPosition, __chimney.width, __chimney.height);
                buildFace(1, 0, 0, -__chimney.width / 2, 0, chimneyPosition + __chimney.width, __chimney.width, __chimney.height);
                buildFace(0, 1, 0, __chimney.width / 2, 0, chimneyPosition, __chimney.width, __chimney.height);
        glPopMatrix();
}

void
drawCeilAndFloor
(
        GLfloat mainHalllength,
        GLfloat chimneyPosition
)
{
        glPushMatrix();
                glColor3f(0.0, 0.0, 0.0);
                buildFace(0, 0, 1, 0.0, 0.0, 0.0, __house.width,  __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)));
                buildFace(0, 0, 1, 0.0, __house.height, 0.0, __house.width,  __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)));
        glPopMatrix();
}

void
drawGarage
(
        GLfloat chimneyPosition, 
        GLfloat mainHalllength
)
{
        glPushMatrix();
                glColor3f(0.5, 0.5, 0.0);
                buildFace(1, 0, 0, __house.width, 0.0, 0.0, __garage.width, __garage.height);
                buildFace(0, 1, 0, __house.width + __garage.width, 0.0, 0.0, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width, __garage.height);
                buildFace(1, 0, 0, __house.width, 0.0, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width, __garage.width, __garage.height);
        glPopMatrix();

        glPushMatrix();
                buildFace(0, 1, 0, __house.width, 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __garage.width * 0.15, __house.height);
                buildFace(0, 1, 0, __house.width, 0.0, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85), __garage.width * 0.15, __house.height);
        glPopMatrix();

        glPushMatrix(); //roof and ceil of garage
                glColor3f(0.0, 0.0, 0.0);
                buildFace(0, 0, 1, __house.width, 0.0, 0.0, __garage.width, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width));
                glTranslatef(0.0, __house.height, 0.0);
                        buildFace(0, 0, 1, __house.width, 0.0, 0.0, __garage.width, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width));
        glPopMatrix();
}


#endif /* FIRSTFLOOR_H*/