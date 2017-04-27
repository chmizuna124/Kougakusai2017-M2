//  @date 2015/09/11

#ifndef _SHUFFLE_COURCE_H
#define _SHUFFLE_COURCE_H

#include "ICource.h"
#include "../controller/Move.h"
#include "ev3api.h"
#include "clock.h"
#include "../device/display.h"

namespace kunokunosort {
    class ShuffleCource : public ICource{
        private:
                void swap();
                void finished();
                void shuffle();
                Clock clock;
        public:
                ShuffleCource(int ballNum); //コンストラクタ

                void run();
    };
};

#endif
