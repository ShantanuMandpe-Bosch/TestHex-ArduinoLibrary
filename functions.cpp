#include "functions.h"
#include "string.h"
#include "Arduino.h"

String shortIntToHex(short value) {
  String hexString = "0x";
  
  if (value < 0) {
    unsigned short uvalue = ~value + 1;
    hexString += String(uvalue, HEX);
  } else {
    hexString += String(value, HEX);
  }

  return hexString;
}

String textToHex(const String &text) {
  String hexString = "";
  char hexChars[] = "0123456789ABCDEF";

  for (size_t i = 0; i < text.length(); i++) {
    char c = text.charAt(i);
    byte highNibble = c >> 4;
    byte lowNibble = c & 0x0F;
    hexString += hexChars[highNibble];
    hexString += hexChars[lowNibble];
  }

  return hexString;
}

String shortIntToBinary(short value) {
  String binaryString = "";
  short numBits = sizeof(value) * 8;

  for (int i = numBits - 1; i >= 0; i--) {
    short bit = bitRead(value, i);
    
    binaryString += String(bit);
  }
  return binaryString;
}

String textToBinary(const String &text) {
  String binaryString = "";

  for (size_t i = 0; i < text.length(); i++) {
    char c = text.charAt(i);
    for (int j = 7; j >= 0; j--) {
      short bit = (c >> j) & 1;
      binaryString += String(bit);
    }
  }

  return binaryString;
}