/*
 * Copyright (c) 2021-2022 hpmicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
.global default_irq_handler
.weak default_irq_handler
.align 2
default_irq_handler:
1:    j 1b

.macro IRQ_HANDLER irq
  .weak default_isr_\irq
  .set default_isr_\irq, default_irq_handler
  .long default_isr_\irq
.endm

.section .vector_table, "a"
.global __vector_table
.align 9

__vector_table:
    .weak default_isr_trap
    .set default_isr_trap, irq_handler_trap
    .long default_isr_trap
    IRQ_HANDLER 1 /* GPIO0_A IRQ handler */
    IRQ_HANDLER 2 /* GPIO0_B IRQ handler */
    IRQ_HANDLER 3 /* GPIO0_C IRQ handler */
    IRQ_HANDLER 4 /* GPIO0_D IRQ handler */
    IRQ_HANDLER 5 /* GPIO0_E IRQ handler */
    IRQ_HANDLER 6 /* GPIO0_F IRQ handler */
    IRQ_HANDLER 7 /* GPIO0_X IRQ handler */
    IRQ_HANDLER 8 /* GPIO0_Y IRQ handler */
    IRQ_HANDLER 9 /* GPIO0_Z IRQ handler */
    IRQ_HANDLER 10 /* GPIO1_A IRQ handler */
    IRQ_HANDLER 11 /* GPIO1_B IRQ handler */
    IRQ_HANDLER 12 /* GPIO1_C IRQ handler */
    IRQ_HANDLER 13 /* GPIO1_D IRQ handler */
    IRQ_HANDLER 14 /* GPIO1_E IRQ handler */
    IRQ_HANDLER 15 /* GPIO1_F IRQ handler */
    IRQ_HANDLER 16 /* GPIO1_X IRQ handler */
    IRQ_HANDLER 17 /* GPIO1_Y IRQ handler */
    IRQ_HANDLER 18 /* GPIO1_Z IRQ handler */
    IRQ_HANDLER 19 /* ADC0 IRQ handler */
    IRQ_HANDLER 20 /* ADC1 IRQ handler */
    IRQ_HANDLER 21 /* ADC2 IRQ handler */
    IRQ_HANDLER 22 /* ADC3 IRQ handler */
    IRQ_HANDLER 23 /* ACMP[0] IRQ handler */
    IRQ_HANDLER 24 /* ACMP[1] IRQ handler */
    IRQ_HANDLER 25 /* ACMP[2] IRQ handler */
    IRQ_HANDLER 26 /* ACMP[3] IRQ handler */
    IRQ_HANDLER 27 /* SPI0 IRQ handler */
    IRQ_HANDLER 28 /* SPI1 IRQ handler */
    IRQ_HANDLER 29 /* SPI2 IRQ handler */
    IRQ_HANDLER 30 /* SPI3 IRQ handler */
    IRQ_HANDLER 31 /* UART0 IRQ handler */
    IRQ_HANDLER 32 /* UART1 IRQ handler */
    IRQ_HANDLER 33 /* UART2 IRQ handler */
    IRQ_HANDLER 34 /* UART3 IRQ handler */
    IRQ_HANDLER 35 /* UART4 IRQ handler */
    IRQ_HANDLER 36 /* UART5 IRQ handler */
    IRQ_HANDLER 37 /* UART6 IRQ handler */
    IRQ_HANDLER 38 /* UART7 IRQ handler */
    IRQ_HANDLER 39 /* UART8 IRQ handler */
    IRQ_HANDLER 40 /* UART9 IRQ handler */
    IRQ_HANDLER 41 /* UART10 IRQ handler */
    IRQ_HANDLER 42 /* UART11 IRQ handler */
    IRQ_HANDLER 43 /* UART12 IRQ handler */
    IRQ_HANDLER 44 /* UART13 IRQ handler */
    IRQ_HANDLER 45 /* UART14 IRQ handler */
    IRQ_HANDLER 46 /* UART15 IRQ handler */
    IRQ_HANDLER 47 /* CAN0 IRQ handler */
    IRQ_HANDLER 48 /* CAN1 IRQ handler */
    IRQ_HANDLER 49 /* CAN2 IRQ handler */
    IRQ_HANDLER 50 /* CAN3 IRQ handler */
    IRQ_HANDLER 51 /* PTPC IRQ handler */
    IRQ_HANDLER 52 /* WDG0 IRQ handler */
    IRQ_HANDLER 53 /* WDG1 IRQ handler */
    IRQ_HANDLER 54 /* WDG2 IRQ handler */
    IRQ_HANDLER 55 /* WDG3 IRQ handler */
    IRQ_HANDLER 56 /* MBX0A IRQ handler */
    IRQ_HANDLER 57 /* MBX0B IRQ handler */
    IRQ_HANDLER 58 /* MBX1A IRQ handler */
    IRQ_HANDLER 59 /* MBX1B IRQ handler */
    IRQ_HANDLER 60 /* GPTMR0 IRQ handler */
    IRQ_HANDLER 61 /* GPTMR1 IRQ handler */
    IRQ_HANDLER 62 /* GPTMR2 IRQ handler */
    IRQ_HANDLER 63 /* GPTMR3 IRQ handler */
    IRQ_HANDLER 64 /* GPTMR4 IRQ handler */
    IRQ_HANDLER 65 /* GPTMR5 IRQ handler */
    IRQ_HANDLER 66 /* GPTMR6 IRQ handler */
    IRQ_HANDLER 67 /* GPTMR7 IRQ handler */
    IRQ_HANDLER 68 /* I2C0 IRQ handler */
    IRQ_HANDLER 69 /* I2C1 IRQ handler */
    IRQ_HANDLER 70 /* I2C2 IRQ handler */
    IRQ_HANDLER 71 /* I2C3 IRQ handler */
    IRQ_HANDLER 72 /* PWM0 IRQ handler */
    IRQ_HANDLER 73 /* HALL0 IRQ handler */
    IRQ_HANDLER 74 /* QEI0 IRQ handler */
    IRQ_HANDLER 75 /* PWM1 IRQ handler */
    IRQ_HANDLER 76 /* HALL1 IRQ handler */
    IRQ_HANDLER 77 /* QEI1 IRQ handler */
    IRQ_HANDLER 78 /* PWM2 IRQ handler */
    IRQ_HANDLER 79 /* HALL2 IRQ handler */
    IRQ_HANDLER 80 /* QEI2 IRQ handler */
    IRQ_HANDLER 81 /* PWM3 IRQ handler */
    IRQ_HANDLER 82 /* HALL3 IRQ handler */
    IRQ_HANDLER 83 /* QEI3 IRQ handler */
    IRQ_HANDLER 84 /* SDP IRQ handler */
    IRQ_HANDLER 85 /* XPI0 IRQ handler */
    IRQ_HANDLER 86 /* XPI1 IRQ handler */
    IRQ_HANDLER 87 /* XDMA IRQ handler */
    IRQ_HANDLER 88 /* HDMA IRQ handler */
    IRQ_HANDLER 89 /* DRAM IRQ handler */
    IRQ_HANDLER 90 /* RNG IRQ handler */
    IRQ_HANDLER 91 /* I2S0 IRQ handler */
    IRQ_HANDLER 92 /* I2S1 IRQ handler */
    IRQ_HANDLER 93 /* I2S2 IRQ handler */
    IRQ_HANDLER 94 /* I2S3 IRQ handler */
    IRQ_HANDLER 95 /* DAO IRQ handler */
    IRQ_HANDLER 96 /* PDM IRQ handler */
    IRQ_HANDLER 97 /* CAM0 IRQ handler */
    IRQ_HANDLER 98 /* CAM1 IRQ handler */
    IRQ_HANDLER 99 /* LCDC_D0 IRQ handler */
    IRQ_HANDLER 100 /* LCDC_D1 IRQ handler */
    IRQ_HANDLER 101 /* PDMA_D0 IRQ handler */
    IRQ_HANDLER 102 /* PDMA_D1 IRQ handler */
    IRQ_HANDLER 103 /* JPEG IRQ handler */
    IRQ_HANDLER 104 /* NTMR0 IRQ handler */
    IRQ_HANDLER 105 /* NTMR1 IRQ handler */
    IRQ_HANDLER 106 /* USB0 IRQ handler */
    IRQ_HANDLER 107 /* USB1 IRQ handler */
    IRQ_HANDLER 108 /* ENET0 IRQ handler */
    IRQ_HANDLER 109 /* ENET1 IRQ handler */
    IRQ_HANDLER 110 /* SDXC0 IRQ handler */
    IRQ_HANDLER 111 /* SDXC1 IRQ handler */
    IRQ_HANDLER 112 /* PSEC IRQ handler */
    IRQ_HANDLER 113 /* PGPIO IRQ handler */
    IRQ_HANDLER 114 /* PWDG IRQ handler */
    IRQ_HANDLER 115 /* PTMR IRQ handler */
    IRQ_HANDLER 116 /* PUART IRQ handler */
    IRQ_HANDLER 117 /* VAD IRQ handler */
    IRQ_HANDLER 118 /* FUSE IRQ handler */
    IRQ_HANDLER 119 /* SECMON IRQ handler */
    IRQ_HANDLER 120 /* RTC IRQ handler */
    IRQ_HANDLER 121 /* BUTN IRQ handler */
    IRQ_HANDLER 122 /* BGPIO IRQ handler */
    IRQ_HANDLER 123 /* BVIO IRQ handler */
    IRQ_HANDLER 124 /* BROWNOUT IRQ handler */
    IRQ_HANDLER 125 /* SYSCTL IRQ handler */
    IRQ_HANDLER 126 /* DEBUG[0] IRQ handler */
    IRQ_HANDLER 127 /* DEBUG[1] IRQ handler */
