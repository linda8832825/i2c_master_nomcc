#include <xc.h>

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
  while(!PIR3bits.SSP1IF); // ���ݶǿ�
  PIR3bits.SSP1IF = 0; //�ǿ駹������|��1�A�n�γn��^�k0
}
uint8_t I2C_Master_Read(uint8_t get){
  uint8_t temp;
  I2C_Master_Wait();
  SSP1CON2bits.RCEN = 1; //����I2C�������Ҧ�
  I2C_Master_Wait();
  temp = SSP1BUF;
  I2C_Master_Wait();
  SSP1CON2bits.ACKDT = (get)?0:1;///////////////////////////////////////
  SSP1CON2bits.ACKEN = 1;//�^��ack���o�e��
  return temp;
}