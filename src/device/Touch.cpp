#include "Touch.h"

namespace device{
    //インスタンス変数初期化
    Touch* Touch::_instance = 0;

    //シングルトン
    Touch* Touch::getInstance(){
        if(_instance == 0){
            _instance = new Touch();
        }
        return _instance;
    }

    //タッチセンサの状態取得
    bool Touch::isPressed(){
        return touchSensor.isPressed();
    }

    bool Touch::isLongPressed(){

        TimeDetection longTouchDetection = TimeDetection();
        longTouchDetection.setTargetTime(2000);

        while( 1){
            if ( isPressed() ){
                if ( longTouchDetection.isDetected() ){
                    return true;
                }
            }
            else{
                return false;
            }
            tslp_tsk(20);
        }
        return false;
    }

    Touch::State Touch::wait(int maxMs){
        TimeDetection timeDetection = TimeDetection();
        timeDetection.setTargetTime(maxMs);


        while ( 1 ){
            if (isPressed() ){
                if(isLongPressed() ){
                    ev3_speaker_play_tone(700, 300);
                    return LONG_PUSHED;
                }
                else {
                    ev3_speaker_play_tone(500, 100);
                    return PUSHED;
                }
            }
            if ( maxMs > 0 && timeDetection.isDetected() ){
                return NONE;
            }
            tslp_tsk(20);
        }
        return NONE;
    }

    //コンストラクタ
    //ポートを指定している
    Touch::Touch()
        :touchSensor(PORT_1)
        {}
}
