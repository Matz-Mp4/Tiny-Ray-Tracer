#include "../../include/window.h"

Window::Window(unsigned int width, unsigned int height): 
	height(height),
	width(width),
	window (NULL),
	renderer (NULL)
{} 

Window::~Window(){
}

void Window::init(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void Window::set_pixel(unsigned int x,unsigned int y,int r, int g, int b){
	SDL_SetRenderDrawColor(renderer, r, g, b, 0);
	SDL_RenderDrawPoint(renderer, x, y);
	/* SDL_RenderPresent(renderer); */
}

void Window::show_window() const{
	SDL_RenderPresent(renderer);
}

bool Window::should_close(){
	if(SDL_PollEvent(&event) && event.type == SDL_QUIT){
		return true;
	}
	return false;
}

void Window::close(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
