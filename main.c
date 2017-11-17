/*
  SDL2_ttf example
  By Théo Alison
  Created : 17/11/17
  Last changes : 17/11/17

  This is an example of how to use the SDL2_ttf library when it's in the same folder as the project's.

  The main things to consider are those :
    - Execute "./configure" and "make" in the library's folder to compile it first.

    - In the makefile, add -L./SDL2_ttf-2.0.14/.libs and -I./SDL2_ttf-2.0.14 to indicate the location of the library and it's include files.

    - To include the library, just add #include "SDL_ttf" (with double quotes like when including a file from your project)
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "SDL_ttf.h"

int main(int argc,char *argv[])
{
  //Libraries initalization
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  //Variables
  TTF_Font *font=NULL;
  SDL_Window *window=NULL;
  SDL_Renderer *renderer=NULL;
  SDL_Surface *text_alloc=NULL;
  SDL_Texture *text_texture=NULL;
  SDL_Event event;
  SDL_Rect text_pos;
  int prog_end=0;
  SDL_Color black = {0,0,0};
  //Initialization
  SDL_CreateWindowAndRenderer(640,480,SDL_WINDOW_OPENGL,&window,&renderer);
  SDL_SetWindowTitle(window,"SDL2_ttf example");
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  //Text
  font=TTF_OpenFont("./arial.ttf",16);
  char text[]="The Quick Brown Fox Jumps Over The Lazy Dog";
  text_alloc=TTF_RenderText_Solid(font,text,black);
  text_texture=SDL_CreateTextureFromSurface(renderer,text_alloc);
  //Position
  text_pos.x=(640-text_alloc->w)>>1;
  text_pos.y=(480-text_alloc->h)>>1;
  text_pos.w=text_alloc->w;
  text_pos.h=text_alloc->h;
  //Drawing
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer,text_texture,NULL,&text_pos);
  SDL_RenderPresent(renderer);
  //Event Loop
  while(!prog_end)
    {
      while(SDL_PollEvent(&event))
	{
	  if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
	    {
	      prog_end=1;
	    }
	}
    }
  return EXIT_SUCCESS;
}
