#ifndef M_GAMEOBJECTMANAGER_H
#define  M_GAMEOBJECTMANAGER_H
#include "Header.h"
#include "M_FileIO.h"
/*アセットを管理するクラス*/
class GameObjectManager {
protected:
	SDL_Rect src, drw;

public:
	SDL_Surface *image = NULL;
	virtual void load(const char *file);
	virtual void create(SDL_Surface &screen, Sint16 srcX, Sint16 srcY, Uint16 srcW, Uint16 srcH, Sint16 drwX, Sint16 drwY);
};
#endif M_GAMEOBJECTMANAGER_H