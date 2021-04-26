/*
    Name:       ByteTypes_example.ino
    Created:	03/06/2019 13:58:02
	Modified:	30/07/2020
    Author:     Jan Wielgus
	
	New data types used in the communication
	Divide basic data types to uint8_ts array
*/

#include <byteType.h>
#include <bitByte.h>


void setup()
{
	Serial.begin(9600);
	Serial.println("Program has started!");	
}


void loop()
{
	uint16Byte zmienna;
	zmienna = 15;
	Serial.print("zmienna: ");
	Serial.println(zmienna);
	
	uint16Byte testowa;
	testowa.byteArray()[0] = zmienna.byteArray()[0];
	testowa.byteArray()[1] = zmienna.byteArray()[1];
	// teraz testowa powinna miec taka sama wartosc jak zmienna
	Serial.print("testowa: ");
	Serial.println(testowa);
	
	
	// bitByte compilation test
	bitByte testBools;
	testBools.bitArray()[0] = false;
	testBools.bitArray()[1] = true;
	uint8_t* testPtr = testBools.byteArray();
	
	
	delay(2000);
	
}
