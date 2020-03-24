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
      kurz();
      kurz();
      kurz();
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
      kurz();
      kurz();
      kurz();
      kurz();
      break;

    case 'i':
      kurz();
      kurz();
      break;

    case 'j':
      kurz();
      lang();
      lang();
      lang();
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
      lang();
      lang();
      lang();
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
      kurz();
      kurz();
      kurz();
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
      kurz();
      kurz();
      kurz();
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
      lang();
      lang();
      lang();
      lang();
      break;

    case '2':
      kurz();
      kurz();
      lang();
      lang();
      lang();
      break;

    case '3':
      kurz();
      kurz();
      kurz();
      lang();
      lang();
      break;

    case '4':
      kurz();
      kurz();
      kurz();
      kurz();
      lang();
      break;

    case '5':
      kurz();
      kurz();
      kurz();
      kurz();
      kurz();
      break;

    case '6':
      lang();
      kurz();
      kurz();
      kurz();
      kurz();
      break;

    case '7':
      lang();
      lang();
      kurz();
      kurz();
      kurz();
      break;

    case '8':
      lang();
      lang();
      lang();
      kurz();
      kurz();
      break;

    case '9':
      lang();
      lang();
      lang();
      lang();
      kurz();
      break;

    case '0':
      for (int i = 0; i<5; i++){
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
  if(Serial.available() > 0){
    char in = Serial.read();
    if(in != -1){
      encode(in);
      Serial.print(in);
    }
  }
}
