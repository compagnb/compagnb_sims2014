#include "Particle.h"


//------------------------------------------------------------
Particle::Particle(){
	setInitialCondition(0,0,0,0,0,0);
	damping = 0.01f;
    
}

//------------------------------------------------------------
void Particle::setInitialCondition(float px, float py, float vx, float vy, float rx, float ry){
    pos.set(px,py);
	vel.set(vx,vy);
    rad.set(rx,ry);
}

//------------------------------------------------------------
void Particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    acc.x = acc.x + x;
    acc.y = acc.y + y;
}

//------------------------------------------------------------
void Particle::update(){	
	vel = vel + acc;
    
    vel = vel * (1.0-damping);
    
	pos = pos + vel;
    
    acc *= 0.0;
    
    rad   = vel * (1.0-damping);
}

//------------------------------------------------------------
void Particle::draw(){
    ofRect(pos.x, pos.y, rad.x, rad.y);
}

//------------------------------------------------------------
void Particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit... for now, we don't
	bool bDampedOnCollision = false;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth()-rad.x;
	float maxy = ofGetHeight()-rad.y;
	
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