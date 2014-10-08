#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    height = ofPoint (20,20);
    vel = ofPoint (20, 20);
    float velMap [20][20];
    float gravity=0.1;
    vector<int>sel;
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    // Determining the change in velocity for each ball.
    //
    
    int y, x;
    for (y=0;y<20;y++) {
        for (x=0;x<20;x++) {
            //if (sel != 0 && sel[0] == x && sel[1] == y) continue;
            float h = heightMap[x][y];
            float v = velMap[x][y];
            
            int x1=0;
            int y1=0;
            
            float f=0;
            for (y1=-1;y1<2;y1++) {
                for (x1=-1;x1<2;x1++) {
                    if (x+x1 > 0 && x+x1 < 19 && y+y1 > 0 && y+y1 < 19 && (x1 != 0 || y1 != 0)) {
                        f += heightMap[x+x1][y+y1];
                    }
                }
            }
            f/=8;
            f = (f-h)/10;
            
            velMap[x][y] -= f;
            velMap[x][y] *=0.95;
            
            heightMap[x][y]-=velMap[x][y];
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
