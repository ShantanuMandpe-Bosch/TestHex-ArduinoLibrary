#ifndef TestHex_h
#define TestHex_h

#include "Arduino.h"

class TestHex
{
  public:
    TestHex(short id);
    void convert(short sensorValue, String axis, short dataID);
    void teleplot3D(String shape,String shapeName, short shapePosition[], short shapeRotation[], String shapeColor);
  private:
    short _id;
};

#endif
 
