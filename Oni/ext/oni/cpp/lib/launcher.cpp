// #include "ofMain.h"
// #include "ofGraphics.h"

#include "launcher.h"
#include "app.h"

#include <iostream>


Launcher::Launcher(Rice::Object self){
	cout << "c++: constructor - launcher\n";
	
	// ofAppGlutWindow mWindow;
	mWindow = new ofAppGlutWindow();
		// Glut window seems to get keyboard input just fine.
		// It seems to break the existing implementation of Ruby-level window closing,
		// but the Ruby-level close callback is still being called, so that's good.
	
	ofSetupOpenGL(mWindow, 1024,768,OF_WINDOW); // <-------- setup the GL context
	
	mApp = new OniApp(self);
	// TODO: rename 'mWindow' to 'app'
	
	// window is the drawing context
	// app is the thing that holds all the update and render logic
	
	// oF defines different types of windows that can be used, and I want to try the GLFW one
	// (GLFW window appears to be the default, actually)
	
	
	
	// ofAppRunner.cpp   : ofSetupOpenGL
	// ofAppRunner.cpp   : ofCreateWindow
		// ofInit();
		// mainLoop()->createWindow(settings);
	
	// ofMainLoop.cpp:43 : ofMainLoop::createWindow
		// shared_ptr<ofAppGLFWWindow> window =
		// shared_ptr<ofAppGLFWWindow>(new ofAppGLFWWindow());
	// and various other types of windows
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
	ofRunApp(mApp);
}


void Launcher::hideCursor(){
	mWindow->hideCursor();
}

void Launcher::showCursor(){
	mWindow->showCursor();
}

void Launcher::setFullscreen(bool fullScreen){
	mWindow->setFullscreen(fullScreen);
}

void Launcher::toggleFullscreen(){
	mWindow->toggleFullscreen();
}

void Launcher::setWindowTitle(std::string title){
	mWindow->setWindowTitle(title);
}

void Launcher::setWindowPosition(int x, int y){
	mWindow->setWindowPosition(x,y);
}

void Launcher::setWindowShape(int w, int h){
	mWindow->setWindowShape(w,h);
}

void Launcher::setWindowIcon(const std::string path){
	// mWindow->setWindowIcon(path); // this method is private. not sure what to do about that.
}


ofPoint Launcher::getWindowPosition(){
	return mWindow->getWindowPosition();
}

ofPoint Launcher::getWindowSize(){
	return mWindow->getWindowSize();
}

ofPoint Launcher::getScreenSize(){
	return mWindow->getScreenSize();
}


// ---------------------------------------------------
