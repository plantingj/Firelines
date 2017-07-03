void serialCheck() {
  if ((limitSwitchBoven) && (limitSwitchLinksTop) && (limitSwitchLinksBot) && (!sendR) && (!meld)) {
    Serial.write("R\n");
    sendR = true;
  }
  if ((!limitSwitchBoven) && (!limitSwitchLinksTop) && (!limitSwitchLinksBot) && (sendR)) {
    sendR = false;
  }
  if (stringComplete) {
    inputString.toCharArray(charBuf, 2);
    if (charBuf[0] == 'M') {
      Serial.print("M\n");
      melding();
      meld = true;
      ratx = 1;
      raty = 1;
      drawMap = true;
      firstPos = false;
      returned = false;
      plotFinish = false;
      allDone = false;
      Serial.write("W\n");
    }
    if (charBuf[0] == 'I') {
      meld = false;
      ratx = 1;
      raty = 1;
      drawMap = true;
      firstPos = false;
      returned = false;
      plotFinish = false;
      allDone = false;
      Serial.write("C\n");
    }
    if (charBuf[0] == 'C') {
      next_val();
    }
    if (charBuf[0] == 'A') pen.write(penOn);
    if (charBuf[0] == 'B') pen.write(penOff);
    if (charBuf[0] == 'K') {
      returned = true;
      firstPos = false;
      plotFinish = true;
      pen.write(penOff);
      posNewX = 0;
      posNewY = 0;
      stepsToDoHor = posNewX - motPosX;
      stepsToDoVert = posNewY - motPosY;
      newPos = true;
      meld = false;
    }
    if (charBuf[0] == 'H') {
      returned = true;
      firstPos = false;
      plotFinish = true;
      pen.write(penOff);
      posNewX = 0;
      posNewY = 0;
      stepsToDoHor = posNewX - motPosX;
      stepsToDoVert = posNewY - motPosY;
      newPos = true;
      allDone = true;
      drawMap = false;
    }

    //P2000 MELDINGEN
    if (charBuf[0] == 'V') {
      Serial.println("V IS OOK BINNEN\n");
      prev = false;
      next_val();
    }
    if (charBuf[0] == 'E') {
      teken = true;
      newPos = true;
      returned = false;
      posNewY = posNewY - (vierkant/2);
      posNewX = posNewX-(vierkant/2);
      stepsToDoHor = posNewX - motPosX;
      stepsToDoVert = posNewY - motPosY;
      Ksend = false;
      vkant = 1;
      previousMillis = millis();
    }

    if (charBuf[0] == 'F') {
      prev = true;
      next_val();
    }



    stringComplete = false;
    inputString = "";
  }


  if ((returned) && (motPosX < 1) && (motPosY < 1) && (!allDone)) {
    if (!Ksend) {
      Serial.write("K\n");
      Ksend = true;
    }
  }
}


void next_val() {
  //  Serial.println(meld);
  newPos = true;
  returned = false;
  String s = inputString.substring(1);
  //  Serial.println("LALALA jorik\n");
  //  Serial.print(s);
  //  Serial.print("\n");
  for (int i = 0; i < s.length(); i++) {
    if (s.substring(i, i + 1) == ";") {
      posNewX = s.substring(0, i + 1).toInt();
      posNewY = s.substring(i + 1).toInt();
      stepsToDoHor = posNewX - motPosX;
      stepsToDoVert = posNewY - motPosY;
      if (!drawMap) {
        ratios();
      }
      break;
    }
  }
  Ksend = false;
}
void ratios() {
  if ((stepsToDoHor != 0) && (stepsToDoVert != 0)) {
    if (stepsToDoHor > stepsToDoVert) {
      float ratio = (float)stepsToDoHor / (float)stepsToDoVert;

      raty = (int)ratio;
      if (raty < 0) {
        raty = raty * -1;
      } else if (raty < 1) {
        raty = 1;
      }
      stepsToDoVert = stepsToDoVert * raty;
      decimal =  getDecimal(ratio);
    } else if (stepsToDoVert > stepsToDoHor) {
      float ratio = (float)stepsToDoVert / (float)stepsToDoHor;
      ratx = (int)ratio;
      if (ratx < 0) {
        ratx = ratx * -1;
      } else if (ratx < 1) {
        ratx = 1;
      }
      stepsToDoHor = stepsToDoHor * ratx;
      decimal =  getDecimal(ratio);
    }
  } else {
    ratx = 1;
    raty = 1;
  }
}
float getDecimal(float val) {
  float d = val - ratx;
  return d;
}


