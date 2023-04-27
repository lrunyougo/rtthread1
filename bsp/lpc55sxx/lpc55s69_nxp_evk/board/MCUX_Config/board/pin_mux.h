/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Enables digital function */
#define IOCON_PIO_DIGITAL_EN 0x0100u
/*!
 * @brief Selects pin function 1 */
#define IOCON_PIO_FUNC1 0x01u
/*!
 * @brief Input function is not inverted */
#define IOCON_PIO_INV_DI 0x00u
/*!
 * @brief No addition pin function */
#define IOCON_PIO_MODE_INACT 0x00u
/*!
 * @brief Open drain is disabled */
#define IOCON_PIO_OPENDRAIN_DI 0x00u
/*!
 * @brief Standard mode, output slew rate control is enabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_13_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 5. */
#define PIO0_13_FUNC_ALT5 0x05u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_14_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 6. */
#define PIO0_14_FUNC_ALT6 0x06u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_17_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_17_FUNC_ALT2 0x02u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_18_FUNC_ALT0 0x00u
/*!
 * @brief Analog switch input control. Usable only if DIGIMODE = 0b0: Analog switch is closed. */
#define PIO0_23_ASW_ENABLE 0x01u
/*!
 * @brief Select Digital mode.: Analog mode, digital input is disabled. */
#define PIO0_23_DIGIMODE_ANALOG 0x00u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_23_FUNC_ALT0 0x00u
/*!
 * @brief
 * Selects function mode (on-chip pull-up/pull-down resistor control).
 * : Inactive.
 * Inactive (no pull-down/pull-up resistor enabled).
 */

#define PIO0_23_MODE_INACTIVE 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_15_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_15_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_18_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_24_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_24_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_25_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_25_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_26_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_27_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO0_27_FUNC_ALT1 0x01u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_31_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_31_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_7_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_7_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_8_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_8_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO0_9_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO0_9_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_0_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 2. */
#define PIO1_0_FUNC_ALT2 0x02u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_8_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_8_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_9_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_9_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_10_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_10_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_11_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_11_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_20_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 5. */
#define PIO1_20_FUNC_ALT5 0x05u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_21_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 5. */
#define PIO1_21_FUNC_ALT5 0x05u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_24_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO1_24_FUNC_ALT1 0x01u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_2_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 6. */
#define PIO1_2_FUNC_ALT6 0x06u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_3_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 6. */
#define PIO1_3_FUNC_ALT6 0x06u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_4_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_4_FUNC_ALT3 0x03u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_5_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_5_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_6_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO1_6_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Digital mode, digital input is enabled. */
#define PIO1_7_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_7_FUNC_ALT3 0x03u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO1_10_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 3. */
#define PIO1_10_FUNC_ALT3 0x03u

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M33 (Core #0) */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
