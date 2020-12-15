#include <xc.h>
#include "i2c_master.h"

void I2C_Master_Wait(){
    while ((SSP1STAT & 0x04) || (SSP1CON2 & 0x1F));
}
void I2C_Master_Start(){
    I2C_Master_Wait();
    SSP1CON2bits.SEN = 1; //start
}
void I2C_Master_RepeatedStart(){
    I2C_Master_Wait();
    SSP1CON2bits.RSEN = 1; //restart
}
void I2C_Master_Stop(){
    I2C_Master_Wait();
    SSP1CON2bits.PEN = 1; //stop
}
void I2C_Master_Write(uint8_t data){
    I2C_Master_Wait();
    SSP1BUF = data;
    while(!PIR3bits.SSP1IF); // 等待傳輸
    PIR3bits.SSP1IF = 0; //傳輸完成之後會為1，要用軟體回歸0
}
uint8_t I2C_Master_Read(uint8_t get){
    uint8_t temp;
    I2C_Master_Wait();
    SSP1CON2bits.RCEN = 1; //智能I2C的接收模式
    I2C_Master_Wait();
    temp = SSP1BUF;
    I2C_Master_Wait();
    SSP1CON2bits.ACKDT = (get)?0:1;//get=1時，ack data=NACK(0)   //get=0時，ack data=ACK(1)
    SSP1CON2bits.ACKEN = 1;//回傳ack data給發送端
    return temp;
}