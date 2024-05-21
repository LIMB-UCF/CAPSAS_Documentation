#include <Adafruit_NeoPixel.h>

#define PIN 10
#define NUMPIXELS 192
#define speed 1000

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
unsigned long previousMillis = 0UL;
unsigned long interval = 15UL;

int irState = HIGH;

bool newData = false;
unsigned int dataNumber = 0;

unsigned int curani = 65535;
unsigned long startMillis = millis();
bool trig = false;
bool dytrig = false;
bool rundynamic = false;
bool finishdynamic = false;
bool dyobjtrig = true;
bool v = true;
unsigned int curstartani = 0;

unsigned long dynamicmillis = 0;

unsigned int wait = 65535;

unsigned int hexnum = 0;
unsigned int aninum = 0;
unsigned int targetnum = 0;

char ca = 'a';
char IME = 'b';

unsigned long b = 0;
unsigned long c = 0;

byte byte1 = 0;
byte byte2 = 0;

void setup() {
  //open serial
  Serial.begin(115200);
  //start LEDs
  pixels.begin(); 
  //ready inputs
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT_PULLUP);

  while (v) {
    recvWithEndMarker();
    wait = showNewNumber();

    if (wait < 65535) {
      Serial.println(millis());
      //Serial.println(millis());
      v = false;
    }
  }
}

void loop() {
  recvWithEndMarker();
  unsigned int newani = (unsigned int)showNewNumber();
  unsigned long currentMillis = millis();
  
  if (newani < 65535) {
    curani = newani;
    //Serial.println(newani);
    startMillis = millis();
    pixels.clear();
    pixels.show();
    if ((curani >> 15) == 0) {
      hexnum = curani/5;
      aninum = curani%5;
      ca = 'b';
      IME = 'a';
    } else if ((curani >> 15) == 1) {
      curstartani = (curani >> 8) - 128;
      hexnum = curstartani/6;
      aninum = curstartani%6;
      targetnum = (curani & 0b0000000011111111)/6;
      ca = 'c';
      IME = 'a';
    }
  }
  //Serial.print(IME);
  switch (ca) {
    case 'b':
      switch (IME) {
        case 'a':
          if (hexnum == 16) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
          } else if (aninum == 0) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
            open(hexnum, startMillis);
          } else if (aninum == 1) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
            close(hexnum, startMillis);
          } else if (aninum == 2) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
            left(hexnum, startMillis);
          } else if (aninum == 3) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
            right(hexnum, startMillis);
          } else if (aninum == 4) {
            if (button(hexnum + 22)) {
              IME = 'b';
              break;
            }
            resi(hexnum, startMillis);
          }
          break;
        case 'b': 
          Serial.println(millis());
          int i = 250;
          if (hexnum < 16) {
            pixels.setPixelColor((hexnum*12) + 0, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 1, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 2, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 3, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 4, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 5, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 6, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 7, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 8, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 9, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 10, pixels.Color(0, i, 0));
            pixels.setPixelColor((hexnum*12) + 11, pixels.Color(0, i, 0));
            pixels.show();
            delay(wait*1000);
          }
          pixels.clear();
          Serial.println(millis());
          pixels.show();
          ca = 'a';
          IME = 'a';
          curani = 65535;
      }
      break;
    default:
      //waiting for new serial
      break;
  }

  if(currentMillis - previousMillis > interval) {
    pixels.show();
    previousMillis = currentMillis;
  }
}

bool button(int irPin) {
  irState = digitalRead(irPin);
  bool triggered = false; //should be false
  if (irState == LOW) { //change  to LOW
    triggered = true;
  }
  return triggered;
}

bool obbutton(int irPin) {
  irState = digitalRead(irPin);
  bool triggered = false;
  if (irState == HIGH) { 
    triggered = true;
  }
  return triggered;
}
