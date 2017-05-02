/**
 * @file app.cpp
 * @brief メインファイル
 */
/* インクルード */
#include <stdio.h>
#include "ev3api.h"
#include "app.h"
#include "contest/Contest.h"

/* 名前空間 */
using namespace ev3api;
using namespace contest_pkg;

/* 最初からいたやつ */
#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

/* 関数宣言 */
extern void main_task(intptr_t unused);

/* オブジェクトへのポインタ定義 */
Contest* con = Contest::getInstance();

/* メインタスク */
void main_task(intptr_t unused)
{
  // ev3_sta_cyc(CYC_DRIVE);
  while(1) {
    con->perform();
    tslp_tsk(4);

    // 暫定的処置
    // これでとりあえず更新される
    // btも動いてそう (?)
    // ただしスリープしてるので，他に影響が出ないかは不明
  }

  ext_tsk();
}

