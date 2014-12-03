#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    shader.load( "shaderVert.c", "shaderFrag.c" );
    fbo.allocate(width, height);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    //Draw into fbo buffer -----------------------------
//	fbo.begin();
    shader.begin();
    shader.setUniform3f("iResolution", ofGetWidth(), ofGetHeight(), 0.0);
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform4f("iMouse", mouseX, mouseY, 0, 0);
    
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    shader.end();
//    fbo.end();
//    
//    //Draw fbo image -----------------------------------
//	ofSetColor( 255, 255, 255 );
//	fbo.draw( 0, 0 );
//    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    shader.load( "shaderVert.c", "shaderFrag.c" );

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
