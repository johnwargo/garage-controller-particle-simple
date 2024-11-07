/******************************************************************
     Garage Door Button: Original Edition
     
     By John M. Wargo
     January 15, 2016
     www.johnwargo.com
     
*******************************************************************/

//==========================================================
//Define the output pins this sketch will use
//==========================================================
// Connect the relay to Digital 0
int relayPin = D0;
// Connect the activity LED to Digital 1
int activityLED = D1;
// Connect the power LED to Digital 2
int powerLED = D2;
//For testing, use the following, it lights the blue LED on the board
//int powerLED = D7;

void setup() {
    
    //Setup serial output
     Serial.begin(9600);
     Serial.println("Device setup initializing...");
     
    //======================================================
    //Setup Digital Output Pins
    //======================================================
    // Set the relay pin to output
    pinMode(relayPin, OUTPUT);
    // Set both LED pins to output
    pinMode(activityLED, OUTPUT);
    pinMode(powerLED, OUTPUT);
    
    //======================================================
    // Turn the power LED on
    // it runs constantly so you can tell from a distance
    // if the board is on.
    //======================================================
    Serial.println("Turning power LED on");
    digitalWrite(powerLED, HIGH);
    
    //======================================================
    // Define the external function call to push the button
    //======================================================
    Particle.function("pushButton", pushButton);
    
}

void loop() {
    //Nothing to do here, really.
    //Unless we want to blink the onbord LED for some reason
}

//=================================================================
// This function pushes the garage door button (through the relay,
// of course)
//=================================================================
int pushButton(String param){
    
    Serial.println("pushButton function called.");
    //==================================================    
    //Remove the following line in production
    //digitalWrite(powerLED, LOW);
    //==================================================    
    
    //Turn the activity LED on, so we can tell it's working
    digitalWrite(activityLED, HIGH);
    //Turn the relay on 
    digitalWrite(relayPin, HIGH);
    //Wait half a second (or however long we determine we need to)
    delay(500);
    //Turn the relay off
    digitalWrite(relayPin, LOW);
    //Turn the activity LED off
    digitalWrite(activityLED, LOW);

    //==================================================
    //Remove the following line in production
    //digitalWrite(powerLED, HIGH);
    //==================================================
   
    //Have to return something, so return a zero (-1 means failure)
    return 0;
}

