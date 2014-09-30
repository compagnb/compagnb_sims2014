//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#pragma once

#include "ofMain.h"
#include "path.h"

class vehicle{
    public:
    
        vehicle();
        void setInit(ofPoint _pos, float ms, float mf);
        void applyForces(const vector<vehicle>& cars, const path& myPath);
        void setColorCondition(int red, int green, int blue);
    
        ofVec2f  separate(const vector<vehicle>& cars);
    
        ofVec2f follow( const path& path );
        ofVec2f getNormalPoint( const ofVec2f& p, const ofVec2f& a, const ofVec2f& b );
        ofVec2f steer( const ofVec2f& target, bool slowdown );
    
        void seek( ofPoint dest );
    
        void update();
        void draw();
    
        ofColor color;
    
        ofPoint pos;
        ofPoint vel;
        ofPoint acc;
        ofPoint predict;
        ofPoint predictPos;
        ofPoint target;
        ofPoint dir;
    
        float radius;
        float damp;
    
        float maxSpeed;
        float maxForce;
    
};
