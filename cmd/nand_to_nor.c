/*
 * Copyright (c) 2011 The Chromium OS Authors. All rights reserved.
 *
 * Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * (C) Copyright 2001
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/*
 * Get Timer overflows after 2^32 / CONFIG_SYS_HZ (32Khz) = 131072 sec
 */
#include <common.h>
#include <command.h>
#include <flash.h>

static int do_nand_to_nor(cmd_tbl_t *cmdtp, int flag, int argc,
		      char * const argv[])
{
	char cmd_buf[128];
	ulong flash_size = 0;

	puts("Flash: ");
	flash_size = flash_init();
	print_size(flash_size, "\n");

	strcpy(cmd_buf, "nand read 30000000 u-boot;protect off all;erase 0 7FFFF;cp.b 30000000 0 80000");
	run_command(cmd_buf, 0);
	return 0;
}

U_BOOT_CMD(
	nand_to_nor, 1,	0,	do_nand_to_nor,
	"Copy bootloader from nand to nor",
	"Switch from nandflash to norflash first, Then Copy bootloader from nand to nor"
);

