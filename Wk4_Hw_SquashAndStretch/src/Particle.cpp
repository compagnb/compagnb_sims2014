#include "Particle.h"

// Constructor doing set up shiznit -------------------------------------------------------------
Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    setColorCondition(0,0,0);
    
    damp = 0.95; // de resistance!!!
    squash.set(0.2,0.2);
    
    radius = 5;
    size.x = 20;
    size.y = 20;
}

// Setting Initial Conditions -------------------------------------------------------------------
void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

// Adds Force To The Accelleration --------------------------------------------------------------
void Particle::addForce(ofPoint _force){
    acc += _force;
}

// Adds Repulsion Force -------------------------------------------------------------------------
void Particle::addRepulsionForce(ofPoint _pos, float _rad, float _scale){
    
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;// PRO way
        addForce(-diff*_scale);
    }
}

// Adds Attraction Force -------------------------------------------------------------------------
void Particle::addAttractionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;
        addForce(diff*_scale);
    }
}

// Adds Clockwise Force -------------------------------------------------------------------------
void Particle::addClockwiseForce( ofPoint _pos, float _rad, float _scale){
	ofVec2f diff = pos - _pos;
	
	if (diff.length() < _rad){
		float pct = 1 - (diff.length() / _rad);
		diff.normalize();
		acc.x -= diff.y * pct * _scale;
		acc.y += diff.x * pct * _scale;
	}
}

// Adds Counter-Clockwise Force -----------------------------------------------------------------
void Particle::addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale){
	ofVec2f diff = pos - _pos;
	
	if (diff.length() < _rad){
		float pct = 1 - (diff.length() / _rad);
		diff.normalize();
		acc.x += diff.y * pct * _scale;
		acc.y -= diff.x * pct * _scale;
        //size.x *= acc.x;
        size.y *= acc.y;
        
	}
}

//-----------------------------------------------------------------------------------------------
void Particle::seek( ofPoint dest ) {
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofPoint desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
        
    }else{
        desired.normalize();
        desired *= maxSpeed;

    }
    
    ofPoint steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}

// Updates Physics -------------------------------------------------------------------------------
void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    //size.set(50,50);
    
  
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
        size.x = size.x * (1+squash.x);
        size.y = size.y * (1-squash.y);
        
    }else if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
        size.x = size.x * (1-squash.x);
        size.y = size.y * (1+squash.y);
    }else{
        size.x = 20;
        size.y = 20;
    }
    
}

// DRAWS!!!!!!!!!!!!!!!!! -------------------------------------------------------------------------
void Particle::draw() {
//    ofCircle(pos, radius);
    
    //set color
    ofSetColor(color.r, color.g, color.b);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 90 );

    ofCircle( 0,0, size.x, size.y);
    
    ofPopMatrix();
}

// Sets Color Conditions -----------------------------------------------------------------------------
void Particle::setColorCondition(int red, int green, int blue){
    color.r = red;
    color.g = green;
    color.b = blue;
}

//------------------------------------------------------------
void Particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit... for now, we don't
	bool bDampedOnCollision = false;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth() - size.x;
	float maxy = ofGetHeight() - size.y;
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.9;
	}
	
}