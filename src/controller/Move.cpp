/**
 * @file Move.cpp
 * @date 2016/04/14
 * @author 薄井翔
 */

#include "Move.h"
#include <math.h>
#include <stdio.h>
namespace controller{
    Move* Move::_instance = 0;

    Move* Move::getInstance(){
        if(_instance == 0){
            _instance = new Move();
        }
        return _instance;
    }

    Move::Move(){
        motor 			 = KunokunoMotors::getInstance();
        arm 			 = Arm::getInstance();
        color 			 = Color::getInstance();
        disp 			 = Display::getInstance();
        present_position = -1;//現在地
    }


    //目的地まで移動する
    void Move::traveling(int distination){
        int distance = 0;//走行する距離
        if(destinationCheck(distination)){//入力値が正しければ
            distance = distanceCalc(distination);//距離計算
            if(distance == 0){//目的地が現在地だったら移動しない
                return;
            }else{
                rotation(distance);
                //setPosition(distination);//現在地更新
            }
        }else{
            return;
        }
    }



    int Move::getPosition(){
        return present_position;
    }

    void Move::setPosition(int position){
        present_position = position;
    }


    void Move::rotation(int distance){
        int pwm = 16;

        if(distance < 0){
            pwm = -pwm;
        }

        // 歯車を使ってタイヤが逆回転するとき
        if ( WHEEL_REVERSED ){
            pwm         *= -1;
            distance    *= -1;
        }

        count_d = new CountDetection(

                CountDetection::WHEEL,      // MotorKind
                (present_position + distance + 1) * ANGLE_OF_ONE,    // target_count
                false,                      // absolute
                pwm,                        // pwm
                0                           // base_count
                );

                //CountDetection::WHEEL , (present_position + distance + 1) * ANGLE_OF_ONE,0);

        motor->setWheelPWM(pwm);

        while(true){
            if(count_d->isDetected()){
                motor->setWheelPWM(0);
                setPosition(present_position+distance);//現在地更新
                break;
            }
        }

    }


    int Move::distanceCalc(int distination){
        return distination - present_position;
    }

    bool Move::destinationCheck(int distination){
        if(distination > BALL_NUM_MAX || distination < -1){
            return false;
        }else{
            return true;
        }
    }

    void Move::replacement(int distination1,int distination2){
        if(distination1 == distination2){
            return;
        }

        //一つ目のボールをtmpに運ぶ
        traveling(distination1);
        arm->push();
        traveling(-1);
        arm->giveBack();

        //二つ目のボールを一つ目に運ぶ

        traveling(distination2);
        arm->push();
        traveling(distination1);
        arm->giveBack();

        //tmpのボールを二つ目に運ぶ
        traveling(-1);
        arm->push();
        traveling(distination2);
        arm->giveBack();
    }



    void Move::ballCheck(int* data, int ballNum){
        char buf1[30]          = "data   ";
        char buf2[ballNum][4] = {0};
        traveling(-1);
        for(int i = 0; i < ballNum; i++){
            //ひとつ移動
            traveling(i);
            //色取得

            //data[i] = approximate(color->getColor());
            data[i] = getColorLoop(10);

            // 音を出す
            ev3_speaker_play_tone(200 + data[i] * 80, 300);

            //文字列結合
            sprintf(buf2[i],"_%d",data[i]);
            strcat(buf1,buf2[i]);
        }

        disp->updateDisplay("                           ",13);
        disp->updateDisplay(buf1,13);
    }

    int Move::getColorLoop(int number){
        char buf[30];
        int colors[number]  = {0};
        int loopNumber      = number;

        while(loopNumber > 0){
            tslp_tsk(10);
            colors[loopNumber-1] = color->getColor();
            sprintf(buf,"data : %d",colors[loopNumber-1]);
            disp->updateDisplay(buf,13);
            //異なる値が入ったらやりなおし
            if(loopNumber != number && 
                    colors[loopNumber-1] != colors[loopNumber]){
                loopNumber = number;
                continue;
            }

            loopNumber--;
        }

        return colors[0];
    }

    int Move::approximate(int colorID){
        /*
           赤ビー玉	7
           みどり	5
           白		6
           青		2
           青ビー玉	1
         */

        int realColor = 0;
        switch(colorID){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            default :
                realColor = colorID;
                break;
        }

        return realColor;
    }

}
