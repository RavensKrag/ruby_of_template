#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

#include "oni.h"
#include "launcher.h"
#include <iostream>

// #include "ofApp.h"
// #include "ofAppRunner.h"


using namespace Rice;

extern "C"

void Init_oni()
{
	std::cout << "c++: set up module\n";
	Module rb_mOni = define_module("Oni");
	
	
	// ofPoint is the same as ofVec3
	Data_Type<ofPoint> rb_cPoint =
		define_class_under<ofPoint>(rb_mOni, "Point");
	
	rb_cPoint
		.define_constructor(Constructor<ofPoint, float, float, float>())
		.define_method("get_component",   &ofVec3f_get_component)
		.define_method("set_component",   &ofVec3f_set_component)
	;
	
	
	
	
	Data_Type<Launcher> rb_cWindow =
		define_class_under<Launcher>(rb_mOni, "Window");
	
	rb_cWindow
		.define_constructor(Constructor<Launcher, Rice::Object>())
		// .define_method("initialize", &Launcher::initialize)
		.define_method("show",   &Launcher::show)
		.define_method("ofExit", &ofExit,
			(
				Arg("status") = 0
			)
		)
		
		// mouse cursor
		.define_method("show_cursor",       &Launcher::showCursor)
		.define_method("hide_cursor",       &Launcher::hideCursor)
		
		// fullscreen
		.define_method("fullscreen",         &Launcher::setFullscreen)
		.define_method("toggle_fullscreen",  &Launcher::toggleFullscreen)
		
		// window properties
		.define_method("window_title=",       &Launcher::setWindowTitle)
		.define_method("set_window_position", &Launcher::setWindowPosition)
		.define_method("set_window_shape",    &Launcher::setWindowShape)
		.define_method("window_position",     &Launcher::getWindowPosition)
		.define_method("window_size",         &Launcher::getWindowSize)
		.define_method("screen_size",         &Launcher::getScreenSize)
		// .define_method("set_window_icon",     &Launcher::setWindowIcon) // private C++ method
		
		
		// colors
		.define_method("ofBackground",       &Launcher::Background)
		.define_method("ofBackgroundHex",    &Launcher::BackgroundHex)
		.define_method("ofSetColor",         &Launcher::SetColor)
		.define_method("ofSetHexColor",      &Launcher::SetHexColor)
		
		// draw primatives
		.define_method("ofDrawRectangle",    &Launcher::DrawRectangle)
		.define_method("ofDrawCircle",       &Launcher::DrawCircle)
		.define_method("ofDrawEllipse",      &Launcher::DrawEllipse)
		.define_method("ofDrawTriangle",     &Launcher::DrawTriangle)
		.define_method("ofDrawLine",         &Launcher::DrawLine)
		
		// bitmap string
		.define_method("ofDrawBitmapString", &Launcher::DrawBitmapString)
		
		// timing and framerate
		.define_method("ofGetLastFrameTime", &ofGetLastFrameTime)
		.define_method("ofGetFrameRate", &ofGetFrameRate)
		.define_method("ofSetFrameRate", &ofSetFrameRate)
	;
	
	

	
	
	
	Data_Type<ofTrueTypeFont> rb_cTrueTypeFont = 
		define_class_under<ofTrueTypeFont>(rb_mOni, "TrueTypeFont");
	
	// typedef ofTrueTypeFont (ofTrueTypeFont::*constructTrueTypeFont)();
	
	rb_cTrueTypeFont
		.define_constructor(Constructor<ofTrueTypeFont>())
		.define_method("load",   &ofTrueTypeFont::load,
			(
				Arg("filename"),
				Arg("fontsize"),
				Arg("_bAntiAliased") = true,
				Arg("_bFullCharacterSet") = true,
				Arg("makeContours") = false,
				Arg("simplifyAmt") = 0.3f,
				Arg("dpi") = 0
			)
		)
		.define_method("draw_string",   &ofTrueTypeFont::drawString)
	;
}

float ofVec3f_get_component(ofPoint& p, int i){
	return p[i];
}

void  ofVec3f_set_component(ofPoint& p, int i, float value){
	p[i] = 100.0;
}

// VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
