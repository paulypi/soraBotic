
// Connection to 74LS595
const int ser = 2;
const int srclk = 3;
const int rclk = 4;
// Set emergency clear pin
const int srclrb = 9;

// Connection to MotorDriver1

// Connection to MotorDriver2

void setup() {
  // 74LS595
  pinMode(rclk, OUTPUT);
  pinMode(srclk, OUTPUT);
  pinMode(ser, OUTPUT);
  pinMode(srclrb, OUTPUT);
  // Setup clear status
  digitalWrite(srclrb, HIGH);

  // MotorDriver1

  // MotorDriver2
}

// Send directions trought 74LS595
void send(int directions) {
  digitalWrite(rclk, LOW);
  shiftOut(ser, srclk, MSBFIRST, directions);
  digitalWrite(rclk, HIGH);
  delay(500);
}

void loop() {
  send(4);
  delay(2000);
  send(15);
  delay(2000);
}
