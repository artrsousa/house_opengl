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

void
drawAll(void)
{
        GLfloat window1Position = __house.width * 0.07;
        GLfloat window2Position = __house.width * 0.5;

        GLfloat windowf1Position = __house.width * 0.14;
        GLfloat windowf2Position = __house.width * 0.25;

        GLfloat chamneyPosition = __house.length * 0.43;
        GLfloat mainHalllength = __house.width * 0.15; 

        glPushMatrix(); //back
                glColor3f(1.0, 0.0, 0.0); 
                buildFace(1, 0, 0, 0.0, 0.0, 0.0, window1Position, __house.height);
                // buildFace(1, 0, 0, window1Position + __window.width, 0.0, 0.0, window2Position - (window1Position + __window.width), __house.height);
                buildFace(1, 0, 0, window2Position + __window.width, 0.0, 0.0, __house.width - (window2Position + __window.width), __house.height);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 0.0, 0.0);
                buildFace(0, 1, 0, 0.0, 0.0, 0.0, chamneyPosition, __house.height);
                buildFace(0, 1, 0, 0.0, 0.0, chamneyPosition + __chimney.width, (__house.length - (chamneyPosition + __chimney.width)) - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), __house.height);
                buildFace(1, 0, 0, 0.0, 0.0, chamneyPosition + __chimney.width + (__house.length - (chamneyPosition + __chimney.width)) - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), window1Position * 0.6, __house.height);

                buildFace(0, 1, 0, window1Position * 0.6, 0.0, chamneyPosition + __chimney.width + mainHalllength, __house.length - (chamneyPosition + __chimney.width + mainHalllength), __house.height);
                glTranslatef(__house.width / 3.8, 0.0, 0.0);
                        buildFace(0, 1, 0, 0.0, 0.0, chamneyPosition + __chimney.width + mainHalllength, __house.length - (chamneyPosition + __chimney.width + mainHalllength), __house.height);
        glPopMatrix();

        glPushMatrix();
                glColor3f(0.0, 0.0, 1.0);
                buildFace(1, 0, 0, (__house.width / 3.8), 0.0, chamneyPosition + __chimney.width + (__house.length - (chamneyPosition + __chimney.width)) - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), windowf1Position, __house.height);
                buildFace(1, 0, 0, (__house.width / 3.8) + windowf1Position + __window.width, 0.0, chamneyPosition + __chimney.width + (__house.length - (chamneyPosition + __chimney.width)) - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), windowf2Position, __house.height);
                buildFace(1, 0, 0, (__house.width / 3.8) + windowf1Position + __window.width + windowf2Position + __window.width, 0.0, chamneyPosition + __chimney.width + (__house.length - (chamneyPosition + __chimney.width)) - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), __house.width - ((__house.width / 3.8) + windowf1Position + __window.width + windowf2Position + __window.width), __house.height);

                buildFace(0, 1, 0, __house.width, 0.0, 0.0, __house.length - (__house.length - (chamneyPosition + __chimney.width + mainHalllength)), __house.height);
        glPopMatrix();
}




















// void drawMainHall(void);
// void drawSideWalls(void);

// void drawWall(void);

// void
// drawMainHall(void)
// {
//         //printf("dimensions: %f\n %f\n %f\n", __house.width, __house.length, __house.height);
//         drawWalls(10.0, 10.0, 10.0, 20.0, 20.0, 1.0);
        
// }

// void 
// drawWall
// (
//         GLfloat startx, 
//         GLfloat starty, 
//         GLfloat startz, 
//         GLfloat width, 
//         GLfloat height, 
//         GLfloat thickness
// )
// {
//         glPushMatrix();
//                 glColor3f(0.0, 0.0, 1.0);
//                 buildFace(0, 1, 0, startx, starty, startz, width, height);
//                 buildFace(1, 0, 0, startx, starty, startz, thickness, height);  
//                 buildFace(0, 0, 1, startx, starty, startz, thickness, height);

//                 glColor3f(1.0, 0.0, 0.0);
//                 buildFace(0, 1, 0, startx, starty, , width, height);
//                 //buildFace(1, 0, 0, startx, starty, length, thickness, height);
//                 //buildFace(0, 0, 1, startx, height, startz, thickness, length);
//         glPopMatrix();
// }

// void drawSideWalls(void)
// {
//         // GLfloat startx = __house.width * 0.7;
//         // GLfloat startz = __house.length * 0.7;

//         // glPushMatrix();
//         //         glColor3f(0.0, 0.0, 1.0);
//         //         buildFace(0, 1, 0, startx, 0.0, 0.0, __house.length * 0.7, __house.height);
//         //         buildFace(1, 0, 0, startx, 0.0, 0.0, __house.thickness, __house.height);  
//         //         buildFace(0, 0, 1, startx, 0.0, 0.0, __house.thickness, __house.length * 0.7);

//         //         buildFace(0, 1, 0, startx + __house.thickness, 0.0, 0.0, __house.length * 0.7, __house.height);
//         //         buildFace(1, 0, 0, startx, 0.0, __house.length * 0.7, __house.thickness, __house.height);
//         //         buildFace(0, 0, 1, startx, __house.height, 0.0, __house.thickness, __house.length * 0.7);
//         // glPopMatrix();

//         // glPushMatrix();
//         //         glTranslatef(__house.width / 4, 0.0, 0.0);
//         //         glColor3f(0.0, 0.0, 1.0);
//         //         buildFace(0, 1, 0, startx, 0.0, 0.0, __house.length * 0.7, __house.height);
//         //         buildFace(1, 0, 0, startx, 0.0, 0.0, __house.thickness, __house.height);  
//         //         buildFace(0, 0, 1, startx, 0.0, 0.0, __house.thickness, __house.length * 0.7);

//         //         buildFace(0, 1, 0, startx + __house.thickness, 0.0, 0.0, __house.length * 0.7, __house.height);
//         //         buildFace(1, 0, 0, startx, 0.0, __house.length * 0.7, __house.thickness, __house.height);
//         //         buildFace(0, 0, 1, startx, __house.height, 0.0, __house.thickness, __house.length * 0.7);
//         // glPopMatrix();
// }


#endif /* FIRSTFLOOR_H*/