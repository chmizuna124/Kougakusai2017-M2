/**
 * @file ICource.cpp
 * @brief こーす
 * @author nagaoka
 * @date 2016/04/21
 */

#include "ICource.h"


namespace kunokunosort {

    ICource::ICource(int ballNum){
        this->ballNum = ballNum;
    }

    int ICource::getBallNum(){
        return ballNum;
    }


    void ICource::started(){
        playTone(200, 150);
        playTone(300, 150);
        playTone(500, 150);
        playTone(700, 150);
    }
    void ICource::finished(){
        playTone(300, 200);
        playTone(500, 200);
        playTone(300, 200);
        playTone(700, 400);
    }

    void ICource::playTone(int tone, int timeMs){
        ev3_speaker_play_tone(tone, timeMs);
        tslp_tsk(timeMs);
    }
}
