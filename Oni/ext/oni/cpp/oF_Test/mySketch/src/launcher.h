#pragma once

// This header will be included in the C++ Rice level.
// It should NOT pull in ANY oF headers.
// Those symbols will be in the static library, so it be fine once it gets to the linker.
// But we must trick theh compiler.
// (similar to resolution of cylic dependencies)
// src: http://stackoverflow.com/questions/2133250/does-not-name-a-type-error
class ofApp;




class Launcher
{

public:
    Launcher();
    virtual ~Launcher(void);
    
    void initialize();
	void show();


protected:
	ofApp* mApp;
};
