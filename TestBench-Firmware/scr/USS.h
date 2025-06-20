#ifndef __USS_H__
#define __USS_H__

#include "ussSwLib.h"
#include "USS_Config/USS_userConfig.h"

/*******************************************************************************
 * Enables Signal gain calibration. It is recommmended to enable this feature
 * once USS_START_CAPTURE_SEC has been configured and UPS and DNS captures have
 * a valid signal
 ******************************************************************************/
#define APPLICATION_ENABLE_SIGNAL_GAIN_CALIBRATION               false
/*******************************************************************************
 * For Single tone application using USS_Alg_AbsToF_Calculation_Option_lobeWide
 * Algorithm it  might be required to scale down binary it the algorithm when
 * the capturing a valid signal but USS_runAlgorithms is returning the following
 * error message
 * USS_message_code_algorithm_error_no_signal_detected_ups_dns_channel
 * Please refer to the library User's Guide for further detail
 ******************************************************************************/
#define APPLICATION_ENABLE_BINARY_PATTERN_SIZE_SCALING      false
#if (APPLICATION_ENABLE_BINARY_PATTERN_SIZE_SCALING == true)
#define APPLICATION_BINARY_PATTERN_SCALE_FACTOR             4
#endif

/*******************************************************************************
 *  Channel Swap configuration
 ******************************************************************************/
#define APPLICATION_ENABLE_CHANNEL_SWAP                     false
#if (APPLICATION_ENABLE_CHANNEL_SWAP == true)
#define APPLICATION_CHANNEL_SWAP_INTERVAL                   1
#endif

/*******************************************************************************
 * Abstof and DToF Offset calculation configuration
 ******************************************************************************/
#define APPLICATION_ENABLE_ABSTOF_DTOF_OFFSET_CALIBRATION               false
#if (APPLICATION_ENABLE_ABSTOF_DTOF_OFFSET_CALIBRATION == true)
#define APPLICATION_ABSTOF_DTOF_OFFSET_UPDATE_INTERVAL      255
#define APPLICATION_ABSTOF_DTOF_OFFSET_LPM_CAPTURE          true
#define APPLICATION_ABSTOF_DTOF_OFFSET_CALC_UPS_ABSTOF      true
#define APPLICATION_ABSTOF_DTOF_OFFSET_CALC_DNS_ABSTOF      false
#define APPLICATION_ABSTOF_DTOF_OFFSET_CALC_DTOF            false
#define APPLICATION_ABSTOF_REFERENCE                        (32.00e-6f)
#endif

/*******************************************************************************
 * Enables UART debug support to output USS algorithm results. To disable this
 * feature set to 0.
 ******************************************************************************/
#define APPLICATION_ENABLE_UART_DEBUG                       1

/*******************************************************************************
 * UART Delimiters for USS results
 ******************************************************************************/
#define APPLICATION_UART_ABSTOF_UPS_DELIM                   '$'
#define APPLICATION_UART_ABSTOF_DNS_DELIM                   '#'
#define APPLICATION_UART_DTOF_DELIM                         '%'
#define APPLICATION_UART_VFR_DELIM                          '!'

//#include "main.h"

USS_Algorithms_Results algResults;
USS_calibration_hspll_results testResults;


#if APPLICATION_ENABLE_UART_DEBUG
 void uartTxByte(char string);
 void uartTxHexByte(uint8_t Data);
 uint8_t nibbleToHex(uint8_t nibble);
 void uartTxUSSResult(float *data, uint8_t end);
#endif


 void Uss_init();
 void checkCode(USS_message_code code, USS_message_code expectedCode);
 void handlePllUnlockEvent(void);
 void disableApplicationInterrupts(void);
 void enableApplicationInterrupts(void);

 USS_Algorithms_Results Uss_measure();
 void Uss_waitInLPM();

 void ReadAndCalculateFlow(void);

 void LCD_TEST(void);

#endif /*__USS_H__*/
