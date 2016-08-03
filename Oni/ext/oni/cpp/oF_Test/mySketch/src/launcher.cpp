// #include "ofMain.h"
#include "launcher.h"
#include "ofMain.h"
#include "ofApp.h"

#include <iostream>


Launcher::Launcher(){
	cout << "c++: constructor\n";
	ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
}

Launcher::~Launcher(){
	delete mApp;
}

void Launcher::initialize(){
	cout << "c++: init\n";
	// TODO: save 'mApp' as a member variable on the 'Launcher' class
	mApp = new ofApp();
}

void Launcher::show(){
	cout << "c++: show\n";
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mApp);
}
