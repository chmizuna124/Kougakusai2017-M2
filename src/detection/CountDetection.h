/**
 * @file CountDetection.h
 * @brief 回転量検知クラス
 * @author tozawa
 */

#ifndef _COUNT_DETECTION_H
#define _COUNT_DETECTION_H

#include "IDetection.h"
#include "../device/KunokunoMotors.h"
#include "ev3api.h"

namespace detection{
    class CountDetection : public IDetection {
    public:
        /**
         * @brief モータの種類
         * @author tozawa
         */
        enum MotorKind {
            PUSHING_ARM,   //!< 押すやつモータ
            BACK_ARM,   //!< 戻すやつモータ
            WHEEL     //!< タイヤモータ
        };

        /**
         * @brief 正負
         * @author tozawa
         */
        enum PlusOrMinus {
            PLUS,  //!< 正の値
            MINUS  //!< 負の値
        };

    private:
        KunokunoMotors* motor; //!< モータ駆動用のオブジェクト
        int base_count_;   //!< 基底エンコーダ値
        int target_count_; //!< 目標エンコーダ値
        MotorKind KIND_;   //!< 監視対象のモータ
        bool absolute = false;
        int pwm;
        bool target_lt_now;
        bool started = false;

    public:
        /**
         * @brief コンストラクタ.
         * モータの回転量を監視し, 目標回転量に到達した時点でそれを検知する.
         * 基底エンコーダ値を設定し, そこからの差分として目標値を設定する.
         * エンコーダ値の単位は角度である.
         * @param KIND 監視対象のモータ
         * @param target_count 基底エンコーダ値から見た目標エンコーダ値を設定する.
         * @param base_count 基底エンコーダ値を設定する. 省略した場合は現在のエンコーダ値を設定する.
         * @atuhor tozawa
         */
        CountDetection(MotorKind KIND, int32_t target_count, bool absolute,  int32_t pwm, int32_t base_count = -1);

        /**
         * @brief 回転量を検知する.
         * 現在の回転量が目標回転量と一致していれば true となる.
         * コンストラクタの引数とするか,
         * 下記のメソッドを利用して設定を行う.
         * @return 現在の回転量が目標回転量である(true), 目標回転量でない(false)
         * @author tozawa
         */
        bool isDetected();
        bool isDetectedR();
        bool isDetectedA();

        /**
         * @brief 基底エンコーダ値をセットする.
         * 省略した場合は現在のエンコーダ値になる.
         * @param base_count 基底エンコーダ値(角度)
         * @author tozawa
         */
        void setBaseCount(int32_t base_count = -1);

        /**
         * @brief 目標エンコーダ値をセットする
         * @param target_count 目標エンコーダ値(角度)
         * @author tozawa
         */
        void setTargetCount(int32_t target_count);

        /**
         * @brief 各エンコーダ値設定をセットする.
         * 基底エンコーダ値の設定を省略した場合,
         * 現在のエンコーダ値が規定エンコーダ値として設定される.
         * @param target_count 目標エンコーダ値(角度)
         * @param base_count 基底エンコーダ値(角度)
         * @author tozawa
         */
        void setCountConfig(int32_t target_count, int32_t base_count = -1);

        /**
         * @brief 監視対象のモータを設定する.
         * @param KIND 監視対象のモータ
         * @author tozawa
         */
        void setTargetMotor(MotorKind KIND);

        /**
         * @brief 現在のエンコーダ値から見て, 目標エンコーダ値が正負のどちらの方向にあるかを返す.
         * @return 正負
         * @author tozawa
         */
        PlusOrMinus comparedWithTargetCount();
    };
};

#endif
