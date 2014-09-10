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
    
    // setup the classes size, angle and distance
    
    for(int i = 0; i < 40; i++){
        myRectangle[i].size = i*2;
        //angle and distance - what angle to project and what distance
        myRectangle[i].set(10 * i, i);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 40; i++){
    //how far we should move, and the center of the class (not using the center in the code)
     myRectangle[i].update(0.01*i, ofPoint(i*40, i*60));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //change background color to grey
    ofBackground(220, 220, 220);
    
    //draw class objects
    for(int i = 0; i < 40; i++){
        myRectangle[i].draw();
    }
}//--------------------------------------------------------------
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
