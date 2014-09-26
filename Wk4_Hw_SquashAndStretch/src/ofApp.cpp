#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    screen.set(ofGetWidth(), ofGetHeight());
	
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 50; i++){
		Particle myParticle;
		myParticle.setInit( ofGetWindowSize() / 2, ofPoint(10, -5) );
		// more interesting with diversity :)
		//myParticle.damping = ofRandom(0.001, 0.05);
		particles.push_back(myParticle);
	}
}
	

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint force;
    force.x = 0;
    force.y = 2.8;
    
    for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(force);
		particles[i].bounceOffWalls();
		particles[i].update();
        //particles[i].seek(screen);
	}


}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(0, 0, 0);
	ofSetColor(255,0,0);
	
	for (int i = 0; i < particles.size(); i++){
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


