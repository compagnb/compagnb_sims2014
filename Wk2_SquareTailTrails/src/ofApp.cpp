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
    
    for(int i = 0; i < 20; i++){
        myRectangle[i].size = i*2;
        myRectangle[i].set(40 * i, i);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 20; i++){
     //myRectangle.angle += TWO_PI/ofGetFrameRate();
    
    //    luna.radius += 0.1;
    //    luna.radius *= 1.01;
    
     myRectangle[i].update(0.01*i, ofPoint(i*40, i*60));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(220, 220, 220);
    for(int i = 0; i < 20; i++){
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
