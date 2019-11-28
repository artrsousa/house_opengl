#ifndef FIRSTFLOOR_H
#define FIRSTFLOOR_H

#include "assets.h"
#include "worker.h"

#ifndef GLUT_H
#include <GL/glut.h>
#endif /* GLUT_H */

#include <math.h>

extern __globalangles __angles; // angles controller from assets
extern __housedimension __house;
extern __windowdimension __window;
extern __chimneydimension __chimney;


void drawAll(void);

void drawChimney(GLfloat chimneyPosition);
void drawDoor(GLfloat chimneyPosition, GLfloat mainHalllength);
void drawRoof(GLfloat chimneyPosition, GLfloat mainHalllength);
void drawGarage(GLfloat chimneyPosition, GLfloat mainHalllength);
void drawGarageDoor(GLfloat chimneyPosition, GLfloat mainHalllength);
void drawCeilAndFloor(GLfloat mainHalllength, GLfloat chimneyPosition);
void drawWalls(GLfloat window1Position, GLfloat window2Position, GLfloat windowf1Position, GLfloat windowf2Position, GLfloat chimneyPosition, GLfloat mainHalllength);
void drawWindows(GLfloat window1Position, GLfloat window2Position, GLfloat windowf1Position, GLfloat windowf2Position, GLfloat chimneyPosition, GLfloat mainHalllength);


void
drawAll()
{
        GLfloat window1Position = __house.width * 0.07;
        GLfloat window2Position = __house.width * 0.5;

        GLfloat windowf1Position = __house.width * 0.14;
        GLfloat windowf2Position = __house.width * 0.25;

        GLfloat chimneyPosition = __house.length * 0.4;
        GLfloat mainHalllength = __house.width * 0.15; 

        drawRoof(
                chimneyPosition, 
                mainHalllength
        );

        drawWalls(
                window1Position,
                window2Position,
                windowf1Position,
                windowf2Position,
                chimneyPosition,
                mainHalllength
        );

        drawDoor(
                chimneyPosition, 
                mainHalllength
        );

        drawWindows(
                window1Position,
                window2Position,
                windowf1Position,
                windowf2Position,
                chimneyPosition,
                mainHalllength
        );

        drawChimney(chimneyPosition);
        drawGarage(chimneyPosition, mainHalllength);
        drawGarageDoor(chimneyPosition, mainHalllength);
        drawCeilAndFloor(mainHalllength, chimneyPosition);
}

void
drawRoof
(
        GLfloat chimneyPosition,
        GLfloat mainHalllength
)
{
        GLfloat angle = 43.0;
        GLfloat over = ((__house.length - (chimneyPosition + __chimney.width + mainHalllength)) / 2);
                
        GLfloat hip = sqrt(pow((((__house.length) / 2) - over), 2) + pow(60, 2));

        
        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef((__house.width - over), (__house.height - 5), (__house.length - over));
                glRotatef(- angle, 0, 0, 1);
                glTranslatef(- (__house.width - over), - (__house.height - 5), - (__house.length - over));
                buildFace(0, 1, 0, __house.width - over, __house.height - 5, (__house.length - over * 2) - (__house.length / 2) + over, (__garage.width + 5) + (__house.length / 2) - over, hip);
        glPopMatrix();


        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef( (__house.width + __garage.width + over), (__house.height - 5), ((__house.length - over * 2) - (__house.length / 2) + over));
                glRotatef(angle, 0, 0, 1);
                glTranslatef( - (__house.width + __garage.width + over), - (__house.height - 5), - ((__house.length - over * 2) - (__house.length / 2) + over));
                buildFace(0, 1, 0, __house.width + __garage.width + over, __house.height - 5, (__house.length - over * 2) - (__house.length / 2) + over, (__garage.width + 5) + (__house.length / 2) - over, hip);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef(5.0, (__house.height - 5), (__house.length - over));
                glRotatef(- angle, 1.0, 0.0, 0.0);
                glTranslatef( -5.0, - (__house.height - 5), - (__house.length - over));
                buildFace(1, 0, 0, -5.0, __house.height - 5, __house.length - over, ((__house.width + 5) + (__garage.width) / 2), hip);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef(- 5.0, __house.height - 5, - over);
                glRotatef(angle, 1.0, 0.0, 0.0);
                glTranslatef(5.0, - (__house.height - 5), over);
                buildFace(1, 0, 0, -5.0, __house.height - 5, - over, (__house.width + 5) + ((__garage.width / 2)), hip);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef( ((__house.width) + (__garage.width) / 2), (__house.height - 5), - over);
                glRotatef(angle, 1, 0, 0);
                glTranslatef( - ((__house.width) + (__garage.width) / 2), - (__house.height - 5), over);
                glBegin(GL_TRIANGLES);
                        glVertex3f(((__house.width) + (__garage.width) / 2), (__house.height - 5), - over);
                        glVertex3f((__house.width + __garage.width ) + over, (__house.height - 5), - over);
                        glVertex3f(((__house.width) + (__garage.width) / 2), (__house.height - 5) + hip, - over);
                glEnd();  
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef(((__house.width + __garage.width ) + over), (__house.height - 5), - over);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(- ((__house.width + __garage.width ) + over), - (__house.height - 5), over);
                glBegin(GL_TRIANGLES);
                        glVertex3f((__house.width + __garage.width ) + over, (__house.height - 5), - over);
                        glVertex3f((__house.width + __garage.width ) + over, (__house.height - 5), (__house.length - over * 2) - (__house.length / 2) + over);
                        glVertex3f((__house.width + __garage.width ) + over, (__house.height - 5) + hip, (__house.length - over * 2) - (__house.length / 2) + over);
                glEnd();  
        glPopMatrix();

        GLfloat interval = (__house.width / 4.05) - ((__house.width * 0.07) * 0.85);
        GLfloat heig = __house.height + 25;

        GLfloat hipfront = sqrt(pow(20, 2) + pow(interval, 2)) - 0.25;

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef((__house.width / 3.78) + 5, __house.height - 5, chimneyPosition + __chimney.width + mainHalllength);
                glRotatef(angle - 2.5, 0, 0, 1);
                glTranslatef( - ((__house.width / 3.78) + 5), - (__house.height - 5), -(chimneyPosition + __chimney.width + mainHalllength));
                buildFace(0, 1, 0, (__house.width / 3.78) + 5, __house.height - 5, chimneyPosition + __chimney.width + mainHalllength - 50, __house.length - (chimneyPosition + __chimney.width + mainHalllength) + 55, hipfront);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 1.0, 0.5);
                glTranslatef(((__house.width * 0.07) * 0.6) - 5, (__house.height - 5), (chimneyPosition + __chimney.width + mainHalllength));
                glRotatef(- (angle - 2.5), 0, 0, 1); 
                glTranslatef(- (((__house.width * 0.07) * 0.6) - 5), - (__house.height - 5), - (chimneyPosition + __chimney.width + mainHalllength));
                buildFace(0, 1, 0, ((__house.width * 0.07) * 0.6) - 5, __house.height - 5, chimneyPosition + __chimney.width + mainHalllength - 50, __house.length - (chimneyPosition + __chimney.width + mainHalllength) + 55, hipfront);
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 0.0, 0.0);
                glBegin(GL_TRIANGLES);
                        glVertex3f(((__house.width * 0.07) * 0.6), __house.height, __house.length);
                        glVertex3f(__house.width / 3.78, __house.height, __house.length);
                        glVertex3f(interval / 2 + ((__house.width * 0.07) * 0.85) , __house.height + 26.89, __house.length);
                glEnd();
        glPopMatrix();

        glPushMatrix();
                glColor3f(1.0, 0.0, 0.0);
                buildFace(1, 0, 0, ((__house.width * 0.07) * 0.85), __house.height - 10, __house.length, interval, 10);
        glPopMatrix();
}     

void
drawDoor(
        GLfloat chimneyPosition, 
        GLfloat mainHalllength
)
{
        GLfloat interval = (__house.width / 4.05) - ((__house.width * 0.07) * 0.85);

        glPushMatrix();
                glTranslatef( (__house.width / 4.05), 0.0, (__house.length));
                glRotatef(__angles.doortetha, 0, 1, 0);
                glTranslatef( - (__house.width / 4.05), 0.0, - (__house.length));
                glColor3f(0.0, 0.0, 0.0);
                buildFace(1, 0, 0, __house.width / 4.05, 0.0, __house.length, - interval, __house.height - 10);
                
                glTranslatef(((__house.width * 0.07) * 0.85) + 5, (__house.height / 2) - 5, __house.length + 1.5);
                glColor3f(0.7, 0.0, 0.0);
                glutSolidSphere(2, 50, 50);
        glPopMatrix();

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

        __garage.width = __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength));

       //parede Azul 
       glPushMatrix();
                glColor3f(0.0, 0.0, 1.0);
                buildFace(1, 0, 0, (__house.width / 4.05), 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), windowf1Position, __house.height);
        
                //wall - window1
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), (__window.width), (__house.height/2) - 5);
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position, ((__house.height/2) - 5) + __window.height, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), (__window.width), __house.height - (((__house.height/2) - 5) + __window.height));
                
                //wall - window2
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + windowf2Position + __window.width, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __window.width, (__house.height/2) - 5);
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + windowf2Position + __window.width, ((__house.height/2) - 5) + __window.height, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), (__window.width), __house.height - (((__house.height/2) - 5) + __window.height));

                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + __window.width, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), windowf2Position, __house.height);
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + __window.width + windowf2Position + __window.width, 0.0, chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __house.width - ((__house.width / 4.05) + windowf1Position + __window.width + windowf2Position + __window.width), __house.height);
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
drawWindows
(
        GLfloat window1Position,
        GLfloat window2Position,
        GLfloat windowf1Position,
        GLfloat windowf2Position,
        GLfloat chimneyPosition,
        GLfloat mainHalllength
)
{
        // window1 left
        glPushMatrix();
                glColor3f(1.0, 1.0, 0.0);
                glTranslatef(((__house.width / 4.05) + windowf1Position), ((__house.height/2) - 5), (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                glRotatef( - __angles.windowtetha, 0, 1, 0);
                glTranslatef(- ((__house.width / 4.05) + windowf1Position), - ((__house.height/2) - 5), - (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position, ((__house.height/2) - 5), chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), (__window.width) / 2, (__window.height));
        glPopMatrix();

        // window 1 right
        glPushMatrix();
                glColor3f(1.0, 1.0, 0.0);
                glTranslatef( ((__house.width / 4.05) + windowf1Position + __window.width), ((__house.height/2) - 5), (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                glRotatef(__angles.windowtetha, 0, 1, 0);
                glTranslatef( - ((__house.width / 4.05) + windowf1Position + __window.width), - ((__house.height/2) - 5), - (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + __window.width, ((__house.height/2) - 5), chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), - ((__window.width) / 2), (__window.height));
        glPopMatrix();

        // window2 left
        glPushMatrix();
                glColor3f(1.0, 1.0, 0.0);

                glTranslatef( ((__house.width / 4.05) + windowf1Position + __window.width + windowf2Position), ((__house.height/2) - 5), (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                glRotatef( - __angles.windowtetha, 0, 1, 0);
                glTranslatef( - ((__house.width / 4.05) + windowf1Position + __window.width + windowf2Position), - ((__house.height/2) - 5), - (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + __window.width + windowf2Position, ((__house.height/2) - 5), chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), (__window.width) / 2, (__window.height));
        glPopMatrix();

        // window2 right
        glPushMatrix(); 
                glColor3f(1.0, 1.0, 0.0);

                glTranslatef( ((__house.width / 4.05) + windowf1Position + __window.width + windowf2Position + __window.width), ((__house.height/2) - 5), (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                glRotatef(__angles.windowtetha, 0, 1, 0);
                glTranslatef( - ((__house.width / 4.05) + windowf1Position + __window.width + windowf2Position + __window.width), - ((__house.height/2) - 5), - (chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))));
                buildFace(1, 0, 0, (__house.width / 4.05) + windowf1Position + __window.width + windowf2Position + __window.width, ((__house.height/2) - 5), chimneyPosition + __chimney.width + (__house.length - (chimneyPosition + __chimney.width)) - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), - (__window.width / 2), (__window.height));
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
                glColor3f(0.5, 0.5, 0.0);
                // buildFace(1, 0, 0, __house.width, __house.height, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width, __garage.width, __garage.height);
                glBegin(GL_TRIANGLES);
                        glVertex3f(__house.width, __house.height, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width);
                        glVertex3f(__house.width + __garage.width, __house.height, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width);
                        glVertex3f(__house.width + (__garage.width / 2), __house.height + __house.height - 5, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength))) + __garage.width);
                glEnd();
        glPopMatrix();

        glPushMatrix();
                glColor3f(0.5, 0.5, 0.0);
                buildFace(0, 1, 0, __house.width, 0.0, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85), __garage.width * 0.15, __house.height);
                buildFace(0, 1, 0, __house.width, 0.0, __house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)), __garage.width * 0.15, __house.height);
                buildFace(0, 1, 0, __house.width, __house.height - 10, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85), - __garage.width * 0.7, 10);
        glPopMatrix();

        glPushMatrix(); //roof and ceil of garage
                glColor3f(0.0, 0.0, 0.0);
                buildFace(0, 0, 1, __house.width, 0.0, 0.0, __garage.width, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width));
                glTranslatef(0.0, __house.height, 0.0);
                        buildFace(0, 0, 1, __house.width, 0.0, 0.0, __garage.width, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width));
        glPopMatrix();
}

void
drawGarageDoor(
        GLfloat chimneyPosition, 
        GLfloat mainHalllength
)
{
        glPushMatrix();
                glColor3f(1.0, 0.0, 0.0);
                glTranslatef(__angles.garagetetha * 0.3, 0.0, 0.0);
                glPushMatrix();
                        glTranslatef(__house.width, __house.height - 10, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85));
                        glRotatef(- __angles.garagetetha, 0, 0, 1);
                        glTranslatef( - (__house.width), - (__house.height - 10), - (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85));
                        buildFace(0, 1, 0, __house.width, __house.height - 10, (__house.length - (__house.length - (chimneyPosition + __chimney.width + mainHalllength)) + __garage.width * 0.85), - __garage.width * 0.7, - (__house.height - 10));
                glPopMatrix();
        glPopMatrix();

        
}

#endif /* FIRSTFLOOR_H*/