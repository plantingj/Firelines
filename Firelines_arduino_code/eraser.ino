void eraserSetup() {
  eraser1.attach(11);
  eraser2.attach(12);
  eraser1.write(160);
  eraser2.write(20);
}

void eraserUp() {
  eraser1.write(160);
  eraser2.write(20);
}

void eraserDown() {
  eraser1.write(115);
  eraser2.write(65);
}
