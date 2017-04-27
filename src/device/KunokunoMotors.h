#ifndef KUNOKUNOMOTORS_
#define KUNOKUNOMOTORS_

#include "ev3api.h"
#include "Motor.h"

using namespace ev3api;

class KunokunoMotors
{
public:
	static KunokunoMotors* getInstance();

	/**
	 * KunokunoMotorsの更新メソッド
	 * ・前回のエンコーダ値更新
	 * ・自己位置推定更新
	 */
	void update();
	//モータリセット
	void motorReset();
	//エンコーダ値初期化
	void initCount();
	//エンコーダ値取得
	int32_t getPushingArmCount();
	int32_t getBackArmCount();
	int32_t getWheelCount();
	//PWMセット
	void setPushingArmPWM(int pwm);
	void setBackArmPWM(int pwm);
	void setWheelPWM(int pwm);
	void setAllPWM(int pushingArm,int backArm,int wheel);

private:
	//オブジェクトへのポインタ定義
	Motor          rWheel;
	Motor          lWheel;
	Motor          pushingArm;
	Motor          backArm;

	static KunokunoMotors* _instance;

	//シングルトンなのでプライベート
	KunokunoMotors();

	int32_t preFMoterCount;	//前回の前輪モータエンコーダ値
	int32_t preLMoterCount;	//前回の左輪モータエンコーダ値
	int32_t preRMoterCount;	//前回の右輪モータエンコーダ値

};

#endif








