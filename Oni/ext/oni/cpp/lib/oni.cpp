#include "oni.h"

#include <iostream>

// C++ stuff
#include "launcher.h"

// Rice glue code
// #include "Window.h" 
#include "Graphics.h"

// #include "ofApp.h"
// #include "ofAppRunner.h"


using namespace Rice;

extern "C"

void Init_oni()
{
	std::cout << "c++: set up module: Oni\n";
	Module rb_mOni = define_module("Oni");
	
	
	Init_oni_graphics(rb_mOni);
	
	
	
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
		
		
		// clipboard support
		.define_method("clipboard_string=",         &Launcher::setClipboardString)
		.define_method("clipboard_string",          &Launcher::getClipboardString)
		
		
		.define_method("ofSetEscapeQuitsApp", &ofSetEscapeQuitsApp)
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
	
	
	
	
	// ofTexture
	// ofImage
	// ofPixels
	
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
