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
		int x = i % cols * 20;
		int y = i / cols * 20;
		particle p;
        p.setInitialCondition(x, y,0, 0.96,y==0 ? 0 : 1 );
		ps.push_back(p);
	}
    
    //create all the springs
    for(int i=0; i<rows * cols; i++){
        int x = int(i) % cols;
        int y = int(i) / cols;
        
        //horizontal structural springs
		if (x<cols-1) {
            spring s;
            s.distance=(&ps[i] - &ps[i+1]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
			sp.push_back(s);
		}
		
		//vertical structural springs
		if (y<rows-1) {
            spring s;
            s.distance=(&ps[i]-&ps[i+cols]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
			sp.push_back(s);
		}
        
        //shear springs left to right
		if (x<cols-1 && y<rows-1) {
            spring s;
            s.distance = (&ps[i]-&ps[i+cols+1]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
			sp.push_back(s);
		}
		
		//shear springs right to left
		if (y>0 && x<cols-1 && y<rows) {
            spring s;
            s.distance = (&ps[i]-&ps[i-cols+1]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
			sp.push_back(s);
		}
		
		//bending springs horizontal
		if (x<cols-2) {
            spring s;
            s.distance = (&ps[i]-&ps[i+2*cols]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
            sp.push_back(s);
		}
		
		//bending springs vertical
		if (y<rows-2) {
            spring s;
            s.distance = (&ps[i]-&ps[i+2*cols]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
            sp.push_back(s);
        }
		
		//bending springs diagonal
		if (y<rows-2 && x<cols-2) {
            spring s;
            s.distance = (&ps[i]-&ps[i+4*cols]);
            s.springiness = 0.2f;
            s.a = &(ps[i]);
            s.b = &(ps[(i+1) % ps.size()]);
            sp.push_back(s);
		}
    }
//     for(int i=0; i<rows * cols; i++){
//         sp[i].rest_length = (sp[i].b->pos - sp[i].a->pos).length();
//     }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //apply forces
    
    for(int i = 0; i <sp.size(); i++){
        ps[i].resetForce();
        ps[i].addForce(0, sin(ofGetElapsedTimef() * 1.6)*8);
    }
    
    //update sprinigs
    for(int i = 0; i<sp.size(); i++){
        sp[i].update();
    }
    
    for (int i = 0; i < ps.size(); i++){
		//ps[i].bounceOffWalls();
		ps[i].addDampingForce();
		ps[i].update();
	}
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest(); // enable z buffering
    
    
ofTranslate(ofGetWidth()/2-200, 100, -300);
	
//    glBegin(GL_POINT);
//    glPointSize(5);
    for (int i = 0; i < ps.size(); i++){
		ps[i].draw();
//        glVertex3f(ps[i].pos.x, ps[i].pos.y,0);
        
	}
//    glEnd();
    
    glBegin(GL_LINES);
    glLineWidth(2);
    for (int i = 0; i < sp.size(); i++){
        glVertex3f(sp[1].a->pos.x, sp[1].a->pos.y,0);
        glVertex3f(sp[1].b->pos.x, sp[1].b->pos.y,0);
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
