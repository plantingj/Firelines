#include <RGBdriver.h>

//interrupt pins
int interruptPin[] = {2, 3, 18, 19, 20, 21};
#include <Servo.h>

Servo pen, eraser1, eraser2;
int raty,ratx;
bool drawMap=false;
bool teken = false;
bool prev = false;
int vierkant = 100;
int vkant;
float decimal;
const int CLK = 35;
const int DIO = 34;


unsigned long previousMillis = 0;
const long interval = 1000;
//Motors x
const int stepPinX1 = 7;
const int dirPinX1 = 6;
const int stepPinX2 = 9;
const int dirPinX2 = 8;
int i_hor = 0;
//Motors y
const int stepPinY1 = 5;
const int dirPinY1 = 4;
int i_vert = 0;
int motPosX, motPosY, posNewX, posNewY;


volatile byte state = LOW;
int stepsToDoHor = 0;
int stepsToDoVert = 0;
int motorDelay = 20;
bool limitSwitchLinksTop = false;
bool limitSwitchRechtsTop = false;
bool limitSwitchLinksBot = false;
bool limitSwitchRechtsBot = false;
bool limitSwitchBoven = false;
bool limitSwitchOnder = false;
bool horFinish = true;
bool vertFinish = true;
bool returned = true;
bool sendR = false;

bool Ksend = false;
bool allDone = true;
bool plotFinish = false;
bool newPos = false;
bool firstPos = false;
bool meld = false;

int penOff = 65;
int penOn = 75;

//SERIAL
String inputString = "";
boolean stringComplete = false;
char charBuf[1];

void setup() {
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pen.attach(10);
  pen.write(penOn);
  // Sets the two pins as Outputs
  pinMode(stepPinX1, OUTPUT);
  pinMode(dirPinX1, OUTPUT);
  pinMode(stepPinX2, OUTPUT);
  pinMode(dirPinX2, OUTPUT);
  pinMode(stepPinY1, OUTPUT);
  pinMode(dirPinY1, OUTPUT);
  Serial.begin(115200);
  //  initLimitSwitch();
  limit_setup();
  eraserSetup();
  inputString.reserve(200);
  motPosY = 0;
  motPosX = 0;
  white();
}

void loop() {
//  Serial.println(drawMap);
//  stift();
    if (!firstPos) pen.write(penOff);
  if (firstPos) pen.write(penOn);
  limit();
  serialCheck();
  if (newPos)  motors();
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
