void limit_setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(interruptPin[i], INPUT);
  }
}

void limit() {
  //  Serial.println(digitalRead(interruptPin[5]));
  for (int i = 0; i < 6; i++) {
    if (digitalRead(interruptPin[i]) == 1 ) {
      if (i == 0) {
        limitSwitchOnder = true;
      }
      if (i == 1) {
        limitSwitchBoven = true;
//        if (!reset1) {
//          i_vert = 0;
//          stepsToDoVert = 0;
//          motPosY = 0;
//          posNewY = 0;
//          newPos = false;
//          Serial.println("POSITIE BEREIKT");
//          reset1 = true;
//        }
      }
      if (i == 2) {
        limitSwitchRechtsBot = true;
      }
      if (i == 3) {
        limitSwitchLinksBot = true;
//        if (!reset2) {
//          i_hor = 0;
//          stepsToDoHor = 0;
//          motPosX = 0;
//          posNewX = 0;
//          newPos = false;
//          Serial.println("POSITIE BEREIKT");
//          reset2 = true;
//        }
      }
      if (i == 4) {
        limitSwitchRechtsTop = true;
      }
      if (i == 5) {
        limitSwitchLinksTop = true;
//        if (!reset2) {
//          i_hor = 0;
//          stepsToDoHor = 0;
//          motPosX = 0;
//          posNewX = 0;
//          newPos = false;
//          Serial.println("POSITIE BEREIKT");
//          reset2 = true;
//        }
      }
    }
    if (digitalRead(interruptPin[i]) == 0 ) {
      if (i == 0) {
        limitSwitchOnder = false;
      }
      if (i == 1) {
        limitSwitchBoven = false;
      }
      if (i == 2) {
        limitSwitchRechtsBot = false;
      }
      if (i == 3) {
        limitSwitchLinksBot = false;
      }
      if (i == 4) {
        limitSwitchRechtsTop = false;
      }
      if (i == 5) {
        limitSwitchLinksTop = false;
      }
    }
  }
}



