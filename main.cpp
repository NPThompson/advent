#include"pxl.h"










screen sc("pxl v 0.0");

//The drawing canvas, viewport origin(offset), and zoom level are managed explicitly.
//screen supplies only the most basic SDL window+renderer functionality.
image canvas;
float zoom = 1.0;
v2    offset(0,0);


bool mainLoop();
void drawCanvas();
void penMode();



int main( int argc, char** argv )
{ canvas = sc.newImage();
  fill( canvas, Grey );
  drawCanvas();
  

  while(mainLoop()){}

  return 0;
}










/*Subroutines*/
bool mainLoop()
{ SDL_Event ev;
  SDL_WaitEvent(&ev);

  static const int view_border = 30;//distance from edge before screen moves

  //escape key -> quit
  if(ev.type == SDL_KEYDOWN )
    { if( ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE )
	return false;
      if( ev.key.keysym.scancode == SDL_SCANCODE_SPACE )
       {zoom = 1.0;
        offset = v2(0,0);
        drawCanvas();
       }
    }


  //Move view when mouse near edges of screen
  if(ev.type == SDL_MOUSEMOTION )
    { if( ev.motion.x < view_border )
	{ offset.x += view_border - ev.motion.x;
	}
      if( ev.motion.x > sc.size().x - view_border )
	{ offset.x -= sc.size().x - ev.motion.x;
	}
      if( ev.motion.y < view_border )
	{ offset.y += view_border - ev.motion.y;
	}
      if( ev.motion.y > sc.size().y - view_border )
	{ offset.y -= sc.size().y - ev.motion.y;
	}
      
      drawCanvas();
    }

  //zoom on scrool
  if(ev.type == SDL_MOUSEWHEEL )
    { if(ev.wheel.y > 0)//zoom in
        zoom *= 1.6;
      if(ev.wheel.y < 0)//zoom out
	zoom /= 1.6;
      drawCanvas();
    }
  
  if(ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT )
    penMode();
  
  return true;
}


//Continue to draw until user releases mouse
void penMode()
{ v2        prev;
  SDL_Event ev;
  bool      fst = true;
  do{
    SDL_WaitEvent( &ev );
    if( fst )
      { drawPoint(canvas, Green, (mouse() - offset)/zoom);
	fst = false;
      }
    else
      drawLine(canvas, Green, (mouse() - offset)/zoom, (prev - offset)/zoom );
    prev = mouse();    
    drawCanvas();
  }while(ev.type != SDL_MOUSEBUTTONUP );


}



void drawCanvas()
{ sc.clear();
  sc.draw( canvas, zoom, offset );
  sc.flip();
}
