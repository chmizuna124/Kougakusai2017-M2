/**
 * @file ShuffleCource.cpp
 * @brief シャッフル
 * @author nagaoka
 * @date 2016/04/21
 */

#include "ShuffleCource.h"
//#include <random>
#include "time.h"
#include "stdlib.h"

using namespace controller;

namespace kunokunosort {

    ShuffleCource::ShuffleCource(int ballNum):ICource(ballNum){
        clock = Clock();
    }

    void ShuffleCource::run(){
        Display::getInstance()->updateDisplay("         S H U F F L E        ",  3);

        started();
        shuffle();
        Move::getInstance()->traveling(-1);
        ICource::finished();
        Display::getInstance()->updateDisplay("                              ",  3);
    }


    void ShuffleCource::swap(){
        int posA, posB;
        srand((unsigned)clock.now() );
        // std::random_device rand;
        posA = rand() % getBallNum();
        posB = rand() % getBallNum();
        while ( posA == posB ){
            posB = rand() % getBallNum();
        }
        Move::getInstance()->replacement(posA, posB);
    }

    void ShuffleCource::shuffle(){
        for ( int i = 0; i <= (getBallNum()/2 + 1); i++){
            Display::getInstance()->drawProgressBar((getBallNum()/2 + 1), i, 4);
            ev3_speaker_play_tone(500, 100);
            swap();
        }
    }

    void playTone(int tone, int timeMs){
        ev3_speaker_play_tone(tone, timeMs);
        tslp_tsk(timeMs);
    }
}
