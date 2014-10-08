#ifndef SPRING_H
#define SPRING_H

#include "ofMain.h"

#include "particle.h"

class spring {

	public:

		spring();
    
        spring(particle *_A, particle *_B, float _k = 0.05);
    

		particle * particleA;
		particle * particleB;
		
		float restlength;
		float k;	 // this is the k, springiness constant
	
		void update();
		void draw();
	
	
};


#endif