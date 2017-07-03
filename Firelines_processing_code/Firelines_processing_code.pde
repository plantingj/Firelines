import processing.serial.*;
import geomerative.*;
import de.bezier.data.sql.*;
MySQL dbconnection;
ArrayList<PVector> location = new ArrayList<PVector>();
ArrayList<PVector> idprio = new ArrayList<PVector>();
PVector previous;
float rdMaxX, rdMinX, rdMaxY, rdMinY, nlMaxX, nlMinX, nlMaxY, nlMinY; 
int id, ellipseSize;
boolean first, empty, drawFirst;
RShape grp;
RPoint[][] pointPaths;
Serial myPort;
char val;
String val2;
boolean kak = true;
String ser;
int j=0;
int p=-1;
int arraySize = 90;
boolean readyForNew;

int nrOfRows, nrOfRowsNew;

char request;
int lf = 10;      // ASCII linefeed 
String inString;  // Input string from serial port

void setup() {
  //frameRate(1);
  size(800, 800, P3D);
  rdMaxX = 278013;
  rdMinX = 13557;
  rdMaxY = 615084;
  rdMinY = 306877;
  //nlMaxX = 753.4138;
  //nlMinX = 43.50278;
  //nlMaxY = 866.53973;
  //nlMinY = 31.769775;
  nlMaxX = 1600;
  nlMinX = 0;
  nlMaxY = 1800;
  nlMinY = 0;
  first = true;
  empty = true;
  drawFirst = true;
  readyForNew = true;
  // VERY IMPORTANT: Allways initialize the library before using it
  RG.init(this);
  RG.setPolygonizer(RG.ADAPTATIVE);
  grp = RG.loadShape("nederland5.svg");

  pointPaths = grp.getPointsInPaths();
  String user     = "sierdmei";
  String pass     = "Xhw23B01ms";
  String database = "sierdmei_p2000";
  //String table    = "";
  dbconnection = new MySQL( this, "sierdmeijer.nl", database, user, pass );
  nrOfRows = db_empty_check();
  database_connect();

  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 115200);
  myPort.bufferUntil(lf);
}

void draw() {
  background(255);
  stroke(0);
  noFill();



  if (p>-1)  draw_map(request);
  database_connect();
  draw_messages(request);
}

void mousePressed() {
  if (p<pointPaths.length-1) {
    p++;
    println("Writing 'I' over serial connection...");
    myPort.write("I\n");
  }
}

void serialEvent(Serial p) { 
  inString = p.readString(); 
  request = inString.charAt(0);
  if (inString.length()>0) {
    println("Received: "+inString);
  }
  if (request=='K') {
    readyForNew = true;
  }
} 