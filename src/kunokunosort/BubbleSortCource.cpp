/**
 * @file BubbleSortCource.cpp
 * @brief バブルそートクラス
 * @author nagaoka
 * @date 2016/04/21
 */

#include "BubbleSortCource.h"

using namespace controller;
using namespace sort;

namespace kunokunosort {

    BubbleSortCource::BubbleSortCource(int ballNum):ICource(ballNum){
    }

    void BubbleSortCource::run(){
        Display::getInstance()->updateDisplay("  B U B B L E   S O R T       ",  3);

        started();
        Move::getInstance()->ballCheck(data, getBallNum());
        new BubbleSort(data , getBallNum());
        Move::getInstance()->ballCheck(data, getBallNum());
        Move::getInstance()->traveling(-1);
        finished();
        Display::getInstance()->updateDisplay("                              ",  3);
    }

}
