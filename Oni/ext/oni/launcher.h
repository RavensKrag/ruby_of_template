#pragma once

#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

// This header will be included in the C++ Rice level.
// It should NOT pull in ANY oF headers.
// Those symbols will be in the static library, so it be fine once it gets to the linker.
// But we must trick the compiler.
// (similar to resolution of cylic dependencies)
// src: http://stackoverflow.com/questions/2133250/does-not-name-a-type-error
class OniWindow;




class Launcher
{

public:
    Launcher(Rice::Object self);
    ~Launcher(void);
    
    void initialize();
	void show();
	
	
	
	// NOTE: can't use the 'of' prefix for this interface, because it confuses the C++ compiler / linker when it tries to resolve the member functions of this class vs the original functions.
	
	void DrawRectangle(float x,float y,float z,float w,float h);
	void DrawCircle(float x, float y, float z, float radius);
	void DrawEllipse(float x, float y, float z, float width, float height);
	void DrawTriangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3);
	void DrawLine(float x1,float y1,float z1,float x2,float y2,float z2);
	
	
	// void ofDrawRectangle(float x,float y,float z,float w,float h);
	// void ofDrawCircle(float x, float y, float z, float radius);
	// void ofDrawEllipse(float x, float y, float z, float width, float height);
	// void ofDrawTriangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3);
	// void ofDrawLine(float x1,float y1,float z1,float x2,float y2,float z2)
	
	
	// ofDrawRectRounded
	// ofDrawCurve
	// ofDrawBezier // <-- this one is pretty complicated. check it out. it's kinda cool.
	
	
	
	void Background(int r, int g, int b, int a);
	void BackgroundHex(int hexColor, int alpha);
	
	void SetColor(int r, int g, int b, int a);
	void SetHexColor(int hexColor);
	// void ofBackgroundHex(int hexColor, int alpha);
	// void ofBackground(int r, int g, int b, int a);
	
	// void ofSetColor(int r, int g, int b, int a);
	// void ofSetHexColor(int hexColor);



protected:
	OniWindow* mWindow;
};

