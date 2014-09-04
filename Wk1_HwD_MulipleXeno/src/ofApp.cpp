//
//
//  Wk1_HwD_MulipleXeno
//
//  Created by compagnb on 9/1/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set framerate
    ofSetFrameRate(60);
    
    //macs by default run on non vertical sync, which make animations run very very fast. This fixes that
    ofSetVerticalSync(true);
    
    // for the alpha in the rectangle
    ofEnableAlphaBlending();
    
    //set background color to light grey
    ofBackground(200, 200, 200);
    
    // set the color of the balls
	myBall.color.r = 200;
    myBall.color.g = 0;
    myBall.color.b = 200;
    myBall.alpha = 50;
    
    myBall1.color.r = 0;
    myBall1.color.g = 100;
    myBall1.color.b = 200;
    myBall1.alpha = 50;
    
    myBall2.color.r = 100;
    myBall2.color.g = 100;
    myBall2.color.b = 0;
    myBall2.alpha = 50;
    
    myBall3.color.r = 0;
    myBall3.color.g = 0;
    myBall3.color.b = 100;
    myBall3.alpha = 50;
	
    
    // set the position of the balls
	myBall.pos.x = ofGetWidth()/2;
	myBall.pos.y = ofGetHeight()/2;
    
    myBall1.pos.x = ofGetWidth()/3;
	myBall1.pos.y = ofGetHeight()/3;
    
    myBall2.pos.x = ofGetWidth()/4;
	myBall2.pos.y = ofGetHeight()/4;
    
    myBall3.pos.x = ofGetWidth()/5;
	myBall3.pos.y = ofGetHeight()/5;
    
    //catchUpSpeeds
    
    myBall1.catchUpSpeed = 0.08f;
    myBall2.catchUpSpeed = 0.05f;
    myBall3.catchUpSpeed = 0.01f;

}

//--------------------------------------------------------------

void ofApp::update(){
    myBall.xenoToPoint(mouseX, mouseY);
    myBall1.xenoToPoint(mouseX, mouseY);
    myBall2.xenoToPoint(mouseX, mouseY);
    myBall3.xenoToPoint(mouseX, mouseY);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw balls
    myBall.draw();
    myBall1.draw();
    myBall2.draw();
    myBall3.draw();

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
