#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

// #include "ofMain.h"
#include "launcher.h"
// #include "ofMain.h"
// #include "ofApp.h"
#include "window.h"

#include <iostream>


Launcher::Launcher(){
	cout << "c++: constructor - launcher\n";
	
	// NOTE: constructor is not being called. This is what prevents the window from being opened
	
	// ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
	
	
	// TODO: save 'mApp' as a member variable on the 'Launcher' class
	mWindow = new OniWindow();
}

Launcher::~Launcher(){
	// delete mApp;
}


// NOTE: If you explictly define a method called #initiailze, then the C++ constructor wrapper used by Rice will not work correctly.
// This method can not be bound to Ruby with Rice. Initializaiton must happen in the constructor.
void Launcher::initialize(){
	// cout << "c++: init\n";
	// // NOTE: this is never getting called, thus problems
	// // ok, now initialize is being called, and it just doesn't work
	// // progress? PROGRESS!
	
	// // TODO: save 'mApp' as a member variable on the 'Launcher' class
	// // mApp = new ofApp();
	
	// ofSetupOpenGL(1024,768,OF_WINDOW);
	// ofApp* app_pointer = new ofApp();
	// ofRunApp(app_pointer);
	
	// cout << "c++: init end\n";
}

void Launcher::show(){
	cout << "c++: Launcher::show()\n";
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mWindow);
}
