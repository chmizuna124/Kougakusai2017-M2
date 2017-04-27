#ifndef TOUCH_
#define TOUCH_

#include "TouchSensor.h"
#include "SonarSensor.h"
#include "GyroSensor.h"
#include "../detection/TimeDetection.h"
#include "ev3api.h"

using namespace ev3api;
using namespace detection;

class Touch
{
public:
    enum State{
        PUSHED,         // タッチセンサが押されたとき
        LONG_PUSHED,    // 3秒以上おされたとき
        NONE            // 押されていないとき
    };

	static Touch* getInstance();
//タッチセンサ
	/**
	 * タッチセンサ値を返す
	 * 押されていたらtrue
	 * @return タッチセンサ値
	 */
	bool isPressed();

	/**
	 * タッチセンサ値を返す
	 * 押されていたらtrue
	 * @return タッチセンサ値
	 */
	bool isLongPressed();

    /**
     * タッチセンサが押されるまでまつ
     * @param maxMs 待つ最大の時間 -1 の場合無限（default)
     * @return State::PUSHED, LONG_PUSHED, NONE
     */
    State wait(int maxMs = -1);

private:
	//オブジェクトへのポインタ定義
	TouchSensor    touchSensor;

	static Touch* _instance;
	//コンストラクタ
	Touch();

};

#endif
