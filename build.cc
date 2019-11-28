#ifndef PRIMARYHOUSE_CC
#define PRIMARYHOUSE_CC

#include <GL/glut.h>

#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

#include "assets.h"
#include "architect.h"

#define SENS_ROT 10.0
#define SENS_OBS 10.0
#define SENS_TRANS 10.0

typedef struct __environment __environment; 
struct
__environment
{
        GLfloat aspect, angle;

        int x_ini, y_ini, bot;
        GLfloat scaleX, scaleY, scaleZ;
        GLfloat obsX, obsY, obsZ, rotX, rotY;
        GLfloat obsX_ini, obsY_ini, obsZ_ini, rotX_ini, rotY_ini;
};


__environment __env; // environment variables 

extern __globalangles __angles; // angles controller from assets
extern __housedimension __house; // house dimension from drawer


void drawHandler(void);
void motionHandler(int x, int y);
void initEnvironment(void);
void setVisualizationParameters(void);
void windowReshape(GLsizei w, GLsizei h);
void keyboardHandler(unsigned char key, int x, int y);
void mouseHandler(int button, int state, int x, int y);


void 
drawHandler(void)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT); 

        drawAxis();

        drawFirstFloor();

        glutSwapBuffers();
}

void 
motionHandler(int x, int y)
{
        int deltaX = __env.x_ini - x;
        int deltaY = __env.y_ini - y; 


        if(__env.bot == GLUT_LEFT_BUTTON)
        {
                __env.rotX = __env.rotX_ini - deltaY/ SENS_ROT;
                __env.rotY = __env.rotY_ini - deltaX/ SENS_ROT;
        }
        else if (__env.bot == GLUT_RIGHT_BUTTON)
        {
                __env.obsZ = __env.obsZ_ini + deltaY/ SENS_OBS;
        }
        else if (__env.bot == GLUT_MIDDLE_BUTTON)
        {
                __env.obsX = __env.obsX_ini + deltaX/ SENS_TRANS;
                __env.obsY = __env.obsY_ini + deltaY/ SENS_TRANS;
        }

        setVisualizationParameters();
        glutPostRedisplay();
}

void 
initEnvironment(void)
{ 
        GLfloat difuselight[] = {0.7, 0.7, 0.7, 1.0};          // "cor" 
        GLfloat ambientlight[] = {0.2, 0.2, 0.2, 1.0}; 
        GLfloat specularlight[] = {1.0, 1.0, 1.0, 1.0};// "brilho" 
        GLfloat lightposition[] = {0.0, 20.0, 20.0, 1.0};

        GLfloat speculatity[] = {1.0,1.0,1.0,1.0}; 
        GLint specularmaterial = 60;

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        
        glShadeModel(GL_SMOOTH);

        glMaterialfv(GL_FRONT, GL_SPECULAR, speculatity);
        glMateriali(GL_FRONT, GL_SHININESS, specularmaterial);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientlight);

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientlight); 
        glLightfv(GL_LIGHT0, GL_DIFFUSE, difuselight);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specularlight);
        glLightfv(GL_LIGHT0, GL_POSITION, lightposition);

        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);  
        glEnable(GL_LIGHT0);
        glEnable(GL_DEPTH_TEST);

        __env.obsZ = 400;
        __env.angle = 45;
        __env.rotX = __env.rotY = 0;
        __env.obsX = __env.obsY = 0;
        __env.scaleX = __env.scaleY = __env.scaleZ = 1;
}

void 
setVisualizationParameters(void)
{
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(__env.angle, __env.aspect, 0.4, 500);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Especifica posição do observador e do alvo
        //gluLookAt(0,80,200, 0,0,0, 0,1,0);
        //gluLookAt(obsX, obsY, obsZ, 0,0,0, 0,1,0);
        glTranslatef(-__env.obsX, -__env.obsY, -__env.obsZ);
        glRotatef(__env.rotX, 1, 0,0);
        glRotatef(__env.rotY, 0, 1,0); 
}

void 
windowReshape
(
      GLsizei w, 
      GLsizei h
)
{
        if(h == 0) 
                h = 1;

        glViewport(0, 0, w, h);
 
        __env.aspect = (GLfloat) w / (GLfloat) h;

        setVisualizationParameters();
}

void 
mouseHandler
(
        int button, 
        int state, 
        int x, 
        int y
)
{
        if(state == GLUT_DOWN)
        {
                __env.x_ini = x;
        
                __env.y_ini = y;
                __env.obsX_ini = __env.obsX;
                __env.obsY_ini = __env.obsY;
                __env.obsZ_ini = __env.obsZ;
                __env.rotX_ini = __env.rotX;
                __env.rotY_ini = __env.rotY;
                __env.bot = button;
        }
        else 
                __env.bot = -1;

        setVisualizationParameters();
        glutPostRedisplay();
}

void 
keyboardHandler
(
        unsigned char key, 
        int x, 
        int y
)
{
        switch(key)
        {
                case 97:
                        if(__angles.doortetha < 136)
                                __angles.doortetha += 1.5;
                        break;
                case 100:
                        if(__angles.doortetha > 0)
                                __angles.doortetha += - 1.5;
                        break;
                case 115:
                        if(__angles.windowtetha < 140)
                                __angles.windowtetha += 1.5;
                        break;
                case 102:     
                        if(__angles.windowtetha > 0)
                                __angles.windowtetha += - 1.5;  
                        break;
                case 103:
                        if(__angles.garagetetha < 85)
                                __angles.garagetetha += 1.5;
                        break;
                case 104:
                        if(__angles.garagetetha > 0)
                                __angles.garagetetha += - 1.5;
                        break;
                default:
                        break;
        }


        glutPostRedisplay();
}

int 
main(int argc, char** argv)
{
        initHouse(); // set house dimensions in architect
        initWindow();
        initChimney();
        initGarage();

        glutInit(&argc, argv);
        
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(900, 700);
        glutCreateWindow("Fabio's House");

        glutDisplayFunc(drawHandler);
        glutReshapeFunc(windowReshape);

        glutMouseFunc(mouseHandler);
        glutMotionFunc(motionHandler);
        glutKeyboardFunc(keyboardHandler);
        
        initEnvironment();

        glutMainLoop();
}

#endif /* PRIMARY_HOUSE */