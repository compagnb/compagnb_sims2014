//
//
//  Wk3_HW_Sinusid
//
//  Created by compagnb on 9/13/14.
//
//

#include "particle.h"
#include "ofMain.h"

//------------------------------------------------------------
// constructor
//------------------------------------------------------------
particle::particle(){
    //set the inital conditions to 0
	setInitialCondition(0,0,0,0);
    
    //set the initial color to black
    setInitialColor(0, 0, 0);
    
    //apply a number for damping
	damping = 0.01f; // like pct!!!
    
    radius = 3;
}

//------------------------------------------------------------
// resets the force
//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
// adds the force
//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
// adds resisting force
//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99 basically, subtract some part of the velocity damping is a force operating in the oposite direction of the velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
// sets the initial conditions for position and velocity
//------------------------------------------------------------
void particle::setInitialCondition(float posX, float posY, float velX, float velY){
    pos.set(posX,posY);
	vel.set(velX,velY);
}

//------------------------------------------------------------
// sets the initiam conditions for color
//------------------------------------------------------------
void particle::setInitialColor(int red, int green, int blue){
    color.r = red;
    color.g = green;
    color.b = blue;
}

//------------------------------------------------------------
// UPDATE!
//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
// DRAW!!!
//------------------------------------------------------------
void particle::draw(){
    //change color
    ofSetColor(color.r, color.g, color.b, alpha);
    //draw particle
    ofCircle(pos.x, pos.y, radius);
}
















