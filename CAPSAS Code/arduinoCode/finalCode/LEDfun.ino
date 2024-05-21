void close(int hex, unsigned long startms) {
  unsigned long currentMillis = millis();

    unsigned long b = millis() - startms;
    unsigned long c = b%750;
    int i = 0; 

    if (c < 250) {
      i = c;
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, 0, 0));
      //pixels.show();
    }
    else if (c < 500) {
      i = c - 250;
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, 0, 0));
      //pixels.show();
    }
    else if (c < 750) {
      i = c - 500;
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, 0, 0));
      //pixels.show();
    }

}

void resi(int hex, unsigned long startms) {
  unsigned long currentMillis = millis();
    int i = 250;
    pixels.setPixelColor((hex*12) + 0, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 1, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 2, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 3, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 4, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 5, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 6, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 7, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 8, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 9, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 10, pixels.Color(0, i, i));
    pixels.setPixelColor((hex*12) + 11, pixels.Color(0, i, i));
    //pixels.show();
}

void open(int hex, unsigned long startms) {
  unsigned long currentMillis = millis();

    unsigned long b = millis() - startms;
    unsigned long c = b%750;
    int i = 0; 

    if (c < 250) {
      i = c;
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, 0, 0));
      //pixels.show();
    }
    else if (c < 500) {
      i = c - 250;
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, 0, 0));
      //pixels.show();
    }
    else if (c < 750) {
      i = c - 500;
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, 0, 0));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, 0, 0));
      //pixels.show();
    }


}

void right(int hex, unsigned long startms) {
  unsigned long currentMillis = millis();

    unsigned long b = millis() - startms;
    unsigned long c = b%750;
    int i = 0; 

    if (c < 250) {
      i = c;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, i, i));
      //pixels.show();
    }
    else if (c < 500) {
      i = c - 250;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 2, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 9, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, i, i));
      //pixels.show();
    }
    else if (c < 750) {
      i = c - 500;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 1, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 10, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 0, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 11, pixels.Color(0, i, i));
      //pixels.show();
    }

}

void left(int hex, unsigned long startms) {
  unsigned long currentMillis = millis();


    /* The Arduino executes this code once every second
    *  (interval = 1000 (ms) = 1 second).
    */
    unsigned long b = millis() - startms;
    unsigned long c = b%750;
    int i = 0; 

    if (c < 250) {
      i = c;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, i, i));
      //pixels.show();
    }
    else if (c < 500) {
      i = c - 250;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 3, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 8, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, i, i));
      //pixels.show();
    }
    else if (c < 750) {
      i = c - 500;
      pixels.clear();
      pixels.setPixelColor((hex*12) + 4, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 7, pixels.Color(0, 250 - i, 250 - i));
      pixels.setPixelColor((hex*12) + 6, pixels.Color(0, i, i));
      pixels.setPixelColor((hex*12) + 5, pixels.Color(0, i, i));
      //pixels.show();
    }
}

void cool(int num) {
  Serial.println(millis());
  int i = 250;
  pixels.clear();
  pixels.setPixelColor((num*12) + 0, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 1, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 2, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 3, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 4, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 5, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 6, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 7, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 8, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 9, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 10, pixels.Color(0, i, 0));
  pixels.setPixelColor((num*12) + 11, pixels.Color(0, i, 0));
  pixels.show();
  delay(3000);
  pixels.clear();
  pixels.show();
  b=0;
}