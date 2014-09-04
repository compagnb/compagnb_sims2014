//
//
//  Wk1_HwC_ShaperControls
//
//  Created by compagnb on 9/1/14.
//
//

#pragma once

#include "ofMain.h"
#include "rectangle.h"


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
    
    //create an object from the rectangle class
    rectangle myRectangle;
    rectangle myRectangle2;
    
    //variables
    float pct;
    int counter;
		
};
