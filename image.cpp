#include"pxl.h"
#include<assert.h>










image::image()
{
}



v2 image::size()
{ int w,h;
  SDL_QueryTexture(_data,NULL,NULL,&w,&h);
  return v2(w,h);
}



image::image(SDL_Renderer* _r )
{ _context = _r;
  SDLtry( (_data = SDL_CreateTexture( _context, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 480 )) != NULL );
}



image::image(SDL_Renderer* _r, const char* fp )
{ SDL_Surface* surf = SDL_LoadBMP( fp );
  _context = _r;
  _data = SDL_CreateTextureFromSurface( _context, surf );
  SDL_FreeSurface(surf);
}



SDL_Texture* image::data()
{ return _data;
}



SDL_Renderer* image::context()
{ return _context;
}


