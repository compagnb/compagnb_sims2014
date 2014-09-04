//
//
//  Wk1_HwC_ShaperControls
//
//  Created by compagnb on 9/1/14.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set framerate
    ofSetFrameRate(60);
    
    //macs by default run on non vertical sync, which make animations run very very fast. This fixes that
    ofSetVerticalSync(true);
    
    //for the alpha on the rectangle
    ofEnableAlphaBlending();
    
    //set background color to light grey
    ofBackground(220, 220, 220);
    
    //set start positions for x and y (posa)
    myRectangle.posa.x = ofGetWidth()/2;
    myRectangle.posa.y = ofGetHeight()/4;
    
    //set end positions for x and y (posb)
    myRectangle.posb.x = ofGetWidth()/2;
    myRectangle.posb.y = ofGetHeight()/2;
    
    //set start positions for length and height (sizea)
    myRectangle.sizea.x = 0;
    myRectangle.sizea.y = 0;
    
    //set end positions for length and height (sizeb)
    myRectangle.sizeb.x = ofGetWidth();
    myRectangle.sizeb.y = ofGetHeight();
    
    //set start positions for color
    myRectangle.alphaa = 0;
    
    //set end positions for length and height (sizeb)
    myRectangle.alphab= 100;
    
    //set start positions for x and y (posa)
    myRectangle2.posa.x = ofGetWidth()/2;
    myRectangle2.posa.y = ofGetHeight()/2;
    
    //set end positions for x and y (posb)
    myRectangle2.posb.x = ofGetWidth()/2;
    myRectangle2.posb.y = ofGetHeight()/4;
    
    //set start positions for length and height (sizea)
    myRectangle2.sizea.x = ofGetWidth();
    myRectangle2.sizea.y = ofGetHeight();
    
    //set end positions for length and height (sizeb)
    myRectangle2.sizeb.x = 0;
    myRectangle2.sizeb.y = 0;
    
    //set start positions for color
    myRectangle2.alphaa = 100;
    
    //set end positions for length and height (sizeb)
    myRectangle2.alphab= 0;
    
    
    //start at 0 percent
    myRectangle.interpolateByPct(0);
    //a variable we can alter...
    pct = 1;
    
    counter = 1;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //print percentage in the console
    printf("%f \n", pct);
    
    //print out counter in console
    cout << "counter " << counter << "\n";
    
    //increase the percentage by a certain amount - create a certain number of keyframes
    pct += .002f;
    
    //if the percentage is over 1 - then reset it to 0
    if (pct > 1){
        pct = 0;
        counter = 0;
    }
    
    if (counter == 1){
        //move the rectangle between posa and posb
        myRectangle.interpolateByPct(pct);
        counter = 0;
    }else if (counter == 0){
        //move the rectangle between posa and posb
        myRectangle2.interpolateByPct(pct);
        counter = 1;
    }
   

}

//--------------------------------------------------------------
void ofApp::draw(){
    myRectangle.draw();
    myRectangle2.draw();

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
