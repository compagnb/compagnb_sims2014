#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    ofDisableArbTex();
    ofLoadImage(heightMap, "heightmap1.png");
    water.loadImage("static_water.jpg");
    //    video.initGrabber(640, 480);
    ofEnableArbTex();
    
    terrainShader.load("terrain");
    
    int scale = 30;
    int w = ofGetWidth()/scale;
    int h = ofGetHeight()/scale;
    for (int y = 0; y < h; y++){
        for (int x = 0; x<w; x++){
            
            //  Per pixel we set the position, normal and texCoord
            //
            float offsetX = 0;
            float offsetY = (x%2==1)?0.5:0.0;
            terrain.addVertex(ofPoint((x+offsetX)*scale,(y+offsetY)*scale,0));
            terrain.addNormal(ofPoint(0,0,1));
            terrain.addTexCoord(ofVec2f((float)(x+offsetX)/(float)w,(float)(y+offsetY)/(float)h));
        }
    }
    
    for (int y = 0; y<h-1; y++){
        for (int x=0; x<w-1; x++){
            if(x%2==0){
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex(x+(y+1)*w);			// d
                
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex((x+1)+(y+1)*w);		// c
                terrain.addIndex(x+(y+1)*w);			// d
            } else {
                terrain.addIndex((x+1)+y*w);			// b
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex((x+1)+(y+1)*w);		// c
                
                terrain.addIndex(x+y*w);				// a
                terrain.addIndex(x+(y+1)*w);			// d
                terrain.addIndex((x+1)+(y+1)*w);		// c
            }
        }
    }
    
    
    
    bWireframe = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
//    float time = ofGetElapsedTimef();	//Get time
//	//Change vertices
//	for (int y=0; y<gridHeight; y++) {
//		for (int x=0; x<gridWidth; x++) {
//			int i = x + gridWidth * y;			//Vertex index
//			ofPoint p = terrain.getVertex( i );
//            
//			//Get Perlin noise value
//			//float value = ofNoise( x * 0.05, y * 0.05, time * 0.5 );
//            float value = ofNoise( x * mouseX, y * mouseY, time * 0.5 );
//            
//			//Change z-coordinate of vertex
//			//p.z = value * 100;
//            p.z = mouseX;
//			terrain.setVertex( i, p );
//            
//			//Change color of vertex
//			terrain.setColor( i, ofColor( value*255, value * 255, 255 ) );
//		}
//	}
	setNormals( terrain );	//Update the normals
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();				//Enable z-buffering
//    
//	//Set a gradient background from white to gray
//	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
//    
//	ofPushMatrix();						//Store the coordinate system
//    
//	//Move the coordinate center to screen's center
//	ofTranslate( ofGetWidth()*0.5, ofGetHeight()*0.5, 0 );
//    
	//Calculate the rotation angle
	float time = ofGetElapsedTimef();   //Get time in seconds
	float angle = time * 20;			//Compute angle. We rotate at speed
    
    ofBackground(0);
    
    cam.begin();
    
    ofPushMatrix();
    
    ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    
    terrainShader.begin();
    terrainShader.setUniformTexture("heightMap", heightMap,0);
    //    terrainShader.setUniformTexture("heightMap", video,0);
    terrainShader.setUniform2f("mouse",mouseX,mouseY);
    terrainShader.setUniform1f("time",ofGetElapsedTimef());     // We can play with this later ;)
    if(bWireframe){
        terrain.drawWireframe();
    } else {
        water.bind();
        terrain.draw();
        water.unbind();
    }
    terrainShader.end();
    
    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        if(key == 'w'){
            bWireframe = !bWireframe;
        } else {
            terrainShader.load("terrain");
        }

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
//Universal function which sets normals for the triangle mesh
void ofApp::setNormals(ofMesh &mesh){
    
	//The number of the vertices
	int nV = mesh.getNumVertices();
    
	//The number of the triangles
	int nT = mesh.getNumIndices() / 3;
    
	vector<ofPoint> norm( nV ); //Array for the normals
    
	//Scan all the triangles. For each triangle add its
	//normal to norm's vectors of triangle's vertices
	for (int t=0; t<nT; t++) {
        
		//Get indices of the triangle t
		int i1 = mesh.getIndex( 3 * t );
		int i2 = mesh.getIndex( 3 * t + 1 );
		int i3 = mesh.getIndex( 3 * t + 2 );
        
		//Get vertices of the triangle
		const ofPoint &v1 = mesh.getVertex( i1 );
		const ofPoint &v2 = mesh.getVertex( i2 );
		const ofPoint &v3 = mesh.getVertex( i3 );
        
		//Compute the triangle's normal
		ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        
		//Accumulate it to norm array for i1, i2, i3
		norm[ i1 ] += dir;
		norm[ i2 ] += dir;
		norm[ i3 ] += dir;
	}
    
	//Normalize the normal's length
	for (int i=0; i<nV; i++) {
		norm[i].normalize();
	}
    
	//Set the normals to mesh
	mesh.clearNormals();
	mesh.addNormals( norm );
}


