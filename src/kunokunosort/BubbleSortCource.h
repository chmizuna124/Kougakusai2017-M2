//  @date 2015/09/11

#ifndef BUBBLE_SORT_COURCE_H
#define BUBBLE_SORT_COURCE_H

#include "ICource.h"
#include "../sort/BubbleSort.h"
#include "../controller/Move.h"
#include "ev3api.h"
#include "../device/display.h"

namespace kunokunosort {
    class BubbleSortCource : public ICource{
        private:
        public:
                BubbleSortCource(int ballNum); //コンストラクタ

                void run();
    };
};

#endif
