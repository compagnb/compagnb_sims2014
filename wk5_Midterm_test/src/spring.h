#ifndef SPRING_H
#define SPRING_H

#include "ofMain.h"

#include "particle.h"

class spring {

	public:

		spring();
		
		particle * a;
		particle * b;
		
		float distance;
		float springiness;	 // this is the k, springiness constant
	
		void update();
		void draw();
        float rest_length;
        float k;
	
	
};


#endif