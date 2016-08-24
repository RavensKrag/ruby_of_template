#include "Graphics.h"

using namespace Rice;

Rice::Module Init_oni_graphics(Rice::Module rb_mOni)
{
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
	
	return rb_mGraphics;
}
