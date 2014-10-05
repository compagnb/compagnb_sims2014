//
//  rock.cpp
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#include "rock.h"

rock::rock(){
    pos.set(0, 0); // position
    vel.set(0,0); // speed
    acc.set(0, 0.3f); // gravity
    rad = 50;
    
}

void rock:: update(){
    
//    if (pos.y > water.GetHeight(pos.x)){
//        Velocity *= 0.84f;
//    }
    
    pos += vel;
    vel += acc;
    
}

void rock::draw(){
    
    ofSetColor(200, 200, 200);
    ofFill();
    ofCircle(pos, rad);
    
//    Vector2 origin = new Vector2(texture.Width, texture.Height) / 2f;
//    spriteBatch.Draw(texture, Position, null, Color.White, 0f, origin, 1f,

}