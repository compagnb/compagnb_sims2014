#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	
	int rows = 40;
	int cols = 40;
    
	//position all particles
	for (int i=0; i<rows*cols; i++) {
		int z = int(i) % cols * 40;
		int x = int(i) / cols * 40;
		Particle p(ofVec3f(x,0,z), x==0 ? 0 : 1, .5 );
		ps.push_back(p);
	}
	
	//create all springs
	for (int i=0; i<rows*cols; i++) {
		int z = int(i) % cols;
		int x = int(i) / cols;
		
		//horizontal structural springs
		if (z<cols-1) {
			sp.push_back(Spring(&ps[i],&ps[i+1]));
		}
		
		//vertical structural springs
		if (x<rows-1) {
			sp.push_back(Spring(&ps[i],&ps[i+cols]));
		}

	}
    
	


}

//--------------------------------------------------------------
void ofApp::update(){

    
	//apply forces
	for (int i=0; i<ps.size(); i++) {
		ps[i].addForce(ofVec3f(1.1,0,0));
		ps[i].addForce(ofVec3f(0,sin(ofGetElapsedTimef()),0));

	}
	//update springs
	for (int i=0; i<sp.size(); i++) {
		sp[i].update();
	}
	
	//update particles
	for (int i=0; i<ps.size(); i++) {
		ps[i].update();
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofTranslate(-400, ofGetHeight()*.75, -300);
	
	//springs
	ofSetColor(255, 255, 255);
	glBegin(GL_LINES);
	for (int i=0; i<sp.size(); i++) {
		glVertex3f(sp[i].a->pos.x, sp[i].a->pos.y, sp[i].a->pos.z);
		glVertex3f(sp[i].b->pos.x, sp[i].b->pos.y, sp[i].b->pos.z);
	}
	glEnd();
	
	//particles
	ofSetColor(0, 0, 255);
	glPointSize(5);
	glBegin(GL_POINTS);
	for (int i=0; i<ps.size(); i++) {
		glVertex3f(ps[i].pos.x, ps[i].pos.y, ps[i].pos.z);
	}
	glEnd();


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
