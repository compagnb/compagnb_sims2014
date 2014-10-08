#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //    // pyramids base verticies with indices 0, 1, 2
    //    myMesh.addVertex (ofPoint(-200, -400, -300));
    //    myMesh.addVertex (ofPoint(200, -400, -300));
    //    myMesh.addVertex (ofPoint(0, -400, 0));
    
    //    //pyamids top vertex with index 3
    //    myMesh.addVertex(ofPoint (0, 0, 300));
    //
    //    //verticies with indices 3, 2, 0
    //    myMesh.addTriangle(3, 2, 0);
    //
    //    //verticies with indices 3, 1, 2
    //    myMesh.addTriangle(3, 1, 2);
    //
    //    //verticies with indices 3, 0, 1
    //    myMesh.addTriangle(3, 0, 1);
    
    // pyramids base vertices
    ofPoint v0 = ofPoint( -200, -100, 0 );
	ofPoint v1 = ofPoint( 200, -100, 0 );
	ofPoint v2 = ofPoint(  0, 200, 0 );
    
    // pyramids top vertex
    ofPoint v3 = ofPoint( 0, 0, 100 );
    
    
    // Add triangles by its vertices
    myMesh.addVertex(v3); myMesh.addVertex(v2); myMesh.addVertex(v0);
    myMesh.addVertex(v3); myMesh.addVertex(v1); myMesh.addVertex(v2);
    myMesh.addVertex(v3); myMesh.addVertex(v0); myMesh.addVertex(v1);
    
    myMesh.setupIndicesAuto();	//Set up indices
    
    
    // set up a texture with coordinates for all vertices
    myMesh.addTexCoord(ofPoint(100, 100)); // v3
    myMesh.addTexCoord(ofPoint(10, 300)); // v2
    myMesh.addTexCoord(ofPoint (10, 10)); // v0
    myMesh.addTexCoord(ofPoint(100,100)); // v3
    myMesh.addTexCoord(ofPoint(300, 10)); // v1
    myMesh.addTexCoord(ofPoint(10, 300)); // v2
    myMesh.addTexCoord(ofPoint(100, 100)); // v3
    myMesh.addTexCoord(ofPoint(10, 10)); // v0
    myMesh.addTexCoord(ofPoint(300, 10)); //v1
    
    water.loadImage("static_water.jpg");
    
    //set normals a function for the light to work
    setNormals(myMesh);
    
    //enable light source
    myLight.enable();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest(); // enable z buffering
    
    ofBackgroundGradient(ofColor(255), ofColor(128));
    
    ofPushMatrix(); // str coordinate system
    
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5, 0); // moove coordinates to the center of the screen
    
    time = ofGetElapsedTimef(); // get time in seconds
    angle = time * 30; // rotation angle
    ofRotate(angle, 0, 1, 1);
    
//    ofSetColor(200, 0, 200);
//    myMesh.draw();
//
    
    ofSetColor(255);
    water.bind(); // use image's texture for drawing
    myMesh.draw(); // draw
    water.unbind(); // end using images texture
    
    
    ofPopMatrix();
    
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
void ofApp::setNormals(ofMesh &mesh){
    
    // the number of the verticies
    int nV = mesh.getNumVertices();
    
    // the number of tringles
    int nT = mesh.getNumIndices()*.33;
    
    vector <ofPoint> norm (nV); // array for the normals
    
    //scan all the triangles... for each triangle adds its normal to norm's vector of he triangles verticies
    for(int i = 0; i < nT; i++){
        // get all the indices of the triangle i
        int i1 = myMesh.getIndex(3 * i);
        int i2 = myMesh.getIndex(3 * i + 1);
        int i3 = myMesh.getIndex(3 * i + 2);
        
        //get all the verticies of the triangle
        const ofPoint &v1 = myMesh.getVertex (i1);
        const ofPoint &v2 = myMesh.getVertex (i2);
        const ofPoint &v3 = myMesh.getVertex (i3);
        
        // computer the traingles normal
        ofPoint dir = ((v2 -v1).crossed(v3 -v1)).normalized();
        
        // accumulate it to norm array for i1, i2, i3
        norm [i1 ]+= dir;
        norm [i2 ]+= dir;
        norm [i3 ]+= dir;
    }
    
    // normalize the normal length
    for(int i=0; i<nV; i++){
        norm[i].normalize();
    }
    
    //Set the normals to mesh
    myMesh.clearNormals();
    myMesh.addNormals(norm);
    
    
    
}

