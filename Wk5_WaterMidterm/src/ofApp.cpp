#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    water.init();
    
//    waterCols = 200;
//
//    for (int i = 0; i < waterCols; i++) {
//        spring s;
//        s.init(i*5, 500, 440, 0);
//        springs.push_back(s);
//    }


}

//--------------------------------------------------------------
void ofApp::update(){
    mouse.x = mouseX;// + ofRandom(-(440-mouseY),(440-mouseY));
    mouse.y = mouseY;// + ofRandom(-100,100);
//    
////   for (int i = 0; i < waters.size(); i++) {    
//    for (int i = 0; i < springs.size(); i++) {
//        //Hooke's Law on each spring 
//        waters[i].update(damp, k);
//        }
//        
//    float lDeltas[waters.size()];// stores the difference in height between each spring and its left neighbor
//    float rDeltas[waters.size()];//stores the difference in height between each spring and its right neighbor
//        
//    for (int j = 0; j < 8; j++) {
//        for (int l = 0; l < waters.size(); l++) {
//            //if statements modify the heights of the springs. We have to measure the height differences before any of the heights are modified.
//            if (l > 0) {
//                lDeltas[l] = spread * (waters[l].height - waters[l-1].height);
//                waters[l-1].speed += lDeltas[l];
//            }
//            if (l < waters.size()-1){
//                rDeltas[l] = spread * (waters[l].height - waters[l+1].height);
//                waters[l+1].speed += rDeltas[l];
//            }
//        }
//    for (int r = 0; r < waters.size(); r++) {
//            if ( r > 0 ) {
//                waters[r-1].height += lDeltas[r];
//            }
//            if (r < waters.size() - 1) {
//                waters[r+1].height += rDeltas[r];
//            }
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Set a gradient background from white to gray
	//for adding an illusion of visual depth to the scene
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    
    water.draw();
    
//    ofSetColor(0,200,255);
//    ofFill();
//    ofBeginShape();
//    ofVertex(0,ofGetHeight());
//    for (int i = 0; i < waterCols; i++) {
//        ofVertex(springs[i].xpos, springs[i].height);
//    }
//    ofVertex(ofGetWidth(),springs[waterCols-1].height);
//    ofVertex(ofGetWidth(),ofGetHeight());
//    ofEndShape();
    
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
//--------------------------------------------------------------
//public void Splash(int index, float speed)
//{
//    if (index >= 0 && index < springs.Length)
//        springs[i].Speed = speed;
//}
