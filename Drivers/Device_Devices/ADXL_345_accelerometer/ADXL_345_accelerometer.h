/*
 * ADXL_345_accelerometer.h
 *
 *  Created on: Sep 3, 2024
 *      Author: M.W Laptop
 */

#ifndef DEVICE_DEVICES_ADXL_345_ACCELEROMETER_H_
#define DEVICE_DEVICES_ADXL_345_ACCELEROMETER_H_

#include <stdint.h>

// I2C address for ADXL345
#define ADXL345_SLA 0x53

// addresses of data registers
#define ADXL345_REG_DEVID 0x00
#define ADXL345_REG_BW_RATE 0x2C
#define ADXL345_REG_POWER_CTL 0x2D
#define ADXL345_REG_DATA_FORMAT 0x31
#define ADXL345_REG_DATAX0 0x32

typedef struct {
	uint8_t I2C_Buffer[6];	//data buffer
	uint8_t Range :2;		//ranges of adxl345 (2g,4g,8g,16g)
	uint8_t Data_Rate;		//data rate (from 0.1HZ to 3200HZ)
	uint8_t Resolution :1;	//res bit for full resolution
	float X_Axis;			//hold the x-axis acceleration reading
	float Y_Axis;			//hold the y-axis acceleration reading
	float Z_Axis;			//hold the z-axis acceleration reading
	struct HW_Interface {
		uint8_t (*Read_Hw_Data)(uint8_t sla, uint8_t *Data, uint8_t Length);//Read function pointer for agnostic HW_IN
		uint8_t (*Write_HW_config)(uint8_t sla, uint8_t *Data, uint8_t Length);	//Write function pointer for agnostic HW_IN
	} AG_HW_Interface_t;
	uint8_t Offsets[3];		//holds the value of offsets
	uint8_t Power_Mode :1;	//power mode bit
	uint8_t Link :1;		//link bit for linking activity with inactivity
	uint8_t Auto_Sleep :1;	//auto sleep bit to sleep if inactivity detected
	uint8_t Measure :1;		//measure bit to apply measuring mode
	uint8_t Sleep :1;		//sleep bit to switch the device into sleep mode
	uint8_t Wakeup :2;//wakeup bit to switch the adxl345 on if activity detected
} adxl345_t;

//enum for range setting
typedef enum {
	range_setting_2g = 00,
	range_setting_4g = 01,
	range_setting_8g = 10,
	range_setting_16g = 11,
} adxl345_range_t;

//enum for data rate setting
typedef enum {
	date_rate_0_1HZ = 0000, //0.10Hz
	data_rate_0_2HZ,		//0.20Hz
	data_rate_0_39HZ,		//0.39Hz
	data_rate_0_78HZ,		//0.78Hz
	data_rate_1_56HZ,		//1.56Hz
	data_rate_3_13HZ,		//3.13Hz
	data_rate_6_25HZ,		//6.25Hz
	data_rate_12_5HZ,		//12.5Hz
	data_rate_25HZ,			//25Hz
	data_rate_50HZ,			//50Hz
	data_rate_100HZ,		//100Hz
	data_rate_200HZ,		//200Hz
	data_rate_400HZ,		//400Hz
	data_rate_800HZ,		//800Hz
	data_rate_1600HZ,		//1600Hz
	data_rate_3200HZ,		//3200Hz
} adxl345_dataratecode_t;

//enum for power m0des
typedef enum {
	normal_power_mode, saving_power_mode
} adxl345_powermode_t;

//emum for the returns of functions
typedef enum {
	ADXL345_success, ADXL345_failed
} adxl345_stat_t;

//functions
adxl345_stat_t ADXL345_Init(adxl345_t *accelerometer);
adxl345_stat_t ADXL345_WriteConfig(adxl345_t *accelerometer);
adxl345_stat_t ADXL345_ReadData(adxl345_t *accelerometer);

#endif /* DEVICE_DEVICES_ADXL_345_ACCELEROMETER_H_ */
