#include "Arm.h"


namespace controller{
    Arm* Arm::_instance = 0;

    Arm* Arm::getInstance(){
        if(_instance == 0){
            _instance = new Arm();
        }
        return _instance;
    }

    Arm::Arm()
    {
        motors = KunokunoMotors::getInstance();
        color = Color::getInstance();
    }

    void Arm::push(int pwm){
        int pushCount = 0;
        do{
            countDetection = new CountDetection(CountDetection::PUSHING_ARM, 360, true, pwm);
            motors->setPushingArmPWM(pwm);
            Display::getInstance()->updateDisplay("    pushing         ", 5);

            while( true ){
                if ( countDetection->isDetected() ){
                    motors->setPushingArmPWM(0);
                    Display::getInstance()->updateDisplay("                    ", 5);
                    break;
                }
            }
            pushCount++;
            if(pushCount >= 3){break;}
        }while(!fallCheck());
    }


    void Arm::giveBack(int pwm){
        int giveBackCount = 0;
        do{
            countDetection = new CountDetection(CountDetection::BACK_ARM, 360, true, pwm);
            motors->setBackArmPWM(pwm);
            Display::getInstance()->updateDisplay("    giving back     ", 5);

            while( true ){
                if ( countDetection->isDetected() ){
                    motors->setBackArmPWM(0);
                    Display::getInstance()->updateDisplay("                    ", 5);
                    break;
                }
            }
            giveBackCount++;
            if(giveBackCount >= 3){break;}
        }while(fallCheck());
    }


    bool Arm::fallCheck(){
        if(color->getColor() == 1){
            return true;
        }else{
            return false;
        }
    }
}
