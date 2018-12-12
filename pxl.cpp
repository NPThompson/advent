/*pxl | N.P.Thompson 2018 | This is free software
  requires SDL 2.0.9
 */

#include"pxl.h"









screen::screen()
{ window = NULL;
  renderer = NULL;
}



screen::screen(const char* title, int w, int h)
{  SDLtry( (window = SDL_CreateWindow(title,
				      SDL_WINDOWPOS_UNDEFINED,
				      SDL_WINDOWPOS_UNDEFINED,
				      w, h,
				      SDL_WINDOW_RESIZABLE )) != NULL );
  
  SDLtry( (renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED )) != NULL );
} 



screen::~screen()
{ SDL_DestroyWindow(   window   );
  SDL_DestroyRenderer( renderer );
}





void screen::clear()
{ SDL_SetRenderTarget( renderer, NULL );
  SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
  SDL_RenderClear(        renderer               );
}



void screen::draw( image graphic )
{ SDL_RenderCopy( renderer, graphic.data(), NULL, NULL );
}



void screen::draw( image graphic, float scale, v2 offset )
{//calculate source and dest rects
  v2 size = graphic.size() * scale;
  SDL_Rect dest = { offset.x, offset.y, size.x, size.y };
  SDL_RenderCopy( renderer, graphic.data(), NULL, &dest );
}



void screen::flip()
{ SDL_RenderPresent( renderer );
}



image screen::newImage()
{ return image( renderer );
}



image screen::newImage(const char* fp)
{ return image( renderer, fp );
}



v2 screen::size()
{ int w,h;
  SDL_GetWindowSize(window,&w,&h);
  return v2(w,h);
}
