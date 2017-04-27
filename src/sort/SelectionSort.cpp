/**
 * @file SelectionSort.cpp
 * @brief 選択ソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

#include <stdio.h>
#include "ev3api.h"

#include "SelectionSort.h"

namespace sort {
 SelectionSort::SelectionSort(int* data,int length){
 
  for(i=0;i<length-1;i++){
    min=data[i]; //仮の最小値を最初の数にセット
    min_pos=i;   //仮の最小値の場所も覚える

    for(n=i+1;n<length;n++){
      if(data[n]<min){ //比較対象の数字が仮の最小値より小さければ、仮の最小値をそれにする
        min=data[n];
        min_pos=n;
      }
    }
    
    swap(data[i],data[min_pos], i, min_pos);//最小値と最初の数を入れ替え
  }

  //show(data,length);

  }//and SelectionSort
}//end namespase