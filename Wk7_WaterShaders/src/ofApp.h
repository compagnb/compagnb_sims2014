#pragma once

/*
 This example implements a fragment shader
 which inverts colors of the image.
 
 It's based on the example 01-ShaderInverting from the book
 "Mastering openFrameworks: Creative Coding Demystified",
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

