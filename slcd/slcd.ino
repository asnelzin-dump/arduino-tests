#include <SerialLCD.h>
#include <SoftwareSerial.h>

const int B = 3975;

float temperature;
const int signal = 8;
SerialLCD slcd(2, 3);

void setup() {
    pinMode(A2, INPUT);
    pinMode(signal, OUTPUT);
    slcd.begin();
    slcd.backlight();
    slcd.print("Temperature:");
    Serial.begin(9600);
}

void loop() {
    float reading = analogRead(A2);
    float resistance=(float)(1023 - reading) * 10000 / reading;
    temperature = 1 / (log(resistance/10000)/B + 1/298.15) - 273.15;
    slcd.setCursor(0, 1);
    slcd.print(temperature, 2);
    slcd.setCursor(6, 1);
    slcd.print(resistance, 2);
    
    if (temperature >= 30)
        digitalWrite(signal, HIGH);
    else
        digitalWrite(signal, LOW);

    slcd.setCursor(0, 1);
    delay(1000);
}
