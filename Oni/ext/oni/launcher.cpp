// #include "ofMain.h"
#include "launcher.h"
// #include "ofMain.h"
// #include "ofApp.h"
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
