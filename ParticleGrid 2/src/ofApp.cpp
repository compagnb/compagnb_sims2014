#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    light.setDiffuseColor(ofFloatColor(1.0,1.0,1.0));
    light.setPosition(ofPoint(0.0,0.0,0.0));
    
    ofSetFrameRate(60);
	ofEnableSmoothing();
    
    fieldWidth = ofGetWidth();
    fieldHeight = ofGetHeight();
    resolution = 20;
    
    //gravity=0.1;
    
    radius = 10;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;
    
    //position all particles
	for (int i=0; i<rows*cols; i++) {
		int x = i % cols * 20;
		int y = i / cols * 20;
		particle p;
        p.setInitialCondition(x, y,0, 0.96,y==0 ? 0 : 1 );
		ps.push_back(p);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    for (int i = 0; i < ps.size(); i++) {
//        ps[i].addForce(0, .1);
//		ps[i].addForce(0, sin(ofGetElapsedTimef()));
//    }
    for (int i = 0; i < ps.size(); i++) {
        ps[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0, 0, 0);
    
    cam.begin();
    light.enable();
    ofEnableLighting();
    
    for (int i = 0; i < ps.size(); i++){
		ps[i].draw();
    }
    
    ofDisableLighting();
    light.disable();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
//    for (int i = 0; i < ps.size(); i++){
//        if( mouseX < ps[i].)
//		
//    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
