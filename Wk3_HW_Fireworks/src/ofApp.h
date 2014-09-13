//
//
//  Wk3_HW_Fireworks
//
//  Created by compagnb on 9/13/14.
//
//


#pragma once

#include "ofMain.h"
#include "particle.h"

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
    
    //create a vector of particles -- a vector is like an array
    vector <particle> particles;
    
    unsigned int timer;
    unsigned int randX;
    unsigned int randY;
    
    unsigned int randR;
    unsigned int randG;
    unsigned int randB;
    
    void setRandomPos();
    void setRandomColor();
    void restart();
};

