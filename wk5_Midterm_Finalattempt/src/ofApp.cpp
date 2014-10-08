#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofEnableSmoothing();
	
	int rows = 20;
	int cols = 20;
    
    //position all particles
	for (int i=0; i<rows*cols; i++) {
		int x = int(i) % cols * 20;
		int y = int(i) / cols * 20;
        ofVec3f pos;
        pos.set(x, y, 0);
		particle p;
        p.init(pos, 1, 0.96);
		ps.push_back(p);
	}
    
    //create all the springs
    for(int i=0; i<rows * cols; i++){
        int x = int(i) % cols;
        int y = int(i) / cols;
        
        //horizontal structural springs
		if (x<cols-1) {
            spring s;
            s.init(&ps[i],&ps[i+1],0.2);
			sp.push_back(s);
		}
		
		//vertical structural springs
		if (y<rows-1) {
            spring s;
            s.init(&ps[i],&ps[i+cols],0.2);
			sp.push_back(s);
		}
        
        //shear springs left to right
		if (x<cols-1 && y<rows-1) {
            spring s;
            s.init(&ps[i],&ps[i+cols+1],0.2);
			sp.push_back(s);
		}
		
		//shear springs right to left
		if (y>0 && x<cols-1 && y<rows) {
            spring s;
            s.init(&ps[i],&ps[i-cols+1],0.2);
			sp.push_back(s);
		}
		
		//bending springs horizontal
		if (x<cols-2) {
                spring s;
                s.init(&ps[i],&ps[i+2*cols],0.2);
                sp.push_back(s);
		}
		
		//bending springs vertical
		if (y<rows-2) {
                spring s;
                s.init(&ps[i],&ps[i+2*cols],0.2);
                sp.push_back(s);
        }
		
		//bending springs diagonal
		if (y<rows-2 && x<cols-2) {
            spring s;
            s.init(&ps[i],&ps[i+4*cols],0.2);
            sp.push_back(s);
		}
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //apply forces
    
    for(int i = 0; i <sp.size(); i++){
        ps[i].addForce(ofVec3f(0,1.1,0));
        ps[i].addForce(ofVec3f(0,0, sin(ofGetElapsedTimef() * 1.6)*8));
    }
    
    //update sprinigs
    for(int i = 0; i<sp.size(); i++){
        ps[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate((ofGetWidth()*0.5)-200, 100, -300);
    
    //springs
    ofSetColor(0, 200, 255);
    glBegin(GL_LINES);
    for (int i=0; i<sp.size(); i++) {
		glVertex3f(sp[i].a->pos.x, sp[i].a->pos.y, sp[i].a->pos.z);
		glVertex3f(sp[i].b->pos.x, sp[i].b->pos.y, sp[i].b->pos.z);
	}
	glEnd();
	
	//particles
	ofSetColor(0, 0, 255);
	glPointSize(5);
	glBegin(GL_POINTS);
	for (int i=0; i<ps.size(); i++) {
        glPointSize(10);
		glVertex3f(ps[i].pos.x, ps[i].pos.y, ps[i].pos.z);
	}
	glEnd();


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
