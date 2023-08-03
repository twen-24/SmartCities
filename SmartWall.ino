//This code controls the opening and closing mechanism of the smart wall. 

int motorPin = 3;
int sensorPin = 7;
boolean wallOpen = true;

void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  //the sensor that we used displays boolean values, controlled by a potentiometer
  int sensorData = digitalRead(sensorPin);

  if(sensorData == 1 && wallOpen){
    //spin wall open
    digitalWrite(motorPin, HIGH);
    delay(200);
    digitalWrite(motorPin,LOW);
    wallOpen = false;
  }
  else if(sensorData == 0 && !wallOpen) {
    //spin wall closed
    digitalWrite(motorPin, HIGH);
    delay(600);
    digitalWrite(motorPin,LOW);
    wallOpen = true;
  }
}
