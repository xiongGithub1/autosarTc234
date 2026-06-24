/**********************************************************************************************************************
 * TLF35584 pin mapping (IEBS_wulin / yuanlitu schematic, QSPI1 on P11).
 * SPI: DaVinci Port + Spi MCAL. GPIO: Dio channels below.
 **********************************************************************************************************************/

#ifndef TLF35584_CFG_H
#define TLF35584_CFG_H

#include "Dio_Cfg.h"

/* QSPI1: P11.2 CS, P11.6 SCLK, P11.9 MOSI, P11.3 MISO 鈥� configured in Port/Spi ECUC */

/* MCU -> TLF35584 ERR (FSP), V1.43: P33.8 */
#define TLF35584_DIO_ERR_PIN          DioConf_DioChannel_DioChannel_35584_ERR
/* Window watchdog trigger WDI, P33.12 */
#define TLF35584_DIO_WDI_PIN          DioConf_DioChannel_DioChannel_35584_WDI
/* TLF35584 -> MCU safe state */
#define TLF35584_DIO_SS1_PIN          DioConf_DioChannel_DioChannel_35584_SS1  /* P21.2 */
#define TLF35584_DIO_SS2_PIN          DioConf_DioChannel_DioChannel_35584_SS2  /* P21.3 */
/* MPS control, P00.12 */
#define TLF35584_DIO_MPS_PIN          DioConf_DioChannel_DioChannel_35584_MPS

#endif /* TLF35584_CFG_H */
