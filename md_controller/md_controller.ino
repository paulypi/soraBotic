// Define directions in decimal 4 mechanum wheels
#define N 170
#define NE 130
#define E 150
#define SE 20
#define S 85
#define SO 65
#define O 105
#define NO 40
#define ROTR 153
#define ROTL 102

// Connection to 74HC595
#define SER 2
#define SRCLK 4
#define RCLK 7
#define SRCLRB 8

// Connection to MotorDriver1
#define ENA1 3
#define ENB1 5

// Connection to MotorDriver2
#define ENA2 6
#define ENB2 9

void setup() {
  // 74HC595
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(SRCLRB, OUTPUT);
  // Clear output
  //digitalWrite(SRCLRB, HIGH);

  // MotorDriver1
  pinMode(ENA1, OUTPUT);
  pinMode(ENB1, OUTPUT);
  digitalWrite(ENA1, LOW);
  digitalWrite(ENB1, LOW);

  // MotorDriver2
  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);
  digitalWrite(ENA2, LOW);
  digitalWrite(ENB2, LOW);
}

void loop() {
  int speeds[4] = {100, 100, 100, 100};

  direct(N);
  speed(speeds);
  delay(3000);

  fullBrakes();
  delay(3000);  
  
  direct(S);
  delay(3000);

  fullBrakes();
}

// Send directions trought 74HC595
void direct(int directions) {
  digitalWrite(SRCLRB, HIGH);
  digitalWrite(RCLK, LOW);
  shiftOut(SER, SRCLK, MSBFIRST, directions);
  digitalWrite(RCLK, HIGH);
  delay(500);
}

// Send speeds
void speed(int speeds[3]) {
  analogWrite(ENA1, speeds[0]);
  analogWrite(ENB1, speeds[1]);
  analogWrite(ENA2, speeds[2]);
  analogWrite(ENB2, speeds[3]);
}

void fullSpeed() {
  digitalWrite(ENA1, HIGH);
  digitalWrite(ENB1, HIGH);
  digitalWrite(ENA2, HIGH);
  digitalWrite(ENB2, HIGH);
}

void fullBrakes() {
  int brakes[4] = {0, 0, 0, 0};
  digitalWrite(SRCLRB, LOW);    // Clear register output
  speed(brakes);
  delay(500);
}
