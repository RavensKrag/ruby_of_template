#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

#include "ofMain.h"
#include "ofApp.h"

#include "window.h"


OniWindow::OniWindow(Rice::Object self) : 
	ofApp()
{
	cout << "c++: constructor - window\n";
	
	// ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
	mSelf = self;
}

OniWindow::~OniWindow(){
	
}

void OniWindow::setup(){
	ofApp::setup();
	
	mSelf.call("setup");
}

void OniWindow::update(){
	ofApp::update();
	
	mSelf.call("update");
}

void OniWindow::draw(){
	ofApp::draw();
	
	mSelf.call("draw");
}


void OniWindow::keyPressed(int key){
	// Something seems to be consuming most keyboard events
	// when the application is started via the Ruby layer in Rake.
	// 
	// That problem prevents this funciton from being called,
	// and also prevents the app from closing when ESC is pressed,
	// like normal ofApp windows do
	// (including the window you get when you execute just the C++ layer of this very project)
	
	ofApp::keyPressed(key);
	
	
	ofLog() << key;
}

void OniWindow::keyReleased(int key){
	ofApp::keyReleased(key);
}

void OniWindow::mouseMoved(int x, int y ){
	ofApp::mouseMoved(x,y);
}

void OniWindow::mouseDragged(int x, int y, int button){
	ofApp::mouseDragged(x,y,button);
}

void OniWindow::mousePressed(int x, int y, int button){
	ofApp::mousePressed(x,y,button);
}

void OniWindow::mouseReleased(int x, int y, int button){
	ofApp::mouseReleased(x,y,button);
}

void OniWindow::mouseEntered(int x, int y){
	ofApp::mouseEntered(x,y);
}

void OniWindow::mouseExited(int x, int y){
	ofApp::mouseExited(x,y);
}

void OniWindow::windowResized(int w, int h){
	ofApp::windowResized(w,h);
}

void OniWindow::dragEvent(ofDragInfo dragInfo){
	ofApp::dragEvent(dragInfo);
}

void OniWindow::gotMessage(ofMessage msg){
	ofApp::gotMessage(msg);
}

