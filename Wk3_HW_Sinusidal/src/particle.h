//
//
//  Wk3_HW_Sinusid
//
//  Created by compagnb on 9/13/14.
//
//

#include "ofMain.h"

class particle
{
    public:
    
        //vectors
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   //accelleration
		
        particle(); //constructor - takes the place of setup

        //functions
        void resetForce(); //resets the force in every frame
        void addForce(float x, float y); //adds force
        void addDampingForce(); //adds resistance
        void setInitialCondition(float posX, float posY, float velX, float velY); //sets up the inital positions and speeds(velocities)
        void setInitialColor(int red, int green, int blue);
        void update(); //updates
        void draw(); //draw shit
	
		float damping; //resistance
    
        ofColor color;//color
        int alpha;
        float radius;

    protected:
    private:
};


