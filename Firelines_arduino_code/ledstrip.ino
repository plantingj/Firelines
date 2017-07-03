RGBdriver Driver(CLK, DIO);


void white() {
  for (int i = 0; i <  255 ; i++) {
    Driver.begin();
    Driver.SetColor(i, i, i); //White fade in
    Driver.end();
  }

}

void melding() {
  int speedBlink = 10;
  int amountBlink = 6;

  for (int i = 255; i > 0 ; i--) {
    Driver.begin();
    Driver.SetColor(i, i, i); //White fade out
    Driver.end();
  }

  for (int j = 0; j < amountBlink ; j++) {
    for (int i = 0; i < 255 ; i = i + speedBlink) {
      Driver.begin();
      Driver.SetColor(i, 0, 0); //Red fade in
      Driver.end();
    }

    for (int i = 255; i > 0 ; i = i - speedBlink) {
      Driver.begin();
      Driver.SetColor(i, 0, 0); //Red fade out
      Driver.end();
    }
  }


  for (int i = 0; i <  255 ; i++) {
    Driver.begin();
    Driver.SetColor(i, i, i); //White fade in
    Driver.end();
  }

}




