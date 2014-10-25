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
    
    vector <vector<ofVec2f> > heightMap;
    vector <vector<ofVec2f> > velMap;
    vector <int> sel;
    
    void drawSphereAt( const ofVec2f &vec, const ofVec2f &pos );
    
    float gravity;
    int fieldWidth, fieldHeight, resolution, radius;
		
    vector <particle> ps;
	//vector <spring> sp;
    
    ofEasyCam   cam;
    ofLight     light;
};
