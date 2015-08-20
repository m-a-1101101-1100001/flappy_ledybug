#ifndef GAME_H
#define GAME_H
/*ゲームの機能をまとめる*/
class InterfaceGame{

	virtual void update() = 0;//ゲームの状態を更新する
	virtual void draw() = 0;//描画する
	virtual void initialize() = 0;//初期化する
	virtual void mainLoop() = 0;//メインループ
	virtual void finalize() = 0;//終了処理

};
#endif //GAME_H