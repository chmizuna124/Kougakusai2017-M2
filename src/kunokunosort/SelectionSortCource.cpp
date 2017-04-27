/**
 * @file SelectionSortCource.cpp
 * @brief 選択そートクラス
 * @author nagaoka
 * @date 2016/04/21
 */

#include "SelectionSortCource.h"

using namespace controller;
using namespace sort;

namespace kunokunosort {

    SelectionSortCource::SelectionSortCource(int ballNum):ICource(ballNum){
    }

    void SelectionSortCource::run(){
        Display::getInstance()->updateDisplay("  S E L E C T I O N  S O R T  ",  3);

        started();
        Move::getInstance()->ballCheck(data, getBallNum());
        new SelectionSort(data , getBallNum());
        Move::getInstance()->ballCheck(data, getBallNum());
        Move::getInstance()->traveling(-1);
        ICource::finished();

        Display::getInstance()->updateDisplay("                              ",  3);
    }

}
