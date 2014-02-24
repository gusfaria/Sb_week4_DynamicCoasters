//include the libraries needed for the MP3 shield
#include <SPI.h>
//This library allows you to communicate with SPI devices, with the Arduino as the master device.
//Add the SdFat Libraries
#include <SdFat.h>
#include <SdFatUtil.h>
//The Arduino SdFat Library is a minimal implementation of FAT16 and FAT32 file systems on SD flash memory cards.
//upload these libraries to allow SD card to be read.
#include <SFEMP3Shield.h>
//add the MP3 Shield Library
int incomingByte;  //a variable to read incoming serial data
int recordedRange; //a variable to record the last range received
int currentState; //a variable to record the current state of the data being received
int prevByte; //a variable to record the previous state of the data being received

/**
 * \brief Object instancing the SdFat library.
 *
 * principal object for handling all SdCard functions.
 */
SdFat sd;

/**
 * \brief Object instancing the SFEMP3Shield library.
 *
 * principal object for handling all the attributes, members and functions for the library.
 */
SFEMP3Shield MP3player;

void setup() {
  //initiate serial communication:
  Serial.begin(9600);

  //Initialize the SdCard
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) sd.initErrorHalt();
  if(!sd.chdir("/")) sd.errorHalt("sd.chdir");
}

void loop(){

  //read serial messages
  if (Serial.available() > 0) {

    //read the incomingByte in the serial monitor
    incomingByte = Serial.read();
  }
 // Below is not needed if interrupt driven. Safe to remove if not using.
#if defined(USE_MP3_REFILL_MEANS) \
  && ( (USE_MP3_REFILL_MEANS == USE_MP3_SimpleTimer) \
    ||   (USE_MP3_REFILL_MEANS == USE_MP3_Polled)      )
//make sure MP3player is available
    MP3player.available();
#endif
//read the serial port
  while (Serial.available()) incomingByte = Serial.read();
//tell the sound only to play when there is a new reading
  if (incomingByte != prevByte) {
    if (incomingByte == 1) {
      MP3player.stopTrack(3);
      MP3player.playTrack(3);
//stop and play track 3
      delay(3000);
    }
    else if (incomingByte == 2) {
  MP3player.stopTrack(2);
  MP3player.playTrack(2);
//stop and play track 2
      delay(3000);
    }
    else if (incomingByte == 3) {
      MP3player.stopTrack(1);
  MP3player.playTrack(1);
//stop and play track 1
      delay(3000);
    }
    prevByte = incomingByte;
    //tell precvious bite to equal incoming byte
  }
}







