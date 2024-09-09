
# _ADXL345 Accelerometer_

This project contains an I2C-based driver for interfacing the ADXL345 3-axis accelerometer. 
It allows for configuration of the accelerometer and reading acceleration data along the X, Y, and Z axes.
It utilizes Dependency Injection (DI) to decouple the hardware interfaces from the core logic, making the code more modular, maintainable, and testable.
## Features

- Reading acceleration data in 16g range.
- Configurable power mode and data rate.
- Supports full-resolution measurement mode.

## Requirements

- STM32 Microcontroller (with I2C support)
- ADXL345 Accelerometer
- HD44780 LCD (optional, for displaying data)

## Hardware Setup
# 1-ADXL345 Pin Connections:

- VCC to 3.3V or 5V (depending on the module)
- GND to GND
- SDA to STM32's I2C data line (SDA)
- SCL to STM32's I2C clock line (SCL)
- SD0 to GND fot slave address 0x53 or SD0 to VCC fot slave address 0x1D

# 2-LCD Pin Connections:

- LCD's data pins and control lines to GPIO pins of the STM32.

# 3-I2C Configuration:

- The I2C1 peripheral on the STM32 is used for communication with the ADXL345. Ensure you configure the correct I2C pins in your STM32CubeMX project.
Software Installation

# Functions
`ADXL345_Init(adxl345_t *config)`
Initializes the ADXL345 sensor with the provided configuration using the injected hardware interface functions.

- Parameters:
config: Pointer to the ADXL345 configuration structure.
- Returns: ADXL345_success on success, ADXL345_failure on failure.

`ADXL345_ReadData(adxl345_t *config)`
Reads acceleration data from the sensor using the injected read function.

- Parameters:
config: Pointer to the ADXL345 structure where data will be stored.
- Returns: ADXL345_success on success, ADXL345_failure on failure.

`ADXL345_WriteConfig(adxl345_t *config)`
Writes configuration data to the sensor using the injected write function (optional function for updating sensor settings).

# _ADXL345 Registers_
- 0x2D: POWER_CTL – Controls power modes.
- 0x31: DATA_FORMAT – Configures data format and range.
- 0x32-0x37: X, Y, and Z axis data registers.

## Plugins

| Plugin | README |
| ------ | ------ |
| Data Sheet | https://www.analog.com/media/en/technical-documentation/data-sheets/adxl345.pdf |
| GitHub | https://github.com/mwmray/ADXL345_Accelerometer.git |
