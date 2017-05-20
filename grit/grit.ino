// CALIBRATE PHOTOCELL AND ADJUST TH
#define TH 960

int SEN = A1;
int LED[14] = {7,8,6,9,5,10,11,4,12,3,13,2,1,0};
int VAL = 0;
int CNT = 0;
int j = 0;
int k = 0;
int STB = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 14; i++) {
    pinMode(LED[i], OUTPUT);
    digitalWrite(LED[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while (CNT < 25) {
    digitalWrite(LED[j], LOW);
    j += 1;
    if (j == 12) {
      j = 0;
    }
    VAL = analogRead(SEN);
    if (VAL > TH) {
      CNT += 1;
    }
    delay(10);
  }
  CNT = 0;
  STB += 1;
  k = 0;
  digitalWrite(LED[13], LOW);
  digitalWrite(LED[k], HIGH);
  delay(100);
  for (int i = 0; i < 1; i++) {
    k += 1;
    while (k < 14) {
      digitalWrite(LED[k-1], LOW);
      digitalWrite(LED[k], HIGH);
      k += 1;
      delay(100);
    }
    while (k > 1) {
      k -= 1;
      digitalWrite(LED[k], LOW);
      digitalWrite(LED[k-1], HIGH);
      delay(100);
    }
    k = 0;
  }

  if (STB > 15) {
    while (1) {
      for (int i = 0; i < 14; i++) {
        digitalWrite(LED[i], HIGH);
      }
      delay(100);
      for (int i = 0; i < 14; i++) {
        digitalWrite(LED[i], LOW);
      }
      delay(100);
    }
  }
}
