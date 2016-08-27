#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"
#include "rice/Array.hpp"

#include "ofMain.h"
#include "ofApp.h"

#include "app.h"


OniApp::OniApp(Rice::Object self) : 
	ofApp()
{
	cout << "c++: constructor - window\n";
	
	// ofSetupOpenGL(1024,768,OF_WINDOW); // <-------- setup the GL context
	mSelf = self;
}

OniApp::~OniApp(){
	
}

void OniApp::setup(){
	ofApp::setup();
	
	mSelf.call("setup");
}

void OniApp::update(){
	ofApp::update();
	
	mSelf.call("update");
}

void OniApp::draw(){
	ofApp::draw();
	
	mSelf.call("draw");
}

void OniApp::exit(){
	// ofApp::exit(); // no parent behavior for exit callback defined
	cout << "c++: exit\n";
	
	mSelf.call("on_exit");
}


void OniApp::keyPressed(int key){
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

void OniApp::keyReleased(int key){
	ofApp::keyReleased(key);
}

void OniApp::mouseMoved(int x, int y ){
	ofApp::mouseMoved(x,y);
	
	mSelf.call("mouse_moved", x,y);
}

void OniApp::mouseDragged(int x, int y, int button){
	ofApp::mouseDragged(x,y,button);
	
	mSelf.call("mouse_dragged", x,y, button);
}

void OniApp::mousePressed(int x, int y, int button){
	ofApp::mousePressed(x,y,button);
	
	mSelf.call("mouse_pressed", x,y, button);
}

void OniApp::mouseReleased(int x, int y, int button){
	ofApp::mouseReleased(x,y,button);
	
	mSelf.call("mouse_released", x,y, button);
}

void OniApp::mouseEntered(int x, int y){
	ofApp::mouseEntered(x,y);
	
	mSelf.call("mouse_entered", x,y);
}

void OniApp::mouseExited(int x, int y){
	ofApp::mouseExited(x,y);
	
	mSelf.call("mouse_exited", x,y);
}

void OniApp::windowResized(int w, int h){
	ofApp::windowResized(w,h);
	
	mSelf.call("window_resized", w,h);
}

void OniApp::dragEvent(ofDragInfo dragInfo){
	// NOTE: drag event example works with Nautilus, but not Thunar (GLFW window)
	
	// https://github.com/openframeworks/openFrameworks/issues/1862
	// ^ this issue explains that Glut windows can not process file drag events on Linux
	
	ofApp::dragEvent(dragInfo);
	
	
	// NOTE: dragInfo.files is a std::vector, not an array. Apparently, Rice doesn't understand how to convert that into a Ruby array? so I guess that needs to be done manually...
	
	// ./test.rb:190:in `show': Unable to convert std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >* (ArgumentError)
	
	Rice::Array filepaths;
	
	for(std::__cxx11::basic_string<char>& e : dragInfo.files){
		filepaths.push(to_ruby(e));
	}

	mSelf.call("drag_event", filepaths, dragInfo.position);
}

void OniApp::gotMessage(ofMessage msg){
	ofApp::gotMessage(msg);
	
	// mSelf.call("got_message", msg);
}

