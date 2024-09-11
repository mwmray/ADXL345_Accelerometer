/*
 * ADXL_345_accelerometer.c
 *
 *  Created on: Sep 3, 2024
 *      Author: M.W Laptop
 */

#include "ADXL_345_accelerometer.h"

typedef enum {
	OFSX_X = 0x1e, OFSX_Y = 0x1f, OFSX_Z = 0x20,
} ADXl345_Reg;

/// @fn adxl345_stat_t ADXL345_Init(adxl345_t*)
/// @brief
/// Initializing the ADXL345 accelerometer
/// @param accelerometer ptr to the accelerometer handle
/// @return ADXL345_success if successful

adxl345_stat_t ADXL345_Init(adxl345_t *accelerometer) {
	//Set the device to measurement mode
	accelerometer->I2C_Buffer[0] = ADXL345_REG_POWER_CTL;
	accelerometer->I2C_Buffer[1] = (accelerometer->Link << 5)
			| (accelerometer->Auto_Sleep << 4) | (accelerometer->Measure << 3)
			| (accelerometer->Sleep << 2) | (accelerometer->Wakeup);

	//apply data
	return (accelerometer->AG_HW_Interface_t.Write_HW_config(ADXL345_SLA,
			accelerometer->I2C_Buffer, 2) != 1) ?
			ADXL345_failed : ADXL345_success;
}

/// @fn uint8_t ADXL345_WriteConfig(adxl345_t*)
/// @brief
/// Applies the configuration to the device
/// @param accelerometer ptr to the accelerometer handle
/// @return ADXL345_success if successful
adxl345_stat_t ADXL345_WriteConfig(adxl345_t *accelerometer) {
	//write the accelerometer offsets
	accelerometer->I2C_Buffer[0] = OFSX_X;

	//load the offset values into the I2C buffer
	for (uint8_t x = 0; x < 3; x++) {
		accelerometer->I2C_Buffer[1 + x] = accelerometer->Offsets[x];
	}
	//apply data
	if (accelerometer->AG_HW_Interface_t.Write_HW_config(ADXL345_SLA,
			accelerometer->I2C_Buffer, 4) != 1) {
		return ADXL345_failed;
	}

	//assigning the rate and power mode to BW_RATE reg
	accelerometer->I2C_Buffer[0] = ADXL345_REG_BW_RATE;
	accelerometer->I2C_Buffer[1] = (accelerometer->Power_Mode << 4)
			| (accelerometer->Data_Rate);
	//apply data
	if (accelerometer->AG_HW_Interface_t.Write_HW_config(ADXL345_SLA,
			accelerometer->I2C_Buffer, 2) != 1)
		return ADXL345_failed;

	//assigning the range and resolution mode to DATA_FORMAT reg
	accelerometer->I2C_Buffer[0] = ADXL345_REG_DATA_FORMAT;
	accelerometer->I2C_Buffer[1] = (accelerometer->Resolution << 3)
			| (accelerometer->Range);

	//apply data
	return (accelerometer->AG_HW_Interface_t.Write_HW_config(ADXL345_SLA,
			accelerometer->I2C_Buffer, 2) != 1) ?
			ADXL345_failed : ADXL345_success;
}

/// @fn adxl345_stat_t ADXL345_ReadData(adxl345_t*, int16_t*, int16_t*, int16_t*)
/// @brief
/// Read the acceleration values in each axis
/// @param accelerometer
/// @return ADXL345_success if successful
adxl345_stat_t ADXL345_ReadData(adxl345_t *accelerometer) {
	adxl345_stat_t t;
	// Read 6 bytes from the data registers (0x32 to 0x37)
	accelerometer->I2C_Buffer[0] = ADXL345_REG_DATAX0;

	//apply data
	t = accelerometer->AG_HW_Interface_t.Write_HW_config(ADXL345_SLA,
			accelerometer->I2C_Buffer, 1) != 1 ?
			ADXL345_failed : ADXL345_success;
	if (t != ADXL345_success) {
		return t;
	}
	//read data of axes
	accelerometer->AG_HW_Interface_t.Read_Hw_Data(ADXL345_SLA,
			accelerometer->I2C_Buffer, 6);
	// Convert the data to 16-bit integers (signed)
	accelerometer->X_Axis = ((int16_t) accelerometer->I2C_Buffer[1] << 8)
			| accelerometer->I2C_Buffer[0];
	accelerometer->Y_Axis = ((int16_t) accelerometer->I2C_Buffer[3] << 8)
			| accelerometer->I2C_Buffer[2];
	accelerometer->Z_Axis = ((int16_t) accelerometer->I2C_Buffer[5] << 8)
			| accelerometer->I2C_Buffer[4];

	return t;
}

