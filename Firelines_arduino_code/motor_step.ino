void motor_vert_step() {
  for (int i = 0; i < (16/raty); i++) {
    digitalWrite(stepPinY1, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(stepPinY1, LOW);
    delayMicroseconds(motorDelay);
  }
}

void motor_hor_top_step() {
  for (int i = 0; i < (16/ratx); i++) {
    digitalWrite(stepPinX2, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(stepPinX2, LOW);
    delayMicroseconds(motorDelay);
  }
}
void motor_hor_bot_step() {
  for (int i = 0; i < (16/ratx); i++) {
    digitalWrite(stepPinX1, HIGH);
    delayMicroseconds(motorDelay);
    digitalWrite(stepPinX1, LOW);
    delayMicroseconds(motorDelay);
  }
}

