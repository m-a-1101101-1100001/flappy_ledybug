#ifndef M_SOUND_H
#define M_SOUND_H
#include "M_GameObjectManager.h"
/*����炷�N���X*/
class Sound :
	public GameObjectManager{
private:
	Mix_Chunk *se;
public:
	void load(const char *file);
	void play(int num = 0);
};
#endif //M_SOUND_H