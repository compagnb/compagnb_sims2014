//
//
//  Wk3_HW_Sinusid
//
//  Created by compagnb on 9/13/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofBackground(50, 50, 50);
    ofEnableAlphaBlending();
    
    //set a random position and color for fireworks
	//setRandomPos();
    setRandomColor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // on every frame we reset the forces add in any forces on the particle perfom damping and then update
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        setRandomColor();
        particles.clear();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
  

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //sets the origin to the mouse position when clicked
    xOrig = mouseX;
    yOrig = mouseY;
    
    float radius = 300;
    float angle = ofGetElapsedTimeMillis()*3.5;
    
    //sets the position of the particles to appear in a circle
    x = xOrig + radius * cos(angle * 1.3);
    y = yOrig + radius * -sin(angle * 2.4);
    
    setRandomColor();
    
    float speed = 3;
    
    //make some particles!!!
    for (int i = 0; i <100; i++){
        particle myParticle;
        
        float angle = ofGetElapsedTimef() * (i * 10);
        float velX = speed * sin(i);
        float velY = speed * -cos(i);
        
        myParticle.setInitialCondition(x, y, velX, velY);
        myParticle.damping = ofRandom(0.01, 0.05);
        myParticle.setInitialColor(randR, randG, randB);
        
        particles.push_back(myParticle);
    }
   
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
void ofApp::setRandomColor(){
	randR = ofRandom(100, 255);
    randG = ofRandom(100, 255);
	randB = ofRandom(100, 255);
}

