//
//
//  Wk2_SquareTailTrails
//
//  Created by compagnb on 9/9/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mouse.y = mouseY;
    mouse.x = mouseX;

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //set origin 0,0 to center of the screen
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(200, 0, 200);
    
    //make the curves out of a series of points
    for(int i = 0; i < 1200; i++){
        
        //use the mouse x and y position to affect the x and y paramters of the curve. These values are quite large, so we scale them down by 0.0001
        pct = (i * mouse) * 0.0001f;
        
        
        //feed two values to sin and cos functions and multiply by how large
        //the sin function is producing -1 to 1 results the total width in this case will be double what we specify.
        
        pos.x = (ofGetWidth() * 0.5) * sin(pct.x);
        pos.y = (ofGetHeight() * 0.5) * cos(pct.y);
        
        ofRect(pos.x, pos.y, 4, 4);
    }
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
