// #include "ofMain.h"
// #include "ofGraphics.h"

#include "launcher.h"
#include "window.h"

#include <iostream>


Launcher::Launcher(Rice::Object self){
	cout << "c++: constructor - launcher\n";
	
	ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
	
	mWindow = new OniWindow(self);
}

Launcher::~Launcher(){
	// delete mApp;
}


// NOTE: If you explictly define a method called #initiailze, then the C++ constructor wrapper used by Rice will not work correctly. Initializaiton must happen in the constructor.


void Launcher::show(){
	cout << "c++: Launcher::show()\n";
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mWindow);
}



// --- graphics functions

void Launcher::DrawRectangle(float x,float y,float z,float w,float h){
	ofDrawRectangle(x,y,z,w,h);
}

void Launcher::DrawCircle(float x, float y, float z, float radius){
	ofDrawCircle(x, y, radius);
}

void Launcher::DrawEllipse(float x, float y, float z, float width, float height){
	ofDrawEllipse(x, y, z, width, height);
}

void Launcher::DrawTriangle(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3){
	ofDrawTriangle(x1,y1,z1,x2,y2,z2,x3,y3,z3);
}

void Launcher::DrawLine(float x1,float y1,float z1,float x2,float y2,float z2){
	ofDrawLine(x1,y1,z1,x2,y2,z2);
}





void Launcher::Background(int r, int g, int b, int a){
	ofBackground(r, g, b, a);
}

void Launcher::BackgroundHex(int hexColor, int alpha){
	ofBackgroundHex(hexColor, alpha);
}



void Launcher::SetColor(int r, int g, int b, int a){
	ofSetColor(r, g, b, a);
}

void Launcher::SetHexColor(int hexColor){
	ofSetHexColor(hexColor);
	// NOTE: SetHexColor doesn't allow for alpha value. 
	// maybe define a custom version here that does use alpha?
}


// ofPushStyle
// ofPushMatrix
// ofPopMatrix
// ofPopStyle


// ---------------------------------------------------
