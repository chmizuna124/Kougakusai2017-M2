//  @date 2015/09/11

#ifndef _SELECTION_SORT_COURCE_H
#define _SELECTION_SORT_COURCE_H

#include "ICource.h"
#include "../sort/SelectionSort.h"
#include "../controller/Move.h"
#include "ev3api.h"
#include "../device/display.h"

namespace kunokunosort {
    class SelectionSortCource : public ICource{
        private:
        public:
                SelectionSortCource(int ballNum); //コンストラクタ

                void run();
    };
};

#endif
