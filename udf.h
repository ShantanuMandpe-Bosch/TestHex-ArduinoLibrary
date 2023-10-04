#ifndef udf_h
#define udf_h

// add sensor defaults to this structure 
typedef struct udf
{
    short sensorID[2] = {1,2} ;
    String sensorName[2] = {"Accelerometer(G)" , "Gyroscope(dps)"};
    short eventSize[2] = {6,6};
    String parseFormat[2] = {"short int","short int"};
    String axisNames[2] = {"x,y,z" , "x,y,z"};
    String scalingFactor[2] = {"0.000488281250000","0.061035156250000"};
}udf;

#endif
