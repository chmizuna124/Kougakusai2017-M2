/**
 * @brief 検知クラス
 * @author tozawa
 */

#ifndef _DETECTION_H
#define _DETECTION_H

namespace detection{
    /**
     * @brief 検知用インタフェース
     * @author tozawa
     */
    class IDetection{
    public:
        virtual bool isDetected() = 0;
    };
};

#endif
