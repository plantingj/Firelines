void draw_messages(char s) {
  if (id>nrOfRows) {
    nrOfRows++;
    myPort.write("M\n");
  }
  if (s=='W') {
    if (drawFirst) {
      myPort.write("V"+location.get(id-1).x+";"+location.get(id-1).y+"\n");
      s='z';
      request= 'z';
      drawFirst=false;
    } else {
      myPort.write("F"+previous.x+";"+previous.y+"\n");
    }
  }
  if (s=='V') {
    myPort.write("V"+location.get(id-1).x+";"+location.get(id-1).y+"\n");
    s='z';
    request= 'z';
  }

  if (s=='Q') {
    myPort.write("EERKANT\n");
    s='z';
    request='z';
  }

  if (s=='E') {
    myPort.write("KLAAR\n");
    s='z';
    request='z';
  }
}