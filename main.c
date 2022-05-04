#include <stdio.h>
#include <SDL2/SDL.h>
#include "./constant.h"

SDL_Window* window = NULL;
SDL_Renderer *renderer = NULL;

int initialize_window(void){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "Error Initializing SDL: %s\n", SDL_GetError());
		return FALSE;
	}
	
	window = SDL_CreateWindow(
			NULL, //No tiene Titulo la ventana del juego
			SDL_WINDOWPOS_CENTERED, //Centramos la ventana en el medio X
			SDL_WINDOWPOS_CENTERED, //Centramos la ventana en el medio Y
			WINDOW_WIDTH, //Altura en X
			WINDOW_HEIGHT, //Altura en Y
			SDL_WINDOW_BORDERLESS //Ventana sin decoracion
	);
	
	if (!window) {
		fprintf(stderr, "Error creating SDL: %s\n", SDL_GetError());
		return FALSE;
	}
	
	renderer = SDL_CreateRenderer(
			window, //La ventana donde el renderizado se muestra, 
			-1, //el índice del controlador de representación que se va a 
			//inicializar o -1 para inicializar el primero que admite 
			//los indicadores solicitados 
			0 //0, o uno o más SDL_RendererFlags O juntos
			);

	//Si no se Dispara el renderizado, muestra error
	if (!renderer) {	
		fprintf(stderr, "Error creating SDL Renderer: %s\n", 
		SDL_GetError());
		return FALSE;
	}

	 	
	return TRUE;
}

int main(int argc, char *argv[])
{
	initialize_window();

	return 0;
}
