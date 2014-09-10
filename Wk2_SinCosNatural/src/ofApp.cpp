#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i = 0; i < 100; i++){
        myBall[i].size = i*2;
        myBall[i].set(10 * i, i);
        myBall[i].alpha = 100 - i*2;
        myBall[i].color.r = 255 - i*4;
        myBall[i].color.g = 0 + i*4;
        myBall[i].color.b = 255 - i*10;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < 100; i++){
        //myRectangle.angle += TWO_PI/ofGetFrameRate();
        
        //    luna.radius += 0.1;
        //    luna.radius *= 1.01;
        
        myBall[i].update(0.01, ofPoint(i*.1, i*.2));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(220, 220, 220);
    for(int i = 0; i < 100; i++){
        myBall[i].draw();
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
