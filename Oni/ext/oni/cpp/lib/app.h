#pragma once

// #include "rice/Data_Type.hpp"
// #include "rice/Constructor.hpp"
// #include "rice/Class.hpp"
// #include "rice/Module.hpp"

#include "ofApp.h"

namespace Rice{
	class Object; // forward declaration
}

class OniApp : public ofApp{

	public:
		OniApp(Rice::Object);
		~OniApp();
		
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	private:
		Rice::Object mSelf;
		
};
