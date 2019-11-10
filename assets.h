#ifndef ASSETS_H
#define ASSETS_H

typedef struct __housedimension __housedimension;
struct
__housedimension
{
        GLfloat width;  // x size
        GLfloat height; // y size
        GLfloat length; // z size
        GLfloat thickness;

        GLfloat windowY;
        GLfloat chimneyX;
};

typedef struct __windowdimension __windowdimension;
struct
__windowdimension
{
        GLfloat width;  // x size
        GLfloat height; // y size
        GLfloat thickness;
};

typedef struct __chimneydimension __chimneydimension;
struct
__chimneydimension
{
        GLfloat width;  // x size
        GLfloat height; // y size
        GLfloat thickness;
};


__housedimension __house;
__windowdimension __window;
__chimneydimension __chimney;

#endif /* ASSETS_H */ 