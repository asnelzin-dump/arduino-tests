#include <Servo.h>

Servo servoMain;

void turn(int velocity, int ms) {
    servoMain.writeMicroseconds(1500 + velocity);
    delay(ms);
    servoMain.writeMicroseconds(1500);    
}

void setup() {
    servoMain.attach(9);
    servoMain.writeMicroseconds(1500);

    turn(800, 5000);

}
 
void loop() {
}