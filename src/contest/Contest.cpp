#include "Contest.h"

/**
 * テスト用
 */
#include "../device/Color.h"////////////

using namespace controller;
using namespace sort;
using namespace kunokunosort;
namespace contest {

    /* メンバ */
    Contest* Contest::instance = 0;


    /* コンストラクタ */
    Contest::Contest() {
        su = StartUp::getInstance();
        starter = Starter::getInstance();

        // state = STARTUP;
    }

    /* インスタンス取得 */
    Contest* Contest::getInstance() {
        if (instance == 0) {
            instance = new Contest();
        }
        return instance;
    }

    void Contest::reset(){
        KunokunoMotors::getInstance()->setAllPWM(0, 0, 0);
        su->reset();
        starter->reset();
    }

    /* 走行体制御 */
    void Contest::perform() {
        static int counter = 0;


        /*スタートアップ・スタート受付*/
        if ( su->startUp() && starter->start() ){
            char message[30] = "course: ";
            sprintf(message, "%s %c", message, su->getSelectedCourse());
            ev3_lcd_draw_string(message, 0, 0);

            Display::getInstance()->updateDisplay(" counter: ", counter++, 1);

            /*選択されたコースを攻略する */
            switch(su->getSelectedCourse()){
                /**
                 * Selection sort cource
                 **/
                case 'L':
                    cource = new SelectionSortCource(su->getBallNum());
                    cource->run();
                    reset();
                    break;

                    /**
                     * Bubble sort cource
                     **/
                case 'R':
                    cource = new BubbleSortCource(su->getBallNum());
                    cource->run();
                    reset();
                    break;

                    /**
                     * コース選択画面の表示名を変えるには、
                     * StartUp.cppのselectCourse()内の
                     * courseNamesを変更してください
                     */
                    /**
                     * Quick sort cource
                     **/
                case '1':
                    cource = new QuickSortCource(su->getBallNum());
                    cource->run();
                    reset();
                    break;
                    break;
                    /**
                     * shuffle cource
                     **/
                case '2':
                    cource = new ShuffleCource(su->getBallNum());
                    cource->run();
                    reset();
                    break;
                    /**
                     * auto
                     * ソート→シャッフル を繰り返す
                     **/
                case '3':
                    {
                        int sortedSleepMs   = 20000; // ソート後に止まる時間(ms)
                        int shuffledSleepMs = 15000; // シャッフル後に止まる時間(ms)
                        Touch::State waitState;

                        cource = new SelectionSortCource(su->getBallNum());
                        cource->run();

                        waitState = Touch::getInstance()->wait(sortedSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                        else{
                            cource = new ShuffleCource(su->getBallNum());
                            cource->run();
                        }

                        waitState = Touch::getInstance()->wait(shuffledSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                        else{
                            cource = new BubbleSortCource(su->getBallNum());
                            cource->run();
                        }

                        waitState = Touch::getInstance()->wait(sortedSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                        else{
                            cource = new ShuffleCource(su->getBallNum());
                            cource->run();
                        }

                        waitState = Touch::getInstance()->wait(shuffledSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                        else{
                            cource = new QuickSortCource(su->getBallNum());
                            cource->run();
                        }

                        waitState = Touch::getInstance()->wait(sortedSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                        else{
                            cource = new ShuffleCource(su->getBallNum());
                            cource->run();
                        }

                        waitState = Touch::getInstance()->wait(shuffledSleepMs);
                        if (Touch::LONG_PUSHED == waitState){
                            reset();
                            break;
                        }
                    }
                    break;
                case '4':

                    while(1){
                        Display::getInstance()->updateDisplay("data: ",Color::getInstance()->getColor(),13);
                    }

                    break;
                case '5':
                    break;
                case '6':
                    break;
                case '7':
                    break;
                case '8':
                    break;
                case '9':
                    break;
                case 'A':
                    break;
            }
        }
    }
}
