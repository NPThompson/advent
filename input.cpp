#include"input.h"



v2 mouse()
{ int x,y;
  SDL_GetMouseState(&x,&y);
  return v2(x,y);
}
	 
