#include <xc.h>
#include "pic16f18854.h"
#include "init.h"
#include "i2c_master.h"

#define SLAVE_ADD 0x50

void main(void) {
    init();//slave id
    I2C_Master_Start();         //Start condition
    I2C_Master_Write((SLAVE_ADD << 1)|0);     //7 bit address + Write(0)
    I2C_Master_Write(0xAA); //¶Ç0b0101 0101
    I2C_Master_Stop();          //Stop condition
    while(1);
}




