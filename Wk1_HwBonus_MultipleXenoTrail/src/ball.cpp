//
//
//  Wk1_HwBonus_MultipleXenoTrail
//
//  Created by compagnb on 9/2/14.
//
//


#include "ball.h"

//------------------------------------------------------------------
ball::ball(){
    catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void ball::draw(){
    
    //fill shape
    ofFill();
    
    //set color
    ofSetColor(color.r, color.g, color.b);
    
    //draw ball
    ofCircle(pos.x, pos.y, 30);

}

//------------------------------------------------------------------
void ball::xenoToPoint(float catchX, float catchY){

    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}