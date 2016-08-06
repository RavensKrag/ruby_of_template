#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

#include "oni.h"
#include "launcher.h"
#include <iostream>

// #include "ofApp.h"
// #include "ofAppRunner.h"
#include "ofMain.h"

using namespace Rice;

extern "C"

void Init_oni()
{
	std::cout << "c++: set up module\n";
	Module rb_mOni = define_module("Oni");
	
	
	Data_Type<Launcher> rb_cWindow = define_class_under<Launcher>(rb_mOni, "Window");
	
	rb_cWindow
		.define_constructor(Constructor<Launcher, Rice::Object>())
		// .define_method("initialize", &Launcher::initialize)
		.define_method("show", &Launcher::show)
		.define_method("exit", &ofExit)
		
		// .define_method("ofBackground", &ofBackground)
		// .define_method("ofSetColor",   &ofSetColor)
		
		.define_method("ofBackground",    &Launcher::Background)
		.define_method("ofBackgroundHex", &Launcher::BackgroundHex)
		.define_method("ofSetColor",      &Launcher::SetColor)
		.define_method("ofSetHexColor",   &Launcher::SetHexColor)
		
		.define_method("ofDrawRectangle", &Launcher::DrawRectangle)
		.define_method("ofDrawCircle",    &Launcher::DrawCircle)
		.define_method("ofDrawEllipse",   &Launcher::DrawEllipse)
		.define_method("ofDrawTriangle",  &Launcher::DrawTriangle)
		.define_method("ofDrawLine",      &Launcher::DrawLine)
		
		
		
		
		;
	
}


// VALUE klass = rb_define_class_under(outer, "Window", rb_cObject);