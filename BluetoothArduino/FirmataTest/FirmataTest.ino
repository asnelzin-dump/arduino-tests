#include <Firmata.h>
#include <SoftwareSerial.h>



#define RxD 6
#define TxD 7

byte analogPin;
SoftwareSerial blueToothSerial(RxD,TxD);

void analogWriteCallback(byte pin, int value)
{
    pinMode(pin,OUTPUT);
    analogWrite(pin, value);
}

void setupBlueToothConnection() {
    pinMode(RxD, INPUT);
    pinMode(TxD, OUTPUT);
    blueToothSerial.begin(38400);
    blueToothSerial.print("\r\n+STWMOD=0\r\n");
    blueToothSerial.print("\r\n+STNA=RobotServer\r\n");
    blueToothSerial.print("\r\n+STOAUT=1\r\n");
    blueToothSerial.print("\r\n+STAUTO=0\r\n");
    delay(2000);
    blueToothSerial.print("\r\n+INQ=1\r\n");
    delay(2000);
    blueToothSerial.flush();
}

void setup()
{
    Firmata.setFirmwareVersion(0, 1);
    Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
    setupBlueToothConnection();

    Firmata.begin(blueToothSerial);
}

void loop()
{
    while(Firmata.available()) {
        Firmata.processInput();
    }
    for(analogPin = 0; analogPin < TOTAL_ANALOG_PINS; analogPin++) {
        Firmata.sendAnalog(analogPin, analogRead(analogPin)); 
    }
}
