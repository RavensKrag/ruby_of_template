#pragma once

#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Class.hpp"
#include "rice/Module.hpp"

#include "ofPoint.h" // you can include this one. this is fine.

// This header will be included in the C++ Rice level.
// It should NOT pull in ANY oF headers.
// Those symbols will be in the static library, so it be fine once it gets to the linker.
// But we must trick the compiler.
// (similar to resolution of cylic dependencies)
// src: http://stackoverflow.com/questions/2133250/does-not-name-a-type-error
class OniApp;
class ofAppGlutWindow;



class Launcher
{

public:
    Launcher(Rice::Object self);
    ~Launcher(void);
    
    void initialize();
	void show();
	
	
	
	void hideCursor();
	void showCursor();
	
	void setFullscreen(bool fullScreen);
	void toggleFullscreen();

	void setWindowTitle(std::string title);
	void setWindowPosition(int x, int y);
	void setWindowShape(int w, int h);
	
	void setWindowIcon(const std::string path);
	
	ofPoint getWindowPosition();
	ofPoint getWindowSize();
	ofPoint getScreenSize();
	
	
	
	// NOTE: can't use the 'of' prefix for this interface, because it confuses the C++ compiler / linker when it tries to resolve the member functions of this class vs the original functions.
	
	
protected:
	OniApp* mApp;
	ofAppGlutWindow* mWindow = NULL;
};

