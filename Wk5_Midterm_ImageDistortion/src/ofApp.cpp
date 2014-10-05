#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    origImage.loadImage("static_water.jpg");
    origImage.resize(ofGetWidth(), ofGetHeight());
    modImage.clone(origImage);//making a copy of the original image

}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    
    //building modified image by using the original image
    for(int i = 0; i < origImage.height; i++){
        for(int j = 0; j < origImage.width; j++){
            //use i and time for shifting on X1
            amp = sin(i * 0.03);
            x1 = j + sin(time * 1.0) * amp * 20.0;
            
            //clamp x1 to the range of 0 to image width
            x1 = ofClamp(x1, 0, origImage.width -1);
       
            
            //set modImage  equal to originalImage
            ofColor color = origImage.getColor(x1, i);
            modImage.setColor(j,i, color);
        }
    }
    modImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    modImage.draw(0,0);

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
