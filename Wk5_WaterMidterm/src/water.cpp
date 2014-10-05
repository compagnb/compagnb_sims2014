//
//  water.cpp
//  Wk5_WaterMidterm
//
//  Created by compagnb on 10/4/14.
//
//

#include "water.h"


void water::init() {
    waterCols = 200;
    
    for (int i = 0; i < waterCols; i++) {
        spring s;
        s.init(i*5, 500, 440, 0);
        springs.push_back(s);
    }
}

void water::update() {
	for (int i = 0; i < springs.size(); i++)
        springs[i].update(damp, k);
    
    float lDeltas[springs.size()];
    float rDeltas[springs.size()];
    // do some passes where columns pull on their neighbours
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < springs.size(); i++)
        {
            if (i > 0)
            {
                lDeltas[i] = spread * (springs[i].height - springs[i - 1].height);
                springs[i - 1].speed += lDeltas[i];
            }
            if (i < springs.size() - 1)
            {
                rDeltas[i] = spread * (springs[i].height - springs[i + 1].height);
                springs[i + 1].speed += rDeltas[i];
            }
        }
        
        for (int i = 0; i < springs.size(); i++)
        {
            if (i > 0)
                springs[i - 1].height += lDeltas[i];
            if (i < springs.size() - 1)
                springs[i + 1].height += rDeltas[i];
        }
    }


}
void water::draw() {
    ofFill();
    ofMesh mesh;
    //ofVertex(0,ofGetHeight());
    
    for (int i = 0; i < waterCols; i++) {
        mesh.addColor(ofFloatColor (0,200,255));
        mesh.addVertex(ofPoint(i* springs[i].xpos, springs[i].height));
        mesh.addColor(ofFloatColor (0,200,255));
        mesh.addVertex(ofPoint((i*-1) * springs[i].xpos, springs[i].height));
        mesh.addColor(ofFloatColor (50,50,255));
        mesh.addVertex(ofPoint(i * springs[i].xpos, ofGetHeight()));
        mesh.addColor(ofFloatColor (50,50,255));
        mesh.addVertex(ofPoint((i *- 1)* springs[i].xpos, ofGetHeight()));
        }
    
    mesh.draw();
//    ofVertex(ofGetWidth(),springs[waterCols-1].height);
//    ofVertex(ofGetWidth(),ofGetHeight());
//    ofEndShape();

}


void water::splash(float index, float speed) {
    if (index >= 0 && index < springs.size()){
//        springs[i].speed = speed;
        }
}