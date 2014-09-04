//
//
// wk1_InClass_FollowMouse
//
//  Created by compagnb on 8/28/14.
//
//

#include "ball.h"

//------------------------------------------------------------------------------
ball::ball(){
    //outerRad = rad * 2;
    //innerRad = rad * 1.75;
    
    //    speedX = 3;
}

//------------------------------------------------------------------------------
void ball::update(){
    //
    //    if (collide == true){
    //        colorR = 200;
    //        colorG = 0;
    //        colorB = 200;
    //
    //    } else if (collide ==false){
    //        colorR = 0;
    //        colorB = 0;
    //    }
}

//------------------------------------------------------------------------------
void ball::draw(){
    
    ofSetColor(255, 80);
    ofFill();
    ofCircle(posX, posY, rad);
}
