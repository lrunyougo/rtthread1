/*
*******************************************************************************
**
** \file      BOARD_FPGA.h
**
** \brief     System initialization.
**
**            (C) Copyright 2012-2013 by Goke Microelectronics Shanghai Branch
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**            OMMISSIONS.
**
** \note
**
*******************************************************************************
*/
#ifndef GPIO_CFG_EVB_H
#define GPIO_CFG_EVB_H
#include "adi_types.h"
#include "adi_gpio.h"

#if 0 //MII
/* for gk7101s_fpga_gpio_151215*/
#define SYSTEM_GPIO_XREF_TABLE                      \
    { GADI_GPIO_0 , GADI_GPIO_TYPE_OUTPUT_SF_CS0        }, \
    { GADI_GPIO_1 , GADI_GPIO_TYPE_OUTPUT_SF_CS1        }, \
    { GADI_GPIO_2 , GADI_GPIO_TYPE_INPUT_UART0_RX       }, \
    { GADI_GPIO_3 , GADI_GPIO_TYPE_OUTPUT_UART0_TX      }, \
    { GADI_GPIO_4 , GADI_GPIO_TYPE_INOUT_I2C_CLK        }, \
    { GADI_GPIO_5 , GADI_GPIO_TYPE_INOUT_I2C_DATA       }, \
    { GADI_GPIO_6 , GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_7 , GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_8 , GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_9 , GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_10, GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_11, GADI_GPIO_TYPE_OUTPUT_PWM0_OUT      }, \
    { GADI_GPIO_12, GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_13, GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_14, GADI_GPIO_TYPE_OUTPUT_SDIO_CLK      }, \
    { GADI_GPIO_15, GADI_GPIO_TYPE_INOUT_SD_CMD         }, \
    { GADI_GPIO_16, GADI_GPIO_TYPE_INPUT_SD_CD_N        }, \
    { GADI_GPIO_17, GADI_GPIO_TYPE_INPUT_SD_WP_N        }, \
    { GADI_GPIO_18, GADI_GPIO_TYPE_INOUT_SD_DATA_0      }, \
    { GADI_GPIO_19, GADI_GPIO_TYPE_INOUT_SD_DATA_1      }, \
    { GADI_GPIO_20, GADI_GPIO_TYPE_INOUT_SD_DATA_2    }, \
    { GADI_GPIO_21, GADI_GPIO_TYPE_INOUT_SD_DATA_3    }, \
    { GADI_GPIO_22, GADI_GPIO_TYPE_UNDEFINED    }, \
    { GADI_GPIO_23, GADI_GPIO_TYPE_UNDEFINED            }, \
    { GADI_GPIO_24, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_0 }, \
    { GADI_GPIO_25, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_1 }, \
    { GADI_GPIO_26, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_2 }, \
    { GADI_GPIO_27, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_3 }, \
    { GADI_GPIO_28, GADI_GPIO_TYPE_INPUT_ENET_CLK_RX    }, \
    { GADI_GPIO_29, GADI_GPIO_TYPE_INPUT_ENET_CLK_TX    }, \
    { GADI_GPIO_30, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0}, \
    { GADI_GPIO_31, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1}, \
    { GADI_GPIO_32, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_2}, \
    { GADI_GPIO_33, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_3}, \
    { GADI_GPIO_34, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXEN }, \
    { GADI_GPIO_35, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_RESET/*ETH reset*/}, \
    { GADI_GPIO_36, GADI_GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O}, \
    { GADI_GPIO_37, GADI_GPIO_TYPE_INOUT_ETH_MDIO       }, \
    { GADI_GPIO_38, GADI_GPIO_TYPE_INPUT_ENET_PHY_CRS   }, \
    { GADI_GPIO_39, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXER  }, \
    { GADI_GPIO_40, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXDV  }, \
    { GADI_GPIO_41, GADI_GPIO_TYPE_INPUT_ENET_PHY_COL   }, \
    { GADI_GPIO_42, GADI_GPIO_TYPE_UNDEFINED/*USB reset*/}
#elif 0   //peripherals
#define SYSTEM_GPIO_XREF_TABLE                      \
    { GADI_GPIO_0 , GADI_GPIO_TYPE_OUTPUT_SF_CS0                }, \
    { GADI_GPIO_1 , GADI_GPIO_TYPE_OUTPUT_SF_CS1                }, \
    { GADI_GPIO_2 , GADI_GPIO_TYPE_INOUT_SF_HOLD /*Sensor reset*/   }, \
    { GADI_GPIO_3 , GADI_GPIO_TYPE_INOUT_SF_WP          }, \
    { GADI_GPIO_4 , GADI_GPIO_TYPE_INOUT_I2C_CLK  /*S C*/       }, \
    { GADI_GPIO_5 , GADI_GPIO_TYPE_INOUT_I2C_DATA /*S D*/       }, \
    { GADI_GPIO_6 , GADI_GPIO_TYPE_INPUT_JTAG_TRSTN         }, \
    { GADI_GPIO_7 , GADI_GPIO_TYPE_INPUT_JTAG_TCK           }, \
    { GADI_GPIO_8 , GADI_GPIO_TYPE_INPUT_JTAG_TMS           }, \
    { GADI_GPIO_9 , GADI_GPIO_TYPE_INPUT_JTAG_TDI           }, \
    { GADI_GPIO_10, GADI_GPIO_TYPE_OUTPUT_JTAGE_TDO         }, \
    { GADI_GPIO_11, GADI_GPIO_TYPE_OUTPUT_PWM0_OUT          }, \
    { GADI_GPIO_12, GADI_GPIO_TYPE_OUTPUT_VD_DATA4          }, \
    { GADI_GPIO_13, GADI_GPIO_TYPE_OUTPUT_VD_DATA5          }, \
    { GADI_GPIO_14, GADI_GPIO_TYPE_OUTPUT_VD_DATA6          }, \
    { GADI_GPIO_15, GADI_GPIO_TYPE_OUTPUT_VD_DATA7          }, \
    { GADI_GPIO_16, GADI_GPIO_TYPE_OUTPUT_VD_HSYNC/*LCD_DISP*/}, \
    { GADI_GPIO_17, GADI_GPIO_TYPE_OUTPUT_VD_VSYNC          }, \
    { GADI_GPIO_18, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1           }, \
    { GADI_GPIO_19, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_2                 }, \
    { GADI_GPIO_20, GADI_GPIO_TYPE_OUTPUT_1   /*LCD_CS*/    }, \
    { GADI_GPIO_21, GADI_GPIO_TYPE_OUTPUT_1   /*LCD_RST*/   }, \
    { GADI_GPIO_22, GADI_GPIO_TYPE_INPUT_UART0_RX           }, \
    { GADI_GPIO_23, GADI_GPIO_TYPE_OUTPUT_UART0_TX          }, \
    { GADI_GPIO_24, GADI_GPIO_TYPE_INPUT_UART1_RX }, \
    { GADI_GPIO_25, GADI_GPIO_TYPE_OUTPUT_UART1_TX }, \
    { GADI_GPIO_26, GADI_GPIO_TYPE_OUTPUT_SPI0_CS0 }, \
    { GADI_GPIO_27, GADI_GPIO_TYPE_OUTPUT_SPI0_SCLK }, \
    { GADI_GPIO_28, GADI_GPIO_TYPE_OUTPUT_SPI0_SO    }, \
    { GADI_GPIO_29, GADI_GPIO_TYPE_INPUT_SPI0_SI    }, \
    { GADI_GPIO_30, GADI_GPIO_TYPE_UNDEFINED}, \
    { GADI_GPIO_31, GADI_GPIO_TYPE_UNDEFINED}, \
    { GADI_GPIO_32, GADI_GPIO_TYPE_UNDEFINED}, \
    { GADI_GPIO_33, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_3}, \
    { GADI_GPIO_34, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXEN }, \
    { GADI_GPIO_35, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_RESET/*ETH reset*/}, \
    { GADI_GPIO_36, GADI_GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O}, \
    { GADI_GPIO_37, GADI_GPIO_TYPE_INOUT_ETH_MDIO       }, \
    { GADI_GPIO_38, GADI_GPIO_TYPE_INPUT_ENET_PHY_CRS   }, \
    { GADI_GPIO_39, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXER  }, \
    { GADI_GPIO_40, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXDV  }, \
    { GADI_GPIO_41, GADI_GPIO_TYPE_INPUT_ENET_PHY_COL   }, \
    { GADI_GPIO_42, GADI_GPIO_TYPE_UNDEFINED/*USB reset*/}

#elif 0   //GK7102C_FPGA_svn509_1704061946.bit  RMII
#define SYSTEM_GPIO_XREF_TABLE                      \
    { GADI_GPIO_0 , GADI_GPIO_TYPE_OUTPUT_SF_CS0                    }, \
    { GADI_GPIO_1 , GADI_GPIO_TYPE_OUTPUT_SF_CS1                    }, \
    { GADI_GPIO_2 , GADI_GPIO_TYPE_OUTPUT_1      /*Sensor reset*/   }, \
    { GADI_GPIO_3 , GADI_GPIO_TYPE_INOUT_SF_WP          }, \
    { GADI_GPIO_4 , GADI_GPIO_TYPE_INOUT_I2C_CLK  /*S C*/           }, \
    { GADI_GPIO_5 , GADI_GPIO_TYPE_INOUT_I2C_DATA /*S D*/           }, \
    { GADI_GPIO_6 , GADI_GPIO_TYPE_INPUT_JTAG_TRSTN                 }, \
    { GADI_GPIO_7 , GADI_GPIO_TYPE_INPUT_JTAG_TCK                   }, \
    { GADI_GPIO_8 , GADI_GPIO_TYPE_INPUT_JTAG_TMS                   }, \
    { GADI_GPIO_9 , GADI_GPIO_TYPE_INPUT_JTAG_TDI                   }, \
    { GADI_GPIO_10, GADI_GPIO_TYPE_OUTPUT_JTAGE_TDO                 }, \
    { GADI_GPIO_11, GADI_GPIO_TYPE_OUTPUT_PWM0_OUT                  }, \
    { GADI_GPIO_12, GADI_GPIO_TYPE_OUTPUT_VD_DATA4                  }, \
    { GADI_GPIO_13, GADI_GPIO_TYPE_OUTPUT_VD_DATA5                  }, \
    { GADI_GPIO_14, GADI_GPIO_TYPE_OUTPUT_VD_DATA6                  }, \
    { GADI_GPIO_15, GADI_GPIO_TYPE_OUTPUT_VD_DATA7                  }, \
    { GADI_GPIO_16, GADI_GPIO_TYPE_OUTPUT_VD_HSYNC/*LCD_DISP*/      }, \
    { GADI_GPIO_17, GADI_GPIO_TYPE_OUTPUT_VD_VSYNC                  }, \
    { GADI_GPIO_18, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1            }, \
    { GADI_GPIO_19, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_2            }, \
    { GADI_GPIO_20, GADI_GPIO_TYPE_OUTPUT_1   /*LCD_CS*/            }, \
    { GADI_GPIO_21, GADI_GPIO_TYPE_OUTPUT_1   /*LCD_RST*/           }, \
    { GADI_GPIO_22, GADI_GPIO_TYPE_INPUT_UART0_RX                   }, \
    { GADI_GPIO_23, GADI_GPIO_TYPE_OUTPUT_UART0_TX                  }, \
    { GADI_GPIO_24, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_0             }, \
    { GADI_GPIO_25, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_1             }, \
    { GADI_GPIO_26, GADI_GPIO_TYPE_OUTPUT_SPI0_CS0                  }, \
    { GADI_GPIO_27, GADI_GPIO_TYPE_OUTPUT_SPI0_SCLK                 }, \
    { GADI_GPIO_28, GADI_GPIO_TYPE_INPUT_0                          }, \
    { GADI_GPIO_29, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_2             }, \
    { GADI_GPIO_30, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0            }, \
    { GADI_GPIO_31, GADI_GPIO_TYPE_UNDEFINED                        }, \
    { GADI_GPIO_32, GADI_GPIO_TYPE_UNDEFINED                        }, \
    { GADI_GPIO_33, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_3            }, \
    { GADI_GPIO_34, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXEN             }, \
    { GADI_GPIO_35, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_RESET/*ETH reset*/}, \
    { GADI_GPIO_36, GADI_GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O           }, \
    { GADI_GPIO_37, GADI_GPIO_TYPE_INOUT_ETH_MDIO                   }, \
    { GADI_GPIO_38, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXDV              }, \
    { GADI_GPIO_39, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXER              }, \
    { GADI_GPIO_40, GADI_GPIO_TYPE_INPUT_0                          }, \
    { GADI_GPIO_41, GADI_GPIO_TYPE_INPUT_ENET_PHY_COL               }, \
    { GADI_GPIO_42, GADI_GPIO_TYPE_UNDEFINED/*USB reset*/           }

#elif 1   //GK7102C_FPGA_svn_1705242221.bit  RMII
#define SYSTEM_GPIO_XREF_TABLE                      \
    { GADI_GPIO_0 , GADI_GPIO_TYPE_UNDEFINED                }, \
    { GADI_GPIO_1 , GADI_GPIO_TYPE_UNDEFINED                }, \
    { GADI_GPIO_2 , GADI_GPIO_TYPE_OUTPUT_1   /*Sensor reset*/  }, \
    { GADI_GPIO_3 , GADI_GPIO_TYPE_OUTPUT_VD_CLOCK              }, \
    { GADI_GPIO_4 , GADI_GPIO_TYPE_INOUT_I2C_CLK  /*S C*/       }, \
    { GADI_GPIO_5 , GADI_GPIO_TYPE_INOUT_I2C_DATA /*S D*/       }, \
    { GADI_GPIO_6 , GADI_GPIO_TYPE_INPUT_JTAG_TRSTN             }, \
    { GADI_GPIO_7 , GADI_GPIO_TYPE_INPUT_JTAG_TCK               }, \
    { GADI_GPIO_8 , GADI_GPIO_TYPE_INPUT_JTAG_TMS               }, \
    { GADI_GPIO_9 , GADI_GPIO_TYPE_INPUT_JTAG_TDI               }, \
    { GADI_GPIO_10, GADI_GPIO_TYPE_OUTPUT_JTAGE_TDO             }, \
    { GADI_GPIO_11, GADI_GPIO_TYPE_OUTPUT_VD_DATA3              }, \
    { GADI_GPIO_12, GADI_GPIO_TYPE_OUTPUT_VD_DATA4              }, \
    { GADI_GPIO_13, GADI_GPIO_TYPE_OUTPUT_VD_DATA5              }, \
    { GADI_GPIO_14, GADI_GPIO_TYPE_OUTPUT_VD_DATA6              }, \
    { GADI_GPIO_15, GADI_GPIO_TYPE_OUTPUT_VD_DATA7              }, \
    { GADI_GPIO_16, GADI_GPIO_TYPE_OUTPUT_VD_HSYNC              }, \
    { GADI_GPIO_17, GADI_GPIO_TYPE_OUTPUT_VD_VSYNC              }, \
    { GADI_GPIO_18, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_1        }, \
    { GADI_GPIO_19, GADI_GPIO_TYPE_OUTPUT_1 /*LCD_DISP*/          }, \
    { GADI_GPIO_20, GADI_GPIO_TYPE_OUTPUT_VD_DATA1              }, \
    { GADI_GPIO_21, GADI_GPIO_TYPE_OUTPUT_1  /*lcd_rst*/        }, \
    { GADI_GPIO_22, GADI_GPIO_TYPE_INPUT_UART0_RX               }, \
    { GADI_GPIO_23, GADI_GPIO_TYPE_OUTPUT_UART0_TX              }, \
    { GADI_GPIO_24, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_0         }, \
    { GADI_GPIO_25, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_1         }, \
    { GADI_GPIO_26, GADI_GPIO_TYPE_OUTPUT_1 /*lcd_bl_en*/       }, \
    { GADI_GPIO_27, GADI_GPIO_TYPE_OUTPUT_VD_DATA0              }, \
    { GADI_GPIO_28, GADI_GPIO_TYPE_INPUT_0            }, \
    { GADI_GPIO_29, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXD_2            }, \
    { GADI_GPIO_30, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXD_0        }, \
    { GADI_GPIO_31, GADI_GPIO_TYPE_INPUT_0                      }, \
    { GADI_GPIO_32, GADI_GPIO_TYPE_INPUT_0                      }, \
    { GADI_GPIO_33, GADI_GPIO_TYPE_OUTPUT_VD_DATA2              }, \
    { GADI_GPIO_34, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_TXEN         }, \
    { GADI_GPIO_35, GADI_GPIO_TYPE_OUTPUT_ENET_PHY_RESET/*ETH reset*/}, \
    { GADI_GPIO_36, GADI_GPIO_TYPE_OUTPUT_ENET_GMII_MDC_O}, \
    { GADI_GPIO_37, GADI_GPIO_TYPE_INOUT_ETH_MDIO       }, \
    { GADI_GPIO_38, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXDV   }, \
    { GADI_GPIO_39, GADI_GPIO_TYPE_INPUT_ENET_PHY_RXER  }, \
    { GADI_GPIO_40, GADI_GPIO_TYPE_INPUT_0  }, \
    { GADI_GPIO_41, GADI_GPIO_TYPE_INPUT_ENET_PHY_COL   }, \
    { GADI_GPIO_42, GADI_GPIO_TYPE_OUTPUT_VD_HVLD/*lcd_de*/}

#endif

#define SYSTEM_ETH_PHY_RESET_GPIO               GADI_GPIO_35//not real pin
#define SYSTEM_GPIO_SENSOR_RESET                GADI_GPIO_2 //GADI_GPIO_16
#define SYSTEM_GPIO_IR_CUT1                     GADI_GPIO_43//GADI_GPIO_18
#define SYSTEM_GPIO_IR_CUT2                     GADI_GPIO_53//GADI_GPIO_19
#define SYSTEM_GPIO_USB_HOST                    GADI_GPIO_63


#endif
