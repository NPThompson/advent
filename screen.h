#ifndef SCREEN_H
#define SCREEN_H




class image{
public:
  image();
  image(SDL_Renderer*);
  image(SDL_Renderer*,const char*);
  SDL_Texture*  data();
  SDL_Renderer* context();
  v2 size();    
private:
  SDL_Texture*  _data;
  SDL_Renderer* _context;
};





class screen{
public:
  screen();
  screen(const char*, int = 640, int = 480);
  ~screen();

  void clear();
  void draw(image); //draw direct
  void draw(image, float, v2 = v2(0,0));//draw with scale and translation
  void flip();
  bool doQuit();

  v2 size();
  
  image newImage();
  image newImage(const char*);
  
private:
  SDL_Event     input;
  SDL_Window*   window;
  SDL_Renderer* renderer;
};



#endif
