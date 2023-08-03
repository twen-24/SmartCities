int motorPin = 3;
int sensorPin = 7;
boolean wallClosed = true;

void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  int sensorData = digitalRead(sensorPin);
  Serial.println(sensorData);

  //the sensor that we used displays boolean values, controlled by a potentiometer
  if(sensorData == 1 && wallClosed){
    digitalWrite(motorPin, HIGH);
    delay(200);
    digitalWrite(motorPin,LOW);
    wallClosed = false;
  }
  else if(sensorData==1 && !wallClosed) {
    digitalWrite(motorPin, HIGH);
    delay(600);
    digitalWrite(motorPin,LOW);
    wallClosed = true;
  }
}