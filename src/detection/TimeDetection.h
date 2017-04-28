/**
 * @file TimeDetection.h
 * @brief 時間検知クラス
 * @author sisido
 */

#ifndef _TIME_DETECTION_H
#define _TIME_DETECTION_H

#include "IDetection.h"
#include "ev3api.h"
#include "Clock.h"
#include "../device/display.h"

using namespace ev3api;
using namespace device;

namespace detection{
	class TimeDetection : public IDetection {

    private:
        /* 時間取得 */
        Clock clock;
        Display* display_;

        /* 基底時間 */
        uint32_t base_time_;
        /* 目標時間 */
        uint32_t target_time_;


    public:
       /**
        * @brief コンストラクタ
        * @author sisido
        */
        TimeDetection();

        /**
        * @brief 目標時間に達したかどうかを検知する
        * 目標時間は基底時間からの経過時間を指す
        * @return 目標時間に達した(true)，してない(false)
        * @author sisido
        */
        bool isDetected();

        /**
        * @brief 基底時間をセットする
        * @author sisido
        */
        void setBaseTime();

        /**
        * @brief 目標時間をセットする
        * 単位はミリ秒なので10秒を目標時間にしたかったら「10000」を引数に指定してください
        * @author sisido
        */
        void setTargetTime(uint32_t target_time);
    };
};

#endif


