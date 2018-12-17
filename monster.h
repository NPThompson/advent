#ifndef PLAYER_H
#define PLAYER_H




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


class monster{
 public:
  monster(v2);

  v2 position, momentum;
};



struct player
{ monster*  avatar;
  keymap    controls;
};



#endif
