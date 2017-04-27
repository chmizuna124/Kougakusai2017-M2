/**
 * @file QuickSortCource.cpp
 * @brief 選択そートクラス
 * @author nagaoka
 * @date 2016/04/21
 */

#include "QuickSortCource.h"

using namespace controller;
using namespace sort;

namespace kunokunosort {

    QuickSortCource::QuickSortCource(int ballNum):ICource(ballNum){
    }

    void QuickSortCource::run(){
        Display::getInstance()->updateDisplay("    Q U I C K   S O R T       ",  3);

        started();
        Move::getInstance()->ballCheck(data, getBallNum());
        new QuickSort(data , getBallNum());
        Move::getInstance()->ballCheck(data, getBallNum());
        Move::getInstance()->traveling(-1);
        finished();
        Display::getInstance()->updateDisplay("                              ",  3);
    }

}
