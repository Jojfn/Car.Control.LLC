// This #include statement was automatically added by the Particle IDE.
#include <Grove_ChainableLED.h>

// ChainableLED leds(SCL, SDA, 1);

int led = D7;

void setup() {
    
Particle.subscribe("IOTSensor", IOTSensor, MY_DEVICES);
// Particle.subscribe("LEDRED", Stop, "ef00cb681cbe1b0391a038");
// Particle.subscribe("LEDYELLOW", Risk, "ef00cb681cbe1b0391a038");
// Particle.subscribe("LEDGREEN", Clear, "ef00cb681cbe1b0391a038");


Serial.begin(9600);

pinMode(led, OUTPUT);
digitalWrite(led, LOW);

}

void loop() {

}

void IOTSensor(const char *event, const char *data){
    
   digitalWrite(led,HIGH);
   
    if (strcmp(data,"Clear")==0) {
        // if the car is far away, then turn your board LED and buzzer off
       digitalWrite(led,LOW);
    }
    else if (strcmp(data,"RISK")==0) {
    // if the car is under 60 cm away, turn your board LED and buzzer on
        digitalWrite(led,HIGH);
        delay(1000);
        digitalWrite(led,LOW);
    }
    else if (strcmp(data,"STOP")==0) {
        // if the car is under 60 cm away, turn your board LED and buzzer on
        digitalWrite(led,HIGH);
       
    }

    delay(1000);
}

// void Stop(const char *event, const char *data){
//     leds.setColorRGB(0, 0, 255, 0);   
//     digitalWrite(leds,HIGH);
//     delay(1000);
// }


// void Risk(const char *event, const char *data){
    
//     leds.setColorRGB(0, 255, 165, 0);   
//     digitalWrite(leds,HIGH);
//     delay(1000);
//     digitalWrite(leds,LOW);
// }

// void Clear(const char *event, const char *data){
    
//     leds.setColorRGB(0, 255, 255, 0);   
//     digitalWrite(leds,HIGH);
//     delay(1000);
// }

