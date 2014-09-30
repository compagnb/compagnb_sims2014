//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#pragma once

#include "ofMain.h"
#include "path.h"
#include "vehicle.h"

class ofApp : public ofBaseApp{
    
public:
	
	void setup();
	void update();
	void draw();
    void addCar(float x, float y);
    void setRandomColor();
//    
//	void keyPressed  (int key);
//	void keyReleased(int key);
//	void mouseMoved(int x, int y );
//	void mouseDragged(int x, int y, int button);
//	void mousePressed(int x, int y, int button);
//	void mouseReleased(int x, int y, int button);
//	void windowResized(int w, int h);
    
    path myPath;
    vector<vehicle> cars;
    
    float randR, randG, randB;
	
};
