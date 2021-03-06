//
//
//  Wk3_HW_Sinusid
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
		
    
        // make a vector of particles -  like an array
        vector <particle> particles;
    
        //variables
        float xOrig;
        float yOrig;
        float fade;
    
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
