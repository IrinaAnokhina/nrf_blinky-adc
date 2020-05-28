#include "sdk_common.h"
#include "ble_srv_common.h"
#include <string.h>
#include "nrf_gpio.h"
#include "boards.h"
#include "nrf_log.h"
#include "ble_adc.h"

uint32_t ble_adc_init(ble_adc_t * p_adc, const ble_adc_init_t * p_adc_init)
{
    if (p_adc == NULL || p_adc_init == NULL)
    {
        return NRF_ERROR_NULL;
    }

    uint32_t   err_code;
    ble_uuid_t ble_uuid;

    // Initialize service structure
p_adc->conn_handle               = BLE_CONN_HANDLE_INVALID;

// Add ADC Service UUID
ble_uuid128_t base_uuid = {ADC_SERVICE_UUID_BASE};
err_code =  sd_ble_uuid_vs_add(&base_uuid, &p_adc->uuid_type);
VERIFY_SUCCESS(err_code);

ble_uuid.type = p_adc->uuid_type;
ble_uuid.uuid = ADC_SERVICE_UUID;

// Add the ADC Service
err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &ble_uuid, &p_adc->service_handle);
if (err_code != NRF_SUCCESS)
{
    return err_code;
}
//return err_code;
}