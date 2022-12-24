#include <IRremote.hpp>
uint8_t rawCode[RAW_BUFFER_LENGTH]; // The durations if raw
uint8_t rawCodeLength; // The length of the code
uint8_t rawCode1[RAW_BUFFER_LENGTH]; // The durations if raw
uint8_t rawCodeLength1; // The length of the code
int buttonState = 0;
void setup()
{
IrReceiver.begin(2, ENABLE_LED_FEEDBACK); // Start the receiver
Serial.begin(9600);
pinMode(3, INPUT);
pinMode(4, INPUT);
}
void loop() {
if (digitalRead(4) == HIGH) {
if (IrReceiver.decode()) {
IrReceiver.printIRResultRawFormatted(&Serial, true); // Output the results in RAW
format
rawCodeLength = IrReceiver.decodedIRData.rawDataPtr->rawlen - 1;
IrReceiver.compensateAndStoreIRResultInArray(rawCode);
IrReceiver.resume();
for (int i = 0; i < rawCodeLength; i++) {
Serial.println(rawCode[i]);
}
delay(500);
Serial.write(1);
Serial.write(rawCodeLength);
delay(500);
Serial.write(rawCode, rawCodeLength);
}
} else if (digitalRead(3) == HIGH) {
if (IrReceiver.decode()) {
IrReceiver.printIRResultRawFormatted(&Serial, true); // Output the results in RAW
format
rawCodeLength1 = IrReceiver.decodedIRData.rawDataPtr->rawlen - 1;
IrReceiver.compensateAndStoreIRResultInArray(rawCode1);
IrReceiver.resume();
for (int i = 0; i < rawCodeLength1; i++) {
Serial.println(rawCode1[i]);
}
delay(500);
Serial.write(2);
Serial.write(rawCodeLength1);
delay(500);
Serial.write(rawCode1, rawCodeLength1);
}
}
}
