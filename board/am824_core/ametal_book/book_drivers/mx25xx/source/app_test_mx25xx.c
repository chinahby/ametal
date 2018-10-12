/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2014 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      ametal.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief book`s mx25xx driver for AM824
 * 
 * \internal
 * \par Modification history
 * - 1.00 18-09-18  adw, first implementation.
 * \endinternal
 */
#include "ametal.h"
#include "am_mx25xx.h"

int app_test_mx25xx (am_mx25xx_handle_t mx25xx_handle)
{
    int i;
    static uint8_t buf[128];

    am_mx25xx_erase(mx25xx_handle, 0x001000, 4096);     // 擦除扇区1
    for (i = 0; i < 128; i++)        buf[i] = i;        // 装载数据
    am_mx25xx_write(mx25xx_handle, 0x001000, buf, 128);
    for (i = 0; i < 128; i++)        buf[i] = 0x0;      // 将所有数据清0
    am_mx25xx_read(mx25xx_handle, 0x001000, buf, 128);
    for(i = 0; i < 128; i++) {
        if (buf[i] != i) {
            return AM_ERROR;
        }
    }
    return AM_OK;
}


/* end of file */
