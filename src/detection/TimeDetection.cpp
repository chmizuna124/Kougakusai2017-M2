/**
 * @file TimeDetection.cpp
 * @brief 時間検知クラス
 * @author sisido
 */

#include "TimeDetection.h"
using namespace device;

namespace detection{
    TimeDetection::TimeDetection(){
        clock           = Clock();
        base_time_      = 0;
        target_time_    = 0;
        display_        = Display::getInstance();
    }

    bool TimeDetection::isDetected(){
        uint32_t now_time_ = clock.now();
        uint32_t def = now_time_ - base_time_;

        char msg[128];
        sprintf(msg,"base : %ld", base_time_);
        display_->updateDisplay(msg, 8);
        sprintf(msg,"tar  : %ld", target_time_);
        display_->updateDisplay(msg, 9);
        sprintf(msg,"now  : %ld", now_time_);
        display_->updateDisplay(msg, 10);
        sprintf(msg,"def  : %ld", def);
        display_->updateDisplay(msg, 11);

        if(def >= target_time_){
            ev3_speaker_play_tone ( 500, 100);
            display_->updateDisplay("target time now! ", 13);
            return true;
        }return false;
    }

    void TimeDetection::setBaseTime (){
        base_time_ = clock.now();
    }

    void TimeDetection::setTargetTime(uint32_t target_time){
        target_time_ = target_time;
    }

    // void TimeDetection::setTimeConfig(uint32_t base_time, uint32_t target_time){
    //     this->setBaseTime(base_time);
    //     this->setTargetTime(target_time);
    // }
};
