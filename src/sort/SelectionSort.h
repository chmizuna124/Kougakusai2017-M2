/**
 * @file SelectionSort.h
 * @brief 選択ソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

 #ifndef SELECTION_SORT_
 #define SELECTION_SORT_

#include "ISort.h"

namespace sort {
 class SelectionSort : public ISort{

  //private変数
  private:
  int i,n;			//汎用
  int min;	  	//仮の最小値の値
  int min_pos;	//仮の最小値の場所
  	
//public変数
public:

//private関数
private:

//public関数
public: 
SelectionSort(int* data,int length);

 };
}
#endif