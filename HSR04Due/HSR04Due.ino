/*
  Distance Measuring with ultrasonic sensor hc-sr04 on an Arduino Due
  by Irwan, http://www.likecircuit.com.
*/
 
// defines pins numbers
const int trigPin [] = {3,5,7};
const int echoPin []= {2,4,6};
 
// defines variables
long duration[3];
float distance[3];
//float Mdistance;

int arraySize ;// = sizeof(trigPin) / sizeof(trigPin[0]);
 
void setup() {
Serial.begin(9600); // Starts the serial communication
Serial.println("INIT");
arraySize = sizeof(trigPin) / sizeof(trigPin[0]);

Serial.println(arraySize);
  
for (int i=0; i< 3;i++) {
pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin[i], INPUT); // Sets the echoPin as an Input
  
}
Serial.println("INITED");
}
 
void loop() {
// Clears the trigPin
for (int i=0; i< arraySize;i++) {
digitalWrite(trigPin[i], LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
//for (int i=0; i< arraySize;i++) {
digitalWrite(trigPin[i], HIGH);
delayMicroseconds(10);
digitalWrite(trigPin[i], LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration[i] = pulseIn(echoPin[i], HIGH);
}
// Calculating the distance
for (int i=0; i< arraySize;i++) {
distance[i]= (duration[i]*0.0228)/2;  // Distance with Cm
//Mdistance= distance[]/100;        // Distance with m
}
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
for (int i=0; i< arraySize;i++) {
Serial.print(distance[i]);
Serial.print(" cm");
Serial.print(";");
//Serial.print(Mdistance);
//Serial.print(" m");
//Serial.println();
}
Serial.println();
//delay(50);
}


