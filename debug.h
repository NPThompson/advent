
#ifndef STACK_TRACE_H
#define STACK_TRACE_H

#include<execinfo.h>


void prst();




#define trace( _PROP_, _MSG_ )do{ 	\
  if( !( _PROP_ ) )						\
  { fprintf(stderr, "The condition " #_PROP_ " failed in: " );  \
    prst();                                     \
    fprintf(stderr, "%s", _MSG_ );		\
    exit( 0 ); }                                \
  }while(0)

#define SDLtry( _PROP_ ) trace( _PROP_, SDL_GetError() )

//#define trace( _PROP_, _MSG_, ... )do{ _PROP_; }while(0)



#endif
