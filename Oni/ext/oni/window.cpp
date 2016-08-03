#include "ofMain.h"
#include "ofApp.h"

#include "window.h"


OniWindow::OniWindow() : 
	ofApp()
{
	cout << "c++: constructor - window\n";
	
	// NOTE: constructor is not being called. This is what prevents the window from being opened
	
	ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
	
	
	// TODO: save 'mApp' as a member variable on the 'Launcher' class
	// mApp = new ofApp();
}

OniWindow::~OniWindow(){
	
}

void OniWindow::setup(){
	ofApp::setup();
}

void OniWindow::update(){
	ofApp::update();
}

void OniWindow::draw(){
	ofApp::draw();
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

