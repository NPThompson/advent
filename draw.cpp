#include"draw.h"
#include<assert.h>


void fill( image i, color C )
{ SDL_Renderer* r = i.context();
  assert( r != NULL );
  
  SDL_SetRenderTarget( r, i.data() );
  SDL_SetRenderDrawColor( r, C.r, C.g, C.b, C.a );
  SDL_RenderClear(   r);
  SDL_RenderPresent( r);

}



void drawPoint( image i, color c, wCoord p )
{ SDL_Renderer* r = i.context();
  assert( r != NULL );

  SDL_SetRenderTarget(r, i.data() );
  SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a );
  SDL_RenderDrawPoint( r, p.x, p.y );
  SDL_RenderPresent( r );
}


void drawLine( image i, color c, wCoord p, wCoord q )
{ SDL_Renderer* r = i.context();
  assert(r != NULL);

  SDL_SetRenderTarget(r, i.data() );
  SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a );
  SDL_RenderDrawLine( r, p.x, p.y, q.x, q.y );
  SDL_RenderPresent( r );
}
 
