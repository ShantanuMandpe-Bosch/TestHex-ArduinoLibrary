#include "Arduino_BHY2.h"
#include "TestHex.h"

// Sensor XYZ has XYZ data as int16_t/short -> convert to binary
SensorXYZ accelerometer(SENSOR_ID_ACC);
SensorXYZ gyroscope(SENSOR_ID_GYRO);

TestHex testhex(2);

void setup(){
  Serial.begin(115200);
  BHY2.begin();

  accelerometer.begin();
  gyroscope.begin(); 
}

void loop(){
  static auto lastCheck = millis();

  // Update function should be continuously polled
  BHY2.update();
 
  // Check sensor values every second  
  if (millis() - lastCheck >= 1000) {
    lastCheck = millis(); 

    short shapeRotation [] = {gyroscope.x(),gyroscope.y(),gyroscope.z()};
    short shapePosition [] = {0,2,1};

    //convert(short sensorValue,String axis,short dataID)
    testhex.convert(gyroscope.x(),"X",0) ;
    testhex.convert(gyroscope.y(),"Y",0) ;
    testhex.convert(gyroscope.z(),"Z",0) ;
    testhex.convert(gyroscope.x(),"X",1);

    //teleplot3D(String shape,String shapeName, short shapePosition[], short shapeRotation[], String shapeColor)
    testhex.teleplot3D("cube","testHexCube",shapePosition,shapeRotation,"blue");
  }
  
}
