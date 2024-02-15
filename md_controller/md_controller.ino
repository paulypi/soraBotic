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

// Connection to 74LS595
#define SER 2
#define SRCLK 3
#define RCLK 4
#define SRCLRB 9  // Set emergency clear pin

// Connection to MotorDriver1

// Connection to MotorDriver2

void setup() {
  // 74LS595
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(SRCLRB, OUTPUT);
  // Setup clear status
  digitalWrite(SRCLRB, HIGH);

  // MotorDriver1

  // MotorDriver2
}

// Send directions trought 74LS595
void send(int directions) {
  digitalWrite(RCLK, LOW);
  shiftOut(SER, SRCLK, MSBFIRST, directions);
  digitalWrite(RCLK, HIGH);
  delay(500);
}

void loop() {
  send(N);
  delay(5000);

  send(S);
  delay(5000);

  send(E);
  delay(5000);

  send(O);
  delay(5000);
}
