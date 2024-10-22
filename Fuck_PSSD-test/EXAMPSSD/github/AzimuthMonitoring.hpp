//Received 100/100

#ifndef AZIMUTHMONITORING_HPP
#define AZIMUTHMONITORING_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class AzimuthMonitoring {
    
    public:

        int seperateCoords(string inst) { //This function is not mine. I have taken it from 
            stringstream ss;              //https://www.geeksforgeeks.org/extract-integers-string-c/
            ss << inst;                   //this is because I could not find a way to extract strings
            string temp;                  //from the vector. I do not take any credibility for this.
            int found;
            while(!ss.eof()) {
                ss >> temp;
                if(stringstream(temp) >> found) {
                    return found;
                }
            }
        }

        int getAzimuth(vector<string> instructions) {
                   
            int angle=0;

            for(int i=0; i<instructions.size(); i++) {

                if(instructions[i] == "HALT") {
                    break;
                } else 
                    if(instructions[i] == "LEFT") {
                        angle = angle - 90;
                    } else 
                        if(instructions[i] == "RIGHT") {
                            angle = angle + 90;
                        } else 
                            if(instructions[i] == "TURN AROUND") {
                                angle = angle + 180;
                            } else 
                                if (instructions[i][4] == ' ') { //checking for a whitespace on the 5th index as L E F T __, 
                                    angle = angle - seperateCoords(instructions[i]); //the underscore represents the whitespace which can help detect the LEFT kewyword
                                } else 
                                    if(instructions[i][5] == ' ') { //checking for a whitespace on the 6th index as R I G H T __, 
                                        angle = angle + seperateCoords(instructions[i]); //the underscore represents the whitespace which can help detect the RIGHT kewyword
                                    }

            }
            
            int someAngle=0;
            while(angle<0) {
                someAngle = 360+angle;
                angle = someAngle;
            }
            while(angle>=360) {
                angle = angle - 360;
            }
            

        return angle;
        }
};

#endif