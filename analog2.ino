unsigned long pulseCount = 0;
unsigned long delayTime = 0;

void readPulse() {
  // The tube has an idle of ~1000 (5V), every hit will
  // cause a reduction to nearly 0 (0V) and slowly go
  // back to ~1000 (5V). Try to find falling edges by
  // waiting until it falls below 100 (0.5V) and then
  // wait until it is back at over 100 (0.5V) to wait
  // again.
  if(analogRead(A0) < 100) {
    pulseCount++;
    while(analogRead(A0) < 100) {}
  }
}

void writePulse() {
  // Write and reset the tube pulse count every
  // 600s to get nSv/h (approximately for this
  // tube, it is not calibrated yet).
  Serial.println(pulseCount);
  pulseCount = 0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  readPulse();
  if(Serial.available() > 0) {
    while(Serial.read() >= 0) {}
    writePulse();
  }
}
