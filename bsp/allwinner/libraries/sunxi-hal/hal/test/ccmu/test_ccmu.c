#include <hal_log.h>
#include <hal_cmd.h>
#include <hal_clk.h>

struct  st_test_clk
{
    hal_clk_id_t id;
    char *name;
};

struct  st_test_clk ccmu_test_table[] =
{
    { HAL_CLK_SRC_ROOT,                  "HAL_CLK_SRC_ROOT"},

    { HAL_CLK_SRC_HOSC24M,          "HAL_CLK_SRC_HOSC24M"},
    { HAL_CLK_SRC_HOSC24MD2,             "HAL_CLK_SRC_HOSC24MD2"},
    { HAL_CLK_SRC_IOSC16M,               "HAL_CLK_SRC_IOSC16M"},
    { HAL_CLK_SRC_OSC48M,                "HAL_CLK_SRC_OSC48M"},
    { HAL_CLK_SRC_OSC48MD4,              "HAL_CLK_SRC_OSC48MD4"},
    { HAL_CLK_SRC_LOSC,                  "HAL_CLK_SRC_LOSC"},
    { HAL_CLK_SRC_RC16M,                 "HAL_CLK_SRC_RC16M"},
    { HAL_CLK_PLL_PERI0DIV25M,           "HAL_CLK_PLL_PERI0DIV25M"},

    { HAL_CLK_PLL_PERI0X2,      "HAL_CLK_PLL_PERI0X2         "},
    { HAL_CLK_PLL_PERI1X2,               "HAL_CLK_PLL_PERI1X2"},
    { HAL_CLK_PLL_AUDIOX2,               "HAL_CLK_PLL_AUDIOX2"},
    { HAL_CLK_PLL_AUDIOX4,               "HAL_CLK_PLL_AUDIOX4"},
    { HAL_CLK_PLL_VIDEOX4,               "HAL_CLK_PLL_VIDEOX4"},
    { HAL_CLK_PLL_DDRDIV4,               "HAL_CLK_PLL_DDRDIV4"},

    { HAL_CLK_PLL_CPUX_C0,          "HAL_CLK_PLL_CPUX_C0     "},
    { HAL_CLK_PLL_CPUX_C1,               "HAL_CLK_PLL_CPUX_C1"},
    { HAL_CLK_PLL_DDR0,                  "HAL_CLK_PLL_DDR0"},
    { HAL_CLK_PLL_DDR1,                  "HAL_CLK_PLL_DDR1"},
    { HAL_CLK_PLL_32K,                   "HAL_CLK_PLL_32K"},
    { HAL_CLK_PLL_PERI0,                 "HAL_CLK_PLL_PERI0"},
    { HAL_CLK_PLL_PERI1,                 "HAL_CLK_PLL_PERI1"},
    { HAL_CLK_PLL_GPU0,                  "HAL_CLK_PLL_GPU0"},
    { HAL_CLK_PLL_GPU1,                  "HAL_CLK_PLL_GPU1"},
    { HAL_CLK_PLL_VIDEO0,                "HAL_CLK_PLL_VIDEO0"},
    { HAL_CLK_PLL_VIDEO1,                "HAL_CLK_PLL_VIDEO1"},
    { HAL_CLK_PLL_VIDEO2,                "HAL_CLK_PLL_VIDEO2"},
    { HAL_CLK_PLL_VE,                    "HAL_CLK_PLL_VE"},
    { HAL_CLK_PLL_DE,                    "HAL_CLK_PLL_DE"},
    { HAL_CLK_PLL_ISP,                   "HAL_CLK_PLL_ISP"},
    { HAL_CLK_PLL_HSIC,                  "HAL_CLK_PLL_HSIC"},
    { HAL_CLK_PLL_AUDIO,                 "HAL_CLK_PLL_AUDIO"},
    { HAL_CLK_PLL_VIDEO,                 "HAL_CLK_PLL_VIDEO"},
    { HAL_CLK_PLL_MIPI,                  "HAL_CLK_PLL_MIPI"},
    { HAL_CLK_PLL_HDMI,                  "HAL_CLK_PLL_HDMI"},
    { HAL_CLK_PLL_USB,                   "HAL_CLK_PLL_USB"},
    { HAL_CLK_PLL_EDP,                   "HAL_CLK_PLL_EDP"},
    { HAL_CLK_PLL_SATA,                  "HAL_CLK_PLL_SATA"},
    { HAL_CLK_PLL_ADC,                   "HAL_CLK_PLL_ADC"},
    { HAL_CLK_PLL_DTMB,                  "HAL_CLK_PLL_DTMB"},
    { HAL_CLK_PLL_24M,                   "HAL_CLK_PLL_24M"},
    { HAL_CLK_PLL_EVE,                   "HAL_CLK_PLL_EVE"},
    { HAL_CLK_PLL_CVE,                   "HAL_CLK_PLL_CVE"},
    { HAL_CLK_PLL_ISE,                   "HAL_CLK_PLL_ISE"},
    { HAL_CLK_PLL_CSI,                   "HAL_CLK_PLL_CSI"},

    { HAL_CLK_BUS_C0_CPU,              "HAL_CLK_BUS_C0_CPU  "},
    { HAL_CLK_BUS_C1_CPU,                "HAL_CLK_BUS_C1_CPU"},
    { HAL_CLK_BUS_C0_AXI,                "HAL_CLK_BUS_C0_AXI"},
    { HAL_CLK_BUS_C1_AXI,                "HAL_CLK_BUS_C1_AXI"},
    { HAL_CLK_BUS_CPUAPB,                "HAL_CLK_BUS_CPUAPB"},
    { HAL_CLK_BUS_PSI,                   "HAL_CLK_BUS_PSI"},
    { HAL_CLK_BUS_AHB1,                  "HAL_CLK_BUS_AHB1"},
    { HAL_CLK_BUS_AHB2,                  "HAL_CLK_BUS_AHB2"},
    { HAL_CLK_BUS_AHB3,                  "HAL_CLK_BUS_AHB3"},
    { HAL_CLK_BUS_APB1,                  "HAL_CLK_BUS_APB1"},
    { HAL_CLK_BUS_APB2,                  "HAL_CLK_BUS_APB2"},
    { HAL_CLK_BUS_CCI400,                "HAL_CLK_BUS_CCI400"},
    { HAL_CLK_BUS_MBUS,                  "HAL_CLK_BUS_MBUS"},
    { HAL_CLK_PERIPH_DMA,                "HAL_CLK_PERIPH_DMA"},
    { HAL_CLK_PERIPH_DE,                 "HAL_CLK_PERIPH_DE"},
    { HAL_CLK_PERIPH_EE,                 "HAL_CLK_PERIPH_EE"},
    { HAL_CLK_PERIPH_DI,                 "HAL_CLK_PERIPH_DI"},
    { HAL_CLK_PERIPH_G2D,                "HAL_CLK_PERIPH_G2D"},
    { HAL_CLK_PERIPH_EDMA,               "HAL_CLK_PERIPH_EDMA"},
    { HAL_CLK_PERIPH_EVE,                "HAL_CLK_PERIPH_EVE"},
    { HAL_CLK_PERIPH_CVE,                "HAL_CLK_PERIPH_CVE"},
    { HAL_CLK_PERIPH_GPU,                "HAL_CLK_PERIPH_GPU"},
    { HAL_CLK_PERIPH_CE,                 "HAL_CLK_PERIPH_CE"},
    { HAL_CLK_PERIPH_VE,                 "HAL_CLK_PERIPH_VE"},
    { HAL_CLK_PERIPH_EISE,               "HAL_CLK_PERIPH_EISE"},
    { HAL_CLK_PERIPH_NNA,                "HAL_CLK_PERIPH_NNA"},
    { HAL_CLK_PERIPH_NNA_RST,            "HAL_CLK_PERIPH_NNA_RST"},
    { HAL_CLK_PERIPH_MSGBOX0,            "HAL_CLK_PERIPH_MSGBOX0"},
    { HAL_CLK_PERIPH_MSGBOX1,            "HAL_CLK_PERIPH_MSGBOX1"},
    { HAL_CLK_PERIPH_MSGBOXR,            "HAL_CLK_PERIPH_MSGBOXR"},
    { HAL_CLK_PERIPH_SPINLOCK,           "HAL_CLK_PERIPH_SPINLOCK"},
    { HAL_CLK_PERIPH_HSTIMER,            "HAL_CLK_PERIPH_HSTIMER"},
    { HAL_CLK_PERIPH_AVS,                "HAL_CLK_PERIPH_AVS"},
    { HAL_CLK_PERIPH_DBGSYS,             "HAL_CLK_PERIPH_DBGSYS"},
    { HAL_CLK_PERIPH_PWM,                "HAL_CLK_PERIPH_PWM"},
    { HAL_CLK_PERIPH_IOMMU,              "HAL_CLK_PERIPH_IOMMU"},
    { HAL_CLK_PERIPH_GPIO,               "HAL_CLK_PERIPH_GPIO"},
    { HAL_CLK_PERIPH_DRAM,               "HAL_CLK_PERIPH_DRAM"},
    { HAL_CLK_PERIPH_NAND0,              "HAL_CLK_PERIPH_NAND0"},
    { HAL_CLK_PERIPH_NAND1,              "HAL_CLK_PERIPH_NAND1"},
    { HAL_CLK_PERIPH_SDMMC0_MOD,         "HAL_CLK_PERIPH_SDMMC0_MOD"},
    { HAL_CLK_PERIPH_SDMMC0_RST,         "HAL_CLK_PERIPH_SDMMC0_RST"},
    { HAL_CLK_PERIPH_SDMMC0_BUS,         "HAL_CLK_PERIPH_SDMMC0_BUS"},
    { HAL_CLK_PERIPH_SDMMC1_MOD,         "HAL_CLK_PERIPH_SDMMC1_MOD"},
    { HAL_CLK_PERIPH_SDMMC1_RST,         "HAL_CLK_PERIPH_SDMMC1_RST"},
    { HAL_CLK_PERIPH_SDMMC2_BUS,         "HAL_CLK_PERIPH_SDMMC2_BUS"},
    { HAL_CLK_PERIPH_SDMMC2_MOD,         "HAL_CLK_PERIPH_SDMMC2_MOD"},
    { HAL_CLK_PERIPH_SDMMC2_RST,         "HAL_CLK_PERIPH_SDMMC2_RST"},
    { HAL_CLK_PERIPH_SDMMC1_BUS,         "HAL_CLK_PERIPH_SDMMC1_BUS"},
    { HAL_CLK_PERIPH_SMHC3,              "HAL_CLK_PERIPH_SMHC3"},
    { HAL_CLK_PERIPH_SMHC4,              "HAL_CLK_PERIPH_SMHC4"},
    { HAL_CLK_PERIPH_SMHC5,              "HAL_CLK_PERIPH_SMHC5"},
    { HAL_CLK_PERIPH_UART0,              "HAL_CLK_PERIPH_UART0"},
    { HAL_CLK_PERIPH_UART1,              "HAL_CLK_PERIPH_UART1"},
    { HAL_CLK_PERIPH_UART2,              "HAL_CLK_PERIPH_UART2"},
    { HAL_CLK_PERIPH_UART3,              "HAL_CLK_PERIPH_UART3"},
    { HAL_CLK_PERIPH_UART4,              "HAL_CLK_PERIPH_UART4"},
    { HAL_CLK_PERIPH_UART5,              "HAL_CLK_PERIPH_UART5"},
    { HAL_CLK_PERIPH_UART6,              "HAL_CLK_PERIPH_UART6"},
    { HAL_CLK_PERIPH_UART7,              "HAL_CLK_PERIPH_UART7"},
    { HAL_CLK_PERIPH_TWI0,               "HAL_CLK_PERIPH_TWI0"},
    { HAL_CLK_PERIPH_TWI1,               "HAL_CLK_PERIPH_TWI1"},
    { HAL_CLK_PERIPH_TWI2,               "HAL_CLK_PERIPH_TWI2"},
    { HAL_CLK_PERIPH_TWI3,               "HAL_CLK_PERIPH_TWI3"},
    { HAL_CLK_PERIPH_TWI4,               "HAL_CLK_PERIPH_TWI4"},
    { HAL_CLK_PERIPH_CAN0,               "HAL_CLK_PERIPH_CAN0"},
    { HAL_CLK_PERIPH_CAN1,               "HAL_CLK_PERIPH_CAN1"},
    { HAL_CLK_PERIPH_CAN2,               "HAL_CLK_PERIPH_CAN2"},
    { HAL_CLK_PERIPH_SCR0,               "HAL_CLK_PERIPH_SCR0"},
    { HAL_CLK_PERIPH_SCR1,               "HAL_CLK_PERIPH_SCR1"},
    { HAL_CLK_PERIPH_SCR2,               "HAL_CLK_PERIPH_SCR2"},
    { HAL_CLK_PERIPH_SCR3,               "HAL_CLK_PERIPH_SCR3"},
    { HAL_CLK_PERIPH_SPI0,               "HAL_CLK_PERIPH_SPI0"},
    { HAL_CLK_PERIPH_SPI1,               "HAL_CLK_PERIPH_SPI1"},
    { HAL_CLK_PERIPH_SPI2,               "HAL_CLK_PERIPH_SPI2"},
    { HAL_CLK_PERIPH_SPI3,               "HAL_CLK_PERIPH_SPI3"},
    { HAL_CLK_PERIPH_SPI4,               "HAL_CLK_PERIPH_SPI4"},
    { HAL_CLK_PERIPH_SPI5,               "HAL_CLK_PERIPH_SPI5"},
    { HAL_CLK_PERIPH_SPI6,               "HAL_CLK_PERIPH_SPI6"},
    { HAL_CLK_PERIPH_SPI7,               "HAL_CLK_PERIPH_SPI7"},
    { HAL_CLK_PERIPH_THS,                "HAL_CLK_PERIPH_THS"},
    { HAL_CLK_PERIPH_GMAC,               "HAL_CLK_PERIPH_GMAC"},
    { HAL_CLK_PERIPH_EPHY,               "HAL_CLK_PERIPH_EPHY"},
    { HAL_CLK_PERIPH_EMAC,               "HAL_CLK_PERIPH_EMAC"},
    { HAL_CLK_PERIPH_SATA,               "HAL_CLK_PERIPH_SATA"},
    { HAL_CLK_PERIPH_TS0,                "HAL_CLK_PERIPH_TS0"},
    { HAL_CLK_PERIPH_TS1,                "HAL_CLK_PERIPH_TS1"},
    { HAL_CLK_PERIPH_IRTX,               "HAL_CLK_PERIPH_IRTX"},
    { HAL_CLK_PERIPH_KEYPAD,             "HAL_CLK_PERIPH_KEYPAD"},
    { HAL_CLK_PERIPH_GPADC,              "HAL_CLK_PERIPH_GPADC"},
    { HAL_CLK_PERIPH_LEDC,               "HAL_CLK_PERIPH_LEDC"},
    { HAL_CLK_PERIPH_PIO,                "HAL_CLK_PERIPH_PIO"},
    { HAL_CLK_PERIPH_MAD,                "HAL_CLK_PERIPH_MAD"},
    { HAL_CLK_PERIPH_LPSD,               "HAL_CLK_PERIPH_LPSD"},
    { HAL_CLK_PERIPH_DTMB,               "HAL_CLK_PERIPH_DTMB"},
    { HAL_CLK_PERIPH_I2S0,               "HAL_CLK_PERIPH_I2S0"},
    { HAL_CLK_PERIPH_I2S1,               "HAL_CLK_PERIPH_I2S1"},
    { HAL_CLK_PERIPH_I2S2,               "HAL_CLK_PERIPH_I2S2"},
    { HAL_CLK_PERIPH_SPDIF,              "HAL_CLK_PERIPH_SPDIF"},
    { HAL_CLK_PERIPH_DSD,                "HAL_CLK_PERIPH_DSD"},
    { HAL_CLK_PERIPH_DMIC,               "HAL_CLK_PERIPH_DMIC"},
    { HAL_CLK_PERIPH_AUDIOCODEC_1X,      "HAL_CLK_PERIPH_AUDIOCODEC_1X"},
    { HAL_CLK_PERIPH_AUDIOCODEC_4X,      "HAL_CLK_PERIPH_AUDIOCODEC_4X"},
    { HAL_CLK_PERIPH_WLAN,               "HAL_CLK_PERIPH_WLAN"},
    { HAL_CLK_PERIPH_USB0,               "HAL_CLK_PERIPH_USB0"},
    { HAL_CLK_PERIPH_USB1,               "HAL_CLK_PERIPH_USB1"},
    { HAL_CLK_PERIPH_USB2,               "HAL_CLK_PERIPH_USB2"},
    { HAL_CLK_PERIPH_USB3,               "HAL_CLK_PERIPH_USB3"},
    { HAL_CLK_PERIPH_USBOHCI0,           "HAL_CLK_PERIPH_USBOHCI0"},
    { HAL_CLK_PERIPH_USBOHCI0_12M,       "HAL_CLK_PERIPH_USBOHCI0_12M"},
    { HAL_CLK_PERIPH_USBOHCI1,           "HAL_CLK_PERIPH_USBOHCI1"},
    { HAL_CLK_PERIPH_USBOHCI1_12M,       "HAL_CLK_PERIPH_USBOHCI1_12M"},
    { HAL_CLK_PERIPH_USBEHCI0,           "HAL_CLK_PERIPH_USBEHCI0"},
    { HAL_CLK_PERIPH_USBEHCI1,           "HAL_CLK_PERIPH_USBEHCI1"},
    { HAL_CLK_PERIPH_USBOTG,             "HAL_CLK_PERIPH_USBOTG"},
    { HAL_CLK_PERIPH_HDMI0,              "HAL_CLK_PERIPH_HDMI0"},
    { HAL_CLK_PERIPH_HDMI1,              "HAL_CLK_PERIPH_HDMI1"},
    { HAL_CLK_PERIPH_HDMI2,              "HAL_CLK_PERIPH_HDMI2"},
    { HAL_CLK_PERIPH_HDMI3,              "HAL_CLK_PERIPH_HDMI3"},
    { HAL_CLK_PERIPH_MIPI_DSI0,          "HAL_CLK_PERIPH_MIPI_DSI0"},
    { HAL_CLK_PERIPH_MIPI_DPHY0,         "HAL_CLK_PERIPH_MIPI_DPHY0"},
    { HAL_CLK_PERIPH_MIPI_HOST0,         "HAL_CLK_PERIPH_MIPI_HOST0"},
    { HAL_CLK_PERIPH_MIPI_DSI1,          "HAL_CLK_PERIPH_MIPI_DSI1"},
    { HAL_CLK_PERIPH_MIPI_HOST1,         "HAL_CLK_PERIPH_MIPI_HOST1"},
    { HAL_CLK_PERIPH_MIPI_DSI2,          "HAL_CLK_PERIPH_MIPI_DSI2"},
    { HAL_CLK_PERIPH_MIPI_HOST2,         "HAL_CLK_PERIPH_MIPI_HOST2"},
    { HAL_CLK_PERIPH_MIPI_DSI3,          "HAL_CLK_PERIPH_MIPI_DSI3"},
    { HAL_CLK_PERIPH_MIPI_HOST3,         "HAL_CLK_PERIPH_MIPI_HOST3"},
    { HAL_CLK_PERIPH_MIPI_DSC,           "HAL_CLK_PERIPH_MIPI_DSC"},
    { HAL_CLK_PERIPH_DISPLAY_TOP,        "HAL_CLK_PERIPH_DISPLAY_TOP"},
    { HAL_CLK_PERIPH_TCON_LCD0,          "HAL_CLK_PERIPH_TCON_LCD0"},
    { HAL_CLK_PERIPH_TCON_LCD1,          "HAL_CLK_PERIPH_TCON_LCD1"},
    { HAL_CLK_PERIPH_TCON_LCD2,          "HAL_CLK_PERIPH_TCON_LCD2"},
    { HAL_CLK_PERIPH_TCON_LCD3,          "HAL_CLK_PERIPH_TCON_LCD3"},
    { HAL_CLK_PERIPH_TCON_TV0,           "HAL_CLK_PERIPH_TCON_TV0"},
    { HAL_CLK_PERIPH_TCON_TV1,           "HAL_CLK_PERIPH_TCON_TV1"},
    { HAL_CLK_PERIPH_TCON_TV2,           "HAL_CLK_PERIPH_TCON_TV2"},
    { HAL_CLK_PERIPH_TCON_TV3,           "HAL_CLK_PERIPH_TCON_TV3"},
    { HAL_CLK_PERIPH_TVE0,               "HAL_CLK_PERIPH_TVE0"},
    { HAL_CLK_PERIPH_TVE1,               "HAL_CLK_PERIPH_TVE1"},
    { HAL_CLK_PERIPH_LVDS,               "HAL_CLK_PERIPH_LVDS"},
    { HAL_CLK_PERIPH_TVD0,               "HAL_CLK_PERIPH_TVD0"},
    { HAL_CLK_PERIPH_TVD1,               "HAL_CLK_PERIPH_TVD1"},
    { HAL_CLK_PERIPH_TVD2,               "HAL_CLK_PERIPH_TVD2"},
    { HAL_CLK_PERIPH_TVD3,               "HAL_CLK_PERIPH_TVD3"},
    { HAL_CLK_PERIPH_TVD4,               "HAL_CLK_PERIPH_TVD4"},
    { HAL_CLK_PERIPH_TVD5,               "HAL_CLK_PERIPH_TVD5"},
    { HAL_CLK_PERIPH_EDP,                "HAL_CLK_PERIPH_EDP"},
    { HAL_CLK_PERIPH_CSI0,               "HAL_CLK_PERIPH_CSI0"},
    { HAL_CLK_PERIPH_CSI1,               "HAL_CLK_PERIPH_CSI1"},
    { HAL_CLK_PERIPH_MIPI_CSI,           "HAL_CLK_PERIPH_MIPI_CSI"},
    { HAL_CLK_PERIPH_SUB_LVDS,           "HAL_CLK_PERIPH_SUB_LVDS"},
    { HAL_CLK_PERIPH_HISP,               "HAL_CLK_PERIPH_HISP"},
    { HAL_CLK_PERIPH_CSI_TOP,            "HAL_CLK_PERIPH_CSI_TOP"},
    { HAL_CLK_PERIPH_CSI_MASTER0,        "HAL_CLK_PERIPH_CSI_MASTER0"},
    { HAL_CLK_PERIPH_CSI_MASTER1,        "HAL_CLK_PERIPH_CSI_MASTER1"},
    { HAL_CLK_PERIPH_ISP,                "HAL_CLK_PERIPH_ISP"},
    { HAL_CLK_PERIPH_DSPO,               "HAL_CLK_PERIPH_DSPO"},
};

#define ccmuapi_test(_func, _id, _name, _result) \
    do { \
        _result = _func(_id); \
        hal_log_info("Test(%04d): func is %s,result is %d\n", \
                     _id, #_func, _result); \
    } while(0)

int cmd_test_ccmu(int argc, char **argv)
{
    char *tname = NULL;
    hal_clk_id_t tid = HAL_CLK_UNINITIALIZED;
    unsigned int tsize = sizeof(ccmu_test_table) / sizeof(ccmu_test_table[0]);

    hal_clk_id_t id = HAL_CLK_UNINITIALIZED;
    unsigned int rate = 0;
    hal_clk_status_t status = HAL_CLK_STATUS_INVALID_PARAMETER;

    for (int i = 0; i < tsize; i++)
    {
        tid = ccmu_test_table[i].id;
        tname = ccmu_test_table[i].name;

        hal_log_info("------------------------------------\n" \
                     "CLK id: %d, \tname: %s\n", tid, tname);
        /* testing get parent API */
        ccmuapi_test(hal_clk_get_parent, tid, tname, id);

        /* testing recalc rate API */
        ccmuapi_test(hal_clk_recalc_rate, tid, tname, rate);

        /* testing get rate API */
        ccmuapi_test(hal_clk_get_rate, tid, tname, rate);

        /* testing is enabled API */
        ccmuapi_test(hal_clock_is_enabled, tid, tname, status);
    }


    /* TODO: add more APIs to test */
    hal_log_info("===================================\n");
    hal_log_info("Test Finished. total number: %d.\n", tsize);
    return 0;
}

FINSH_FUNCTION_EXPORT_CMD(cmd_test_ccmu, hal_ccmu, ccmu hal APIs tests)

