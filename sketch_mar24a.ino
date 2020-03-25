// Morsecode

int Speaker = 11;
int ledPin = 13;

int UNIT = 500;

void setup() {
  pinMode(Speaker, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void kurz() {
  tone(Speaker, 440);
  digitalWrite(ledPin, HIGH);
  delay(1 * UNIT);
  noTone(Speaker);
  digitalWrite(ledPin, LOW);
  delay(1 * UNIT);
}

void lang() {
  tone(Speaker, 440);
  digitalWrite(ledPin, HIGH);
  delay(3 * UNIT);
  noTone(Speaker);
  digitalWrite(ledPin, LOW);
  delay(1 * UNIT);
}

void encode(char c) {
  switch (tolower(c)) {
    case 'a':
      kurz();
      lang();
      break;

    case 'b':
      lang();
      for (int i = 0; i < 3; i++) {
        kurz();
      }
      break;

    case 'c':
      lang();
      kurz();
      lang();
      kurz();
      break;

    case 'd':
      lang();
      kurz();
      kurz();
      break;

    case 'e':
      kurz();
      break;

    case 'f':
      kurz();
      kurz();
      lang();
      kurz();
      break;

    case 'g':
      lang();
      lang();
      kurz();
      break;

    case 'h':
      for (int i = 0; i < 4; i++) {
        kurz();
      }
      break;

    case 'i':
      kurz();
      kurz();
      break;

    case 'j':
      kurz();
      for (int i = 0; i < 3; i++) {
        lang();
      }
      break;

    case 'k':
      lang();
      kurz();
      lang();
      break;

    case 'l':
      kurz();
      lang();
      kurz();
      kurz();
      break;

    case 'm':
      lang();
      lang();
      break;

    case 'n':
      lang();
      kurz();
      break;

    case 'o':
      for (int i = 0; i < 3; i++) {
        lang();
      }
      break;

    case 'p':
      kurz();
      lang();
      lang();
      kurz();
      break;

    case 'q':
      lang();
      lang();
      kurz();
      lang();
      break;

    case 'r':
      kurz();
      lang();
      kurz();
      break;

    case 's':
      for (int i = 0; i < 3; i++) {
        kurz();
      }
      break;

    case 't':
      lang();
      break;

    case 'u':
      kurz();
      kurz();
      lang();
      break;

    case 'v':
      for (int i = 0; i < 3; i++) {
        kurz();
      }
      lang();
      break;

    case 'w':
      kurz();
      lang();
      lang();
      break;

    case 'x':
      lang();
      kurz();
      kurz();
      lang();
      break;

    case 'y':
      lang();
      kurz();
      lang();
      lang();
      break;

    case 'z':
      lang();
      lang();
      kurz();
      kurz();
      break;

    case '1':
      kurz();
      for (int i = 0; i < 4; i++) {
        lang();
      }
      break;

    case '2':
      kurz();
      kurz();
      for (int i = 0; i < 3; i++) {
        lang();
      }
      break;

    case '3':
      for (int i = 0; i < 3; i++) {
        kurz();
      }
      lang();
      lang();
      break;

    case '4':
      for (int i = 0; i < 4; i++) {
        kurz();
      }
      lang();
      break;

    case '5':
      for (int i = 0; i < 5; i++) {
        kurz();
      }
      break;

    case '6':
      lang();
      for (int i = 0; i < 4; i++) {
        kurz();
      }
      break;

    case '7':
      lang();
      lang();
      for (int i = 0; i < 3; i++) {
        kurz();
      }
      break;

    case '8':
      for (int i = 0; i < 3; i++) {
        lang();
      }
      kurz();
      kurz();
      break;

    case '9':
      for (int i = 0; i < 4; i++) {
        lang();
      }
      kurz();
      break;

    case '0':
      for (int i = 0; i < 5; i++) {
        lang();
      }
      break;

    default:
      delay(4 * UNIT);
      break;
  }
  delay(2 * UNIT);
}

void encode(const char *c) {
  while (*c) encode(*c++);
}

void loop() {
  if (Serial.available() > 0) {
    char in = Serial.read();
    if (in != -1) {
      encode(in);
      Serial.print(in);
    }
  }
}
