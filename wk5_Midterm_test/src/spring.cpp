#include "spring.h"


//---------------------------------------------------------------------
spring::spring(){
	a = NULL;
	b = NULL;
    
    //rest_length = (b->pos - a->pos).length();
}

//---------------------------------------------------------------------
void spring::update(){
	if ((a == NULL) || (b == NULL)){
		return;
	}
	
	ofVec2f pta = a->pos;
	ofVec2f ptb = b->pos;

	float theirDistance = (pta - ptb).length();
	float springForce = (springiness * (distance - theirDistance));
	ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
	
	a->addForce(frcToAdd.x, frcToAdd.y);
	b->addForce(-frcToAdd.x, -frcToAdd.y);
    
//    ofVec2f dir = b->pos - a->pos;
//    float dist = dir.length();
//    float f = (rest_length - dist) * k; // linear force spring
//    dir.normalize();
//    ofVec2f frcToAdd = dir * f;
//    a->addForce(frcToAdd.x, frcToAdd.y);
//    b->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void spring::draw(){
	
	if ((a == NULL) || (b == NULL)){
		return;
	}
	
	//ofLine(a->pos.x, a->pos.y, b->pos.x, b->pos.y);
}