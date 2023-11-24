/*
 * Copyright (C) 2013-2014 Hisense, Inc.
 *
 * Author:
 *   zhaoyufeng <zhaoyufeng@hisense.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _PRODUCTINFO_H_
#define _PRODUCTINFO_H_
enum {
	PRODUCTINFO_VENDOR_ID,
	PRODUCTINFO_BOARD_ID,
	PRODUCTINFO_HW_VERSION_ID,
	PRODUCTINFO_LCD_ID,
	PRODUCTINFO_CTP_ID,
	PRODUCTINFO_SUB_CTP_ID,
	PRODUCTINFO_HDMI_ID,
	PRODUCTINFO_MAIN_CAMERA_ID,
	PRODUCTINFO_FRONT_CAMERA_ID,
	PRODUCTINFO_DDR_ID,
	PRODUCTINFO_EMMC_NAND_ID,
	PRODUCTINFO_EMMC_MORE,
	PRODUCTINFO_UFS_NAND_ID,
	PRODUCTINFO_UFS_MORE,
	PRODUCTINFO_NAND_ID,
	PRODUCTINFO_SENSOR_ACCELEROMETER_ID,
	PRODUCTINFO_SENSOR_COMPASS_ID,
	PRODUCTINFO_SENSOR_ALSPS_ID,
	PRODUCTINFO_BT_ID,
	PRODUCTINFO_WIFI_ID,
	PRODUCTINFO_CODEC_ID,
	PRODUCTINFO_MODEM_ID,
	PRODUCTINFO_LED_ID,
	/* Please add it, yourself! */
	PRODUCTINFO_MAIN_ANX_CAMERA_ID,
	PRODUCTINFO_WIDE_CAMERA_ID,
	PRODUCTINFO_MICRO_CAMERA_ID,
	PRODUCTINFO_SENSOR_GYRO_ID,
	PRODUCTINFO_SENSOR_HALL_ID,
	PRODUCTINFO_CPU_ID,
	PRODUCTINFO_FUSE_ID,
	PRODUCTINFO_FINGERPRINT_ID,
	PRODUCTINFO_NFC_ID,
	PRODUCTINFO_SENSOR_BARO_ID,
	PRODUCTINFO_SENSOR_SAR_ID,
	PRODUCTINFO_SENSOR_TEM_HUM_ID,
	PRODUCTINFO_LCD_COMPATIBLE_ID,
	PRODUCTINFO_ID_NUM,
	PRODUCTINFO_MAX_ID = 40,
	PRODUCTINFO_SIGN = 0x7fffffff,
};

int productinfo_register(int id, const char *devname, const char *devinfo);
int productinfo_dump(char *buf, int offset);
char *get_product_hw_info(int id);

#endif

