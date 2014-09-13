//
//
//  Wk3_HW_Fireworks
//
//  Created by compagnb on 9/13/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFullscreen(true);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(50, 50, 50);
    ofEnableAlphaBlending();

    
    //set a random position and color for fireworks
	setRandomPos();
    setRandomColor();
    
    for (int i = 0; i < 300; i++){
        particle myParticle;
        
        float angle = ofGetElapsedTimef() * (i * 10.0);
        float velX = ofRandom(-4,4);
        float velY = ofRandom(-4,4);
        
        
        
        myParticle.setInitCondition(randX, randY, velX, velY);
        myParticle.damping = ofRandom(0.01, 0.05);
        myParticle.setColorCondition(randR, randG, randB);
        
        particles.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void ofApp::restart(){
 
    timer = 0;
    
    setRandomPos();
    setRandomColor();
    
    for (int i = 0; i < particles.size(); i++){
		float velX = ofRandom(-4,4);
		float velY = ofRandom(-4,4);
        
		particles[i].setInitCondition(randX,randY, velX, velY);
        particles[i].setColorCondition(randR, randG, randB);
		
	}
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    // on every frame we reset the forces add in any forces on the particle perfom damping and then update

    timer++;
    
    if (timer > ofRandom(60,120)) {
        restart();
    }
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addForce(0, 0.04); //gravity
        particles[i].addDampingForce();
        particles[i].update();
        
    }
    printf("pos x: %i\n",randX);
    printf("pos y: %i\n",randY);
    
	printf("color r: %i\n",randR);
    printf("color g: %i\n",randG);
    printf("color b: %i\n",randR);
	
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < particles.size(); i++) {
        
        particles[i].draw();
        
    }

    
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

//--------------------------------------------------------------
void ofApp::setRandomPos(){
	randX = ofRandom(100, ofGetWidth()-100);
	randY = ofRandom(100, ofGetHeight()-100);
}

//--------------------------------------------------------------
void ofApp::setRandomColor(){
	randR = ofRandom(100, 255);
    randG = ofRandom(100, 255);
	randB = ofRandom(100, 255);
}
