#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );
    
	fbo.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "static_water.jpg" );
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
	
    //Draw into fbo buffer -----------------------------
	fbo.begin();
    
	ofBackground(255);
    ofSetColor( 255, 255, 255 );
	image.draw( 0, 0 );
    
	fbo.end();
    
	//2. Draw through shader ---------------------------
	shader.begin();
    float time = ofGetElapsedTimef();
    shader.setUniform1f("time", time);
    
	//Draw fbo image
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );
    
	shader.end();		
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
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

