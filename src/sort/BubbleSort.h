/**
 * @file bubbleSort.h
 * @brief バブルソートクラス
 * @date 2016/04/14
 * @author kuno 
 */

 #ifndef _BUBBLE_SORT
 #define _BUBBLE_SORT
 
 #include "ISort.h"
 //#include "../drive/LineTrace.h"

namespace sort {
 class BubbleSort : public ISort{

	//private変数
	private:
 	int iLoop;  // （データの個数－１）回回すための変数
    int iComp;  // 比較するときのループ変数


	//public変数
	public:

	//private関数
	private:

	//public関数
	public:
    BubbleSort(int* data,int length);


 };
}
#endif