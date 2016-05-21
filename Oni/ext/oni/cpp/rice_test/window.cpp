// this file is just a sketch, to show the general outline of this program



// creates an instance of App, and executes it

launcher::launcher(){
	ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
}

launcher::initialize(){
	// TODO: save 'mApp' as a member variable on the 'launcher' class
	ofApp mApp = new ofApp();
}

launcher::show(){
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(mApp);
}

extern "C"

// using void pointers here, because this code must display a C interface.
// HOWEVER, the 'app' pointer will actually be a C++ type.

// callback structure taken from Oni/ext/oni/window.c
static void cb_app_setup(void* app){
	// example function call
	// rb_funcall((VALUE)rb_window, rb_intern("button_down"), 1, INT2NUM(key_id));
}

static void cb_app_update(void* app){
	
}

static void cb_app_draw(void* app){
	
}










// main object used by openFrameworks

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();
	cb_app_setup(&this); // cb is for 'callback'
}

//--------------------------------------------------------------
void ofApp::update(){
	cb_app_update(&this);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);  // Clear the screen with a black color
	ofSetColor(255);  // Set the drawing color to white
	
	// Draw some shapes
	ofDrawRectangle(50, 50, 100, 100); // Top left corner at (50, 50), 100 wide x 100 high
	ofDrawCircle(250, 100, 50); // Centered at (250, 100), radius of 50
	ofDrawEllipse(400, 100, 80, 100); // Centered at (400 100), 80 wide x 100 high
	ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corners: (500, 150), (550, 50), (600, 150)
	ofDrawLine(700, 50, 700, 150); // Line from (700, 50) to (700, 150)
	
	cb_app_draw(&this);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLog() << key; // use this instead of using std::out
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}





//      _________    __    __    ____  ___   ________ _______
//	   / ____/   |  / /   / /   / __ )/   | / ____/ //_/ ___/
//	  / /   / /| | / /   / /   / __  / /| |/ /   / ,<  \__ \ 
//	 / /___/ ___ |/ /___/ /___/ /_/ / ___ / /___/ /| |___/ / 
//	 \____/_/  |_/_____/_____/_____/_/  |_\____/_/ |_/____/  

// the purpose of these callbacks is just to call ruby-level functions
// any C/C++ code can be mixed into the lines above

extern "C"

// using void pointers here, because this code must display a C interface.
// HOWEVER, the 'app' pointer will actually be a C++ type.

// callback structure taken from Oni/ext/oni/window.c
static void cb_app_setup(void* app){
	// example function call
	// rb_funcall((VALUE)rb_window, rb_intern("button_down"), 1, INT2NUM(key_id));
}

static void cb_app_update(void* app){
	
}

static void cb_app_draw(void* app){
	
}

