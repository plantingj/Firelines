void draw_map(char s) {
  if (p==pointPaths.length) {
    //myPort.write("HELEMAAL KLAAR\n");
  }
  if (p!=pointPaths.length) {
    if (j==pointPaths[p].length) {
      println("KLAAR");
      myPort.write("KLAAR\n");
      j=0;
      s='z';
      request= 'z';
    }
  }
  if (s=='C') {
    if (p!=pointPaths.length) {
      myPort.write("C"+str(map(pointPaths[p][j].x, 5, 1195, 0, 3500))+";"+str(map(pointPaths[p][j].y, 134, 1655, 0, 4200)) +"\n");
      s='z';
      request = 'z';
      j++;
    }
  }

  if (s=='K') {
    p++;
    println("Writing 'I' over serial connection...");
    myPort.write("I\n");
    s='z';
    request= 'z';
  }
}