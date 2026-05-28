#include <SPI.h>
#include <RF24.h>
// Definitions, not sure if these are correct due to lack of testing material
#define PTT_PIN 2
#define AUDIO_IN A0
#define AUDIO_OUT 11
#define LED 16

RF24 radio(9, 10);
const byte address[6] = "00001";
uint8_t audioBuffer[32];
volatile uint8_t bufferIndex = 0;

void setup() {
  pinMode(PTT_PIN, INPUT_PULLUP);
  pinMode(AUDIO_OUT, OUTPUT);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS); // High speed for audio data

}

void loop() {
  // Check if button is pressed
  if (digitalRead(PTT_PIN) == LOW) {
    // TRANSMIT MODE
    radio.stopListening();
    digitalWrite(LED, HIGH);
    if (bufferIndex >= 32) {
      radio.write(&audioBuffer, 32);
      bufferIndex = 0;
    }
  } else {
    // RECEIVE MODE
    radio.startListening();
    digitalWrite(LED, LOW);
    if (radio.available()) {
      digitalWrite(LED, HIGH);
      radio.read(&audioBuffer, 32);
      for(int i=0; i<32; i++) {
        analogWrite(AUDIO_OUT, audioBuffer[i]); // Simplistic representation
        delayMicroseconds(125); // 1/8000Hz = 125us, not sure if this is correct, from gemini
      }
    }
  }
}
