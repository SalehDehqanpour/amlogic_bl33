
/*
 * board/amlogic/txl_skt_v1/firmware/timing.c
 *
 * Copyright (C) 2015 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <asm/arch/secure_apb.h>
#include <asm/arch/timing.h>
#include <asm/arch/ddr_define.h>

/* DDR freq range */
#define CONFIG_DDR_CLK_LOW  375
#define CONFIG_DDR_CLK_HIGH 1500
/* DON'T OVER THESE RANGE */

#if 0
#if (CONFIG_DDR_CLK < CONFIG_DDR_CLK_LOW) || (CONFIG_DDR_CLK > CONFIG_DDR_CLK_HIGH)
	#error "Over DDR PLL range! Please check CONFIG_DDR_CLK in board header file! \n"
#endif
#endif

/* CPU freq range */
#define CONFIG_CPU_CLK_LOW  600
#define CONFIG_CPU_CLK_HIGH 2000
/* DON'T OVER THESE RANGE */
#if (CONFIG_CPU_CLK < CONFIG_CPU_CLK_LOW) || (CONFIG_CPU_CLK > CONFIG_CPU_CLK_HIGH)
	#error "Over CPU PLL range! Please check CONFIG_CPU_CLK in board header file! \n"
#endif

#define DDR3_DRV_40OHM		0
#define DDR3_DRV_34OHM		1
#define DDR3_ODT_0OHM		0
#define DDR3_ODT_60OHM		1
#define DDR3_ODT_120OHM		2
#define DDR3_ODT_40OHM		3
#define DDR3_ODT_20OHM		4
#define DDR3_ODT_30OHM		5

/* lpddr2 drv odt */
#define LPDDR2_DRV_34OHM	1
#define LPDDR2_DRV_40OHM	2
#define LPDDR2_DRV_48OHM	3
#define LPDDR2_DRV_60OHM	4
#define LPDDR2_DRV_80OHM	6
#define LPDDR2_DRV_120OHM	7
#define LPDDR2_ODT_0OHM		0

/* lpddr3 drv odt */
#define LPDDR3_DRV_34OHM	1
#define LPDDR3_DRV_40OHM	2
#define LPDDR3_DRV_48OHM	3
#define LPDDR3_DRV_60OHM	4
#define LPDDR3_DRV_80OHM	6
#define LPDDR3_DRV_34_40OHM	9
#define LPDDR3_DRV_40_48OHM	10
#define LPDDR3_DRV_34_48OHM	11
#define LPDDR3_ODT_0OHM		0
#define LPDDR3_ODT_60OHM	1
#define LPDDR3_ODT_12OHM	2
#define LPDDR3_ODT_240HM	3

#define DDR4_DRV_34OHM		0
#define DDR4_DRV_48OHM		1
#define DDR4_ODT_0OHM		0
#define DDR4_ODT_60OHM		1
#define DDR4_ODT_120OHM		2
#define DDR4_ODT_40OHM		3
#define DDR4_ODT_240OHM		4
#define DDR4_ODT_48OHM		5
#define DDR4_ODT_80OHM		6
#define DDR4_ODT_34OHM		7

#if ((CONFIG_DDR_TYPE == CONFIG_DDR_TYPE_DDR3) || (CONFIG_DDR_TYPE == CONFIG_DDR_TYPE_AUTO))
#define CFG_DDR_DRV  DDR3_DRV_34OHM
#define CFG_DDR_ODT  DDR3_ODT_60OHM
#elif (CONFIG_DDR_TYPE == CONFIG_DDR_TYPE_LPDDR2)
#define CFG_DDR_DRV  LPDDR2_DRV_48OHM
#define CFG_DDR_ODT  DDR3_ODT_120OHM
#elif (CONFIG_DDR_TYPE == CONFIG_DDR_TYPE_LPDDR3)
#define CFG_DDR_DRV  LPDDR3_DRV_48OHM
#define CFG_DDR_ODT  LPDDR3_ODT_12OHM
#elif (CONFIG_DDR_TYPE == CONFIG_DDR_TYPE_DDR4)
#define CFG_DDR_DRV  DDR4_DRV_34OHM //useless, no effect
#define CFG_DDR_ODT  DDR4_ODT_60OHM //useless, no effect
#endif

#define CFG_DDR4_DRV  DDR4_DRV_48OHM //ddr4 driver use this one
#define CFG_DDR4_ODT  DDR4_ODT_60OHM //ddr4 driver use this one

/*
 * these parameters are corresponding to the pcb layout,
 * please don't enable this function unless these signals
 * has been measured by oscilloscope.
 */
#ifdef CONFIG_DDR_CMD_BDL_TUNE
#define DDR_AC_LCDLR   0
#define	DDR_CK0_BDL	18
#define	DDR_RAS_BDL	18
#define	DDR_CAS_BDL	24
#define	DDR_WE_BDL	21
#define	DDR_BA0_BDL	16
#define	DDR_BA1_BDL	2
#define	DDR_BA2_BDL	13
#define	DDR_ACPDD_BDL	27
#define	DDR_CS0_BDL	27
#define	DDR_CS1_BDL	27
#define	DDR_ODT0_BDL	27
#define	DDR_ODT1_BDL	27
#define	DDR_CKE0_BDL	27
#define	DDR_CKE1_BDL	27
#define	DDR_A0_BDL	14
#define	DDR_A1_BDL	9
#define	DDR_A2_BDL	5
#define	DDR_A3_BDL	18
#define	DDR_A4_BDL	4
#define	DDR_A5_BDL	16
#define	DDR_A6_BDL	1
#define	DDR_A7_BDL	10
#define	DDR_A8_BDL	4
#define	DDR_A9_BDL	7
#define	DDR_A10_BDL	10
#define	DDR_A11_BDL	9
#define	DDR_A12_BDL	6
#define	DDR_A13_BDL	16
#define	DDR_A14_BDL	8
#define	DDR_A15_BDL	27
#endif

/* CAUTION!! */
/* If you don't know how to config following parameters, then don't edit it. */




ddr_timing_t __ddr_timming[] = {
	{0},
	{0},
};



ddr_reg_t __ddr_reg[] = {
	/* demo, user defined override register */
	{0xaabbccdd, 0, 0, 0, 0, 0},
	{0x11223344, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
};

bl2_reg_t __bl2_reg[] = {
	/* demo, user defined override register */
	/* eg: PWM init */
	{0xabcdef12, 0, 0, 0, 0, 0},
	{0xfedcba00, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
};

ddr_set_t __ddr_setting[] = {
{
	/* common and function defines */
	.board_id				= 1,
	.version				= 1,
	.dram_rank_config		= CONFIG_DDR_CHANNEL_SET,
	.DramType				= CONFIG_DDR_TYPE,
	.DRAMFreq				= CONFIG_DDR_CLK,
	.ddr_base_addr			= CFG_DDR_BASE_ADDR,
	.ddr_start_offset		= CFG_DDR_START_OFFSET,
	.imem_load_addr			= 0xFFFC0000, //sram
	.dmem_load_size			= 0x1000, //4K

	.DisabledDbyte			= 0xf0,
	.Is2Ttiming				= 1,
	.HdtCtrl				= 0x0a,
	.dram_cs0_size_MB		= 2048,
	.dram_cs1_size_MB		= 0,
	.training_SequenceCtrl	= {0x31f,0x61}, //ddr3 0x21f 0x31f
	.phy_odt_config_rank	= {0x23,0x13}, // // Odt pattern for accesses //targeting rank 0. [3:0] is used //for write ODT [7:4] is used for //read ODT
	.dfi_odt_config			= 0x0808,
	.PllBypassEn			= 0, //bit0-ps0,bit1-ps1
	.ddr_rdbi_wr_enable		= 0,
	.pll_ssc_mode			= 0,
	.clk_drv_ohm			= 40,
	.cs_drv_ohm				= 40,
	.ac_drv_ohm				= 40,
	.soc_data_drv_ohm_p		= 40,
	.soc_data_drv_ohm_n		= 40,
	.soc_data_odt_ohm_p		= 60,
	.soc_data_odt_ohm_n		= 0,
	.dram_data_drv_ohm		= 40,
	.dram_data_odt_ohm		= 60,
	.dram_ac_odt_ohm		= 0,
	.soc_clk_slew_rate		= 0,
	.soc_cs_slew_rate		= 0,
	.soc_ac_slew_rate		= 0,
	.soc_data_slew_rate		= 0,
	.vref_output_permil		= 860,
	.vref_receiver_permil	= 0,
	.vref_dram_permil		= 0,
	.vref_reverse			= 0,
	.ac_trace_delay			= {00,00},
	.ac_pinmux				= {00,00},
	.ddr_dmc_remap			= {
							[0] = ( 5 |  7 << 5 |  8 << 10 |  9 << 15 | 10 << 20 | 11 << 25 ),
							[1] = ( 12|  0 << 5 |  0 << 10 | 14 << 15 | 15 << 20 | 16 << 25 ),
							[2] = ( 17| 18 << 5 | 19 << 10 | 21 << 15 | 22 << 20 | 23 << 25 ),
							[3] = ( 24| 25 << 5 | 26 << 10 | 27 << 15 | 28 << 20 | 29 << 25 ),
							[4] = ( 30| 13 << 5 | 20 << 10 |  6 << 15 |  0 << 20 |  0 << 25 ),
	},
	.ddr_lpddr34_ca_remap	= {00,00},
	.ddr_lpddr34_dq_remap	= {00,00},
	.dram_rtt_nom_wr_park	= {00,00},

	.ddr_func				= DDR_FUNC,
},
{
	.board_id				= 8,
	.DRAMFreq				= {2222, 3333, 4444, 5555},
},
};

pll_set_t __pll_setting = {
	.cpu_clk				= CONFIG_CPU_CLK / 24 * 24,
#ifdef CONFIG_PXP_EMULATOR
	.pxp					= 1,
#else
	.pxp					= 0,
#endif
	.spi_ctrl				= 0,
	.lCustomerID			= CONFIG_AML_CUSTOMER_ID,
#ifdef CONFIG_DEBUG_MODE
	.debug_mode				= CONFIG_DEBUG_MODE,
	.ddr_clk_debug			= CONFIG_DDR_CLK_DEBUG,
	.cpu_clk_debug			= CONFIG_CPU_CLK_DEBUG,
#endif
};

