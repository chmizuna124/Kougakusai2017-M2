/**
 * @file QuickSort.cpp
 * @brief クイックソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

#include <stdio.h>
#include "ev3api.h"

#include "QuickSort.h"
namespace sort {

QuickSort::QuickSort(int* data, int length){
    Sub_QuickSort(data, 0, length-1);
    //show(data,length);
}

// 再帰関数
// nFirst : ブロックの最初のインデックス
// nLast  : ブロックの最後のインデックス
void QuickSort::Sub_QuickSort(int* data, int nFirst, int nLast){
    
    int iLess    = nFirst;  // 前半のインデックス
    int iGreater = nLast;   // 後半のインデックス
    int x;                  // 「ある値」

    // 「ある値」は両端の要素の平均値にする
    x = (data[nFirst] + data[nLast]) / 2;

    // 交換ループ
    // 位置が逆になると終了
    while(iLess < iGreater)
    {
        // x より小さい要素は無視
        while(data[iLess] < x)
            iLess++;
        // x より大きい要素は無視
        while(data[iGreater] > x)
            iGreater--;

        // 位置がちゃんとしているときは交換し、
        // iLess と iGreater を１つずつ進める
        if(iLess < iGreater){
            swap(data[iLess], data[iGreater] , iLess , iGreater);
            iLess++;iGreater--;
        }
    }
    // iLess == iGreater で終わった時は、
    // iGreater < iLess になるようにする
    if(iLess == iGreater)
    {
        if(data[iLess] < x)
            iLess++;
        else if(data[iLess] > x)
            iGreater--;
    }

    // 次のブロックのサイズが２以上の時は再帰
    if(iLess >= nFirst + 2)
        Sub_QuickSort(data, nFirst, iLess - 1);
    if(iGreater <= nLast - 2)
        Sub_QuickSort(data, iGreater + 1, nLast);

}//end Sub_QuickSort

}//end namespase
