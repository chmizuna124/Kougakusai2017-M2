/**
 * @file IStrategy.h
 * @brief 戦略クラス
 *  このインターフェイスクラスから派生してそれぞれの戦略のクラスを作成してください
 * @author kuno
 */

#ifndef _ICOURCE_H
#define _ICOURCE_H

#include "ev3api.h"

#define BALL_NUM_MAX 20      // ボールの数
#define BALL_NUM_DEFAULT 12      // ボールの数


namespace kunokunosort{

    class ICource{
        private:
            int ballNum = BALL_NUM_DEFAULT;
        public:
            int data[BALL_NUM_MAX];             // ボールの情報

        ICource(int ballNum); // コンストラクタ
        //デストラクタ
        //virtual ~IStrategy();

        /**
         * @brief 攻略する．
         * @details
         */
        virtual void run() = 0;

        void finished();
        void started();
        void playTone(int tone, int timeMs);

        int getBallNum();
    };
}
#endif
