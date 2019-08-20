/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: LPC845
package_id: LPC845M301JBD48
mcu_data: ksdk2_0
processor_version: 6.0.1
pin_labels:
- {pin_num: '14', pin_signal: PIO1_1/CAPT_X2, label: LED_BLUE, identifier: LEDpin2}
- {pin_num: '11', pin_signal: PIO1_0/CAPT_X1, label: LED_GREEN, identifier: LEDpin1}
- {pin_num: '16', pin_signal: PIO1_2/CAPT_X3, label: LED_RED, identifier: LEDpin3}
- {pin_num: '6', pin_signal: PIO0_4/ADC_11, label: BTN_K3, identifier: BTNpin3}
- {pin_num: '4', pin_signal: PIO0_12, label: BTN_K1, identifier: BTNpin1}
- {pin_num: '20', pin_signal: PIO0_24, label: USART0_RX}
- {pin_num: '19', pin_signal: PIO0_25, label: USART0_TX}
- {pin_num: '15', pin_signal: PIO0_16, label: MAG_HH, identifier: MAG_HH}
- {pin_num: '48', pin_signal: PIO0_17/ADC_9/DACOUT_0, label: MAG_MM, identifier: MAG_MM}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_swm.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '11', peripheral: GPIO, signal: 'PIO1, 0', pin_signal: PIO1_0/CAPT_X1, direction: OUTPUT, gpio_init_state: 'false', mode: inactive}
  - {pin_num: '14', peripheral: GPIO, signal: 'PIO1, 1', pin_signal: PIO1_1/CAPT_X2, direction: OUTPUT, mode: inactive}
  - {pin_num: '16', peripheral: GPIO, signal: 'PIO1, 2', pin_signal: PIO1_2/CAPT_X3, direction: OUTPUT, mode: inactive}
  - {pin_num: '6', peripheral: GPIO, signal: 'PIO0, 4', pin_signal: PIO0_4/ADC_11, direction: INPUT, mode: inactive}
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, direction: INPUT, mode: inactive}
  - {pin_num: '20', peripheral: USART0, signal: RXD, pin_signal: PIO0_24}
  - {pin_num: '19', peripheral: USART0, signal: TXD, pin_signal: PIO0_25}
  - {pin_num: '15', peripheral: GPIO, signal: 'PIO0, 16', pin_signal: PIO0_16, direction: INPUT}
  - {pin_num: '48', peripheral: GPIO, signal: 'PIO0, 17', pin_signal: PIO0_17/ADC_9/DACOUT_0, direction: INPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
    /* Enables clock for IOCON.: enable */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: enable */
    CLOCK_EnableClock(kCLOCK_Swm);
    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    GPIO->CLR[1] = ((GPIO->CLR[1] &
                     /* Mask bits to zero which are setting */
                     (~(GPIO_CLR_CLRP_MASK)))

                    /* Clear output bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on the specific
                     * device and package. 0 = No operation. 1 = Clear output bit.: 0x01u */
                    | GPIO_CLR_CLRP(0x01u));
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    GPIO->DIR[0] = ((GPIO->DIR[0] &
                     /* Mask bits to zero which are setting */
                     (~(GPIO_DIR_DIRP_MASK)))

                    /* Selects pin direction for pin PIOm_n (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins
                     * depends on the specific device and package. 0 = input. 1 = output.: 0x00u */
                    | GPIO_DIR_DIRP(0x00u));
    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    GPIO->DIR[1] = ((GPIO->DIR[1] &
                     /* Mask bits to zero which are setting */
                     (~(GPIO_DIR_DIRP_MASK)))

                    /* Selects pin direction for pin PIOm_n (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins
                     * depends on the specific device and package. 0 = input. 1 = output.: 0x07u */
                    | GPIO_DIR_DIRP(0x07u));

    IOCON->PIO[2] = ((IOCON->PIO[2] &
                      /* Mask bits to zero which are setting */
                      (~(IOCON_PIO_MODE_MASK)))

                     /* Selects function mode (on-chip pull-up/pull-down resistor control).: Inactive. Inactive (no
                      * pull-down/pull-up resistor enabled). */
                     | IOCON_PIO_MODE(PIO0_12_MODE_INACTIVE));

    IOCON->PIO[4] = ((IOCON->PIO[4] &
                      /* Mask bits to zero which are setting */
                      (~(IOCON_PIO_MODE_MASK)))

                     /* Selects function mode (on-chip pull-up/pull-down resistor control).: Inactive. Inactive (no
                      * pull-down/pull-up resistor enabled). */
                     | IOCON_PIO_MODE(PIO0_4_MODE_INACTIVE));

    IOCON->PIO[36] = ((IOCON->PIO[36] &
                       /* Mask bits to zero which are setting */
                       (~(IOCON_PIO_MODE_MASK)))

                      /* Selects function mode (on-chip pull-up/pull-down resistor control).: Inactive. Inactive (no
                       * pull-down/pull-up resistor enabled). */
                      | IOCON_PIO_MODE(PIO1_0_MODE_INACTIVE));

    IOCON->PIO[37] = ((IOCON->PIO[37] &
                       /* Mask bits to zero which are setting */
                       (~(IOCON_PIO_MODE_MASK)))

                      /* Selects function mode (on-chip pull-up/pull-down resistor control).: Inactive. Inactive (no
                       * pull-down/pull-up resistor enabled). */
                      | IOCON_PIO_MODE(PIO1_1_MODE_INACTIVE));

    IOCON->PIO[38] = ((IOCON->PIO[38] &
                       /* Mask bits to zero which are setting */
                       (~(IOCON_PIO_MODE_MASK)))

                      /* Selects function mode (on-chip pull-up/pull-down resistor control).: Inactive. Inactive (no
                       * pull-down/pull-up resistor enabled). */
                      | IOCON_PIO_MODE(PIO1_2_MODE_INACTIVE));

    /* USART0_TXD connect to P0_25 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_TXD, kSWM_PortPin_P0_25);

    /* USART0_RXD connect to P0_24 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_RXD, kSWM_PortPin_P0_24);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
