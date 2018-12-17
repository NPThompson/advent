/*pxl | N.P.Thompson 2018 | This is free software
  requires SDL 2.0.9
 */

#include"pxl.h"











screen openWindow(const char* title, unsigned int w, unsigned int h)
{ screen sdl;
  
  SDLtry( (sdl.window = SDL_CreateWindow(title,
				      SDL_WINDOWPOS_UNDEFINED,
				      SDL_WINDOWPOS_UNDEFINED,
				      w, h,
				      SDL_WINDOW_RESIZABLE )) != NULL );
  
  SDLtry( (sdl.render = SDL_CreateRenderer( sdl.window, -1, SDL_RENDERER_ACCELERATED )) != NULL );
  
  return sdl;
} 

void closeWindow(screen sdl)
{ SDL_DestroyWindow(sdl.window);
  SDL_DestroyRenderer(sdl.render);
}



void setColor( screen sc, color c )
{SDL_SetRenderDrawColor(sc.render,c.r,c.g,c.b,c.a);
}



void fill( screen sc, color c )
{ setColor(sc,c);
  SDL_RenderClear(sc.render);
}



void flip( screen sc )
{SDL_RenderPresent(sc.render);
}



// void screen::draw( image graphic )
// { SDL_RenderCopy( renderer, graphic.data(), NULL, NULL );
// }



// void screen::draw( image graphic, float scale, v2 offset )
// {//calculate source and dest rects
//   v2 size = graphic.size() * scale;
//   SDL_Rect dest = { offset.x, offset.y, size.x, size.y };
//   SDL_RenderCopy( renderer, graphic.data(), NULL, &dest );
// }



// void screen::flip()
// { SDL_RenderPresent( renderer );
// }



// image screen::newImage()
// { return image( renderer );
// }



// image screen::newImage(const char* fp)
// { return image( renderer, fp );
// }



// v2 screen::size()
// { int w,h;
//   SDL_GetWindowSize(window,&w,&h);
//   return v2(w,h);
// }
