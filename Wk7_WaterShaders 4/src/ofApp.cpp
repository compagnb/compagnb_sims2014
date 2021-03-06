#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );
    
	fbo.allocate( ofGetWidth(), ofGetHeight() );
    fbo2.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "static_water.jpg" );
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef();
	
    //Draw into fbo buffer -----------------------------
	fbo.begin();
    
	ofBackground(255);
    ofSetColor( 255, 255, 255 );
	image.draw( 0, 0 );
    
	fbo.end();
    
    //Draw a rect into the second buffer
    fbo2.begin();
    ofBackground(255);
    float angle = time * 30;
    
    ofPushMatrix();
    ofTranslate(500, 300);
    ofRotate(angle);
    ofFill();
    ofSetColor(255);
    ofRect(200, 200, 100, 100);
    ofPopMatrix();
    fbo2.end();
    
	//Draw through shader ---------------------------
    ofEnableAlphaBlending();
	shader.begin();
    
    shader.setUniform1f("time", time);
    //shader.setUniform1fv( "myArray", myArray, 256);// if passing an array
    
    //Draw fbo image -----------------------------------
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

