/**
 * @file BubbleSort.cpp
 * @brief バブルソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

#include <stdio.h>
#include "ev3api.h"

#include "BubbleSort.h"

namespace sort {

BubbleSort::BubbleSort(int* data,int length){

    // （データの個数－１）回
    for(iLoop = 0; iLoop < length - 1; iLoop++){
        // 比較を行い、大きい方のデータを左に持っていきます
        // 初めは（データの個数－１）回で、一週毎に回数が減っていきます
        for(iComp = 0; iComp < length - 1 - iLoop; iComp++){
            // 比較して、左の方が大きければ交換
            if(data[iComp] > data[iComp + 1]){
                swap(data[iComp], data[iComp + 1] , iComp, iComp + 1);
            }
        }
    }

    //show(data,length);

 }//end BubbleSort

}//end namespase