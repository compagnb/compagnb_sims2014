//
//
//  Wk1_HwA_RectInterpolate
//
//  Created by compagnb on 8/31/14.
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
    
    //set the start (posa) positions of the rectangle
    myRectangle.posa.x = ofGetWidth()/3; //a third of the way into the screen
    myRectangle.posa.y = ofGetHeight()/2; //middle of the screen on the y
    
    //and end (posb) positions of the rectangle
    myRectangle.posb.x = ofGetWidth()/3 * 2; //a third of the way to the screen end
    myRectangle.posb.y = ofGetHeight()/2; //middle of the screen on the y
    
    // start at 0 percent
    myRectangle.interpolateByPct(0);
    // a variable we can alter...
	pct = 1;
    
   counter = 0;
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //print percentage in the console
    printf("%f \n", pct);
    
    //print counter in the console to get the MPH
    cout << "counter " << counter << "\n";
    
    //increase the percentage by a certain amount - create keyframes
    //pct += 0.00001f; // slowest -- imperceptible:very slight, gradual, or subtle
    pct += 1.9f; // fastest
    
    //if the percentage is over 1 - then reset it to 0
    if (pct>1){
        pct = 0;
    }
    
    
    // Move between posistion a and position b
    myRectangle.interpolateByPct(pct);
    
    counter = counter + 1;

}

//--------------------------------------------------------------
void ofApp::draw(){
    myRectangle.draw();

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
