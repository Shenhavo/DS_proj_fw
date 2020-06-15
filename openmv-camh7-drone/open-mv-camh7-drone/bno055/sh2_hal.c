/*
 * Copyright 2015-16 Hillcrest Laboratories, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License and 
 * any applicable agreements you may have with Hillcrest Laboratories, Inc.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * BNO080 Sensor Event decoding
 */

#include "sh2_hal.h"



// SO:
int sh2_hal_reset(bool dfuMode,
                  sh2_rxCallback_t *onRx,
                  void *cookie)
{
	return 0;
}

// Send data to SH-2.
// Call may return without blocking before transfer is complete.
int sh2_hal_tx(uint8_t *pData, uint32_t len)
{
	return HAL_I2C_Master_Transmit(&hi2c2, BNO080_I2C_ADD, pData, (uint16_t)len, BNO080_I2C_TO);
}

// Read len bytes from device into pData.
// Blocks until transfer is complete.
// This function is necessary when INTN does not generate
// read operations.  e.g. for DFU support.
//
// (In normal operation, the HAL will respond to INTN by
// automatically reading the device.  The data produced will be
// delivered to the client via the onRx callback)
int sh2_hal_rx(uint8_t *pData, uint32_t len)
{
	return HAL_I2C_Master_Receive(&hi2c2, BNO080_I2C_ADD, pData, (uint16_t)len, BNO080_I2C_TO);
}

