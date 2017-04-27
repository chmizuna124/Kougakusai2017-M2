
/**
 * @file StartUp.cpp
 * @date 2015/07/08
 * @note  スタートアップクラス
 * @author motoki nagaoka
 */
#include "StartUp.h"
#include "stdio.h"

#define COURSES_NUM 	12 // コースの数 2 + テスト用

namespace contest{

    StartUp* StartUp::instance = 0;

    StartUp::StartUp(){
        touch = Touch::getInstance();
        display = Display::getInstance();
    }

    StartUp* StartUp::getInstance(){
        if (!instance) {
            instance = new StartUp();
        }
        return instance;
    }

    bool StartUp::startUp(){
        return selectCourse();
    }

    void StartUp::reset(){
        courseSelected = false;
        confirmed = false;
        // 前回にタッチセンサが押されていたらtrue
        hasPressed = true;
    }

    char StartUp::getSelectedCourse(){
        return selectedCourse;
    }


    bool StartUp::selectCourse(){

        //　前回にタッチセンサが押されていて、まだ離されていないとき
        if ( hasPressed && isPressed() )
            return courseSelected && confirmed;
        else // タッチセンサが離されたとき
            hasPressed = false;


        // ↑ ボタンが押されたとき
        if (ev3_button_is_pressed (UP_BUTTON) ){
            hasPressed = true;
            index--;
        }
        // ↓ ボタンが押されたとき
        else if (ev3_button_is_pressed (DOWN_BUTTON)){
            hasPressed = true;
            index++;
        }
        // → ボタンが押されたとき
        else if (ev3_button_is_pressed (RIGHT_BUTTON)){
            hasPressed = true;
            ballNum++;
        }
        // 左 ボタンが押されたとき
        else if (ev3_button_is_pressed (LEFT_BUTTON)){
            hasPressed = true;
            ballNum--;
        }
        // エンターボタンが押されたとき
        else if (ev3_button_is_pressed (ENTER_BUTTON)){
            hasPressed = true;
            courseSelected = true;
            switch(index){
                case 0:
                    selectedCourse = 'L';
                    break;
                case 1:
                    selectedCourse = 'R';
                    break;

                    // テスト用
                case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
                    selectedCourse = '0' + index -1;
                    break;
                case 11:
                    selectedCourse = 'A' + index - 10;
                    break;
            }
            // 音を出す
            ev3_speaker_play_tone ( 500, 100);
        }
        if (index < 0)
            index = 0;
        if (index >= COURSES_NUM)
            index = COURSES_NUM - 1;

        char courseNames[COURSES_NUM][30] = {"   SELECTION SORT          ",
            "   BUBBLE SORT             ",
            "   QUICK SORT          ",
            "   SHUFFLE                 ",
            "   AUTO                      ",
            "   T4                      ",
            "   T5                        ",
            "   T6                        ",
            "   T7                        ",
            "   T8                        ",
            "   T9                        ",
            "   T10                       "};
        courseNames[index][1] = '>';

        if (!courseSelected){
            display-> updateDisplay("                            ", 0);
            display-> updateDisplay("        SELECT COURSE       ", 1);
            display-> updateDisplay("Number of balls", ballNum, 2);

            for (int low = 0; low < COURSES_NUM; low++){
                display -> updateDisplay(courseNames[low], low + 3);
            }
        }
        else if (courseSelected && !confirmed){
            if (ev3_button_is_pressed (ENTER_BUTTON) || touch->isPressed() ){
                hasPressed = true;
                confirmed = true;
            }

            char message[30];
            sprintf(message, "  SELECTED COURSE: %c", selectedCourse);
            for ( int i = 0; i < 15; i++){
                display-> updateDisplay("                            ", i);
            }
            display-> updateDisplay(message, 3);
        }

        return courseSelected && confirmed;
    }

    bool StartUp::isPressed(){
        bool anyPressed = false;
        anyPressed = anyPressed || touch->isPressed();
        anyPressed = anyPressed || ev3_button_is_pressed (UP_BUTTON);
        anyPressed = anyPressed || ev3_button_is_pressed (DOWN_BUTTON);
        anyPressed = anyPressed || ev3_button_is_pressed (ENTER_BUTTON);
        anyPressed = anyPressed || ev3_button_is_pressed (LEFT_BUTTON);
        anyPressed = anyPressed || ev3_button_is_pressed (RIGHT_BUTTON);
        return anyPressed;
    }

    int StartUp::getBallNum(){
        return ballNum;
    }

}
