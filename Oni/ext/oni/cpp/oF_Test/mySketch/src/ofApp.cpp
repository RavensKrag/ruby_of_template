#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();
	
	ofLoadImage(mTexture, "/home/ravenskrag/Pictures/Buddy Icons/100shinn1.png");
	
	
	int x = 500;
	int y = 500;
	int width = 100;
	int height = 100;
	
	mPoints[0].x = x;           mPoints[0].y = y;
	mPoints[1].x = x + width;   mPoints[1].y = y;
	mPoints[2].x = x + width;   mPoints[2].y = y + height;
	mPoints[3].x = x;           mPoints[3].y = y + height;
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);  // Clear the screen with a black color
	ofSetColor(255);  // Set the drawing color to white
	
	// Draw some shapes
	ofDrawRectangle(50, 50, 100, 100); // Top left corner at (50, 50), 100 wide x 100 high
	ofDrawCircle(250, 100, 50); // Centered at (250, 100), radius of 50
	ofDrawEllipse(400, 100, 80, 100); // Centered at (400 100), 80 wide x 100 high
	ofDrawTriangle(500, 150, 550, 50, 600, 150); // Three corners: (500, 150), (550, 50), (600, 150)
	ofDrawLine(700, 50, 700, 150); // Line from (700, 50) to (700, 150)
	
	
	
	ofDrawBitmapString("Hello World!", 300, 300);
	
	
	mTexture.draw(mPoints[0], mPoints[1], mPoints[2], mPoints[3]);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLog() << key; // use this instead of using std::out
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
