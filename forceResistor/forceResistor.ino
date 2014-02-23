boolean bCupIsOver = false;

void setup() {
	// open serial port
	Serial.begin(9600);
}

void loop() {
	// read and send the value of analog sensor
        long raw_val = analogRead(A0);

        int range_offet = 3;
        int range_size = 60; 
  //        raw_val = raw_val - range_offet;
  //      raw_val = constrain( (raw_val * 1023 / range_size), 0, 1023);
        
        if(raw_val>50){
          bCupIsOver = true;
        } else {
          bCupIsOver = false;
        }
         
        if(bCupIsOver == true){
            Serial.println(raw_val);
            if(raw_val < 400){
               Serial.println("cup is over and need refill!");
            } else {
               Serial.println("cup is over!");  
            }
        }
        
	// wait to send the next value so that you
	// don't clog up the serial port
	delay(100);
}
