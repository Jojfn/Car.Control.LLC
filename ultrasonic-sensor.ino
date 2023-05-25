// This #include statement was automatically added by the Particle IDE.
#include <Grove_ChainableLED.h>

// This #include statement was automatically added by the Particle IDE.
#include <Grove-Ultrasonic-Ranger.h>

float distance_1 = 50.00;
float distance_2 = 100.00;

long duration;
long distance;

// defines pins numbers
#define trigPin	D2
#define echoPin	D6
// defines variables

// Ultrasonic ultrasonic(D4);

// ChainableLED leds(SCL, SDA, 1);


void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}

void loop() {
    
    //long Range = ultrasonic.MeasureInCentimeters();
    //Serial.print("Distance: ");
    //Serial.println(Range);
    //Particle.publish("distance",String(Range),NO_ACK);
    
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
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    
    if(distance <= distance_1){
       Particle.publish("IOTSensor","STOP",PRIVATE);
        //leds.setColorRGB(0, 0, 255, 0);   
        //Particle.publish("LEDRED",NO_ACK);
    }
    else if(distance > distance_1 && distance < distance_2){
      Particle.publish("IOTSensor","RISK",PRIVATE);
        // leds.setColorRGB(0, 255, 165, 0);   
        // Particle.publish("LEDYELLOW",NO_ACK);
      }
    else if(distance >= distance_2){
      Particle.publish("IOTSensor","Clear",PRIVATE);
        //leds.setColorRGB(0, 255, 0, 0);   
        //Particle.publish("LEDGREEN",NO_ACK);
      }
    delay(1000);
    }