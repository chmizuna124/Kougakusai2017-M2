#ifndef ARM_
#define ARM_

#include "../device/KunokunoMotors.h"
#include "../detection/CountDetection.h"
#include "../device/display.h"
#include "../device/Color.h"

using namespace detection;
namespace controller{
    class Arm
    {
        public:
            static Arm* getInstance();

            void push(int pwm = 50);
            void giveBack(int pwm = 50);

        private:
            //オブジェクトへのポインタ定義
            KunokunoMotors* motors;
            CountDetection* countDetection;
            Color* color;

            static Arm* _instance;

            //シングルトンなのでプライベート
            Arm();

            bool fallCheck();
    };

}
#endif
