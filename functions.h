#ifndef functions_h
#define functions_h

#include "Arduino.h"

extern String textToHex(const String &text) ;
extern String shortIntToHex(short value) ;
extern String shortIntToBinary(short value);
extern String textToBinary(const String &text);

#endif