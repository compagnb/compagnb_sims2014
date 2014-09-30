//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //standard setup
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    
	//
    float offset = 60;
    
    //set up path
    myPath.init();
	myPath.addPoint( offset, offset );
	myPath.addPoint( ofGetWidth() - offset, offset );
	myPath.addPoint( ofGetWidth() - offset, ofGetHeight() - offset );
	myPath.addPoint( ofGetWidth() * 0.5, ofGetHeight() - offset * 3 );
	myPath.addPoint( offset, ofGetHeight() - offset );
	
    for( int i=0; i<10; i++ )
	{
		addCar(ofRandom(0, ofGetWidth()),ofRandom(0, ofGetHeight()));
	}
}
               
//----------------------------------------------------------------------
void ofApp :: addCar(float x, float y){
            float maxspeed	= ofRandom( 2, 4 );
            float maxforce	= 0.3;
            
            ofVec2f pos;
            pos.set( x, y );
            
            cars.push_back( vehicle() );
            setRandomColor();
            vehicle& b = cars.back();
            b.setInit(pos,maxspeed, maxforce );
            b.setColorCondition(randR, randG, randB);

}

//----------------------------------------------------------------------
void ofApp :: update(){
    
    for( int i=0; i<cars.size(); i++ ){
        vehicle& vehicle = cars.at(i);
        vehicle.applyForces(cars, myPath);
        vehicle.update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
	ofBackground( 255, 255, 255 );
	myPath.draw();
    
    for( int i=0; i<cars.size(); i++ ){
        vehicle& vehicle = cars.at(i);
        vehicle.draw();
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::setRandomColor(){
    randR = ofRandom(0, 255);
    randG = ofRandom(0, 255);
    randB = ofRandom(0, 255);
    
    
}
