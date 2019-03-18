#include <rtthread.h>
#include <fpioa.h>
#include <drv_io_config.h>
#include <sysctl.h>

#define HS_GPIO(n) (FUNC_GPIOHS0 + n)

static struct io_config
{
    int io_num;
    fpioa_function_t func;
} io_config[] = 
{
#ifdef BSP_USING_LCD
    {BSP_LCD_CS_PIN, FUNC_SPI0_SS0},                 /* LCD CS PIN */
    {BSP_LCD_WR_PIN, FUNC_SPI0_SCLK},                /* LCD WR PIN */
    {BSP_LCD_DC_PIN, HS_GPIO(LCD_DC_PIN)},     /* LCD DC PIN */
#endif

#ifdef BSP_USING_CAMERA
    {BSP_CAMERA_SCCB_SDA_PIN, FUNC_SCCB_SDA},
    {BSP_CAMERA_SCCB_SCLK_PIN, FUNC_SCCB_SCLK},
    {BSP_CAMERA_CMOS_RST_PIN, FUNC_CMOS_RST},
    {BSP_CAMERA_CMOS_VSYNC_PIN, FUNC_CMOS_VSYNC},
    {BSP_CAMERA_CMOS_PWDN_PIN, FUNC_CMOS_PWDN},
    {BSP_CAMERA_CMOS_XCLK_PIN, FUNC_CMOS_XCLK},
    {BSP_CAMERA_CMOS_PCLK_PIN, FUNC_CMOS_PCLK},
    {BSP_CAMERA_CMOS_PCLK_PIN, FUNC_CMOS_HREF},
#endif

#ifdef BSP_USING_SPI1
    {BSP_SPI1_CLK_PIN, FUNC_SPI1_SCLK},
    {BSP_SPI1_D0_PIN, FUNC_SPI1_D0},
    {BSP_SPI1_D1_PIN, FUNC_SPI1_D1},
#ifdef BSP_USING_SPI1_AS_QSPI
    {BSP_SPI1_D2_PIN, FUNC_SPI1_D2},
    {BSP_SPI1_D3_PIN, FUNC_SPI1_D3},
#endif
#ifdef BSP_SPI1_USING_SS0
    {BSP_SPI1_SS0_PIN, HS_GPIO(SPI1_CS0_PIN)},
#endif
#ifdef BSP_SPI1_USING_SS1
    {BSP_SPI1_SS1_PIN, HS_GPIO(SPI1_CS1_PIN)},
#endif
#ifdef BSP_SPI1_USING_SS2
    {BSP_SPI1_SS2_PIN, HS_GPIO(SPI1_CS2_PIN)},
#endif
#ifdef BSP_SPI1_USING_SS3
    {BSP_SPI1_SS3_PIN, HS_GPIO(SPI1_CS3_PIN)},
#endif
#endif

};


int io_config_init(void)
{
    int count = sizeof(io_config) / sizeof(io_config[0]);
    int i;

    sysctl_set_power_mode(SYSCTL_POWER_BANK0, SYSCTL_POWER_V18);
    sysctl_set_power_mode(SYSCTL_POWER_BANK1, SYSCTL_POWER_V18);
    sysctl_set_power_mode(SYSCTL_POWER_BANK2, SYSCTL_POWER_V18);
    
    for(i = 0; i < count; i++)
    {
        fpioa_set_function(io_config[i].io_num, io_config[i].func);
    }

#if defined(BSP_USING_CAMERA) || defined(BSP_USING_LCD)
    sysctl_set_spi0_dvp_data(1);
#endif

}
INIT_BOARD_EXPORT(io_config_init);
