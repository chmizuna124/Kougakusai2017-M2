//  @date 2015/09/11

#ifndef _QUICK_SORT_COURCE_H
#define _QUICK_SORT_COURCE_H

#include "ICource.h"
#include "../sort/QuickSort.h"
#include "../controller/Move.h"
#include "ev3api.h"
#include "../device/display.h"

namespace kunokunosort {
    class QuickSortCource : public ICource{
        private:
        public:
                QuickSortCource(int ballNum); //コンストラクタ

                void run();
    };
};

#endif
