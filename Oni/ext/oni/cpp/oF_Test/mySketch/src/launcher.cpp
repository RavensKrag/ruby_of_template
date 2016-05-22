// #include "ofMain.h"
#include "launcher.h"
#include "ofMain.h"
#include "ofApp.h"

Launcher::Launcher(){
	ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
}

Launcher::~Launcher(){
	delete mApp;
}

void Launcher::initialize(){
	// TODO: save 'mApp' as a member variable on the 'Launcher' class
	mApp = new ofApp();
}

void Launcher::show(){
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mApp);
}
