#include "M_Game.h"
#include "M_ErrorLog.h"
int main(int argc, char* argv[]){
	Game game;

	try{
		game.initialize();
	}catch (const char *e){
		ErrorLog err(e); err.write();
		SDL_Quit();
	}

	game.mainLoop();
	game.finalize();
	return 0;
}