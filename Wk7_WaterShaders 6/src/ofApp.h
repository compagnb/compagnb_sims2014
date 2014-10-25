#pragma once

/*
 This example implements a fragment shader
 which creates a video effect using the sin of time on an image.
 
 It's based on the examples from "Mastering openFrameworks: Creative Coding Demystified",
 Chapter 8 - Using Shaders
 */

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
    
	ofShader shader;	//Shader
	ofFbo fbo;			//Buffer for intermediate drawing
    ofFbo fbo2;         //Second buffer for mask
	ofImage image;		//water image
    
    float time0;
    float phase;
    float distortAmt;
    
	void keyPressed  (int key);
	void keyReleased (int key);
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
};

