#pragma once

#include "ofMain.h"
#include "water.h"
#include "rock.h"
#include "spring.h"

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
    
    ofPoint mouse;
    
    water water;
    vector <spring> springs;
    vector<rock> rocks;
    //water** w;
    
    int waterCols;
    float k = 0.025f;
    float damp = 0.025f;
    float spread = 0.025f;//controls how fast the waves spread
    
private:
   
    
};
