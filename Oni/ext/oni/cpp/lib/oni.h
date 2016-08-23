#pragma once

#include "ofMain.h"


// Behaves as expected. Rice passes the C++ ofPoint correspoinding to 'self' into the function
float ofVec3f_get_component(ofPoint& p, int i);
void  ofVec3f_set_component(ofPoint& p, int i, float value);
