#include"input.h"




wCoord mouse()
{ int x,y;
  SDL_GetMouseState(&x,&y);
  return wCoord(x,y);
}


bool doQuit()
{ SDL_Event input;
  SDL_PollEvent(&input);
  return input.key.keysym.scancode == SDL_SCANCODE_ESCAPE;
}
