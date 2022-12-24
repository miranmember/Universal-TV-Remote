#include <IRremote.hpp>
uint8_t rawCode[RAW_BUFFER_LENGTH]; // The durations if raw
uint8_t rawCodeLength; // The length of the code
uint8_t rawCode1[RAW_BUFFER_LENGTH]; // The durations if raw
uint8_t rawCodeLength1; // The length of the code
//uint8_t buf[100] = {179, 87, 12, 32, 12, 10, 12, 10, 12, 11, 12, 10, 12, 10, 12, 10, 12, 10,
13, 9, 12, 32, 12, 32, 12, 32, 12, 33, 12, 32, 12, 32, 12, 32, 12, 32, 12, 32, 12, 10, 12, 11,
12, 10, 12, 10, 12, 10, 12, 10, 12, 11, 12, 10, 12, 32, 12, 32, 12, 32, 12, 33, 12, 32, 12,
32, 12, 32, 12, 33, 12, 10, 12, 10, 12, 10, 12, 11, 12, 10, 12, 10, 12, 10, 13, 10, 12, 32,
12, 32, 12, 33, 12, 32,12,32,12,33,12};
int incomingByte = 0;
void setup()
{
IrSender.begin(3, ENABLE_LED_FEEDBACK);
Serial.begin(9600);
pinMode(4, INPUT);
pinMode(5, INPUT);
}
void loop() {
if (Serial.available() > 0) {
incomingByte = Serial.read();
Serial.print(incomingByte);
Serial.println(" Button");
if (incomingByte == 1) {
incomingByte = Serial.read();
rawCodeLength = incomingByte;
Serial.print(rawCodeLength);
Serial.println(" Length");
Serial.readBytes(rawCode, rawCodeLength);
for (int i = 0; i < rawCodeLength; i++) {
Serial.println(rawCode[i]);
}
Serial.println(rawCodeLength);
} else if (incomingByte == 2) {
incomingByte = Serial.read();
rawCodeLength1 = incomingByte;
Serial.print(rawCodeLength1);
Serial.println(" Length");
Serial.readBytes(rawCode1, rawCodeLength1);
for (int i = 0; i < rawCodeLength1; i++) {
Serial.println(rawCode1[i]);
}
Serial.println(rawCodeLength1);
}
}
if (digitalRead(4) == HIGH) {
IrSender.sendRaw(rawCode, rawCodeLength, 38);
} else if (digitalRead(5) == HIGH) {
IrSender.sendRaw(rawCode1, rawCodeLength1, 38);
}
}