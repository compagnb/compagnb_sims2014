//
//
//  Wk4_Hw_PathFollow
//
//  Created by compagnb on 9/27/14.
//  based on http://www.shiffman.net/teaching/nature/path-following/OM,
//
//

#include "path.h"

//--------------------------------------------------
void path::init(){
    
    rad = 20;
}

//--------------------------------------------------
void path::addPoint(float x, float y){
    
    points.push_back(ofVec2f());
    points.back().set(x, y);
    
}

//--------------------------------------------------
void path::draw(){
    
    for(int i = 0; i < points.size(); i++){
        ofVec2f& point = points.at(i);
        ofSetColor(200, 200, 200);
        ofNoFill();
        ofEllipse(point.x, point.y, rad * 2, rad * 2);
    }
    
    for(int i = 0; i < points.size(); i++){
     
        ofPoint start;
        start.set(i);
        ofPoint end;
        end.set((i + 1) % points.size());
        ofVec2f line = end - start;
        
        ofVec2f normal;
        normal.set (line.y, -line.x);
        normal.normalize();
        normal *= rad;
        
        ofPoint a = start + normal;
        ofPoint b = end = normal;
        ofPoint c = end - normal;
        ofPoint d = start - normal;
        
        ofSetColor(255);
        ofFill();
        ofBeginShape();
        ofVertex( a.x, a.y );
		ofVertex( b.x, b.y );
		ofVertex( c.x, c.y );
		ofVertex( d.x, d.y );
		ofEndShape( false );
    }
    
    ofSetColor(0,0,0);
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < points.size(); i++){
        
        ofVec2f& loc = points.at(i);
        ofVertex(loc.x, loc.y);
    }
    ofEndShape(true);
    
}