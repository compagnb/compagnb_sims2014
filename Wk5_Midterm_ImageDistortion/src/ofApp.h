//
//
//
// Barbara Compagnoni
// based off the example 06-HorizontalDistortion from the book "Mastering openFrameworks: Creative Coding Demystified"
//
//
//

#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofImage origImage;
        ofImage modImage;
        float time;
        float amp;
        int x1;

		
};
