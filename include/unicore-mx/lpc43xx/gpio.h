/** @defgroup gpio_defines General Purpose I/O Defines

@brief <b>Defined Constants and Types for the LPC43xx General Purpose I/O</b>

@ingroup LPC43xx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2012 Michael Ossmann <mike@ossmann.com>
@author @htmlonly &copy; @endhtmlonly 2014 Jared Boone <jared@sharebrained.com>

@date 10 March 2013

LGPL License Terms @ref lgpl_license
 */
/*
 * Copyright (C) 2010 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Michael Ossmann <mike@ossmann.com>
 * Copyright (C) 2014 Jared Boone <jared@sharebrained.com>
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

#ifndef LPC43XX_GPIO_H
#define LPC43XX_GPIO_H

/**@{*/

#include <unicore-mx/cm3/common.h>
#include <unicore-mx/lpc43xx/memorymap.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --- Convenience macros -------------------------------------------------- */

/* GPIO port base addresses (for convenience) */
#define GPIO0                           (GPIO_PORT_BASE + 0x2000)
#define GPIO1                           (GPIO_PORT_BASE + 0x2004)
#define GPIO2                           (GPIO_PORT_BASE + 0x2008)
#define GPIO3                           (GPIO_PORT_BASE + 0x200C)
#define GPIO4                           (GPIO_PORT_BASE + 0x2010)
#define GPIO5                           (GPIO_PORT_BASE + 0x2014)
#define GPIO6                           (GPIO_PORT_BASE + 0x2018)
#define GPIO7                           (GPIO_PORT_BASE + 0x201C)

/* GPIO number definitions (for convenience) */
#define GPIOPIN0                        (1 << 0)
#define GPIOPIN1                        (1 << 1)
#define GPIOPIN2                        (1 << 2)
#define GPIOPIN3                        (1 << 3)
#define GPIOPIN4                        (1 << 4)
#define GPIOPIN5                        (1 << 5)
#define GPIOPIN6                        (1 << 6)
#define GPIOPIN7                        (1 << 7)
#define GPIOPIN8                        (1 << 8)
#define GPIOPIN9                        (1 << 9)
#define GPIOPIN10                       (1 << 10)
#define GPIOPIN11                       (1 << 11)
#define GPIOPIN12                       (1 << 12)
#define GPIOPIN13                       (1 << 13)
#define GPIOPIN14                       (1 << 14)
#define GPIOPIN15                       (1 << 15)
#define GPIOPIN16                       (1 << 16)
#define GPIOPIN17                       (1 << 17)
#define GPIOPIN18                       (1 << 18)
#define GPIOPIN19                       (1 << 19)
#define GPIOPIN20                       (1 << 20)
#define GPIOPIN21                       (1 << 21)
#define GPIOPIN22                       (1 << 22)
#define GPIOPIN23                       (1 << 23)
#define GPIOPIN24                       (1 << 24)
#define GPIOPIN25                       (1 << 25)
#define GPIOPIN26                       (1 << 26)
#define GPIOPIN27                       (1 << 27)
#define GPIOPIN28                       (1 << 28)
#define GPIOPIN29                       (1 << 29)
#define GPIOPIN30                       (1 << 30)
#define GPIOPIN31                       (1 << 31)

/* --- GPIO registers ------------------------------------------------------ */

/* GPIO pin interrupts */

/* Pin Interrupt Mode register */
#define GPIO_PIN_INTERRUPT_ISEL         MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x000)

/* Pin interrupt level (rising edge) interrupt enable register */
#define GPIO_PIN_INTERRUPT_IENR         MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x004)

/* Pin interrupt level (rising edge) interrupt set register */
#define GPIO_PIN_INTERRUPT_SIENR        MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x008)

/* Pin interrupt level (rising edge interrupt) clear register */
#define GPIO_PIN_INTERRUPT_CIENR        MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x00C)

/* Pin interrupt active level (falling edge) interrupt enable register */
#define GPIO_PIN_INTERRUPT_IENF         MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x010)

/* Pin interrupt active level (falling edge) interrupt set register */
#define GPIO_PIN_INTERRUPT_SIENF        MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x014)

/* Pin interrupt active level (falling edge) interrupt clear register */
#define GPIO_PIN_INTERRUPT_CIENF        MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x018)

/* Pin interrupt rising edge register */
#define GPIO_PIN_INTERRUPT_RISE         MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x01C)

/* Pin interrupt falling edge register */
#define GPIO_PIN_INTERRUPT_FALL         MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x020)

/* Pin interrupt status register */
#define GPIO_PIN_INTERRUPT_IST          MMIO32(GPIO_PIN_INTERRUPT_BASE + 0x024)

/* GPIO GROUP0 interrupt */

/* GPIO grouped interrupt control register */
#define GPIO_GROUP0_INTERRUPT_CTRL \
			MMIO32(GPIO_GROUP0_INTERRUPT_BASE + 0x000)

/* GPIO grouped interrupt port [0..7] polarity register */
#define GPIO_GROUP0_INTERRUPT_PORT_POL(x) \
			MMIO32(GPIO_GROUP0_INTERRUPT_BASE + 0x020 + ((x)*4))

/* GPIO grouped interrupt port [0..7] enable register */
#define GPIO_GROUP0_INTERRUPT_PORT_ENA(x) \
			MMIO32(GPIO_GROUP0_INTERRUPT_BASE + 0x040 + ((x)*4))

/* GPIO GROUP1 interrupt */

/* GPIO grouped interrupt control register */
#define GPIO_GROUP1_INTERRUPT_CTRL \
			MMIO32(GPIO_GROUP1_INTERRUPT_BASE + 0x000)

/* GPIO grouped interrupt port [0..7] polarity register */
#define GPIO_GROUP1_INTERRUPT_PORT_POL(x) \
			MMIO32(GPIO_GROUP1_INTERRUPT_BASE + 0x020 + ((x)*4))

/* GPIO grouped interrupt port [0..7] enable register */
#define GPIO_GROUP1_INTERRUPT_PORT_ENA(x) \
			MMIO32(GPIO_GROUP1_INTERRUPT_BASE + 0x040 + ((x)*4))

/* Byte pin registers port 0; pins PIO0_0 to PIO0_31 (R/W) */
#define GPIO_B0                         (GPIO_PORT_BASE + 0x0000)
#define GPIO_B1                         (GPIO_PORT_BASE + 0x0001)
#define GPIO_B2                         (GPIO_PORT_BASE + 0x0002)
#define GPIO_B3                         (GPIO_PORT_BASE + 0x0003)
#define GPIO_B4                         (GPIO_PORT_BASE + 0x0004)
#define GPIO_B5                         (GPIO_PORT_BASE + 0x0005)
#define GPIO_B6                         (GPIO_PORT_BASE + 0x0006)
#define GPIO_B7                         (GPIO_PORT_BASE + 0x0007)
#define GPIO_B8                         (GPIO_PORT_BASE + 0x0008)
#define GPIO_B9                         (GPIO_PORT_BASE + 0x0009)
#define GPIO_B10                        (GPIO_PORT_BASE + 0x000A)
#define GPIO_B11                        (GPIO_PORT_BASE + 0x000B)
#define GPIO_B12                        (GPIO_PORT_BASE + 0x000C)
#define GPIO_B13                        (GPIO_PORT_BASE + 0x000D)
#define GPIO_B14                        (GPIO_PORT_BASE + 0x000E)
#define GPIO_B15                        (GPIO_PORT_BASE + 0x000F)
#define GPIO_B16                        (GPIO_PORT_BASE + 0x0010)
#define GPIO_B17                        (GPIO_PORT_BASE + 0x0011)
#define GPIO_B18                        (GPIO_PORT_BASE + 0x0012)
#define GPIO_B19                        (GPIO_PORT_BASE + 0x0013)
#define GPIO_B20                        (GPIO_PORT_BASE + 0x0014)
#define GPIO_B21                        (GPIO_PORT_BASE + 0x0015)
#define GPIO_B22                        (GPIO_PORT_BASE + 0x0016)
#define GPIO_B23                        (GPIO_PORT_BASE + 0x0017)
#define GPIO_B24                        (GPIO_PORT_BASE + 0x0018)
#define GPIO_B25                        (GPIO_PORT_BASE + 0x0019)
#define GPIO_B26                        (GPIO_PORT_BASE + 0x001A)
#define GPIO_B27                        (GPIO_PORT_BASE + 0x001B)
#define GPIO_B28                        (GPIO_PORT_BASE + 0x001C)
#define GPIO_B29                        (GPIO_PORT_BASE + 0x001D)
#define GPIO_B30                        (GPIO_PORT_BASE + 0x001E)
#define GPIO_B31                        (GPIO_PORT_BASE + 0x001F)

/* Byte pin registers port 1 (R/W) */
#define GPIO_B32                        (GPIO_PORT_BASE + 0x0020)
#define GPIO_B33                        (GPIO_PORT_BASE + 0x0021)
#define GPIO_B34                        (GPIO_PORT_BASE + 0x0022)
#define GPIO_B35                        (GPIO_PORT_BASE + 0x0023)
#define GPIO_B36                        (GPIO_PORT_BASE + 0x0024)
#define GPIO_B37                        (GPIO_PORT_BASE + 0x0025)
#define GPIO_B38                        (GPIO_PORT_BASE + 0x0026)
#define GPIO_B39                        (GPIO_PORT_BASE + 0x0027)
#define GPIO_B40                        (GPIO_PORT_BASE + 0x0028)
#define GPIO_B41                        (GPIO_PORT_BASE + 0x0029)
#define GPIO_B42                        (GPIO_PORT_BASE + 0x002A)
#define GPIO_B43                        (GPIO_PORT_BASE + 0x002B)
#define GPIO_B44                        (GPIO_PORT_BASE + 0x002C)
#define GPIO_B45                        (GPIO_PORT_BASE + 0x002D)
#define GPIO_B46                        (GPIO_PORT_BASE + 0x002E)
#define GPIO_B47                        (GPIO_PORT_BASE + 0x002F)
#define GPIO_B48                        (GPIO_PORT_BASE + 0x0030)
#define GPIO_B49                        (GPIO_PORT_BASE + 0x0031)
#define GPIO_B50                        (GPIO_PORT_BASE + 0x0032)
#define GPIO_B51                        (GPIO_PORT_BASE + 0x0033)
#define GPIO_B52                        (GPIO_PORT_BASE + 0x0034)
#define GPIO_B53                        (GPIO_PORT_BASE + 0x0035)
#define GPIO_B54                        (GPIO_PORT_BASE + 0x0036)
#define GPIO_B55                        (GPIO_PORT_BASE + 0x0037)
#define GPIO_B56                        (GPIO_PORT_BASE + 0x0038)
#define GPIO_B57                        (GPIO_PORT_BASE + 0x0039)
#define GPIO_B58                        (GPIO_PORT_BASE + 0x003A)
#define GPIO_B59                        (GPIO_PORT_BASE + 0x003B)
#define GPIO_B60                        (GPIO_PORT_BASE + 0x003C)
#define GPIO_B61                        (GPIO_PORT_BASE + 0x003D)
#define GPIO_B62                        (GPIO_PORT_BASE + 0x003E)
#define GPIO_B63                        (GPIO_PORT_BASE + 0x003F)

/* Byte pin registers port 2 (R/W) */
#define GPIO_B64                        (GPIO_PORT_BASE + 0x0040)
#define GPIO_B65                        (GPIO_PORT_BASE + 0x0041)
#define GPIO_B66                        (GPIO_PORT_BASE + 0x0042)
#define GPIO_B67                        (GPIO_PORT_BASE + 0x0043)
#define GPIO_B68                        (GPIO_PORT_BASE + 0x0044)
#define GPIO_B69                        (GPIO_PORT_BASE + 0x0045)
#define GPIO_B70                        (GPIO_PORT_BASE + 0x0046)
#define GPIO_B71                        (GPIO_PORT_BASE + 0x0047)
#define GPIO_B72                        (GPIO_PORT_BASE + 0x0048)
#define GPIO_B73                        (GPIO_PORT_BASE + 0x0049)
#define GPIO_B74                        (GPIO_PORT_BASE + 0x004A)
#define GPIO_B75                        (GPIO_PORT_BASE + 0x004B)
#define GPIO_B76                        (GPIO_PORT_BASE + 0x004C)
#define GPIO_B77                        (GPIO_PORT_BASE + 0x004D)
#define GPIO_B78                        (GPIO_PORT_BASE + 0x004E)
#define GPIO_B79                        (GPIO_PORT_BASE + 0x004F)
#define GPIO_B80                        (GPIO_PORT_BASE + 0x0050)
#define GPIO_B81                        (GPIO_PORT_BASE + 0x0051)
#define GPIO_B82                        (GPIO_PORT_BASE + 0x0052)
#define GPIO_B83                        (GPIO_PORT_BASE + 0x0053)
#define GPIO_B84                        (GPIO_PORT_BASE + 0x0054)
#define GPIO_B85                        (GPIO_PORT_BASE + 0x0055)
#define GPIO_B86                        (GPIO_PORT_BASE + 0x0056)
#define GPIO_B87                        (GPIO_PORT_BASE + 0x0057)
#define GPIO_B88                        (GPIO_PORT_BASE + 0x0058)
#define GPIO_B89                        (GPIO_PORT_BASE + 0x0059)
#define GPIO_B90                        (GPIO_PORT_BASE + 0x005A)
#define GPIO_B91                        (GPIO_PORT_BASE + 0x005B)
#define GPIO_B92                        (GPIO_PORT_BASE + 0x005C)
#define GPIO_B93                        (GPIO_PORT_BASE + 0x005D)
#define GPIO_B94                        (GPIO_PORT_BASE + 0x005E)
#define GPIO_B95                        (GPIO_PORT_BASE + 0x005F)

/* Byte pin registers port 3 (R/W) */
#define GPIO_B96                        (GPIO_PORT_BASE + 0x0060)
#define GPIO_B97                        (GPIO_PORT_BASE + 0x0061)
#define GPIO_B98                        (GPIO_PORT_BASE + 0x0062)
#define GPIO_B99                        (GPIO_PORT_BASE + 0x0063)
#define GPIO_B100                       (GPIO_PORT_BASE + 0x0064)
#define GPIO_B101                       (GPIO_PORT_BASE + 0x0065)
#define GPIO_B102                       (GPIO_PORT_BASE + 0x0066)
#define GPIO_B103                       (GPIO_PORT_BASE + 0x0067)
#define GPIO_B104                       (GPIO_PORT_BASE + 0x0068)
#define GPIO_B105                       (GPIO_PORT_BASE + 0x0069)
#define GPIO_B106                       (GPIO_PORT_BASE + 0x006A)
#define GPIO_B107                       (GPIO_PORT_BASE + 0x006B)
#define GPIO_B108                       (GPIO_PORT_BASE + 0x006C)
#define GPIO_B109                       (GPIO_PORT_BASE + 0x006D)
#define GPIO_B110                       (GPIO_PORT_BASE + 0x006E)
#define GPIO_B111                       (GPIO_PORT_BASE + 0x006F)
#define GPIO_B112                       (GPIO_PORT_BASE + 0x0070)
#define GPIO_B113                       (GPIO_PORT_BASE + 0x0071)
#define GPIO_B114                       (GPIO_PORT_BASE + 0x0072)
#define GPIO_B115                       (GPIO_PORT_BASE + 0x0073)
#define GPIO_B116                       (GPIO_PORT_BASE + 0x0074)
#define GPIO_B117                       (GPIO_PORT_BASE + 0x0075)
#define GPIO_B118                       (GPIO_PORT_BASE + 0x0076)
#define GPIO_B119                       (GPIO_PORT_BASE + 0x0077)
#define GPIO_B120                       (GPIO_PORT_BASE + 0x0078)
#define GPIO_B121                       (GPIO_PORT_BASE + 0x0079)
#define GPIO_B122                       (GPIO_PORT_BASE + 0x007A)
#define GPIO_B123                       (GPIO_PORT_BASE + 0x007B)
#define GPIO_B124                       (GPIO_PORT_BASE + 0x007C)
#define GPIO_B125                       (GPIO_PORT_BASE + 0x007D)
#define GPIO_B126                       (GPIO_PORT_BASE + 0x007E)
#define GPIO_B127                       (GPIO_PORT_BASE + 0x007F)

/* Byte pin registers port 4 (R/W) */
#define GPIO_B128                       (GPIO_PORT_BASE + 0x0080)
#define GPIO_B129                       (GPIO_PORT_BASE + 0x0081)
#define GPIO_B130                       (GPIO_PORT_BASE + 0x0082)
#define GPIO_B131                       (GPIO_PORT_BASE + 0x0083)
#define GPIO_B132                       (GPIO_PORT_BASE + 0x0084)
#define GPIO_B133                       (GPIO_PORT_BASE + 0x0085)
#define GPIO_B134                       (GPIO_PORT_BASE + 0x0086)
#define GPIO_B135                       (GPIO_PORT_BASE + 0x0087)
#define GPIO_B136                       (GPIO_PORT_BASE + 0x0088)
#define GPIO_B137                       (GPIO_PORT_BASE + 0x0089)
#define GPIO_B138                       (GPIO_PORT_BASE + 0x008A)
#define GPIO_B139                       (GPIO_PORT_BASE + 0x008B)
#define GPIO_B140                       (GPIO_PORT_BASE + 0x008C)
#define GPIO_B141                       (GPIO_PORT_BASE + 0x008D)
#define GPIO_B142                       (GPIO_PORT_BASE + 0x008E)
#define GPIO_B143                       (GPIO_PORT_BASE + 0x008F)
#define GPIO_B144                       (GPIO_PORT_BASE + 0x0090)
#define GPIO_B145                       (GPIO_PORT_BASE + 0x0091)
#define GPIO_B146                       (GPIO_PORT_BASE + 0x0092)
#define GPIO_B147                       (GPIO_PORT_BASE + 0x0093)
#define GPIO_B148                       (GPIO_PORT_BASE + 0x0094)
#define GPIO_B149                       (GPIO_PORT_BASE + 0x0095)
#define GPIO_B150                       (GPIO_PORT_BASE + 0x0096)
#define GPIO_B151                       (GPIO_PORT_BASE + 0x0097)
#define GPIO_B152                       (GPIO_PORT_BASE + 0x0098)
#define GPIO_B153                       (GPIO_PORT_BASE + 0x0099)
#define GPIO_B154                       (GPIO_PORT_BASE + 0x009A)
#define GPIO_B155                       (GPIO_PORT_BASE + 0x009B)
#define GPIO_B156                       (GPIO_PORT_BASE + 0x009C)
#define GPIO_B157                       (GPIO_PORT_BASE + 0x009D)
#define GPIO_B158                       (GPIO_PORT_BASE + 0x009E)
#define GPIO_B159                       (GPIO_PORT_BASE + 0x009F)

/* Byte pin registers port 5 (R/W) */
#define GPIO_B160                       (GPIO_PORT_BASE + 0x00A0)
#define GPIO_B161                       (GPIO_PORT_BASE + 0x00A1)
#define GPIO_B162                       (GPIO_PORT_BASE + 0x00A2)
#define GPIO_B163                       (GPIO_PORT_BASE + 0x00A3)
#define GPIO_B164                       (GPIO_PORT_BASE + 0x00A4)
#define GPIO_B165                       (GPIO_PORT_BASE + 0x00A5)
#define GPIO_B166                       (GPIO_PORT_BASE + 0x00A6)
#define GPIO_B167                       (GPIO_PORT_BASE + 0x00A7)
#define GPIO_B168                       (GPIO_PORT_BASE + 0x00A8)
#define GPIO_B169                       (GPIO_PORT_BASE + 0x00A9)
#define GPIO_B170                       (GPIO_PORT_BASE + 0x00AA)
#define GPIO_B171                       (GPIO_PORT_BASE + 0x00AB)
#define GPIO_B172                       (GPIO_PORT_BASE + 0x00AC)
#define GPIO_B173                       (GPIO_PORT_BASE + 0x00AD)
#define GPIO_B174                       (GPIO_PORT_BASE + 0x00AE)
#define GPIO_B175                       (GPIO_PORT_BASE + 0x00AF)
#define GPIO_B176                       (GPIO_PORT_BASE + 0x00B0)
#define GPIO_B177                       (GPIO_PORT_BASE + 0x00B1)
#define GPIO_B178                       (GPIO_PORT_BASE + 0x00B2)
#define GPIO_B179                       (GPIO_PORT_BASE + 0x00B3)
#define GPIO_B180                       (GPIO_PORT_BASE + 0x00B4)
#define GPIO_B181                       (GPIO_PORT_BASE + 0x00B5)
#define GPIO_B182                       (GPIO_PORT_BASE + 0x00B6)
#define GPIO_B183                       (GPIO_PORT_BASE + 0x00B7)
#define GPIO_B184                       (GPIO_PORT_BASE + 0x00B8)
#define GPIO_B185                       (GPIO_PORT_BASE + 0x00B9)
#define GPIO_B186                       (GPIO_PORT_BASE + 0x00BA)
#define GPIO_B187                       (GPIO_PORT_BASE + 0x00BB)
#define GPIO_B188                       (GPIO_PORT_BASE + 0x00BC)
#define GPIO_B189                       (GPIO_PORT_BASE + 0x00BD)
#define GPIO_B190                       (GPIO_PORT_BASE + 0x00BE)
#define GPIO_B191                       (GPIO_PORT_BASE + 0x00BF)

/* Byte pin registers port 6 (R/W) */
#define GPIO_B192                       (GPIO_PORT_BASE + 0x00C0)
#define GPIO_B193                       (GPIO_PORT_BASE + 0x00C1)
#define GPIO_B194                       (GPIO_PORT_BASE + 0x00C2)
#define GPIO_B195                       (GPIO_PORT_BASE + 0x00C3)
#define GPIO_B196                       (GPIO_PORT_BASE + 0x00C4)
#define GPIO_B197                       (GPIO_PORT_BASE + 0x00C5)
#define GPIO_B198                       (GPIO_PORT_BASE + 0x00C6)
#define GPIO_B199                       (GPIO_PORT_BASE + 0x00C7)
#define GPIO_B200                       (GPIO_PORT_BASE + 0x00C8)
#define GPIO_B201                       (GPIO_PORT_BASE + 0x00C9)
#define GPIO_B202                       (GPIO_PORT_BASE + 0x00CA)
#define GPIO_B203                       (GPIO_PORT_BASE + 0x00CB)
#define GPIO_B204                       (GPIO_PORT_BASE + 0x00CC)
#define GPIO_B205                       (GPIO_PORT_BASE + 0x00CD)
#define GPIO_B206                       (GPIO_PORT_BASE + 0x00CE)
#define GPIO_B207                       (GPIO_PORT_BASE + 0x00CF)
#define GPIO_B208                       (GPIO_PORT_BASE + 0x00D0)
#define GPIO_B209                       (GPIO_PORT_BASE + 0x00D1)
#define GPIO_B210                       (GPIO_PORT_BASE + 0x00D2)
#define GPIO_B211                       (GPIO_PORT_BASE + 0x00D3)
#define GPIO_B212                       (GPIO_PORT_BASE + 0x00D4)
#define GPIO_B213                       (GPIO_PORT_BASE + 0x00D5)
#define GPIO_B214                       (GPIO_PORT_BASE + 0x00D6)
#define GPIO_B215                       (GPIO_PORT_BASE + 0x00D7)
#define GPIO_B216                       (GPIO_PORT_BASE + 0x00D8)
#define GPIO_B217                       (GPIO_PORT_BASE + 0x00D9)
#define GPIO_B218                       (GPIO_PORT_BASE + 0x00DA)
#define GPIO_B219                       (GPIO_PORT_BASE + 0x00DB)
#define GPIO_B220                       (GPIO_PORT_BASE + 0x00DC)
#define GPIO_B221                       (GPIO_PORT_BASE + 0x00DD)
#define GPIO_B222                       (GPIO_PORT_BASE + 0x00DE)
#define GPIO_B223                       (GPIO_PORT_BASE + 0x00DF)

/* Byte pin registers port 7 (R/W) */
#define GPIO_B224                       (GPIO_PORT_BASE + 0x00E0)
#define GPIO_B225                       (GPIO_PORT_BASE + 0x00E1)
#define GPIO_B226                       (GPIO_PORT_BASE + 0x00E2)
#define GPIO_B227                       (GPIO_PORT_BASE + 0x00E3)
#define GPIO_B228                       (GPIO_PORT_BASE + 0x00E4)
#define GPIO_B229                       (GPIO_PORT_BASE + 0x00E5)
#define GPIO_B230                       (GPIO_PORT_BASE + 0x00E6)
#define GPIO_B231                       (GPIO_PORT_BASE + 0x00E7)
#define GPIO_B232                       (GPIO_PORT_BASE + 0x00E8)
#define GPIO_B233                       (GPIO_PORT_BASE + 0x00E9)
#define GPIO_B234                       (GPIO_PORT_BASE + 0x00EA)
#define GPIO_B235                       (GPIO_PORT_BASE + 0x00EB)
#define GPIO_B236                       (GPIO_PORT_BASE + 0x00EC)
#define GPIO_B237                       (GPIO_PORT_BASE + 0x00ED)
#define GPIO_B238                       (GPIO_PORT_BASE + 0x00EE)
#define GPIO_B239                       (GPIO_PORT_BASE + 0x00EF)
#define GPIO_B240                       (GPIO_PORT_BASE + 0x00F0)
#define GPIO_B241                       (GPIO_PORT_BASE + 0x00F1)
#define GPIO_B242                       (GPIO_PORT_BASE + 0x00F2)
#define GPIO_B243                       (GPIO_PORT_BASE + 0x00F3)
#define GPIO_B244                       (GPIO_PORT_BASE + 0x00F4)
#define GPIO_B245                       (GPIO_PORT_BASE + 0x00F5)
#define GPIO_B246                       (GPIO_PORT_BASE + 0x00F6)
#define GPIO_B247                       (GPIO_PORT_BASE + 0x00F7)
#define GPIO_B248                       (GPIO_PORT_BASE + 0x00F8)
#define GPIO_B249                       (GPIO_PORT_BASE + 0x00F9)
#define GPIO_B250                       (GPIO_PORT_BASE + 0x00FA)
#define GPIO_B251                       (GPIO_PORT_BASE + 0x00FB)
#define GPIO_B252                       (GPIO_PORT_BASE + 0x00FC)
#define GPIO_B253                       (GPIO_PORT_BASE + 0x00FD)
#define GPIO_B254                       (GPIO_PORT_BASE + 0x00FE)
#define GPIO_B255                       (GPIO_PORT_BASE + 0x00FF)

/* Word pin registers port 0 (R/W) */
#define GPIO_W0                         (GPIO_PORT_BASE + 0x1000)
#define GPIO_W1                         (GPIO_PORT_BASE + 0x1004)
#define GPIO_W2                         (GPIO_PORT_BASE + 0x1008)
#define GPIO_W3                         (GPIO_PORT_BASE + 0x100C)
#define GPIO_W4                         (GPIO_PORT_BASE + 0x1010)
#define GPIO_W5                         (GPIO_PORT_BASE + 0x1014)
#define GPIO_W6                         (GPIO_PORT_BASE + 0x1018)
#define GPIO_W7                         (GPIO_PORT_BASE + 0x101C)
#define GPIO_W8                         (GPIO_PORT_BASE + 0x1020)
#define GPIO_W9                         (GPIO_PORT_BASE + 0x1024)
#define GPIO_W10                        (GPIO_PORT_BASE + 0x1028)
#define GPIO_W11                        (GPIO_PORT_BASE + 0x102C)
#define GPIO_W12                        (GPIO_PORT_BASE + 0x1030)
#define GPIO_W13                        (GPIO_PORT_BASE + 0x1034)
#define GPIO_W14                        (GPIO_PORT_BASE + 0x1038)
#define GPIO_W15                        (GPIO_PORT_BASE + 0x103C)
#define GPIO_W16                        (GPIO_PORT_BASE + 0x1040)
#define GPIO_W17                        (GPIO_PORT_BASE + 0x1044)
#define GPIO_W18                        (GPIO_PORT_BASE + 0x1048)
#define GPIO_W19                        (GPIO_PORT_BASE + 0x104C)
#define GPIO_W20                        (GPIO_PORT_BASE + 0x1050)
#define GPIO_W21                        (GPIO_PORT_BASE + 0x1054)
#define GPIO_W22                        (GPIO_PORT_BASE + 0x1058)
#define GPIO_W23                        (GPIO_PORT_BASE + 0x105C)
#define GPIO_W24                        (GPIO_PORT_BASE + 0x1060)
#define GPIO_W25                        (GPIO_PORT_BASE + 0x1064)
#define GPIO_W26                        (GPIO_PORT_BASE + 0x1068)
#define GPIO_W27                        (GPIO_PORT_BASE + 0x106C)
#define GPIO_W28                        (GPIO_PORT_BASE + 0x1070)
#define GPIO_W29                        (GPIO_PORT_BASE + 0x1074)
#define GPIO_W30                        (GPIO_PORT_BASE + 0x1078)
#define GPIO_W31                        (GPIO_PORT_BASE + 0x107C)

/* Word pin registers port 1 (R/W) */
#define GPIO_W32                        (GPIO_PORT_BASE + 0x1080)
#define GPIO_W33                        (GPIO_PORT_BASE + 0x1084)
#define GPIO_W34                        (GPIO_PORT_BASE + 0x1088)
#define GPIO_W35                        (GPIO_PORT_BASE + 0x108C)
#define GPIO_W36                        (GPIO_PORT_BASE + 0x1090)
#define GPIO_W37                        (GPIO_PORT_BASE + 0x1094)
#define GPIO_W38                        (GPIO_PORT_BASE + 0x1098)
#define GPIO_W39                        (GPIO_PORT_BASE + 0x109C)
#define GPIO_W40                        (GPIO_PORT_BASE + 0x10A0)
#define GPIO_W41                        (GPIO_PORT_BASE + 0x10A4)
#define GPIO_W42                        (GPIO_PORT_BASE + 0x10A8)
#define GPIO_W43                        (GPIO_PORT_BASE + 0x10AC)
#define GPIO_W44                        (GPIO_PORT_BASE + 0x10B0)
#define GPIO_W45                        (GPIO_PORT_BASE + 0x10B4)
#define GPIO_W46                        (GPIO_PORT_BASE + 0x10B8)
#define GPIO_W47                        (GPIO_PORT_BASE + 0x10BC)
#define GPIO_W48                        (GPIO_PORT_BASE + 0x10C0)
#define GPIO_W49                        (GPIO_PORT_BASE + 0x10C4)
#define GPIO_W50                        (GPIO_PORT_BASE + 0x10C8)
#define GPIO_W51                        (GPIO_PORT_BASE + 0x10CC)
#define GPIO_W52                        (GPIO_PORT_BASE + 0x10D0)
#define GPIO_W53                        (GPIO_PORT_BASE + 0x10D4)
#define GPIO_W54                        (GPIO_PORT_BASE + 0x10D8)
#define GPIO_W55                        (GPIO_PORT_BASE + 0x10DC)
#define GPIO_W56                        (GPIO_PORT_BASE + 0x10E0)
#define GPIO_W57                        (GPIO_PORT_BASE + 0x10E4)
#define GPIO_W58                        (GPIO_PORT_BASE + 0x10E8)
#define GPIO_W59                        (GPIO_PORT_BASE + 0x10EC)
#define GPIO_W60                        (GPIO_PORT_BASE + 0x10F0)
#define GPIO_W61                        (GPIO_PORT_BASE + 0x10F4)
#define GPIO_W62                        (GPIO_PORT_BASE + 0x10F8)
#define GPIO_W63                        (GPIO_PORT_BASE + 0x10FC)

/* Word pin registers port 2 (R/W) */
#define GPIO_W64                        (GPIO_PORT_BASE + 0x1100)
#define GPIO_W65                        (GPIO_PORT_BASE + 0x1104)
#define GPIO_W66                        (GPIO_PORT_BASE + 0x1108)
#define GPIO_W67                        (GPIO_PORT_BASE + 0x110C)
#define GPIO_W68                        (GPIO_PORT_BASE + 0x1110)
#define GPIO_W69                        (GPIO_PORT_BASE + 0x1114)
#define GPIO_W70                        (GPIO_PORT_BASE + 0x1118)
#define GPIO_W71                        (GPIO_PORT_BASE + 0x111C)
#define GPIO_W72                        (GPIO_PORT_BASE + 0x1120)
#define GPIO_W73                        (GPIO_PORT_BASE + 0x1124)
#define GPIO_W74                        (GPIO_PORT_BASE + 0x1128)
#define GPIO_W75                        (GPIO_PORT_BASE + 0x112C)
#define GPIO_W76                        (GPIO_PORT_BASE + 0x1130)
#define GPIO_W77                        (GPIO_PORT_BASE + 0x1134)
#define GPIO_W78                        (GPIO_PORT_BASE + 0x1138)
#define GPIO_W79                        (GPIO_PORT_BASE + 0x113C)
#define GPIO_W80                        (GPIO_PORT_BASE + 0x1140)
#define GPIO_W81                        (GPIO_PORT_BASE + 0x1144)
#define GPIO_W82                        (GPIO_PORT_BASE + 0x1148)
#define GPIO_W83                        (GPIO_PORT_BASE + 0x114C)
#define GPIO_W84                        (GPIO_PORT_BASE + 0x1150)
#define GPIO_W85                        (GPIO_PORT_BASE + 0x1154)
#define GPIO_W86                        (GPIO_PORT_BASE + 0x1158)
#define GPIO_W87                        (GPIO_PORT_BASE + 0x115C)
#define GPIO_W88                        (GPIO_PORT_BASE + 0x1160)
#define GPIO_W89                        (GPIO_PORT_BASE + 0x1164)
#define GPIO_W90                        (GPIO_PORT_BASE + 0x1168)
#define GPIO_W91                        (GPIO_PORT_BASE + 0x116C)
#define GPIO_W92                        (GPIO_PORT_BASE + 0x1170)
#define GPIO_W93                        (GPIO_PORT_BASE + 0x1174)
#define GPIO_W94                        (GPIO_PORT_BASE + 0x1178)
#define GPIO_W95                        (GPIO_PORT_BASE + 0x117C)

/* Word pin registers port 3 (R/W) */
#define GPIO_W96                        (GPIO_PORT_BASE + 0x1180)
#define GPIO_W97                        (GPIO_PORT_BASE + 0x1184)
#define GPIO_W98                        (GPIO_PORT_BASE + 0x1188)
#define GPIO_W99                        (GPIO_PORT_BASE + 0x118C)
#define GPIO_W100                       (GPIO_PORT_BASE + 0x1190)
#define GPIO_W101                       (GPIO_PORT_BASE + 0x1194)
#define GPIO_W102                       (GPIO_PORT_BASE + 0x1198)
#define GPIO_W103                       (GPIO_PORT_BASE + 0x119C)
#define GPIO_W104                       (GPIO_PORT_BASE + 0x11A0)
#define GPIO_W105                       (GPIO_PORT_BASE + 0x11A4)
#define GPIO_W106                       (GPIO_PORT_BASE + 0x11A8)
#define GPIO_W107                       (GPIO_PORT_BASE + 0x11AC)
#define GPIO_W108                       (GPIO_PORT_BASE + 0x11B0)
#define GPIO_W109                       (GPIO_PORT_BASE + 0x11B4)
#define GPIO_W110                       (GPIO_PORT_BASE + 0x11B8)
#define GPIO_W111                       (GPIO_PORT_BASE + 0x11BC)
#define GPIO_W112                       (GPIO_PORT_BASE + 0x11C0)
#define GPIO_W113                       (GPIO_PORT_BASE + 0x11C4)
#define GPIO_W114                       (GPIO_PORT_BASE + 0x11C8)
#define GPIO_W115                       (GPIO_PORT_BASE + 0x11CC)
#define GPIO_W116                       (GPIO_PORT_BASE + 0x11D0)
#define GPIO_W117                       (GPIO_PORT_BASE + 0x11D4)
#define GPIO_W118                       (GPIO_PORT_BASE + 0x11D8)
#define GPIO_W119                       (GPIO_PORT_BASE + 0x11DC)
#define GPIO_W120                       (GPIO_PORT_BASE + 0x11E0)
#define GPIO_W121                       (GPIO_PORT_BASE + 0x11E4)
#define GPIO_W122                       (GPIO_PORT_BASE + 0x11E8)
#define GPIO_W123                       (GPIO_PORT_BASE + 0x11EC)
#define GPIO_W124                       (GPIO_PORT_BASE + 0x11F0)
#define GPIO_W125                       (GPIO_PORT_BASE + 0x11F4)
#define GPIO_W126                       (GPIO_PORT_BASE + 0x11F8)
#define GPIO_W127                       (GPIO_PORT_BASE + 0x11FC)

/* Word pin registers port 4 (R/W) */
#define GPIO_W128                       (GPIO_PORT_BASE + 0x1200)
#define GPIO_W129                       (GPIO_PORT_BASE + 0x1204)
#define GPIO_W130                       (GPIO_PORT_BASE + 0x1208)
#define GPIO_W131                       (GPIO_PORT_BASE + 0x120C)
#define GPIO_W132                       (GPIO_PORT_BASE + 0x1210)
#define GPIO_W133                       (GPIO_PORT_BASE + 0x1214)
#define GPIO_W134                       (GPIO_PORT_BASE + 0x1218)
#define GPIO_W135                       (GPIO_PORT_BASE + 0x121C)
#define GPIO_W136                       (GPIO_PORT_BASE + 0x1220)
#define GPIO_W137                       (GPIO_PORT_BASE + 0x1224)
#define GPIO_W138                       (GPIO_PORT_BASE + 0x1228)
#define GPIO_W139                       (GPIO_PORT_BASE + 0x122C)
#define GPIO_W140                       (GPIO_PORT_BASE + 0x1230)
#define GPIO_W141                       (GPIO_PORT_BASE + 0x1234)
#define GPIO_W142                       (GPIO_PORT_BASE + 0x1238)
#define GPIO_W143                       (GPIO_PORT_BASE + 0x123C)
#define GPIO_W144                       (GPIO_PORT_BASE + 0x1240)
#define GPIO_W145                       (GPIO_PORT_BASE + 0x1244)
#define GPIO_W146                       (GPIO_PORT_BASE + 0x1248)
#define GPIO_W147                       (GPIO_PORT_BASE + 0x124C)
#define GPIO_W148                       (GPIO_PORT_BASE + 0x1250)
#define GPIO_W149                       (GPIO_PORT_BASE + 0x1254)
#define GPIO_W150                       (GPIO_PORT_BASE + 0x1258)
#define GPIO_W151                       (GPIO_PORT_BASE + 0x125C)
#define GPIO_W152                       (GPIO_PORT_BASE + 0x1260)
#define GPIO_W153                       (GPIO_PORT_BASE + 0x1264)
#define GPIO_W154                       (GPIO_PORT_BASE + 0x1268)
#define GPIO_W155                       (GPIO_PORT_BASE + 0x126C)
#define GPIO_W156                       (GPIO_PORT_BASE + 0x1270)
#define GPIO_W157                       (GPIO_PORT_BASE + 0x1274)
#define GPIO_W158                       (GPIO_PORT_BASE + 0x1278)
#define GPIO_W159                       (GPIO_PORT_BASE + 0x127C)

/* Word pin registers port 5 (R/W) */
#define GPIO_W160                       (GPIO_PORT_BASE + 0x1280)
#define GPIO_W161                       (GPIO_PORT_BASE + 0x1284)
#define GPIO_W162                       (GPIO_PORT_BASE + 0x1288)
#define GPIO_W163                       (GPIO_PORT_BASE + 0x128C)
#define GPIO_W164                       (GPIO_PORT_BASE + 0x1290)
#define GPIO_W165                       (GPIO_PORT_BASE + 0x1294)
#define GPIO_W166                       (GPIO_PORT_BASE + 0x1298)
#define GPIO_W167                       (GPIO_PORT_BASE + 0x129C)
#define GPIO_W168                       (GPIO_PORT_BASE + 0x12A0)
#define GPIO_W169                       (GPIO_PORT_BASE + 0x12A4)
#define GPIO_W170                       (GPIO_PORT_BASE + 0x12A8)
#define GPIO_W171                       (GPIO_PORT_BASE + 0x12AC)
#define GPIO_W172                       (GPIO_PORT_BASE + 0x12B0)
#define GPIO_W173                       (GPIO_PORT_BASE + 0x12B4)
#define GPIO_W174                       (GPIO_PORT_BASE + 0x12B8)
#define GPIO_W175                       (GPIO_PORT_BASE + 0x12BC)
#define GPIO_W176                       (GPIO_PORT_BASE + 0x12C0)
#define GPIO_W177                       (GPIO_PORT_BASE + 0x12C4)
#define GPIO_W178                       (GPIO_PORT_BASE + 0x12C8)
#define GPIO_W179                       (GPIO_PORT_BASE + 0x12CC)
#define GPIO_W180                       (GPIO_PORT_BASE + 0x12D0)
#define GPIO_W181                       (GPIO_PORT_BASE + 0x12D4)
#define GPIO_W182                       (GPIO_PORT_BASE + 0x12D8)
#define GPIO_W183                       (GPIO_PORT_BASE + 0x12DC)
#define GPIO_W184                       (GPIO_PORT_BASE + 0x12E0)
#define GPIO_W185                       (GPIO_PORT_BASE + 0x12E4)
#define GPIO_W186                       (GPIO_PORT_BASE + 0x12E8)
#define GPIO_W187                       (GPIO_PORT_BASE + 0x12EC)
#define GPIO_W188                       (GPIO_PORT_BASE + 0x12F0)
#define GPIO_W189                       (GPIO_PORT_BASE + 0x12F4)
#define GPIO_W190                       (GPIO_PORT_BASE + 0x12F8)
#define GPIO_W191                       (GPIO_PORT_BASE + 0x12FC)

/* Word pin registers port 6 (R/W) */
#define GPIO_W192                       (GPIO_PORT_BASE + 0x1300)
#define GPIO_W193                       (GPIO_PORT_BASE + 0x1304)
#define GPIO_W194                       (GPIO_PORT_BASE + 0x1308)
#define GPIO_W195                       (GPIO_PORT_BASE + 0x130C)
#define GPIO_W196                       (GPIO_PORT_BASE + 0x1310)
#define GPIO_W197                       (GPIO_PORT_BASE + 0x1314)
#define GPIO_W198                       (GPIO_PORT_BASE + 0x1318)
#define GPIO_W199                       (GPIO_PORT_BASE + 0x131C)
#define GPIO_W200                       (GPIO_PORT_BASE + 0x1320)
#define GPIO_W201                       (GPIO_PORT_BASE + 0x1324)
#define GPIO_W202                       (GPIO_PORT_BASE + 0x1328)
#define GPIO_W203                       (GPIO_PORT_BASE + 0x132C)
#define GPIO_W204                       (GPIO_PORT_BASE + 0x1330)
#define GPIO_W205                       (GPIO_PORT_BASE + 0x1334)
#define GPIO_W206                       (GPIO_PORT_BASE + 0x1338)
#define GPIO_W207                       (GPIO_PORT_BASE + 0x133C)
#define GPIO_W208                       (GPIO_PORT_BASE + 0x1340)
#define GPIO_W209                       (GPIO_PORT_BASE + 0x1344)
#define GPIO_W210                       (GPIO_PORT_BASE + 0x1348)
#define GPIO_W211                       (GPIO_PORT_BASE + 0x134C)
#define GPIO_W212                       (GPIO_PORT_BASE + 0x1350)
#define GPIO_W213                       (GPIO_PORT_BASE + 0x1354)
#define GPIO_W214                       (GPIO_PORT_BASE + 0x1358)
#define GPIO_W215                       (GPIO_PORT_BASE + 0x135C)
#define GPIO_W216                       (GPIO_PORT_BASE + 0x1360)
#define GPIO_W217                       (GPIO_PORT_BASE + 0x1364)
#define GPIO_W218                       (GPIO_PORT_BASE + 0x1368)
#define GPIO_W219                       (GPIO_PORT_BASE + 0x136C)
#define GPIO_W220                       (GPIO_PORT_BASE + 0x1370)
#define GPIO_W221                       (GPIO_PORT_BASE + 0x1374)
#define GPIO_W222                       (GPIO_PORT_BASE + 0x1378)
#define GPIO_W223                       (GPIO_PORT_BASE + 0x137C)

/* Word pin registers port 7 (R/W) */
#define GPIO_W224                       (GPIO_PORT_BASE + 0x1380)
#define GPIO_W225                       (GPIO_PORT_BASE + 0x1384)
#define GPIO_W226                       (GPIO_PORT_BASE + 0x1388)
#define GPIO_W227                       (GPIO_PORT_BASE + 0x138C)
#define GPIO_W228                       (GPIO_PORT_BASE + 0x1390)
#define GPIO_W229                       (GPIO_PORT_BASE + 0x1394)
#define GPIO_W230                       (GPIO_PORT_BASE + 0x1398)
#define GPIO_W231                       (GPIO_PORT_BASE + 0x139C)
#define GPIO_W232                       (GPIO_PORT_BASE + 0x13A0)
#define GPIO_W233                       (GPIO_PORT_BASE + 0x13A4)
#define GPIO_W234                       (GPIO_PORT_BASE + 0x13A8)
#define GPIO_W235                       (GPIO_PORT_BASE + 0x13AC)
#define GPIO_W236                       (GPIO_PORT_BASE + 0x13B0)
#define GPIO_W237                       (GPIO_PORT_BASE + 0x13B4)
#define GPIO_W238                       (GPIO_PORT_BASE + 0x13B8)
#define GPIO_W239                       (GPIO_PORT_BASE + 0x13BC)
#define GPIO_W240                       (GPIO_PORT_BASE + 0x13C0)
#define GPIO_W241                       (GPIO_PORT_BASE + 0x13C4)
#define GPIO_W242                       (GPIO_PORT_BASE + 0x13C8)
#define GPIO_W243                       (GPIO_PORT_BASE + 0x13CC)
#define GPIO_W244                       (GPIO_PORT_BASE + 0x13D0)
#define GPIO_W245                       (GPIO_PORT_BASE + 0x13D4)
#define GPIO_W246                       (GPIO_PORT_BASE + 0x13D8)
#define GPIO_W247                       (GPIO_PORT_BASE + 0x13DC)
#define GPIO_W248                       (GPIO_PORT_BASE + 0x13E0)
#define GPIO_W249                       (GPIO_PORT_BASE + 0x13E4)
#define GPIO_W250                       (GPIO_PORT_BASE + 0x13E8)
#define GPIO_W251                       (GPIO_PORT_BASE + 0x13EC)
#define GPIO_W252                       (GPIO_PORT_BASE + 0x13F0)
#define GPIO_W253                       (GPIO_PORT_BASE + 0x13F4)
#define GPIO_W254                       (GPIO_PORT_BASE + 0x13F8)
#define GPIO_W255                       (GPIO_PORT_BASE + 0x13FC)

#define GPIO_W(port, pin)				MMIO32(GPIO_PORT_BASE + 0x1000 + (port * 0x80) + (pin * 4))

/* GPIO data direction register (GPIOn_DIR) */
#define GPIO_DIR(port)                  MMIO32((port) + 0x00)
#define GPIO0_DIR                       GPIO_DIR(GPIO0)
#define GPIO1_DIR                       GPIO_DIR(GPIO1)
#define GPIO2_DIR                       GPIO_DIR(GPIO2)
#define GPIO3_DIR                       GPIO_DIR(GPIO3)
#define GPIO4_DIR                       GPIO_DIR(GPIO4)
#define GPIO5_DIR                       GPIO_DIR(GPIO5)
#define GPIO6_DIR                       GPIO_DIR(GPIO6)
#define GPIO7_DIR                       GPIO_DIR(GPIO7)

/* GPIO fast mask register (GPIOn_MASK) */
#define GPIO_MASK(port)                 MMIO32((port) + 0x80)
#define GPIO0_MASK                      GPIO_MASK(GPIO0)
#define GPIO1_MASK                      GPIO_MASK(GPIO1)
#define GPIO2_MASK                      GPIO_MASK(GPIO2)
#define GPIO3_MASK                      GPIO_MASK(GPIO3)
#define GPIO4_MASK                      GPIO_MASK(GPIO4)
#define GPIO5_MASK                      GPIO_MASK(GPIO5)
#define GPIO6_MASK                      GPIO_MASK(GPIO6)
#define GPIO7_MASK                      GPIO_MASK(GPIO7)

/* GPIO port pin value register (GPIOn_PIN) */
#define GPIO_PIN(port)                  MMIO32((port) + 0x100)
#define GPIO0_PIN                       GPIO_PIN(GPIO0)
#define GPIO1_PIN                       GPIO_PIN(GPIO1)
#define GPIO2_PIN                       GPIO_PIN(GPIO2)
#define GPIO3_PIN                       GPIO_PIN(GPIO3)
#define GPIO4_PIN                       GPIO_PIN(GPIO4)
#define GPIO5_PIN                       GPIO_PIN(GPIO5)
#define GPIO6_PIN                       GPIO_PIN(GPIO6)
#define GPIO7_PIN                       GPIO_PIN(GPIO7)

/* GPIO port masked pin value register (GPIOn_MPIN) */
#define GPIO_MPIN(port)                 MMIO32((port) + 0x180)
#define GPIO0_MPIN                      GPIO_MPIN(GPIO0)
#define GPIO1_MPIN                      GPIO_MPIN(GPIO1)
#define GPIO2_MPIN                      GPIO_MPIN(GPIO2)
#define GPIO3_MPIN                      GPIO_MPIN(GPIO3)
#define GPIO4_MPIN                      GPIO_MPIN(GPIO4)
#define GPIO5_MPIN                      GPIO_MPIN(GPIO5)
#define GPIO6_MPIN                      GPIO_MPIN(GPIO6)
#define GPIO7_MPIN                      GPIO_MPIN(GPIO7)

/* GPIO port output set register (GPIOn_SET) */
#define GPIO_SET(port)                  MMIO32((port) + 0x200)
#define GPIO0_SET                       GPIO_SET(GPIO0)
#define GPIO1_SET                       GPIO_SET(GPIO1)
#define GPIO2_SET                       GPIO_SET(GPIO2)
#define GPIO3_SET                       GPIO_SET(GPIO3)
#define GPIO4_SET                       GPIO_SET(GPIO4)
#define GPIO5_SET                       GPIO_SET(GPIO5)
#define GPIO6_SET                       GPIO_SET(GPIO6)
#define GPIO7_SET                       GPIO_SET(GPIO7)

/* GPIO port output clear register (GPIOn_CLR) */
#define GPIO_CLR(port)                  MMIO32((port) + 0x280)
#define GPIO0_CLR                       GPIO_CLR(GPIO0)
#define GPIO1_CLR                       GPIO_CLR(GPIO1)
#define GPIO2_CLR                       GPIO_CLR(GPIO2)
#define GPIO3_CLR                       GPIO_CLR(GPIO3)
#define GPIO4_CLR                       GPIO_CLR(GPIO4)
#define GPIO5_CLR                       GPIO_CLR(GPIO5)
#define GPIO6_CLR                       GPIO_CLR(GPIO6)
#define GPIO7_CLR                       GPIO_CLR(GPIO7)

/* GPIO port toggle register (GPIOn_NOT) */
#define GPIO_NOT(port)                  MMIO32((port) + 0x300)
#define GPIO0_NOT                       GPIO_NOT(GPIO0)
#define GPIO1_NOT                       GPIO_NOT(GPIO1)
#define GPIO2_NOT                       GPIO_NOT(GPIO2)
#define GPIO3_NOT                       GPIO_NOT(GPIO3)
#define GPIO4_NOT                       GPIO_NOT(GPIO4)
#define GPIO5_NOT                       GPIO_NOT(GPIO5)
#define GPIO6_NOT                       GPIO_NOT(GPIO6)
#define GPIO7_NOT                       GPIO_NOT(GPIO7)

/* TODO interrupts */

BEGIN_DECLS

void gpio_set(uint32_t gpioport, uint32_t gpios);
void gpio_clear(uint32_t gpioport, uint32_t gpios);
void gpio_toggle(uint32_t gpioport, uint32_t gpios);
uint32_t gpio_get(uint32_t gpioport, uint32_t gpios);

END_DECLS

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
