/*
 * Hardware_Interface.c
 *
 *  Created on: Sep 7, 2024
 *      Author: M.W Laptop
 */

#include "Hardware_Interface.h"

extern I2C_HandleTypeDef hi2c1;

/// @fn uint8_t Read_Hw_Data(uint8_t, uint8_t*, uint8_t)
/// @brief
/// A hardware interface function that uses I2C com protocol to receive data
/// @param sla
/// @param Data
/// @param Length
/// @return 1 if acknowledgment received
uint8_t Read_Hw_Data(uint8_t sla, uint8_t *Data, uint8_t Length) {
	HAL_StatusTypeDef ok = HAL_I2C_Master_Receive(&hi2c1, sla << 1, Data,
			Length, 100);
	return (ok == HAL_OK) ? 1 : 0;
}

/// @fn uint8_t Write_HW_config(uint8_t, uint8_t*, uint8_t)
/// @brief
/// A hardware interface function that uses I2C com protocol to send data
/// @param sla
/// @param Data
/// @param Length
/// @return  1 if acknowledgment received
uint8_t Write_HW_config(uint8_t sla, uint8_t *Data, uint8_t Length) {
	HAL_StatusTypeDef ok = HAL_I2C_Master_Transmit(&hi2c1, sla << 1, Data,
			Length, 100);
	return (ok == HAL_OK) ? 1 : 0;
}
