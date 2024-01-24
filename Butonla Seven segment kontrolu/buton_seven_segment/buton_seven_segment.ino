int digit_array[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0 abcdef
  {0, 1, 1, 0, 0, 0, 0},  // 1 bc
  {1, 1, 0, 1, 1, 0, 1},  // 2 ab de g
  {1, 1, 1, 1, 0, 0, 1},  // 3 abcd g
  {0, 1, 1, 0, 0, 1, 1},  // 4 bc fg
  {1, 0, 1, 1, 0, 1, 1},  // 5 a cd fg
  {1, 0, 1, 1, 1, 1, 1},  // 6 a cdefg
  {1, 1, 1, 0, 0, 0, 0},  // 7 abc
  {1, 1, 1, 1, 1, 1, 1},  // 8 abcdefg
  {1, 1, 1, 0, 0, 1, 1},  // 9 abcd fg
};

int sag_buton = 10;
int sol_buton = 9;
int sayac = 0;

void setup() {
  // 7-segment display pinleri başlangıçta çıkışa ayarlanmalıdır.
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(sag_buton, INPUT);
  pinMode(sol_buton, INPUT);
}

void display(int sayac) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(i + 2, digit_array[sayac][i]);
  }
  delay(250);
}

void loop() {
  

  if (digitalRead(sag_buton) == 1) {
    sayac++;
    display(sayac);
  }

  if (digitalRead(sol_buton) == 1) {
    sayac--;
    display(sayac);
  }

  if (sayac > 9) {
    sayac = 0;
  }
  if (sayac < 0) {
    sayac = 9;
  }
}


