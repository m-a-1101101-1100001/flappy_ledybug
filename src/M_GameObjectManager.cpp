#include "M_GameObjectManager.h"
void GameObjectManager::load(const char *file){
	FileIO fileIO(file); 
	image = IMG_Load(fileIO.readAssets());
}

void GameObjectManager::create(SDL_Surface &screen, Sint16 srcX, Sint16 srcY, Uint16 srcW, Uint16 srcH, Sint16 drwX, Sint16 drwY){
	src.x = srcX; src.y = srcY; src.w = srcW; src.h = srcH;
	drw.x = drwX; drw.y = drwY;
	SDL_BlitSurface(image, &src, &screen, &drw);
}