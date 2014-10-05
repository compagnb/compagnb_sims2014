// with the help of "Mastering openFrameworks: Creative Coding Demystified",
// Chapter 7 - Drawing in 3D

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
    
    vector <ofPoint> vertices;
    vector <ofColor> colors;
    
    int nTri;// the number of triangles
    int nVert; // the number of vertices needed to make the triangles (ntri * 3)
    
    float sphereRad; // spheres radius
    float triRad; // triangle radius  maxium diviation of the triangle's center
    
    ofPoint center;
    float time;
    float angle;
		
};
