#include"pxl.h"
#include"draw.h"
#include"player.h"








auto                sc   = openWindow("advent v 0.0");
static const Uint8* kbd;
player              p1;
               

bool    mainLoop();
void    handleControls();
void    redraw();
void    update(double);
#define quit()      closeWindow(sc); return false








int main( int argc, char** argv )
{ p1.avatar   = new monster(v2(10,10));
  p1.controls = defaultP1keymap;

  while(mainLoop())
    {}
  return 0;
}










/*Subroutines*/
bool mainLoop()
{ //waitforevent();
  pollevents();
  
  //escape key -> quit
  ifev(SDL_KEYDOWN)
    {ifev(SDL_SCANCODE_ESCAPE)
	{ quit();
	}
    }

  //close window -> quit
  ifev(SDL_QUIT)
    { quit();
    }

  //default continue
  handleControls();
  update(0.001);
  redraw();
  return true;
}



void update(double dt)
{ p1.avatar->position += p1.avatar->momentum * dt;
}



void redraw()
{ fill( sc, Black );
  drawmonster(sc,*p1.avatar);
  flip( sc );
}



void handleControls()
{static         bool fst = true;

 //Only call GetKeyboardState the first time handleControls is called, use fst to tell if this is the first time
 if(fst)
  {kbd = SDL_GetKeyboardState(NULL);
   fst = false;//never call GetKeyboardState again
  }

 controlavatar( p1 );
}





#define ifk( _C_ ) if( kbd [ p.controls[ control::_C_ ]])

void controlavatar( player p )
{ if( p.avatar != NULL )
    { ifk( Left )
	{ p.avatar->momentum += v2(-1, 0 );
	}
      ifk( Right )
	{ p.avatar->momentum += v2( 1, 0 );
	}
      ifk( Up )
	{ p.avatar->momentum += v2( 0,-1 );
	}
      ifk( Down )
	{ p.avatar->momentum += v2( 0, 1 );
	}
    }
}
#undef ifk
