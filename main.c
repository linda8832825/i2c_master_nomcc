#include <xc.h>
#include "pic16f18854.h"
#include "init.h"
#include "i2c_master.h"

#define SLAVE_ADD 0x3A
uint8_t slave_feedback;
void main(void) {
    init();
    I2C_Master_Start();        
    I2C_Master_Write((SLAVE_ADD << 1)|0); //7 bit address + Write(0)
    I2C_Master_Write(0xDB); //¶Ç0b0101 0101
    I2C_Master_Stop(); 
    
    I2C_Master_Start(); 
    I2C_Master_Write((SLAVE_ADD << 1)|1); //7 bit address + Read(1)
    slave_feedback=I2C_Master_Read(0);
    I2C_Master_Stop();        
    if(slave_feedback==0xDB){
        RA1=1;
    }
    while(1){
    ;
    }
}




