//
//  
//  Wk3_HW_NotBallParticles
//
//  Created by compagnb on 9/13/14.
//
//

#include "particle.h"

void particle::setup() {
    float speed = 3;
    
    vel.x = speed * sin(age);
    vel.y = speed * -cos(age);
    angle = ofGetElapsedTimeMillis()*3.5;
    age = 0;
}

void particle::draw() {
    ofSetColor(color,ofMap(age,0,20,255,0,true));// ofMap remaps the value passed in "value", calculating it's linear distance between inputMin and inputMax, and remapping it based on that percentage to outputMin and outputMax. You can choose to clamp the results, which will constrain the results between outputMin and outputMax.
    ofLine(oldpos,pos);
}

void particle::update() {
    angle += ofSignedNoise(pos.x, pos.y)*cos(age);//Calculates a three dimensional Perlin noise value between -1.0...1.0.
    vel.rotate(angle);//rotates the velocity to the angle
    oldpos = pos;//updates old position
    pos += vel;//updates position
    age++;//udates age
}

