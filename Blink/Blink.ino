//the pin on which you connect the anode (+) of the LED
int incomingData = 0;
float voltage, degreesC;

const int temperaturePin = A0;
const int ledPin =  12;


 
//this function runs only once (after reset)
void setup(){
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
}
 
void loop(){
  
  printTemperature(temperaturePin);
  
  if (Serial.available() > 0) {
      incomingData = Serial.read();
      if (incomingData == 49){ 
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
  }
  
  delay(1000);
}

int printTemperature(int pin) {
  voltage = (analogRead(pin) * 0.004882814);
  degreesC = (voltage - 0.5) * 100.0;
  Serial.println(degreesC, DEC);
  
}
