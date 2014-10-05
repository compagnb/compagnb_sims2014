#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // load texture from file
    ofLoadImage(texture, "static_water.jpg");
    
    //set up initial corners
    p[0].set(100, 100);
    p[1].set(300, 100);
    p[2].set(300, 300);
    p[3].set(100, 300);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255);
    texture.draw(p[0], p[1], p[2], p[3]);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Select corner to edit by keys 1,2,3,4
    if ( key == '1' ) { ind = 0; }
    if ( key == '2' ) { ind = 1; }
    if ( key == '3' ) { ind = 2; }
    if ( key == '4' ) { ind = 3; }
    
    //Move selected corner by cursor keys
    if ( key == OF_KEY_LEFT ) { p[ ind ].x -= 10; }
    if ( key == OF_KEY_RIGHT ) { p[ ind ].x += 10; }
    if ( key == OF_KEY_UP ) { p[ ind ].y -= 10; }
    if ( key == OF_KEY_DOWN ) { p[ ind ].y += 10; }

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
