OGL_INC= -I/usr/X11R6/include
OGL_LIB= -I/usr/lib64 -lGL -lGLU
SDL_INC= `sdl2-config --cflags`
SDL_LIB= `sdl2-config --libs`

OBJS= main.o pxl.o debug.o tools.o image.o draw.o coord.o input.o

CXX= g++
FLAGS= -g -rdynamic
INCLUDE= $(SDL_INC) 
LIBS=    $(SDL_LIB) 

main: $(OBJS)
	$(CXX) $(FLAGS) -o main $(OBJS) $(SDL_LIB)

%.o:%.cpp
	$(CXX) -c $(FLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -f pxl $(OBJS)
