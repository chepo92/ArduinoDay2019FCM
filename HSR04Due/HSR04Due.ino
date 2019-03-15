/*
  Distance Measuring with ultrasonic sensor hc-sr04 on an Arduino Due
  by Irwan, http://www.likecircuit.com.
*/
 
// defines pins numbers
const int trigPin = 5;
const int echoPin = 6;
 
// defines variables
long duration;
float distance;
float Mdistance;
 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= (duration*0.0228)/2;  // Distance with Cm
Mdistance= distance/100;        // Distance with m
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.print(" cm");
Serial.print(" or ");
Serial.print(Mdistance);
Serial.print(" m");
Serial.println();
delay(50);
}
