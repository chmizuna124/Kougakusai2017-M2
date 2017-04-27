/**
 * @file quickSort.h
 * @brief クイックソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

 #ifndef QUICK_SORT_
 #define QUICK_SORT_

#include "ISort.h"

namespace sort {
 class QuickSort : public ISort{

     //private関数
     private:
     void Sub_QuickSort(int* data, int nFirst, int nLast);

     //public関数
     public:
     QuickSort(int* data, int length);

 };
}
#endif