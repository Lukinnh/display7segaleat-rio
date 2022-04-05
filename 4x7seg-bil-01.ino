#include "SevSeg.h"
int senha = 4534;
SevSeg sevseg; 

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = true; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(
    hardwareConfig, 
    numDigits, 
    digitPins, 
    segmentPins, 
    resistorsOnSegments,
    updateWithDelays, 
    leadingZeros, 
    disableDecPoint
  );
    
  sevseg.setBrightness(90);
}

void loop() {

    sevseg.refreshDisplay(); 
    for(int i = 0; i < 9999; i++)
    {
      if(senha == i){
        for(int x =0; x<5000; x++){ 
          for(int v=0; v<1000; v++){
          sevseg.setNumber(i, 1);
          sevseg.refreshDisplay();
          }
          for(int y=0; y<500; y++){
           sevseg.setBrightness(0);
           sevseg.refreshDisplay();
          }
          sevseg.setBrightness(90);
        }
        exit(0);
       }
      sevseg.setNumber(i, 1);
      sevseg.refreshDisplay();   
    }
  
}
