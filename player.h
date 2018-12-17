#ifndef PLAYER_H
#define PLAYER_H
#include<SDL.h>
#include"coord.h"



enum control{
  Left = 0,
  Right,
  Up,
  Down,
  A,
  B,
  Start,
  Select,
  Size//Not a value -- gives the size needed to specify an array indexable by control
};
typedef SDL_Scancode keymap[control::Size];

static const keymap defaultP1keymap = {
  SDL_SCANCODE_LEFT,
  SDL_SCANCODE_RIGHT,
  SDL_SCANCODE_UP,
  SDL_SCANCODE_DOWN,
  SDL_SCANCODE_X,
  SDL_SCANCODE_Z,
  SDL_SCANCODE_RETURN,
  SDL_SCANCODE_TAB
};



class monster{
 public:
  monster(v2);

  v2 position, momentum;
};



struct player
{ monster*  avatar;
  const SDL_Scancode* controls;
};


void controlavatar( player );

#endif
