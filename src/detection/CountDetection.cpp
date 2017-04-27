/**
 * @file CountDetection.cpp
 * @brief 回転量検知クラス
 * @author tozawa
 */

#include "../device/display.h"
Display* disp = Display::getInstance();

#include <stdlib.h>
#include "CountDetection.h"

namespace detection{
    CountDetection::CountDetection(MotorKind KIND, int32_t target_count, bool absolute, int32_t pwm, int32_t base_count){

        motor           = KunokunoMotors::getInstance();
        KIND_           = KIND;
        target_count_   = target_count;
        this->absolute  = absolute;
        this->pwm       = pwm;
        this->setBaseCount(base_count);
    }

    bool CountDetection::isDetected(){
        if ( absolute )
            return isDetectedA();
        else
            return isDetectedR();
    }

    bool CountDetection::isDetectedR(){
        int32_t now_count = -1;
        switch (KIND_) {
        case MotorKind::PUSHING_ARM:
            now_count = motor->getPushingArmCount();
            break;
        case MotorKind::BACK_ARM:
            now_count = motor->getBackArmCount();
            break;
        case MotorKind::WHEEL:
            now_count = motor->getWheelCount();
        }
        disp->updateDisplay("now",now_count,10);
        disp->updateDisplay("base",base_count_,11);
        disp->updateDisplay("tar",target_count_,12);

        if ( pwm > 0 ){
            if (target_count_+base_count_ <= now_count){ return true; }
        }
        else{
            if (target_count_ + base_count_ >= now_count){ return true; }
        }
        return false;
    }

    bool CountDetection::isDetectedA(){
        int32_t now_count = -1;
        int32_t now_digree;
        int32_t margin = 180;
        switch (KIND_) {
        case MotorKind::PUSHING_ARM:
            now_count = motor->getPushingArmCount();
            break;
        case MotorKind::BACK_ARM:
            now_count = motor->getBackArmCount();
            break;
        case MotorKind::WHEEL:
            now_count = motor->getWheelCount();
        }
        now_digree = (now_count + margin + target_count_) % 360;

        if ( abs(now_count - base_count_) < 45) return false;

        if ( !started){
            target_lt_now = now_digree >= margin;
            started = true;
            return false;
        }
        disp->updateDisplay("now",now_digree,10);
        disp->updateDisplay("base", now_digree,11);
        disp->updateDisplay("tar",target_count_,12);

        if ( target_lt_now != ( now_digree >= margin) ){
            //ev3_speaker_play_tone(700, 100);
            if ( ( (pwm > 0) && !target_lt_now) || ((pwm < 0) && target_lt_now) ){
                started = false;
                // ev3_speaker_play_tone(500, 100);
                return true;
            }
            target_lt_now = now_digree >= margin;
        }
        return false;
    }

    void CountDetection::setBaseCount(int32_t base_count){
        if (base_count == -1){
            switch (KIND_) {
            case MotorKind::PUSHING_ARM:
                base_count_ = motor->getPushingArmCount();
                break;
            case MotorKind::BACK_ARM:
                base_count_ = motor->getBackArmCount();
                break;
            case MotorKind::WHEEL:
                base_count_ = motor->getWheelCount();
            }
        } else {
            base_count_ = base_count;
        }
    }

    void CountDetection::setTargetCount(int32_t target_count){
        target_count_ = target_count;
    }

    void CountDetection::setCountConfig(int32_t target_count, int32_t base_count){
        this->setBaseCount(base_count);
        this->setTargetCount(target_count);
    }

    void CountDetection::setTargetMotor(MotorKind KIND){
        KIND_ = KIND;
    }

    CountDetection::PlusOrMinus CountDetection::comparedWithTargetCount(){
        int32_t now_count = -1;
        switch (KIND_) {
        case MotorKind::PUSHING_ARM:
            now_count = motor->getPushingArmCount();
            break;
        case MotorKind::BACK_ARM:
            now_count = motor->getBackArmCount();
            break;
        case MotorKind::WHEEL:
            now_count = motor->getWheelCount();
        }

        if (target_count_+base_count_ > now_count){
            return PlusOrMinus::PLUS;
        }
        return PlusOrMinus::MINUS;
    }
};
