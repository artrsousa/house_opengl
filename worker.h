#ifndef WORKER_H
#define WORKER_H

// #include "assets.h"

#ifndef GLUT_H
#include <GL/glut.h>
#endif /* GLUT_H */

void buildFace(int xy, int yz, int xz, GLfloat sx, GLfloat sy, GLfloat sz, GLfloat wsize, GLfloat hsize, GLfloat lsize);

void buildFace
(
        int xy, 
        int yz, 
        int xz, 
        GLfloat sx, //start point 
        GLfloat sy, 
        GLfloat sz,
        GLfloat wsize, 
        GLfloat hsize
)
{
        GLfloat xwidth = sx + wsize;
        GLfloat zwidth = sz + wsize;
        GLfloat yheight = sy + hsize;
        GLfloat zheight = sz + hsize;

        glBegin(GL_QUADS);
                glVertex3f(sx, sy, sz);
                glVertex3f((xy * xwidth) + (xz * xwidth) + (yz * sx), (xy * sy) + (xz * sy) + (yz * sy), (xy * sz) + (xz * sz) + (yz * zwidth));
                glVertex3f((xy * xwidth) + (xz * xwidth) + (yz * sx), (xy * yheight) + (xz * sy) + (yz * yheight), (xy * sz) + (xz * zheight) + (yz * zwidth));
                glVertex3f((xy * sx) + (xz * sx) + (yz * sx), (xy * yheight) + (xz * sy) + (yz * yheight), (xy * sz) + (xz * zheight) + (yz * sz));
        glEnd();
}


#endif /* WORKER_H */