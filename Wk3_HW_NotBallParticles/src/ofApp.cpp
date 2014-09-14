//
//
//  Wk3_HW_NotBallParticles
//
//  Created by compagnb on 9/13/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    //load the image
    surf.loadImage("images/test.jpg");
    
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i<particles.size(); i++){
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<particles.size(); i++) {
        particle &p = particles[i]; //particle p = #
        p.draw();//draw particle
    }
    
    for (int i=0; i<100; i++) {//creates 100 particles
        createParticle();
    }
    
    while (particles.size()>1000) {
        particles.erase(particles.begin()); //erase after 1000 particles are drawn
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
void ofApp::createParticle() {
    particle p; //create a particle and name it p
    p.setup(); //run setup
    p.pos.set(ofRandomWidth(), ofRandomHeight());//set randomly
    p.color = surf.getColor(p.pos.x,p.pos.y);//gets the color from the x and y pos
    particles.push_back(p);// push it back in the vector
}
