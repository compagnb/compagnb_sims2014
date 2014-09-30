//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#include "vehicle.h"

// Constructor doing set up shiznit -------------------------------------------------------------
vehicle::vehicle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    setColorCondition(0,0,0);
    
    damp = 0.95; // de resistance!!!
    
    maxSpeed = 10.0;
    maxForce = 0.4;
    
}

// Setting Initial Conditions -------------------------------------------------------------------
void vehicle::setInit(ofPoint _pos, float ms, float mf){
    pos = _pos;
    acc.set(0,0,0);
	radius = 12;
	maxSpeed = ms;
	maxForce = mf;
	vel.set(maxSpeed, 0 );
}

void vehicle :: applyForces(const vector<vehicle>& cars, const path& myPath){
	ofVec2f f = follow(myPath);
	ofVec2f s = separate(cars);
	f	*= 3;
	s	*= 1;
	acc += f;
	acc += s;
}

////-----------------------------------------------------------------------------------------------
//void vehicle::seek( ofPoint dest ) {
//   
//    float slowDownRadius = 200.0;
//    
//    ofPoint desired = dest - pos;
//    
//    if( desired.length() < slowDownRadius ){
//        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
//        
//        desired.normalize();
//        desired *= newMag;
//    }else{
//        desired.normalize();
//        desired *= maxSpeed;
//    }
//    
//    ofPoint steer = desired - vel;
//    steer.limit( maxForce );
//    
//    addForce( steer );
//}

// Updates Physics -------------------------------------------------------------------------------
void vehicle::update() {
    
    vel += acc;
    vel *= damp;
    vel.limit(maxSpeed);
    pos += vel;
    acc *= 0.0;
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
}

// DRAWS!!!!!!!!!!!!!!!!! -------------------------------------------------------------------------
void vehicle::draw() {
    //    ofCircle(pos, radius);
    
    //set color
    ofSetColor(color.r, color.g, color.b);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 90 );
    ofFill();
    ofRect( 0,0, 20, 40);
    
    ofPopMatrix();
}
// -------------------------------------------------------------------------
ofVec2f vehicle :: separate(const vector<vehicle>& cars){
	
    float desiredseparation = radius * 2;
	ofVec2f steer;
	int count = 0;
	
	for( int i=0; i<cars.size(); i++ ){
		const vehicle& other = cars.at( i );
		
		float d;
		d = pos.distance( other.pos );
		
		if( ( d > 0 ) && ( d < desiredseparation ) )
		{
			ofVec2f diff;
			diff = pos - other.pos;
			diff.normalize();
			diff /= d;
			steer += diff;
			count++;
		}
	}
    
    if( count > 0 )
	{
		steer /= (float)count;
	}
	
    if( steer.length() > 0 )
	{
		steer.normalize();
		steer *= maxSpeed;
		steer -= vel;
		steer.limit( maxForce );
    }
    return steer;
}


// Sets Color Conditions -----------------------------------------------------------------------------
void vehicle::setColorCondition(int red, int green, int blue){
    color.r = red;
    color.g = green;
    color.b = blue;
}

// Follow Path ------------------------------------------------------------------
ofVec2f vehicle::follow( const path& path ){
    
    predict.set(0,0);
    predict.set(vel);
    predict.normalize();
    predict *= radius;
    
    predictPos.set(0,0);
    predictPos = pos + predict;
    
    target.set(0,0);
    
    float record = 1000000;
    
    for( int i=0; i<path.points.size(); i++ )
	{
		ofVec2f a;
		a.set( path.points.at( i ) );									// current point.
		
		ofVec2f b;
		b.set( path.points.at( ( i + 1 ) % path.points.size() ) );		// next point.
		
		// the normal is a vector that extends from that point and is perpendicular to the line.
		// http://www.shiffman.net/itp/classes/nature/pathimages/path5normal.jpg
		// http://www.shiffman.net/itp/classes/nature/pathimages/path6normal.jpg
		
		ofVec2f normal;
		normal = getNormalPoint( predictPos, a, b );
		
		// check if normal is on line segment
		
		float da;
		da = normal.distance( a );
		
		float db;
		db = normal.distance( b );
		
		ofVec2f line;
		line = b - a;
		
		// if it's not within the line segment, consider the normal to just be the end of the line segment (point b)
        
		if( da + db > line.length() + 1 )
		{
			normal.set( b );
			
			a.set( path.points.at( ( i + 1 ) % path.points.size() ) );
			b.set( path.points.at( ( i + 2 ) % path.points.size() ) );
			line = b - a;
		}
		
		float d;
		d = predictPos.distance( normal );
		
		if( d < record )
		{
			record = d;
			target.set( normal );
			
			dir.set( line );
			dir.normalize();
			dir *= 25;
		}
    }
	
    if( record > path.rad || vel.length() < 0.1 )
	{
		target += dir;
		return steer( target, false );
    }
    else
	{
		ofVec2f v;
		return v;
    }
    
    
}

ofVec2f vehicle :: getNormalPoint( const ofVec2f& p, const ofVec2f& a, const ofVec2f& b )
{
	ofVec2f ap;
	ap = p - a;
    
	ofVec2f ab;
	ab = b - a;
    ab.normalize();
	
	ab *= ap.dot( ab );
	
    ofVec2f normalPoint;
	normalPoint = a + ab;
    
	return normalPoint;
}

ofVec2f vehicle :: steer( const ofVec2f& trg, bool slowdown )
{
	ofVec2f steer;
    
	ofVec2f desired;
	desired = trg - pos;
    
	float d;
	d = desired.length();
	
	if( d > 0 )
	{
		desired.normalize();
		if( slowdown && ( d < 100.0f ) )
		{
			desired += maxSpeed * ( d / 100.0f );
		}
		else
		{
			desired *= maxSpeed;
		}
		
		steer = desired - vel;		// Steering = Desired minus Velocity
		steer.limit( maxForce );	// Limit to maximum steering force
    }
    else
	{
		steer.set( 0, 0 );
    }
	
    return steer;
}








