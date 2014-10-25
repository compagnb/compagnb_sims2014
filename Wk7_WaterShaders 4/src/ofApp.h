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
    ofFbo fbo2;
	ofImage image;		//water image
    
    
	void keyPressed  (int key);
	void keyReleased (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};

