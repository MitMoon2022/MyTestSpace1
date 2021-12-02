/*------------------------------------------------------------------------------
This is example to calculate MODBUS CRC.
Reference from http://www.nongnu.org/avr-libc/user-manual/group__util__crc.html
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

#include <iostream>
#include <bitset>

/* Function to calculate MODBUS CRC. */
//it is use in ASCII code. however, i want to use Hex.
uint16_t crc16_update(uint16_t crc, uint8_t a) {
	int i;

	crc ^= (uint16_t)a;
	for (i = 0; i < 8; ++i) {
		if (crc & 1)
			crc = (crc >> 1) ^ 0xA001;
		else
			crc = (crc >> 1);
	}

	return crc;
}

//--------- Another Code------------------------------------------------
unsigned short int crc16(const unsigned char* data_p, unsigned char length){
    unsigned char x;
    unsigned short int crc = 0xFFFF;

    while (length--){
        x = crc >> 8 ^ *data_p++;
        x ^= x>>4;
        crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
    }
    return crc;
}
//--------- Another Code 2------------------------------------------------
unsigned int crc_fn(unsigned char *dpacket,unsigned int len) // CRC Function(Error calcualtion)
{
 unsigned int crc = 0xffff,poly = 0xa001;
 unsigned int i; 
 unsigned int j;

 for(i=0;i<len;i++)
 {
    crc^= dpacket[i];
    for(j=0;j<8;j++)
    {
     if(crc & 0x01)
     {
      crc >>= 1;
      crc ^= poly;
     }
     else
    crc >>= 1;
    }
 }
 return (crc); 
} 


using namespace std;

int main(void) {

	// uint16_t crc;
	// int i;
	// uint8_t str[] = "123456789"; //this is using ASCII

	// /* MODBUS CRC initial value is 0xFFFF. */
	// crc = 0xFFFF;
	// for(i = 0; i < 9; i++)
	// 	crc = crc16_update(crc, str[i]);
	// printf("%X\n", (int)crc);
	
	// crc = 0xFFFF;
	// for(i = 0; i < 9; i++)
	// 	crc = crc16_update(crc, str[8-i]);
	// printf("%X\n", (int)crc);

    //---Test another function CRC-16 Modbus
    unsigned char str_H [] = {0x00, 0x01, 0x06, 0x05, 0x60};
    //The correct resut should be 0x85C6.


    //Testing 1st Function
    unsigned short int Rcrc16 = crc16(str_H, 5);
    printf("In Hex: %X\n", Rcrc16);

    cout<<"-----------------------------"<<endl;
    //Test 2nd Function and it works!
    unsigned int R2crc16 = crc_fn(str_H,5);

    printf("In Hex: %X\n", R2crc16);

    cout << "Rcrc16 in hex = " << hex <<std::uppercase<<R2crc16<<endl;

    cout<<"--------Another test code using 2nd Function----------"<<endl;

    unsigned char str2_H [] = {0x00, 0x30, 0x00, 0x7d, 0x00,
                                 0x00, 0x04, 0xb0, 0x01, 0x2c,
                                  0x01, 0x5e, 0x00, 0x28, 0x00, 0x14, 0x00, 0x00};
    //The correct resut should be 0xC8BC.

    unsigned int R3crc16 = crc_fn(str2_H,18);

    printf("In Hex: %X\n", R3crc16);


}