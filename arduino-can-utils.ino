#include <SPI.h>
#include "mcp-header.h"
#include "can-header.h"
#include "SoftwareSerial.h"

#define DEBUG_MODE
#define LW232_CAN_BUS_SHIELD_CS_PIN   10
#define LW232_DEFAULT_BAUD_RATE        115200

void setup() {
	  Serial.begin(LW232_DEFAULT_BAUD_RATE); 

        // Can232::init  (RATE, CLOCK)
        // Rates: CAN_10KBPS, CAN_20KBPS, CAN_50KBPS, CAN_100KBPS, CAN_125KBPS, CAN_250KBPS, CAN_500KBPS, CAN_500KBPS, CAN_1000KBPS, CAN_83K3BPS
        // Clock: MCP_16MHz or MCP_8MHz. 
        //        
    Can232::init(CAN_500KBPS, MCP_16MHz); 

}

INT8U myCustomAddressFilter(INT32U addr) {
    INT8U ret = LW232_FILTER_SKIP; //LW232_FILTER_PROCESS or LW232_FILTER_SKIP
    switch(addr) {
  
      case 0x3d0: 
      ret = LW232_FILTER_PROCESS;

    }

  return ret;
}

void loop() {
    Can232::loop();
}

void serialEvent() {
    Can232::serialEvent();
}
