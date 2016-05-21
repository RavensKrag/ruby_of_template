#pragma once

#include "ofMain.h"
#include "ofApp.h"


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
