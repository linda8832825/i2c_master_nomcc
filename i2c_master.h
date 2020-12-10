#ifndef i2c_master
#define	i2c_master

#include <xc.h> 
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(uint8_t data);
uint8_t I2C_Master_Read(uint8_t get);

#endif	/* i2c_master */

