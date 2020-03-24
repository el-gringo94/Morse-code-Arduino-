// Morsecode

int Speaker = 11;

void setup() {
  pinMode(Speaker, OUTPUT);
}

void kurz() {
  tone(Speaker, 440, 500);
  delay(1000);
}

void lang() {
  tone(Speaker, 440, 1000);
  delay(1500);
}

void encode(char c) {
  switch(tolower(c)){
    case 'a':
    kurz();
    lang();
    break;

    case 'b'
    lang();
    kurz();
    kurz();
    kurz();
    break;
    
    case 'c':
    lang();
    kurz();
    lang();
    kurz();

    case 'd':
    lang();
    kurz();
    kurz();

    case 'e':
    kurz();

    
    
  }
}

void loop() {
  kurz();
  lang();
}
