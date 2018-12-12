#ifndef DRAW_H
#define DRAW_H



#include"pxl.h"
#include"coord.h"









struct color{
  unsigned int r,g,b,a;
};

static const color Red = {255,0,0,255};
static const color Green={0,255,0,255};
static const color Grey ={100,100,100,255};

void fill( image, color );
void drawPoint( image, color, wCoord );
void drawLine( image, color, wCoord, wCoord );

#endif
