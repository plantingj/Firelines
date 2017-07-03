void motors() {
  //   // DRAAI NAAR LINKS
  if (stepsToDoHor < 0) {
    horFinish = false;
    digitalWrite(dirPinX1, LOW);
    digitalWrite(dirPinX2, HIGH);
    if (i_hor < (stepsToDoHor * -1)) {
      if ((stepsToDoHor != 0) && (!limitSwitchLinksTop)) {
        motor_hor_top_step();
        motPosX--;
      }
      if ((stepsToDoHor != 0) && (!limitSwitchLinksBot)) {
        motor_hor_bot_step();
      }
    }
  }
  // DRAAI NAAR RECHTS
  if (stepsToDoHor > 0) {
    horFinish = false;
    digitalWrite(dirPinX1, HIGH);
    digitalWrite(dirPinX2, LOW);
    if (i_hor < stepsToDoHor) {
      if ((stepsToDoHor != 0) && (!limitSwitchRechtsTop)) {
        motor_hor_top_step();
        motPosX++;
      }
      if ((stepsToDoHor != 0) && (!limitSwitchRechtsBot)) {
        motor_hor_bot_step();
      }
    }
  }
  if (stepsToDoVert < 0) {
    vertFinish = false;
    digitalWrite(dirPinY1, LOW);
    if (i_vert < (stepsToDoVert * -1)) {
      if ((stepsToDoVert != 0) && (!limitSwitchBoven)) {
        motor_vert_step();
        motPosY--;
      }
    }
  }
  if (stepsToDoVert > 0) {
    vertFinish = false;
    digitalWrite(dirPinY1, HIGH);
    if (i_vert < stepsToDoVert + 1) {
      if ((stepsToDoVert != 0) && (!limitSwitchOnder)) {
        motor_vert_step();
        motPosY++;
      }
    }
  }




  if (stepsToDoHor != 0)  i_hor++;
  if (stepsToDoVert != 0) i_vert++;
  if ((stepsToDoHor == i_hor) || (stepsToDoHor * -1 == i_hor)) {
    i_hor = 0;
    stepsToDoHor = 0;
    horFinish = true;
  }
  if ((stepsToDoVert == i_vert) || (stepsToDoVert * -1 == i_vert)) {
    i_vert = 0;
    stepsToDoVert = 0;
    vertFinish = true;
  }
  if ((horFinish) && (vertFinish)) {
    newPos = false;
    if (!returned) firstPos = true;
    //    Serial.println("POSITIE BEREIKT\n");
    if (!plotFinish) {
      //      delay(2000);
      if (!meld) Serial.write("C\n");
      if (meld) {
        if (prev) Serial.write("V\n");
        if ((!prev) && (!teken)) Serial.write("Q\n");
        if (teken) {
          while (true) {
            if (vkant == 1 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 2 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY + vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 3 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 4 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY - vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
                       if (vkant == 5 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 6 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY + vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 7 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 8 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY - vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
                       if (vkant == 9 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 10 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY + vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 11 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 12 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY - vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
                       if (vkant == 13 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 14 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY + vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 15 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 16 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY - vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
                       if (vkant == 17 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 18 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY + vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 19 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewX = posNewX + (vierkant / 10);
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 20 ) {
              teken = true;
              newPos = true;
              returned = false;
              posNewY = posNewY - vierkant;
              stepsToDoHor = posNewX - motPosX;
              stepsToDoVert = posNewY - motPosY;
              Ksend = false;
            }
            if (vkant == 21) {
              teken = false;
              Serial.write("E\n");
            }
            vkant++;
            break;
          }
        }
      }
    }
  }
}

