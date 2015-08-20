#ifndef M_GAME_H
#define M_GAME_H
#include "Header.h"
#include "M_GameObjectManager.h"
#include "M_Character.h"
#include "M_Obstacle.h"
#include "M_Sound.h"
#include "Game.h"
/*ゲームで使うアセット*/
class Assets{
public:
	GameObjectManager background; //背景
	int scroll();//1フレームでスクロールさせる長さ
	GameObjectManager title;//タイトル
	GameObjectManager gameOver;//ゲームオーバー
	Character ledybug;//実機(ledybug)
	Obstacle obstacle[2];//障害物
	void hitCheck();//当たり判定
	Sound hitSE;
};
/*キーボードの入力があったかどうか判断するクラス
イベントを処理したらkeyEventをfalseに戻す
*/
class Keyboard{
public:
	bool keyEvent = false;//キー入力イベントがあったかどうか。イベントを処理したらfalseに戻す
	int keyActivity();//キーイベント
};
/*ゲームを実際に動かすクラス*/
class Game:
	public InterfaceGame  {
private:
	SDL_Surface *screen;//メイン画面
	Assets assets;
	Keyboard keyboard;
	int gameMode = 0;//ゲームのスクリーンを変えるための変数(０タイトル、1ゲーム、2ゲームオーバー)
	virtual Uint32 delayTime();//フレームレートの最適化(fps30)
	bool fulag = false;//延滞処理が必要か
	virtual void update();
	virtual void draw();

public:
	virtual void initialize();//例外がでるようにしてある
	virtual void mainLoop();
	virtual void finalize();
};
#endif //M_GAME_H