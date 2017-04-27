/**
 * @file ISort.h
 * @brief ソートクラス
 *  このインターフェイスクラスから派生してそれぞれのソートクラスを作成してください
 * @author kuno
 */

#ifndef _ISORT_H
#define _ISORT_H

#include "ev3api.h"
#include "../controller/Move.h"

using namespace controller;

namespace sort{

    class ISort{
        //private:
        public:
            Move* move;

            ISort(){
                
                move = Move::getInstance();
            }

        //デストラクタ
        //virtual ~IStrategy();

        /**
         * @brief　値の交換．
         * @details 引数a と　引数bの値を入れ替える a_num b_numはa,bの場所?? 移動方法が不明
         */
        inline void swap(int& a, int& b ,int anum,int bnum){

            /*データ上の値入れ替え*/    
            int temp;
            temp = a;
            a = b;
            b = temp;

            /*モーターに命令を出す*/
            move->replacement(anum,bnum);


    }


        /**
         * @brief　配列の値確認．
         * @details 配列の値を全て表示させる
         */
    void show(int* data, int length){

        int i=0;//汎用

        printf("＊＊＊＊＊配列の内容＊＊＊＊＊");
        printf("\n");

        for(i=0;i<length;i++){
            //printf(data[i]+"\n");
            printf("%d",data[i]);
        }

    }


    };
}
#endif
