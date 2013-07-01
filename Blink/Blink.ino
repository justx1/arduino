//used to store what we receive
int incomingData = 0;

//the pin on which you connect the anode (+) of the LED
const int temperaturePin = 0;
const int ledPin =  13;
float voltage, degreesC, degreesF;

 
//this function runs only once (after reset)
void setup(){
  //open the serial port and set data rate to 9600 bps
  Serial.begin(9600); 
  //set the pin we use to OUTPUT so we can power-up the LED
  pinMode(ledPin, OUTPUT); 
  //send our status
  Serial.println("Program started.");
  Serial.print("The LED connected to GND and PIN ");
  Serial.print(ledPin, DEC);
  Serial.println(" will be on if you send '1' or off if you send anything else!");
}
 
//this function runs continuosly (after setup)
void loop(){
 
 voltage = getVoltage(temperaturePin);
 degreesC = (voltage - 0.5) * 100.0;
 
  //look if we have data
  if (Serial.available() > 0) {
      //get the sent data
      incomingData = Serial.read();
      Serial.print("We received : ");
      Serial.println(incomingData);
      Serial.print("The LED is : ");
      //49 = ASCII code for '1'
      if (incomingData == 49){ 
        digitalWrite(ledPin, HIGH);
        Serial.println("ON");
      } else {
        digitalWrite(ledPin, LOW);
        Serial.println("OFF");
      }
      Serial.println();
      Serial.print("  deg C: ");
      Serial.print(degreesC);
      Serial.print("  V: ");
      Serial.print(voltage);

  }
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}
