/*
 * Copyright (C) 2015 Kuldeep Singh Dhaka <kuldeepdhaka9@gmail.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UNICOREMX_EFM32_DAC_H
#define UNICOREMX_EFM32_DAC_H

#include <unicore-mx/efm32/memorymap.h>
#include <unicore-mx/cm3/common.h>
#include <unicore-mx/efm32/prs.h>

#define DAC_CTRL(base)		MMIO32((base) + 0x00)
#define DAC_STATUS(base)	MMIO32((base) + 0x04)
#define DAC_CHx_CTRL(base, x)	MMIO32((base) + 0x08 + (0x04 * (x)))
#define DAC_CH0CTRL(base)	DAC_CHx_CTRL(base, 0)
#define DAC_CH1CTRL(base)	DAC_CHx_CTRL(base, 1)
#define DAC_IEN(base)		MMIO32((base) + 0x010)
#define DAC_IF(base)		MMIO32((base) + 0x014)
#define DAC_IFS(base)		MMIO32((base) + 0x018)
#define DAC_IFC(base)		MMIO32((base) + 0x01C)
#define DAC_CH0DATA(base)	MMIO32((base) + 0x020)
#define DAC_CH1DATA(base)	MMIO32((base) + 0x024)
#define DAC_COMBDATA(base)	MMIO32((base) + 0x028)
#define DAC_CAL(base)		MMIO32((base) + 0x02C)
#define DAC_BIASPROG(base)	MMIO32((base) + 0x030)
#define DAC_OPACTRL(base)	MMIO32((base) + 0x054)
#define DAC_OPAOFFSET(base) MMIO32((base) + 0x058)
#define DAC_OPA0MUX(base)	MMIO32((base) + 0x05C)
#define DAC_OPA1MUX(base)	MMIO32((base) + 0x060)
#define DAC_OPA2MUX(base)	MMIO32((base) + 0x064)

/* DAC_CTRL */
#define DAC_CTRL_REFRSEL_SHIFT		(20)
#define DAC_CTRL_REFRSEL_MASK		(0x3 << DAC_CTRL_REFRSEL_SHIFT)
#define DAC_CTRL_REFRSEL(v)			\
	(((v) << DAC_CTRL_REFRSEL_SHIFT) & DAC_CTRL_REFRSEL_MASK)
#define DAC_CTRL_REFRSEL_8CYCLES	DAC_CTRL_REFRSEL(0)
#define DAC_CTRL_REFRSEL_16CYCLES	DAC_CTRL_REFRSEL(1)
#define DAC_CTRL_REFRSEL_32CYCLES	DAC_CTRL_REFRSEL(2)
#define DAC_CTRL_REFRSEL_64CYCLES	DAC_CTRL_REFRSEL(3)

#define DAC_CTRL_PRESC_SHIFT		(16)
#define DAC_CTRL_PRESC_MASK		(0x7 << DAC_CTRL_PRESC_SHIFT)
#define DAC_CTRL_PRESC(v)		\
	(((v) << DAC_CTRL_PRESC_SHIFT) & DAC_CTRL_PRESC_MASK)
#define DAC_CTRL_PRESC_DIV1		DAC_CTRL_PRESC(0)
#define DAC_CTRL_PRESC_DIV2		DAC_CTRL_PRESC(1)
#define DAC_CTRL_PRESC_DIV4		DAC_CTRL_PRESC(2)
#define DAC_CTRL_PRESC_DIV8		DAC_CTRL_PRESC(3)
#define DAC_CTRL_PRESC_DIV16		DAC_CTRL_PRESC(4)
#define DAC_CTRL_PRESC_DIV32		DAC_CTRL_PRESC(5)
#define DAC_CTRL_PRESC_DIV64		DAC_CTRL_PRESC(6)
#define DAC_CTRL_PRESC_DIV128		DAC_CTRL_PRESC(7)
#define DAC_CTRL_PRESC_NODIV		DAC_CTRL_PRESC_DIV1

#define DAC_CTRL_REFSEL_SHIFT		(8)
#define DAC_CTRL_REFSEL_MASK		(0x3 << DAC_CTRL_REFSEL_SHIFT)
#define DAC_CTRL_REFSEL(v)		\
	(((v) << DAC_CTRL_REFSEL_SHIFT) & DAC_CTRL_REFSEL_MASK)
#define DAC_CTRL_REFSEL_1V25		DAC_CTRL_REFSEL(0)
#define DAC_CTRL_REFSEL_2V5		DAC_CTRL_REFSEL(1)
#define DAC_CTRL_REFSEL_VDD		DAC_CTRL_REFSEL(2)

#define DAC_CTRL_CH0PRESCRST		(1 << 7)
#define DAC_CTRL_OUTENPRS		(1 << 6)

#define DAC_CTRL_OUTMODE_SHIFT		(4)
#define DAC_CTRL_OUTMODE_MASK		(0x3 << DAC_CTRL_OUTMODE_SHIFT)
#define DAC_CTRL_OUTMODE(v)		\
	(((v) << DAC_CTRL_OUTMODE_SHIFT) & DAC_CTRL_OUTMODE_MASK)
#define DAC_CTRL_OUTMODE_DISABLE	DAC_CTRL_OUTMODE(0)
#define DAC_CTRL_OUTMODE_PIN		DAC_CTRL_OUTMODE(1)
#define DAC_CTRL_OUTMODE_ADC		DAC_CTRL_OUTMODE(2)
#define DAC_CTRL_OUTMODE_PINADC		DAC_CTRL_OUTMODE(3)

#define DAC_CTRL_CONVMODE_SHIFT		(2)
#define DAC_CTRL_CONVMODE_MASK		(0x3 << DAC_CTRL_CONVMODE_SHIFT)
#define DAC_CTRL_CONVMODE(v)		\
	(((v) << DAC_CTRL_CONVMODE_SHIFT) & DAC_CTRL_CONVMODE_MASK)
#define DAC_CTRL_CONVMODE_CONTINUOUS	DAC_CTRL_CONVMODE(0)
#define DAC_CTRL_CONVMODE_SAMPLEHOLD	DAC_CTRL_CONVMODE(1)
#define DAC_CTRL_CONVMODE_SAMPLEOFF	DAC_CTRL_CONVMODE(2)

#define DAC_CTRL_SINMODE		(1 << 1)
#define DAC_CTRL_DIFF			(1 << 0)

/* DAC_STATUS */
#define DAC_STATUS_CH1DV		(1 << 1)
#define DAC_STATUS_CH0DV		(1 << 0)

/* DAC_CH_CTRL */
#define DAC_CH_CTRL_PRSSEL_SHIFT	(4)
#define DAC_CH_CTRL_PRSSEL_MASK		(0xF << DAC_CH_CTRL_PRSSEL_SHIFT)
#define DAC_CH_CTRL_PRSSEL(v)		\
	(((v) << DAC_CH_CTRL_PRSSEL_SHIFT) & DAC_CH_CTRL_PRSSEL_MASK)
#define DAC_CH_CTRL_PRSSEL_PRSCHx(x)	DAC_CH_CTRL_PRSSEL(x)
#define DAC_CH_CTRL_PRSSEL_PRSCH0	DAC_CH_CTRL_PRSSEL_PRSCHx(0)
#define DAC_CH_CTRL_PRSSEL_PRSCH1	DAC_CH_CTRL_PRSSEL_PRSCHx(1)
#define DAC_CH_CTRL_PRSSEL_PRSCH2	DAC_CH_CTRL_PRSSEL_PRSCHx(2)
#define DAC_CH_CTRL_PRSSEL_PRSCH3	DAC_CH_CTRL_PRSSEL_PRSCHx(3)
#define DAC_CH_CTRL_PRSSEL_PRSCH4	DAC_CH_CTRL_PRSSEL_PRSCHx(4)
#define DAC_CH_CTRL_PRSSEL_PRSCH5	DAC_CH_CTRL_PRSSEL_PRSCHx(5)
#define DAC_CH_CTRL_PRSSEL_PRSCH6	DAC_CH_CTRL_PRSSEL_PRSCHx(6)
#define DAC_CH_CTRL_PRSSEL_PRSCH7	DAC_CH_CTRL_PRSSEL_PRSCHx(7)
#define DAC_CH_CTRL_PRSSEL_PRSCH8	DAC_CH_CTRL_PRSSEL_PRSCHx(8)
#define DAC_CH_CTRL_PRSSEL_PRSCH9	DAC_CH_CTRL_PRSSEL_PRSCHx(9)
#define DAC_CH_CTRL_PRSSEL_PRSCH10	DAC_CH_CTRL_PRSSEL_PRSCHx(10)
#define DAC_CH_CTRL_PRSSEL_PRSCH11	DAC_CH_CTRL_PRSSEL_PRSCHx(11)

#define DAC_CH_CTRL_PRSEN	(1 << 2)
#define DAC_CH_CTRL_REFREN	(1 << 1)
#define DAC_CH_CTRL_EN		(1 << 0)

/* DAC_CH0CTRL */
#define DAC_CH0CTRL_PRSSEL_SHIFT	DAC_CH_CTRL_PRSSEL_SHIFT
#define DAC_CH0CTRL_PRSSEL_MASK		DAC_CH_CTRL_PRSSEL_MASK
#define DAC_CH0CTRL_PRSSEL(v)		DAC_CH_CTRL_PRSSEL(v)
#define DAC_CH0CTRL_PRSSEL_PRSCHx(x)	DAC_CH_CTRL_PRSSEL_PRSCHx(x)
#define DAC_CH0CTRL_PRSSEL_PRSCH0	DAC_CH0CTRL_PRSSEL_PRSCH0
#define DAC_CH0CTRL_PRSSEL_PRSCH1	DAC_CH_CTRL_PRSSEL_PRSCH1
#define DAC_CH0CTRL_PRSSEL_PRSCH2	DAC_CH_CTRL_PRSSEL_PRSCH2
#define DAC_CH0CTRL_PRSSEL_PRSCH3	DAC_CH_CTRL_PRSSEL_PRSCH3
#define DAC_CH0CTRL_PRSSEL_PRSCH4	DAC_CH_CTRL_PRSSEL_PRSCH4
#define DAC_CH0CTRL_PRSSEL_PRSCH5	DAC_CH_CTRL_PRSSEL_PRSCH5
#define DAC_CH0CTRL_PRSSEL_PRSCH6	DAC_CH_CTRL_PRSSEL_PRSCH6
#define DAC_CH0CTRL_PRSSEL_PRSCH7	DAC_CH_CTRL_PRSSEL_PRSCH7
#define DAC_CH0CTRL_PRSSEL_PRSCH8	DAC_CH_CTRL_PRSSEL_PRSCH8
#define DAC_CH0CTRL_PRSSEL_PRSCH9	DAC_CH_CTRL_PRSSEL_PRSCH9
#define DAC_CH0CTRL_PRSSEL_PRSCH10	DAC_CH_CTRL_PRSSEL_PRSCH10
#define DAC_CH0CTRL_PRSSEL_PRSCH11	DAC_CH_CTRL_PRSSEL_PRSCH11

#define DAC_CH0CTRL_PRSEN	DAC_CH_CTRL_PRSEN
#define DAC_CH0CTRL_REFREN	DAC_CH_CTRL_REFREN
#define DAC_CH0CTRL_EN		DAC_CH_CTRL_EN

/* DAC_CH1CTRL */
#define DAC_CH1CTRL_PRSSEL_SHIFT	DAC_CH_CTRL_PRSSEL_SHIFT
#define DAC_CH1CTRL_PRSSEL_MASK		DAC_CH_CTRL_PRSSEL_MASK
#define DAC_CH1CTRL_PRSSEL(v)		DAC_CH_CTRL_PRSSEL(v)
#define DAC_CH1CTRL_PRSSEL_PRSCHx(x)	DAC_CH_CTRL_PRSSEL_PRSCHx(x)
#define DAC_CH1CTRL_PRSSEL_PRSCH0	DAC_CH_CTRL_PRSSEL_PRSCH0
#define DAC_CH1CTRL_PRSSEL_PRSCH1	DAC_CH_CTRL_PRSSEL_PRSCH1
#define DAC_CH1CTRL_PRSSEL_PRSCH2	DAC_CH_CTRL_PRSSEL_PRSCH2
#define DAC_CH1CTRL_PRSSEL_PRSCH3	DAC_CH_CTRL_PRSSEL_PRSCH3
#define DAC_CH1CTRL_PRSSEL_PRSCH4	DAC_CH_CTRL_PRSSEL_PRSCH4
#define DAC_CH1CTRL_PRSSEL_PRSCH5	DAC_CH_CTRL_PRSSEL_PRSCH5
#define DAC_CH1CTRL_PRSSEL_PRSCH6	DAC_CH_CTRL_PRSSEL_PRSCH6
#define DAC_CH1CTRL_PRSSEL_PRSCH7	DAC_CH_CTRL_PRSSEL_PRSCH7
#define DAC_CH1CTRL_PRSSEL_PRSCH8	DAC_CH_CTRL_PRSSEL_PRSCH8
#define DAC_CH1CTRL_PRSSEL_PRSCH9	DAC_CH_CTRL_PRSSEL_PRSCH9
#define DAC_CH1CTRL_PRSSEL_PRSCH10	DAC_CH_CTRL_PRSSEL_PRSCH10
#define DAC_CH1CTRL_PRSSEL_PRSCH11	DAC_CH_CTRL_PRSSEL_PRSCH11

#define DAC_CH1CTRL_PRSEN	DAC_CH_CTRL_PRSEN
#define DAC_CH1CTRL_REFREN	DAC_CH_CTRL_REFREN
#define DAC_CH1CTRL_EN		DAC_CH_CTRL_EN

/* DAC_IEN */
#define DAC_IEN_CH1UF	(5 << 0)
#define DAC_IEN_CH0UF	(4 << 0)
#define DAC_IEN_CH1	(1 << 1)
#define DAC_IEN_CH0	(1 << 0)

/* DAC_IF */
#define DAC_IF_CH1UF	(5 << 0)
#define DAC_IF_CH0UF	(4 << 0)
#define DAC_IF_CH1	(1 << 1)
#define DAC_IF_CH0	(1 << 0)

/* DAC_IFS */
#define DAC_IFS_CH1UF	(5 << 0)
#define DAC_IFS_CH0UF	(4 << 0)
#define DAC_IFS_CH1	(1 << 1)
#define DAC_IFS_CH0	(1 << 0)

/* DAC_IFC */
#define DAC_IFC_CH1UF	(5 << 0)
#define DAC_IFC_CH0UF	(4 << 0)
#define DAC_IFC_CH1	(1 << 1)
#define DAC_IFC_CH0	(1 << 0)

/* DAC_CAL */
#define DAC_CAL_GAIN_SHIFT	(16)
#define DAC_CAL_GAIN_MASK	(0x7F << DAC_CAL_GAIN_SHIFT)
#define DAC_CAL_GAIN(v)		\
	(((v) << DAC_CAL_GAIN_SHIFT) & DAC_CAL_GAIN_MASK)

#define DAC_CAL_CH1OFFSET_SHIFT	(8)
#define DAC_CAL_CH1OFFSET_MASK	(0x3F << DAC_CAL_CH1OFFSET_SHIFT)
#define DAC_CAL_CH1OFFSET(v)	\
	(((v) << DAC_CAL_CH1OFFSET_SHIFT) & DAC_CAL_CH1OFFSET_MASK)

#define DAC_CAL_CH0OFFSET_SHIFT	(0)
#define DAC_CAL_CH0OFFSET_MASK	(0x3F << DAC_CAL_CH0OFFSET_SHIFT)
#define DAC_CAL_CH0OFFSET(v)	\
	(((v) << DAC_CAL_CH0OFFSET_SHIFT) & DAC_CAL_CH0OFFSET_MASK)

/* DAC_BIASPROG */
#define DAC_BIASPROG_OPA2HALFBIAS	(1 << 14)

#define DAC_BIASPROG_OPA2BIASPROG_SHIFT	(8)
#define DAC_BIASPROG_OPA2BIASPROG_MASK	(0xF << DAC_BIASPROG_OPA2BIASPROG_SHIFT)
#define DAC_BIASPROG_OPA2BIASPROG(v)		\
	((((v) << DAC_BIASPROG_OPA2BIASPROG_SHIFT)) & \
	DAC_BIASPROG_OPA2BIASPROG_MASK)

#define DAC_BIASPROG_HALFBIAS		(1 << 6)

#define DAC_BIASPROG_BIASPROG_SHIFT	(0)
#define DAC_BIASPROG_BIASPROG_MASK	(0xF << DAC_BIASPROG_BIASPROG_SHIFT)
#define DAC_BIASPROG_BIASPROG(v)	\
	((((v) << DAC_BIASPROG_BIASPROG_SHIFT)) & DAC_BIASPROG_BIASPROG_MASK)

/* DAC_OPACTRL */
#define DAC_OPACTRL_OPA2SHORT		(1 << 24)
#define DAC_OPACTRL_OPA1SHORT		(1 << 23)
#define DAC_OPACTRL_OPA0SHORT		(1 << 22)

#define DAC_OPACTRL_OPA2LPFDIS_SHIFT	(16)
#define DAC_OPACTRL_OPA2LPFDIS_MASK	(0x3 << DAC_OPACTRL_OPA2LPFDIS_SHIFT)
#define DAC_OPACTRL_OPA2LPFDIS(v)	\
	(((v) << DAC_OPACTRL_OPA2LPFDIS_SHIFT) & DAC_OPACTRL_OPA2LPFDIS_MASK)
#define DAC_OPACTRL_OPA2LPFDIS_PLPFDIS	DAC_OPACTRL_OPA2LPFDIS(0b01)
#define DAC_OPACTRL_OPA2LPFDIS_NLPFDIS	DAC_OPACTRL_OPA2LPFDIS(0b10)

#define DAC_OPACTRL_OPA1LPFDIS_SHIFT	(14)
#define DAC_OPACTRL_OPA1LPFDIS_MASK	(0x3 << DAC_OPACTRL_OPA1LPFDIS_SHIFT)
#define DAC_OPACTRL_OPA1LPFDIS(v)	\
	(((v) << DAC_OPACTRL_OPA1LPFDIS_SHIFT) & DAC_OPACTRL_OPA1LPFDIS_MASK)
#define DAC_OPACTRL_OPA1LPFDIS_PLPFDIS	DAC_OPACTRL_OPA1LPFDIS(0b01)
#define DAC_OPACTRL_OPA1LPFDIS_NLPFDIS	DAC_OPACTRL_OPA1LPFDIS(0b10)

#define DAC_OPACTRL_OPA0LPFDIS_SHIFT	(14)
#define DAC_OPACTRL_OPA0LPFDIS_MASK	(0x3 << DAC_OPACTRL_OPA0LPFDIS_SHIFT)
#define DAC_OPACTRL_OPA0LPFDIS(v)	\
	(((v) << DAC_OPACTRL_OPA0LPFDIS_SHIFT) & DAC_OPACTRL_OPA0LPFDIS_MASK)
#define DAC_OPACTRL_OPA0LPFDIS_PLPFDIS	DAC_OPACTRL_OPA0LPFDIS(0b01)
#define DAC_OPACTRL_OPA0LPFDIS_NLPFDIS	DAC_OPACTRL_OPA0LPFDIS(0b10)

#define DAC_OPACTRL_OPA2HCMDIS		(1 << 8)
#define DAC_OPACTRL_OPA1HCMDIS		(1 << 7)
#define DAC_OPACTRL_OPA0HCMDIS		(1 << 6)

#define DAC_OPACTRL_OPA2EN		(1 << 2)
#define DAC_OPACTRL_OPA1EN		(1 << 1)
#define DAC_OPACTRL_OPA0EN		(1 << 0)

/* DAC_OPA0MUX */
#define DAC_OPA0MUX_RESSEL_SHIFT	(28)
#define DAC_OPA0MUX_RESSEL_MASK		(0x7 << DAC_OPA0MUX_RESSEL_SHIFT)
#define DAC_OPA0MUX_RESSEL_RESSEL(v)	\
	((((v) << DAC_OPA0MUX_RESSEL_SHIFT)) & DAC_OPA0MUX_RESSEL_MASK)
#define DAC_OPA0MUX_RESSEL_RESSEL_RESx(x)	DAC_OPA0MUX_RESSEL_RESSEL(x)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES0	DAC_OPA0MUX_RESSEL_RESSEL_RESx(0)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES1	DAC_OPA0MUX_RESSEL_RESSEL_RESx(1)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES2	DAC_OPA0MUX_RESSEL_RESSEL_RESx(2)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES3	DAC_OPA0MUX_RESSEL_RESSEL_RESx(3)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES4	DAC_OPA0MUX_RESSEL_RESSEL_RESx(4)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES5	DAC_OPA0MUX_RESSEL_RESSEL_RESx(5)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES6	DAC_OPA0MUX_RESSEL_RESSEL_RESx(6)
#define DAC_OPA0MUX_RESSEL_RESSEL_RES7	DAC_OPA0MUX_RESSEL_RESSEL_RESx(7)

#define DAC_OPA0MUX_NEXTOUT		(1 << 26)

#define DAC_OPA0MUX_OUTMODE_SHIFT	(22)
#define DAC_OPA0MUX_OUTMODE_MASK	(0x3 << DAC_OPA0MUX_OUTMODE_SHIFT)
#define DAC_OPA0MUX_OUTMODE(v)		\
	(((v) << DAC_OPA0MUX_OUTMODE_SHIFT) & DAC_OPA0MUX_OUTMODE_MASK)
#define DAC_OPA0MUX_OUTMODE_DISABLE	DAC_OPA0MUX_OUTMODE(0)
#define DAC_OPA0MUX_OUTMODE_MAIN	DAC_OPA0MUX_OUTMODE(1)
#define DAC_OPA0MUX_OUTMODE_ALT		DAC_OPA0MUX_OUTMODE(2)
#define DAC_OPA0MUX_OUTMODE_ALL		DAC_OPA0MUX_OUTMODE(3)

#define DAC_OPA0MUX_OUTPEN_SHIFT	(18)
#define DAC_OPA0MUX_OUTPEN_MASK		(0x1F << DAC_OPA0MUX_OUTPEN_SHIFT)
#define DAC_OPA0MUX_OUTPEN(v)		\
	(((v) << DAC_OPA0MUX_OUTPEN_SHIFT) & DAC_OPA0MUX_OUTPEN_MASK)
#define DAC_OPA0MUX_OUTPEN_OUT0		DAC_OPA0MUX_OUTPEN(1 << 0)
#define DAC_OPA0MUX_OUTPEN_OUT1		DAC_OPA0MUX_OUTPEN(1 << 1)
#define DAC_OPA0MUX_OUTPEN_OUT2		DAC_OPA0MUX_OUTPEN(1 << 2)
#define DAC_OPA0MUX_OUTPEN_OUT3		DAC_OPA0MUX_OUTPEN(1 << 3)
#define DAC_OPA0MUX_OUTPEN_OUT4		DAC_OPA0MUX_OUTPEN(1 << 4)

#define DAC_OPA0MUX_NPEN		(1 << 13)
#define DAC_OPA0MUX_PPEN		(1 << 12)

#define DAC_OPA0MUX_RESINMUX_SHIFT	(8)
#define DAC_OPA0MUX_RESINMUX_MASK	(0x7 << DAC_OPA0MUX_RESINMUX_SHIFT)
#define DAC_OPA0MUX_RESINMUX(v)		\
	(((v) << DAC_OPA0MUX_RESINMUX_SHIFT) & DAC_OPA0MUX_RESINMUX_MASK)
#define DAC_OPA0MUX_RESINMUX_DISABLE	DAC_OPA0MUX_RESINMUX(0)
#define DAC_OPA0MUX_RESINMUX_OPA0INP	DAC_OPA0MUX_RESINMUX(1)
#define DAC_OPA0MUX_RESINMUX_NEGPAD	DAC_OPA0MUX_RESINMUX(2)
#define DAC_OPA0MUX_RESINMUX_POSPAD	DAC_OPA0MUX_RESINMUX(3)
#define DAC_OPA0MUX_RESINMUX_VSS	DAC_OPA0MUX_RESINMUX(4)

#define DAC_OPA0MUX_NEGSEL_SHIFT	(4)
#define DAC_OPA0MUX_NEGSEL_MASK		(0x3 << DAC_OPA0MUX_NEGSEL_SHIFT)
#define DAC_OPA0MUX_NEGSEL(v)		\
	(((v) << DAC_OPA0MUX_NEGSEL_SHIFT) & DAC_OPA0MUX_NEGSEL_MASK)
#define DAC_OPA0MUX_NEGSEL_DISABLE	DAC_OPA0MUX_NEGSEL(0)
#define DAC_OPA0MUX_NEGSEL_UG		DAC_OPA0MUX_NEGSEL(1)
#define DAC_OPA0MUX_NEGSEL_OPATAP	DAC_OPA0MUX_NEGSEL(2)
#define DAC_OPA0MUX_NEGSEL_NEGPAD	DAC_OPA0MUX_NEGSEL(3)

#define DAC_OPA0MUX_POSSEL_SHIFT	(0)
#define DAC_OPA0MUX_POSSEL_MASK		(0x7 << DAC_OPA0MUX_POSSEL_SHIFT)
#define DAC_OPA0MUX_POSSEL(v)		\
	(((v) << DAC_OPA0MUX_POSSEL_SHIFT) & DAC_OPA0MUX_POSSEL_MASK)
#define DAC_OPA0MUX_POSSEL_DISABLE	DAC_OPA0MUX_POSSEL(0)
#define DAC_OPA0MUX_POSSEL_DAC		DAC_OPA0MUX_POSSEL(1)
#define DAC_OPA0MUX_POSSEL_POSPAD	DAC_OPA0MUX_POSSEL(2)
#define DAC_OPA0MUX_POSSEL_OPA0INP	DAC_OPA0MUX_POSSEL(3)
#define DAC_OPA0MUX_POSSEL_OPATAP	DAC_OPA0MUX_POSSEL(4)

/* DAC_OPA1MUX */
#define DAC_OPA1MUX_RESSEL_SHIFT	(28)
#define DAC_OPA1MUX_RESSEL_MASK		(0x7 << DAC_OPA1MUX_RESSEL_SHIFT)
#define DAC_OPA1MUX_RESSEL_RESSEL(v)	\
	((((v) << DAC_OPA1MUX_RESSEL_SHIFT)) & DAC_OPA1MUX_RESSEL_MASK)
#define DAC_OPA1MUX_RESSEL_RESSEL_RESx(x)	DAC_OPA1MUX_RESSEL_RESSEL(x)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES0	DAC_OPA1MUX_RESSEL_RESSEL_RESx(0)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES1	DAC_OPA1MUX_RESSEL_RESSEL_RESx(1)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES2	DAC_OPA1MUX_RESSEL_RESSEL_RESx(2)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES3	DAC_OPA1MUX_RESSEL_RESSEL_RESx(3)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES4	DAC_OPA1MUX_RESSEL_RESSEL_RESx(4)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES5	DAC_OPA1MUX_RESSEL_RESSEL_RESx(5)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES6	DAC_OPA1MUX_RESSEL_RESSEL_RESx(6)
#define DAC_OPA1MUX_RESSEL_RESSEL_RES7	DAC_OPA1MUX_RESSEL_RESSEL_RESx(7)

#define DAC_OPA1MUX_NEXTOUT	(1 << 26)

#define DAC_OPA1MUX_OUTMODE_SHIFT	(22)
#define DAC_OPA1MUX_OUTMODE_MASK	(0x3 << DAC_OPA1MUX_OUTMODE_SHIFT)
#define DAC_OPA1MUX_OUTMODE(v)		\
	(((v) << DAC_OPA1MUX_OUTMODE_SHIFT) & DAC_OPA1MUX_OUTMODE_MASK)
#define DAC_OPA1MUX_OUTMODE_DISABLE	DAC_OPA1MUX_OUTMODE(0)
#define DAC_OPA1MUX_OUTMODE_MAIN	DAC_OPA1MUX_OUTMODE(1)
#define DAC_OPA1MUX_OUTMODE_ALT		DAC_OPA1MUX_OUTMODE(2)
#define DAC_OPA1MUX_OUTMODE_ALL		DAC_OPA1MUX_OUTMODE(3)

#define DAC_OPA1MUX_OUTPEN_SHIFT	(18)
#define DAC_OPA1MUX_OUTPEN_MASK		(0x1F << DAC_OPA1MUX_OUTPEN_SHIFT)
#define DAC_OPA1MUX_OUTPEN(v)		\
	(((v) << DAC_OPA1MUX_OUTPEN_SHIFT) & DAC_OPA1MUX_OUTPEN_MASK)
#define DAC_OPA1MUX_OUTPEN_OUT0		DAC_OPA1MUX_OUTPEN(1 << 0)
#define DAC_OPA1MUX_OUTPEN_OUT1		DAC_OPA1MUX_OUTPEN(1 << 1)
#define DAC_OPA1MUX_OUTPEN_OUT2		DAC_OPA1MUX_OUTPEN(1 << 2)
#define DAC_OPA1MUX_OUTPEN_OUT3		DAC_OPA1MUX_OUTPEN(1 << 3)
#define DAC_OPA1MUX_OUTPEN_OUT4		DAC_OPA1MUX_OUTPEN(1 << 4)

#define DAC_OPA1MUX_NPEN		(1 << 13)
#define DAC_OPA1MUX_PPEN		(1 << 12)

#define DAC_OPA1MUX_RESINMUX_SHIFT	(8)
#define DAC_OPA1MUX_RESINMUX_MASK	(0x7 << DAC_OPA1MUX_RESINMUX_SHIFT)
#define DAC_OPA1MUX_RESINMUX(v)		\
	(((v) << DAC_OPA1MUX_RESINMUX_SHIFT) & DAC_OPA1MUX_RESINMUX_MASK)
#define DAC_OPA1MUX_RESINMUX_DISABLE	DAC_OPA1MUX_RESINMUX(0)
#define DAC_OPA1MUX_RESINMUX_OPA0INP	DAC_OPA1MUX_RESINMUX(1)
#define DAC_OPA1MUX_RESINMUX_NEGPAD	DAC_OPA1MUX_RESINMUX(2)
#define DAC_OPA1MUX_RESINMUX_POSPAD	DAC_OPA1MUX_RESINMUX(3)
#define DAC_OPA1MUX_RESINMUX_VSS	DAC_OPA1MUX_RESINMUX(4)

#define DAC_OPA1MUX_NEGSEL_SHIFT	(4)
#define DAC_OPA1MUX_NEGSEL_MASK		(0x3 << DAC_OPA1MUX_NEGSEL_SHIFT)
#define DAC_OPA1MUX_NEGSEL(v)		\
	(((v) << DAC_OPA1MUX_NEGSEL_SHIFT) & DAC_OPA1MUX_NEGSEL_MASK)
#define DAC_OPA1MUX_NEGSEL_DISABLE	DAC_OPA1MUX_NEGSEL(0)
#define DAC_OPA1MUX_NEGSEL_UG		DAC_OPA1MUX_NEGSEL(1)
#define DAC_OPA1MUX_NEGSEL_OPATAP	DAC_OPA1MUX_NEGSEL(2)
#define DAC_OPA1MUX_NEGSEL_NEGPAD	DAC_OPA1MUX_NEGSEL(3)

#define DAC_OPA1MUX_POSSEL_SHIFT	(0)
#define DAC_OPA1MUX_POSSEL_MASK		(0x7 << DAC_OPA1MUX_POSSEL_SHIFT)
#define DAC_OPA1MUX_POSSEL(v)		\
	(((v) << DAC_OPA1MUX_POSSEL_SHIFT) & DAC_OPA1MUX_POSSEL_MASK)
#define DAC_OPA1MUX_POSSEL_DISABLE	DAC_OPA1MUX_POSSEL(0)
#define DAC_OPA1MUX_POSSEL_DAC		DAC_OPA1MUX_POSSEL(1)
#define DAC_OPA1MUX_POSSEL_POSPAD	DAC_OPA1MUX_POSSEL(2)
#define DAC_OPA1MUX_POSSEL_OPA0INP	DAC_OPA1MUX_POSSEL(3)
#define DAC_OPA1MUX_POSSEL_OPATAP	DAC_OPA1MUX_POSSEL(4)


/* DAC_OPA2MUX */
#define DAC_OPA2MUX_RESSEL_SHIFT	(28)
#define DAC_OPA2MUX_RESSEL_MASK		(0x7 << DAC_OPA2MUX_RESSEL_SHIFT)
#define DAC_OPA2MUX_RESSEL_RESSEL(v)	\
	((((v) << DAC_OPA2MUX_RESSEL_SHIFT)) & DAC_OPA2MUX_RESSEL_MASK)
#define DAC_OPA2MUX_RESSEL_RESSEL_RESx(x)	DAC_OPA2MUX_RESSEL_RESSEL(x)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES0	DAC_OPA2MUX_RESSEL_RESSEL_RESx(0)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES1	DAC_OPA2MUX_RESSEL_RESSEL_RESx(1)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES2	DAC_OPA2MUX_RESSEL_RESSEL_RESx(2)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES3	DAC_OPA2MUX_RESSEL_RESSEL_RESx(3)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES4	DAC_OPA2MUX_RESSEL_RESSEL_RESx(4)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES5	DAC_OPA2MUX_RESSEL_RESSEL_RESx(5)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES6	DAC_OPA2MUX_RESSEL_RESSEL_RESx(6)
#define DAC_OPA2MUX_RESSEL_RESSEL_RES7	DAC_OPA2MUX_RESSEL_RESSEL_RESx(7)

#define DAC_OPA2MUX_NEXTOUT	(1 << 26)

#define DAC_OPA2MUX_OUTMODE	(1 << 22)

#define DAC_OPA2MUX_OUTPEN_SHIFT	(14)
#define DAC_OPA2MUX_OUTPEN_MASK		(0x3 << DAC_OPA2MUX_OUTPEN_SHIFT)
#define DAC_OPA2MUX_OUTPEN(v)		\
	(((v) << DAC_OPA2MUX_OUTPEN_SHIFT) & DAC_OPA2MUX_OUTPEN_MASK)
#define DAC_OPA2MUX_OUTPEN_OUT0		DAC_OPA2MUX_OUTPEN(0)
#define DAC_OPA2MUX_OUTPEN_OUT1		DAC_OPA2MUX_OUTPEN(1)

#define DAC_OPA2MUX_NPEN	(1 << 13)
#define DAC_OPA2MUX_PPEN	(1 << 12)

#define DAC_OPA2MUX_RESINMUX_SHIFT	(8)
#define DAC_OPA2MUX_RESINMUX_MASK	(0x7 << DAC_OPA2MUX_RESINMUX_SHIFT)
#define DAC_OPA2MUX_RESINMUX(v)		\
	(((v) << DAC_OPA2MUX_RESINMUX_SHIFT) & DAC_OPA2MUX_RESINMUX_MASK)
#define DAC_OPA2MUX_RESINMUX_DISABLE	DAC_OPA2MUX_RESINMUX(0)
#define DAC_OPA2MUX_RESINMUX_OPA1INP	DAC_OPA2MUX_RESINMUX(1)
#define DAC_OPA2MUX_RESINMUX_NEGPAD		DAC_OPA2MUX_RESINMUX(2)
#define DAC_OPA2MUX_RESINMUX_POSPAD		DAC_OPA2MUX_RESINMUX(3)
#define DAC_OPA2MUX_RESINMUX_VSS		DAC_OPA2MUX_RESINMUX(4)

#define DAC_OPA2MUX_NEGSEL_SHIFT	(4)
#define DAC_OPA2MUX_NEGSEL_MASK		(0x3 << DAC_OPA2MUX_NEGSEL_SHIFT)
#define DAC_OPA2MUX_NEGSEL(v)		\
	(((v) << DAC_OPA2MUX_NEGSEL_SHIFT) & DAC_OPA2MUX_NEGSEL_MASK)
#define DAC_OPA2MUX_NEGSEL_DISABLE	DAC_OPA2MUX_NEGSEL(0)
#define DAC_OPA2MUX_NEGSEL_UG		DAC_OPA2MUX_NEGSEL(1)
#define DAC_OPA2MUX_NEGSEL_OPATAP	DAC_OPA2MUX_NEGSEL(2)
#define DAC_OPA2MUX_NEGSEL_NEGPAD	DAC_OPA2MUX_NEGSEL(3)

#define DAC_OPA2MUX_POSSEL_SHIFT	(0)
#define DAC_OPA2MUX_POSSEL_MASK		(0x7 << DAC_OPA2MUX_POSSEL_SHIFT)
#define DAC_OPA2MUX_POSSEL(v)		\
	(((v) << DAC_OPA2MUX_POSSEL_SHIFT) & DAC_OPA2MUX_POSSEL_MASK)
#define DAC_OPA2MUX_POSSEL_DISABLE	DAC_OPA2MUX_POSSEL(0)
#define DAC_OPA2MUX_POSSEL_DAC		DAC_OPA2MUX_POSSEL(1)
#define DAC_OPA2MUX_POSSEL_POSPAD	DAC_OPA2MUX_POSSEL(2)
#define DAC_OPA2MUX_POSSEL_OPA1INP	DAC_OPA2MUX_POSSEL(3)
#define DAC_OPA2MUX_POSSEL_OPATAP	DAC_OPA2MUX_POSSEL(4)

/* DAC0 */
#define DAC0			DAC0_BASE
#define DAC0_CTRL		DAC_CTRL(DAC0)
#define DAC0_STATUS		DAC_STATUS(DAC0)
#define DAC0_CH0CTRL		DAC_CH0CTRL(DAC0)
#define DAC0_CH1CTRL		DAC_CH1CTRL(DAC0)
#define DAC0_IEN		DAC_IEN(DAC0)
#define DAC0_IF			DAC_IF(DAC0)
#define DAC0_IFS		DAC_IFS(DAC0)
#define DAC0_IFC		DAC_IFC(DAC0)
#define DAC0_CH0DATA		DAC_CH0DATA(DAC0)
#define DAC0_CH1DATA		DAC_CH1DATA(DAC0)
#define DAC0_COMBDATA		DAC_COMBDATA(DAC0)
#define DAC0_CAL		DAC_CAL(DAC0)
#define DAC0_BIASPROG		DAC_BIASPROG(DAC0)
#define DAC0_OPACTRL		DAC_OPACTRL(DAC0)
#define DAC0_OPAOFFSET		DAC_OPAOFFSET(DAC0)
#define DAC0_OPAOFFSET		DAC_OPAOFFSET(DAC0)
#define DAC0_OPA1MUX		DAC_OPA1MUX(DAC0)
#define DAC0_OPA2MUX		DAC_OPA2MUX(DAC0)

/** @defgroup dac_ch DAC Channel Number
@ingroup dac_defines

@{*/
enum dac_ch {
	DAC_CH0 = 0,
	DAC_CH1
};
/**@}*/

BEGIN_DECLS

void dac_set_refresh_cycle(uint32_t dac_base, uint32_t refrsel);
void dac_set_clock_prescaler(uint32_t dac_base, uint32_t presc);
void dac_set_reference(uint32_t dac_base, uint32_t refsel);
void dac_set_out_mode(uint32_t dac_base, uint32_t outmode);
void dac_set_conversion_mode(uint32_t dac_base, uint32_t convmode);
void dac_enable_sine(uint32_t dac_base);
void dac_disable_sine(uint32_t dac_base);

void dac_set_prs_trigger(uint32_t dac_base, enum dac_ch dac_chan,
		enum prs_ch prs_chan);
void dac_enable_prs_trigger(uint32_t dac_base, enum dac_ch ch);
void dac_disable_prs_trigger(uint32_t dac_base, enum dac_ch ch);
void dac_enable_auto_refresh(uint32_t dac_base, enum dac_ch ch);
void dac_disable_auto_refresh(uint32_t dac_base, enum dac_ch ch);

void dac_enable_channel(uint32_t dac_base, enum dac_ch ch);
void dac_disable_channel(uint32_t dac_base, enum dac_ch ch);

END_DECLS

#endif
