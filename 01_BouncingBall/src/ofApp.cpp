#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cout << &myBall.position.x << endl;
    cout << &myBall.position.y << endl;
    cout << &myBall.position.z << endl;
    cout << &myBall.xVelocity << endl;
    cout << &myBall.yVelocity << endl;
    
    pointerX = &myBall.position.x;
    pointerY = &myBall.position.y;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    myBall.update();
    
//    cout << *pointerX <<endl;
    
    *pointerX *= ;
    *pointerX += ofRandom(-1, 1);
    *pointerX += ofRandom(-1, 1);
    *pointerY += ofRandom(-1, 1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
	ofSetColor(255,0,0);
    myBall.draw();
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
