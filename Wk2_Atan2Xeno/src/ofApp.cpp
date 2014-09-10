//
//
//  Wk2_Atan2Xeno
//
//  Created by compagnb on 9/10/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
    
    // set background:
	
	ofEnableAlphaBlending();
	ofBackground(200,200,200);

    
    //set u p the balls
    for(int i = 0; i < 100; i++){
        //size
        myBall[i].size = i*2;
        
       //angle and distance
        myBall[i].pos.x = 10 * i;
        myBall[i].pos.y = 10 * i;
        
        
        //color and alpha
        myBall[i].alpha = 100 - i*2;
        myBall[i].color.r = 255 - i*4;
        myBall[i].color.g = 0 + i*4;
        myBall[i].color.b = 255 - i*10;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myBall[0].xenoToPoint(mouseX, mouseY);
    
    //move the balls
    for(int i = 1; i < 100; i++){
        myBall[i].xenoToPoint(myBall[i-1].pos.x, myBall[i-1].pos.y);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //set background color
    ofBackground(220, 220, 220);
    
    //draw balls
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
