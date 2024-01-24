int digit_array[10][7] = {
  {1,1,1,1,1,1,0},  // 0 abcdef
  {0,1,1,0,0,0,0},  // 1  bc
  {1,1,0,1,1,0,1},  // 2 ab de g
  {1,1,1,1,0,0,1},  // 3 abcd  g
  {0,1,1,0,0,1,1},  // 4  bc  fg
  {1,0,1,1,0,1,1},  // 5 a cd fg
  {1,0,1,1,1,1,1},  // 6 a cdefg
  {1,1,1,0,0,0,0},  // 7 abc    
  {1,1,1,1,1,1,1},  // 8 abcdefg
  {1,1,1,0,0,1,1},  // 9 abcd fg
};

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(i + 2, digit_array[digit][i]);
  }
}

void setup() {
  // 7-segment display pinleri başlangıçta çıkışa ayarlanmalıdır.
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // 0'dan 9'a kadar olan rakamları sırayla göster
  for (int i = 0; i < 10; i++) {
    displayDigit(i);
    delay(1000); // 1 saniye beklet
  }

  
}
