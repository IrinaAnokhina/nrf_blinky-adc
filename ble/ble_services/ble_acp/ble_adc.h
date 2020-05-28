#ifndef BLE_ADC_H_
#define BLE_ADC_H_

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"
#include "nrf_sdh_ble.h"

/**@brief   Macro for defining a ble_cus instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
#define BLE_ADC_DEF(_name)                                                                          \
static ble_adc_t _name;     

#define ADC_UUID_BASE        {0xEB, 0x2B, 0x32, 0x5E, 0x8C, 0xC0, 0x3C, 0xB0, \
                              0x0A, 0x4C, 0xCF, 0x95, 0x1B, 0x92, 0x3E, 0x04}
#define ADC_UUID_SERVICE     0x1400
#define ADC_UUID_CHAR        0x1401

/**@brief ADC Service init structure. This contains all options and data needed for
 *        initialization of the service.*/
typedef struct
{
    uint8_t                       initial_adc_value;           /**< Initial adc value */
    ble_srv_cccd_security_mode_t  adc_value_char_attr_md;     /**< Initial security level for Custom characteristics attribute */
} ble_adc_init_t;

/**@brief Custom Service structure. This contains various status information for the service. */
struct ble_adc_s
{
    uint16_t                      service_handle;                 /**< Handle of Custom Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t      adc_value_handles;           /**< Handles related to the Custom Value characteristic. */
    uint16_t                      conn_handle;                    /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection). */
    uint8_t                       uuid_type; 
};

// Forward declaration of the ble_adc_t type.
typedef struct ble_adc_s ble_adc_t;

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_adc       Custom Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_adc_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_adc_init(ble_adc_t * p_adc, const ble_adc_init_t * p_adc_init);

