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

typedef struct __garagedimension __garagedimension;
struct
__garagedimension
{
        GLfloat width;
        GLfloat height;
        GLfloat thickness;
};

typedef struct __globalangles __globalangles;
struct
__globalangles
{
        GLfloat doortetha;
        GLfloat windowtetha;
        GLfloat garagetetha;
};


__housedimension __house;
__windowdimension __window;
__chimneydimension __chimney;
__garagedimension __garage;
__globalangles __angles;

#endif /* ASSETS_H */ 