// run.ino
#include <Servo.h>

Servo servo;

void setup() {
    servo.attach(10);
    servo.writeMicroseconds(1700);
}   

void loop() {

}

