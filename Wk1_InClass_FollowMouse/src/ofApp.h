//
//
// wk1_InClass_FollowMouse
//
//  Created by compagnb on 8/28/14.
//
//

#pragma once

#include "ofMain.h"
#include "ball.h"


class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void collision();
    
    
    ball myBall;
    
    int w, h, level;
    float sum, myX, myY, distance, mDis;
    int rad, centerX, centerY;
    
    
};
