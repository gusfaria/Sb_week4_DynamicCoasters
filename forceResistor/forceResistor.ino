int glassWeight = 50; // this is how much the glass weight.
void setup() {
	// open serial port
	Serial.begin(9600);
}

void loop() {
	// read and send the value of analog sensor
        long raw_val = analogRead(A0);
        

        //is their a cup is over the coaster?
        if(raw_val > glassWeight) {
          // yes, the cup is over the coaster so send data.
          Serial.println(raw_val);  
      } 
      // else, leave the last value catched. 
      // Because we don't need to know everytime you take a sip, we need to know if the bottle is empty.
	
       delay(100);
}
