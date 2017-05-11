/**
 * @file Contest.cpp
 * @brief 競技クラス
 * @author usui kakeru
 */

#include "Contest.h"


namespace contest_pkg {

    /* メンバ */
    Contest* Contest::instance_ = 0;
    device::Touch* Contest::hogetouch_ = 0;

    /* コンストラクタ */
    Contest::Contest() {
        startUp_ = StartUp::getInstance();
        hogetouch_ = device::Touch::getInstance();
        //bool doremi_[7] = {false};
        prePressed_ = false;
        count_ = 0;
        oto_ = 0;
    }

    /* インスタンス取得 */
    Contest* Contest::getInstance() {
        if (instance_ == 0) {
            instance_ = new Contest();
        }
        return instance_;
    }

    /* 走行体制御 */
    void Contest::perform() {
        static bool initialized = false;

        /*スタートアップ*/
        if ( startUp_->isFinished() ){
            /*選択されたコースのインスタンスを生成する */
            switch(startUp_->getSelectedCourse()){
            case 'L':
                if (!initialized) {
                    // courseL_ = new Course(SelectedCourse::L_COURSE);
                    initialized = true;
                }
                break;

            case 'R':
                if (!initialized) {
                    // courseR_ = new Course(SelectedCourse::R_COURSE);
                    initialized = true;
                }
                break;
            }

            /* スタート受付 */
            if ( startUp_->acceptStart() ){
                switch (startUp_->getSelectedCourse() ){
                    case 'L':
                    if(hogetouch_->isPressed() == true){
                        if(prePressed_ == false){
                            if(count_%7 == 0){
                                oto_ = NOTE_C4;
                            }
                            else if(count_%7 == 1){
                                oto_ = NOTE_D4;
                            }
                            else if(count_%7 == 2){
                                oto_ = NOTE_E4;
                            }
                            else if(count_%7 == 3){
                                oto_ = NOTE_F4;
                            }
                            else if(count_%7 == 4){
                                oto_ = NOTE_G4;
                            }
                            else if(count_%7 == 5){
                                oto_ = NOTE_A4;
                            }
                            else if(count_%7 == 6){
                                oto_ = NOTE_B4;
                            }
                            ev3_speaker_play_tone(oto_, 300);
                            count_++;
                        }
                        prePressed_ = true;
                    }
                    else{
                        prePressed_ = false;
                    }
                    // courseL_->capture();
                    break;
                    case 'R':
                    // courseR_->capture();
                    break;
                }
            }
        }
    }
}
