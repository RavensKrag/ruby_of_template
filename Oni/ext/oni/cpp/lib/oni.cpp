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
	
	
	Module rb_mGraphics = define_module_under(rb_mOni, "Graphics");
	// ------------------
	// global oF functions
	// ------------------
	
	// these typedefs select one version of a polymorphic interface
	typedef void (*wrap_ofDrawBitmapString)(const std::string& textString, float x, float y, float z);
	
	
	typedef void (*wrap_ofDrawRectangle)(float x,float y,float z,float w,float h);
	typedef void (*wrap_ofDrawCircle)(float x, float y, float z, float radius);
	typedef void (*wrap_ofDrawEllipse)(float x, float y, float z, float width, float height);
	typedef void (*wrap_ofDrawTriangle)(float x1,float y1,float z1,float x2,float y2,float z2,float x3, float y3,float z3);
	typedef void (*wrap_ofDrawLine)(float x1,float y1,float z1,float x2,float y2,float z2);
	
	typedef void (*wrap_ofDrawRectRounded)(float x, float y, float z, float w, float h, float topLeftRadius, float topRightRadius, float bottomRightRadius, float bottomLeftRadius);
	
	
	typedef void (*wrap_ofBackground)(int r, int g, int b, int a);
	typedef void (*wrap_ofBackgroundHex)(int hexColor, int alpha);
	typedef void (*wrap_ofSetColor)(int r, int g, int b, int a);
	typedef void (*wrap_ofSetHexColor)(int hexColor);
	
	
	rb_mGraphics
		// bitmap string
		.define_method("ofDrawBitmapString", wrap_ofDrawBitmapString(&ofDrawBitmapString))
		
		// draw primatives
		.define_method("ofDrawRectangle",    wrap_ofDrawRectangle(&ofDrawRectangle))
		.define_method("ofDrawCircle",       wrap_ofDrawCircle(&ofDrawCircle))
		.define_method("ofDrawEllipse",      wrap_ofDrawEllipse(&ofDrawEllipse))
		.define_method("ofDrawTriangle",     wrap_ofDrawTriangle(&ofDrawTriangle))
		.define_method("ofDrawLine",         wrap_ofDrawLine(&ofDrawLine))
		
		.define_method("ofDrawRectRounded",  wrap_ofDrawRectRounded(&ofDrawRectRounded))
		
		// colors
		.define_method("ofBackground",       wrap_ofBackground(&ofBackground))
		.define_method("ofBackgroundHex",    wrap_ofBackgroundHex(&ofBackgroundHex))
		.define_method("ofSetColor",         wrap_ofSetColor(&ofSetColor))
		.define_method("ofSetHexColor",      wrap_ofSetHexColor(&ofSetHexColor))
		
		// matrix stack manipulation
		.define_method("ofPushStyle",        &ofPushStyle)
		.define_method("ofPopStyle",         &ofPopStyle)
		.define_method("ofPushMatrix",       &ofPushMatrix)
		.define_method("ofPopMatrix",        &ofPopMatrix)
	;
	
	// ------------------
	
	// NOTE: ofSetHexColor doesn't allow for alpha value. 
	// maybe define a custom version here that does use alpha?
	
	
	// ofDrawCurve
	// ofDrawBezier // <-- this one is pretty complicated. check it out. it's kinda cool.
	// TODO: find out what the difference / connection is between ofDrawCurve and ofDrawBezier
	
	
	
	
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
	
	
	
	
	
	Data_Type<ofTexture> rb_cTexture = 
		define_class_under<ofTexture>(rb_mOni, "Texture");
	
	
	
	typedef void (ofTexture::*ofTexture_draw_wh)(float x, float y, float z, float w, float h) const;
	typedef void (ofTexture::*ofTexture_draw_pt)(const ofPoint & p1, const ofPoint & p2, const ofPoint & p3, const ofPoint & p4) const;
	
	rb_cTexture
		.define_constructor(Constructor<ofTexture>())
		.define_method("draw_wh",   ofTexture_draw_wh(&ofTexture::draw))
		.define_method("draw_pt",   ofTexture_draw_pt(&ofTexture::draw))
	;
	
	// void draw(float x, float y, float z, float w, float h) const;
	// void draw(const ofPoint & p1, const ofPoint & p2, const ofPoint & p3, const ofPoint & p4) const;
	// void drawSubsection // <-- many different interfaces. unsure which to bind
	
	
	typedef bool (*load_image_from_file)(ofTexture & tex, string path);
	
	rb_cWindow
		// textures
		.define_method("ofLoadImage", load_image_from_file(&ofLoadImage))
	;
}

float ofVec3f_get_component(ofPoint& p, int i){
	return p[i];
}

void  ofVec3f_set_component(ofPoint& p, int i, float value){
	p[i] = 100.0;
}

// VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);
