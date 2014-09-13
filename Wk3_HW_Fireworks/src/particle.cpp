//
//
//  Wk3_HW_Fireworks
//
//  Created by compagnb on 9/13/14.
//
//

#include "particle.h"

//-----------------------------------------------------------------
// constructor i.e. setup
//-----------------------------------------------------------------

particle::particle(){
    //set initial speed and velocity to 0
    setInitCondition(0, 0, 0, 0);
    setColorCondition(0,0,0);
    
    //put a damping force
    damping= 0.01f; //like the pct!!!
    
    //set up the tail
    myTail.setup();
}

//-----------------------------------------------------------------
// add force for x and y
//-----------------------------------------------------------------

void particle::addForce(float x, float y){
    frc.x += x;
    frc.y += y;
}

//-----------------------------------------------------------------
// reset force every frame
//-----------------------------------------------------------------

void particle::resetForce(){
    frc.set(0,0);
}

//-----------------------------------------------------------------
// add resistance
//-----------------------------------------------------------------

void particle::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99 basically, subtract some part of the velocity damping is a force operating in the oposite direction of the velocity vector
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    
}

//-----------------------------------------------------------------
// set the initial condition function
//-----------------------------------------------------------------

void particle::setInitCondition(float posX, float posY, float velX, float velY){
    
    pos.set(posX, posY);
    vel.set(velX, velY);
    
    myTail.clearPoints();
}

//-----------------------------------------------------------------
// set the initial condition function
//-----------------------------------------------------------------

void particle::setColorCondition(int red, int green, int blue){
    color.r = red;
    color.g = green;
    color.b = blue;
}
//-----------------------------------------------------------------
// update the position and velocity
//-----------------------------------------------------------------

void particle::update(){
    
    vel = vel + frc;
    pos = pos + vel;
    myTail.update(pos.x, pos.y);
    
}

//-----------------------------------------------------------------
// reset the inital condition position and speed
//-----------------------------------------------------------------

void particle::reset(){
    
    setInitCondition(0,0,0,0);
    setColorCondition(50,50,50);
    myTail.update(pos.x, pos.y);
    
}

//-----------------------------------------------------------------
// DRAW!!!!
//-----------------------------------------------------------------

void particle::draw(){
    
    //set color
    ofSetColor(color.r, color.g, color.b);
    myTail.draw();
    ofFill();
    ofCircle(pos.x, pos.y, 2);
    
}






























