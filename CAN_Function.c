#include "can.h"
unsigned int MSG[10]; 
void can_config(void)
{
VPBDIV=2; //Config Pclk=30Mhz
/*Config P0.23,P0.24,P0.25 as RD2,TD2,RD1*/
PINSEL1|=(1<<14)|(1<<16)|(1<<18);
PINSEL1&=~((1<<15)|(1<<17)|(1<<19));

C2MOD=(1<<0); //Disable CAN 
/*TSEG1=1100[]*/
C2BTR=(1<<20)|(1<<19)|(1<<18)|(29<<0);
C2MOD=0;

C1MOD=(1<<0);

C1BTR=(1<<20)|(1<<19)|(1<<18)|(29<<0);
C1MOD=0;
}

void can_tx(unsigned int d) //CAN2 as Transmitter
{
while(!(C2GSR&(1<<2)));  //Check Tx buufer is empty or not
C2TID1=0x27;            //LoaD Message TD to CAN TX Id red
C2TFI1=(1<<19);          //load DLC=1000[19 18 17 16], RTR=0[30],IDE=0[31] 
C2TDA1=d;
C2TDB1=d;               //LOAD the data on CAN data REgister
C2CMR=(1<<0)|(1<<5);     // Enable queued Tx, and select Tx Buffer 1
while(!(C2GSR&(1<<3)));// Check data transmiteed successfully or not
}

unsigned int can_rx(void)
{
  while(C1GSR&(1<<0));                    //monitor receiver buffer is empty or not 
  MSG[0]=C1RID;                           //load the msg ID to MSG[0]
  MSG[1]=C1RDA;                           //load the received data to MSG[1]
  C1CMR=(1<<2);                           //release receiver buffer

  return MSG[1];              //Release RBR for next reception
}