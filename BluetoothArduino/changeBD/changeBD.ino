#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7);

void setup()
{
mySerial.begin(38400);
mySerial.print("\r\n+STBD=57600\r\n");
}

void loop()
{

}