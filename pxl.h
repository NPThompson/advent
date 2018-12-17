#ifndef PXL_H
#define PXL_H

#include<SDL.h>
#include"coord.h"
#include"debug.h"
#include"input.h"




struct color{
  unsigned int r,g,b,a;
};

static const color Red = {255,0,0,255};
static const color Green={0,255,0,255};
static const color Grey ={100,100,100,255};
static const color Black={0,0,0, 255};


struct screen{
  SDL_Renderer* render;
  SDL_Window*   window;
};

screen openWindow(const char* title = "", unsigned int w = 640, unsigned int h = 480 );
void   closeWindow( screen );


void fill( screen, color = Black );
void flip( screen );
void setColor( screen, color );

#endif
