#include "Arduino.h"
#include "TestHex.h"


#include "udf.h"
#include "functions.h"

TestHex::TestHex(short id) 
{
  _id = id;
}

//3D| Name : S(cube/sphere) : P:px:py:pz : R:rx:ry:rz : C:color_name 
void TestHex::teleplot3D(String shape,String shapeName, short shapePosition[], short shapeRotation[], String shapeColor){
  String serial3D = "3D|"+ shapeName +":S:"+ shape +":R:" +String(shapeRotation[0])+ ":" +String(shapeRotation[1])+ ":" +String(shapeRotation[2])+":P:"+ String(shapePosition[0]) + ":" +String(shapePosition[1])+ ":" +String(shapePosition[2])+ ":C:" +shapeColor;
  Serial.print(textToBinary("3"));
  Serial.print(" ");
  Serial.println(textToBinary(serial3D));
}

void TestHex::convert(short sensorValue,String axis,short dataID)
{
  udf sensor;
  int counter = 0;
  int length = sizeof(sensor.sensorID)/sizeof(sensor.sensorID[0]);

  for(int i=0;i< length;i++){
    if (_id == sensor.sensorID[i]) {counter = i;break;}
  }

  String hex0 = (String(dataID));
  String hex1 = (String(sensor.sensorID[counter]));
  String hex2 = (sensor.sensorName[counter] + '-' +axis);
  String hex3 = (String(sensor.eventSize[counter]));
  String hex4 = (sensor.parseFormat[counter]);
  String hex5 = (sensor.axisNames[counter]);
  String hex6 = (sensor.scalingFactor[counter]);
  String hex7 = (String(sensorValue));

  if(dataID == 0){
    // we are just sending normal data 
    String serialData = hex1 + " " + hex2 + " " + hex3 + " " + hex4 + " " + hex5 + " " + hex6 + " " + hex7;
    Serial.print(textToBinary("1"));
    Serial.print(" ");
    Serial.println(textToBinary(serialData)); 
  } else {
    // we are sending console data  
    String serialConsole = ":The data being sent is from sensor ->" + hex2 + " ->" + hex7;
    Serial.print(textToBinary("2"));
    Serial.print(" ");
    Serial.println(textToBinary(serialConsole));
  }
}
