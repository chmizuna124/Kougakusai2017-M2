/**
 * @file Move.h
 * @date 2016/04/14
 * @author 薄井翔
 */

#ifndef MOVE_H
#define MOVE_H

#include "../device/KunokunoMotors.h"//モーター
#include "../device/Color.h"//カラーセンサ
#include "../device/display.h"
#include "Arm.h"//アーム
#include "../detection/CountDetection.h"//回転検知
#include "../kunokunosort/ICource.h"


#define ANGLE_OF_ONE 72     //1マス移動するのに必要な角度
#define WHEEL_REVERSED 0    // 歯車を使ってタイヤが逆回転するとき:true(1)

using namespace detection;

namespace controller{
    class Move{
        private:
            KunokunoMotors* motor; //モーター
            Arm* arm;
            Color* color;
            Display* disp;
            CountDetection* count_d;//回転検知
            int present_position;//現在地

            static Move* _instance;

        public:
            static Move* getInstance();



            /**
             * @brief 走行する
             * @details 目的地まで走行する
             * 
             * @param distination 目的地(-1 <= distination <= tmp_position)
             */
            void traveling(int distination);

            /**
             * @brief 現在地を取得
             * @return 現在地
             */
            int getPosition();

            /**
             * @brief 現在地設定
             * 
             * @param position セットする現在地
             */
            void setPosition(int position);

            /**
             * @brief ボールの入れ替え
             * @details 2つのボールをtmpを使って入れ替える
             * 
             * @param distination1 入れ替えるボール(始めにpushされる)
             * @param distination2 入れ替えるボール
             */
            void replacement(int distination1,int distination2);

            /**
             * @brief ボールの色を確認
             * @details 1マスごとにボールの色を確認して移動し配列に格納する
             * 
             * @param data ボールの色が入る配列
             */
            void ballCheck(int* data, int ballNum);


        private:

            Move();

            /**
             * @details 実際の距離に変換して走行する
             * 
             * @param distination 目的地
             */
            void rotation(int distance);

            /**
             * @brief 距離計算
             * @details 現在地から目的地までの距離を計算
             * 
             * @param destination 目的地
             * @return 目的地までの距離
             */
            int distanceCalc(int distination);

            /**
             * @details 目的地が存在するか確認
             * 
             * @param distination 目的地
             * @return 存在するかどうか
             */
            bool destinationCheck(int distination);

            /**
             * @brief カラーを複数回取得する
             * @details カラーをnumber回取得し、同じ値になるまで繰り返す
             * 
             * @param number 繰り返し回数
             * @return カラーID
             */
            int getColorLoop(int number);

            /**
             * @brief ColorIDを近似する
             * @details 同じボールでも異なる値をとることがあるので、同じ値に近似する
             * 
             * @param color ColorID
             * @return 近似値
             */
            int approximate(int color);


    };
}
#endif
