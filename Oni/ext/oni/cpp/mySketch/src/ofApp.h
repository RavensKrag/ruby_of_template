#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		virtual void setup();
		virtual void update();
		virtual void draw();

		virtual void keyPressed(int key);
		virtual void keyReleased(int key);
		virtual void mouseMoved(int x, int y );
		virtual void mouseDragged(int x, int y, int button);
		virtual void mousePressed(int x, int y, int button);
		virtual void mouseReleased(int x, int y, int button);
		virtual void mouseEntered(int x, int y);
		virtual void mouseExited(int x, int y);
		virtual void windowResized(int w, int h);
		virtual void dragEvent(ofDragInfo dragInfo);
		virtual void gotMessage(ofMessage msg);
	
	private:
		ofTexture mTexture;
		ofPoint mPoints[4];
};
