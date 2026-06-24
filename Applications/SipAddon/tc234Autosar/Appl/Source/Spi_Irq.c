/**********************************************************************************************************************
 *  Spi_Irq.c
 *  Os CAT2 ISR wrappers for Infineon SPI/QSPI + DMA (QSPI1).
 *
 *  Vector OS maps ISR(name) -> Os_Isr_name. Hardware vectors are in Os_Hal_Entry_Lcfg.c;
 *  these handlers call the MCAL SPI driver ISRs.
 **********************************************************************************************************************/

#include "Os.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define SPI_IRQ_QSPI1_MODULE  (SPI_QSPI1_INDEX)

#define OS_START_SEC_SpiIsrDmaRx_CODE
#include "MemMap.h"

ISR(SpiIsrDmaRx)
{
  Spi_IsrDmaQspiRx(SPI_IRQ_QSPI1_MODULE);
}

#define OS_STOP_SEC_SpiIsrDmaRx_CODE
#include "MemMap.h"


#define OS_START_SEC_SpiIsrDmaTx_CODE
#include "MemMap.h"

ISR(SpiIsrDmaTx)
{
  Spi_IsrDmaQspiTx(SPI_IRQ_QSPI1_MODULE);
}

#define OS_STOP_SEC_SpiIsrDmaTx_CODE
#include "MemMap.h"


#define OS_START_SEC_SpiIsrQspiErr_CODE
#include "MemMap.h"

ISR(SpiIsrQspiErr)
{
  Spi_IsrQspiError(SPI_IRQ_QSPI1_MODULE);
}

#define OS_STOP_SEC_SpiIsrQspiErr_CODE
#include "MemMap.h"


#define OS_START_SEC_SpiIsrQspiPt_CODE
#include "MemMap.h"

ISR(SpiIsrQspiPt)
{
  Spi_IsrQspiPt(SPI_IRQ_QSPI1_MODULE);
}

#define OS_STOP_SEC_SpiIsrQspiPt_CODE
#include "MemMap.h"


/* Legacy Os ISRs for QSPI TX/RX SRC (not used when TOS=DMA). Required until ECUC is cleaned up. */
#define OS_START_SEC_SpiIsrTx_CODE
#include "MemMap.h"

ISR(SpiIsrTx)
{
}

#define OS_STOP_SEC_SpiIsrTx_CODE
#include "MemMap.h"


#define OS_START_SEC_SPiIsrRx_CODE
#include "MemMap.h"

ISR(SPiIsrRx)
{
}

#define OS_STOP_SEC_SPiIsrRx_CODE
#include "MemMap.h"
