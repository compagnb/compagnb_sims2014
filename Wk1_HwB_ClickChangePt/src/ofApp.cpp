//
//
//  Wk1_HwB_ClickChangePt
//
//  Created by compagnb on 8/31/14.
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
    ofBackground(200, 200, 200);
    
    
    //set the start (posa) x and y positions of the rectangle
    myRectangle.posa.x = ofGetWidth()/4;
    myRectangle.posa.y = ofGetHeight()/2;
    
    //set the end (posb) x and y positions of the rectangle
    myRectangle.posb.x = ofGetWidth() - ofGetWidth()/4;
    myRectangle.posb.y = ofGetHeight()/2;
    
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
    pct += .003f;
    
    //if the percentage is over 1 - then reset it to 0
    if (pct > 1){
        pct = 0;
    }
    
    //move the rectangle between posa and posb
    myRectangle.interpolateByPct(pct);

}

//--------------------------------------------------------------
void ofApp::draw(){
    myRectangle.draw();

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
    
    if (counter == 1){   //finish is mouse position
        //reset the percentage
        pct = 0;
    
        //reset the start (posa) positions of x and y to be the current x and y (pos)
        myRectangle.posa.x = myRectangle.pos.x;
        myRectangle.posa.y = myRectangle.pos.y;
    
        //change the desitination (posb) positions of x and y to be where the mouse was clicked
        myRectangle.posb.x = mouseX;
        myRectangle.posb.y = mouseY;
       
         //alternate between changing start and finish on click
        counter++;
    
    }else if (counter == 2){ //beginning is mouse position
        //reset the percentage
        pct = 0;
        
        //reset the start (posab) positions of x and y to be the current x and y (pos)
        myRectangle.posb.x = myRectangle.pos.x;
        myRectangle.posb.y = myRectangle.pos.y;
        
        //change the desitination (posa) positions of x and y to be where the mouse was clicked
        myRectangle.posa.x = mouseX;
        myRectangle.posa.y = mouseY;
        
        //alternate between changing start and finish on click
        counter--;
        
    }

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
