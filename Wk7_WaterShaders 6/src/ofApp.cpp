#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    nTri = 1500;
    nVert = nTri * 3;
    
    sphereRad = 250;
    triRad = 25;
    
    //fill the vericies array
    vertices.resize(nVert); // resise to the amount of vertices
    for (int i = 0; i < nTri; i++){
        // scan all the triangles and generate the center as a point on the sphere
        // take the random point from cube [-1, 1]x[-1, 1]x[-1, 1]
        center.set(ofRandom(-1, 1),ofRandom(-1, 1),ofRandom(-1, 1));
        center.normalize(); //normalize the vectors length to 1
        center *= sphereRad; // now we have the lenth of the spheres radius
        
        //geneate the triangles vertices as the center plus a random point from [-triRad,triRad]x[-triRad,triRad]x[-triRad,triRad]
        
        for (int j = 0; j < 3; j++) { // three because there are three sides to a triangle
            vertices[i*3 +j] = center + ofPoint (ofRandom( -triRad, triRad), ofRandom( -triRad, triRad), ofRandom( -triRad, triRad));
        }
    }
    //Fill the array of triangles colors
    colors.resize (nTri);
    for (int i = 0; i < nTri; i++){
        // take a random color from black to blue
        colors[i] = ofColor (0, 0, ofRandom(0, 255));
        
    }
    
    
    time0 = 0;
    phase = 0;
    distortAmt = 0;
    
    shader.load( "shaderVert.c", "shaderFrag.c" );


    
}

//--------------------------------------------------------------
void ofApp::update(){

    //compute time difference
    float time = ofGetElapsedTimef();
    float dt = ofClamp(time - time0, 0, 0.1);
    time0 = time;
    
    float speed = ofMap(mouseY, 0, ofGetHeight(), 0, 5);
    
    phase += speed * dt;
    distortAmt = ofMap(mouseX, 0, ofGetWidth(), 0, 1.0);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();				//Enable z-buffering
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    
    
    ofPushMatrix();	//Store the coordinate system
    
	//Move the coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
    
	//Calculate the rotation angle
	float time = ofGetElapsedTimef();	//Get time in seconds
	float angle = time * 10;			//Compute angle. We rotate at speed 10 degrees per second
	ofRotate( angle, 0, 1, 0 );			//Rotate the coordinate system along y-axe
    

    shader.begin();
    shader.setUniform1f("phase", phase);
    shader.setUniform1f("distortAmt", distortAmt);
    
    //draw the triangles
    for (int i = 0; i<nTri; i++) {
        ofSetColor(colors[i]);
        ofTriangle(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
    }
   
    shader.end();
    
    ofPopMatrix(); // Restre coordinate system



}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
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

