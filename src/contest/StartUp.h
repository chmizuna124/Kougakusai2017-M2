/**
 * @file StartUp.h
 * @brief スタートアップクラス
 * @author motoki nagaoka
 * @date 2015/07/08
 */


#ifndef START_UP_
#define START_UP_
#define BALL_NUM_DEFAULT    12  // ボールの数のデフォルト値
#include "../device/Touch.h"
#include "../device/display.h"

namespace contest{
    class StartUp{
        public:
            /**
             * @brief インスタンスを取得する．
             * @details シングルトンパターンに基づいて，共有のインスタンスを取得する．
             * @return スタートアップクラスのインスタンス
             */
            static StartUp* getInstance();

            /**
             * @brief スタートアップする
             *
             *
             */
            bool startUp();
            void reset();
            /**
             * @brief 選択されたコースを取得する
             * @details Lコース：L, Rコース：R
             *
             * @return 'L', または 'R'
             * @author motoki nagaoka
             */
            char getSelectedCourse();

            int getBallNum();

        private:

            static StartUp* instance;	// インスタンス

            int index = 0;
            bool courseSelected = false;
            int ballNum = BALL_NUM_DEFAULT;
            bool confirmed = false;
            // 前回にタッチセンサが押されていたらtrue
            bool hasPressed = true;

            char selectedCourse = 0;	// 選択されたコース (Lコース； 'L', Rコース：'R')

            Touch* touch;
            Display* display;

            //コンストラクタ
            StartUp();

            bool calibrate();		// キャリブレーションする
            bool selectCourse();	// コースを選択する
            bool isPressed();

    };
}
#endif
