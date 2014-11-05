#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //specify shader parameters
    shader.setGeometryInputType(GL_LINES);
    shader.setGeometryOutputType(GL_LINE_STRIP);
    shader.setGeometryOutputCount(128); //maximum output verticies
    
    //load shader
    shader.load( "shaderVert.c","shaderFrag.c", "shaderGeom.c" );
    
    fbo.allocate( ofGetWidth(), ofGetHeight() );
	water.loadImage( "static_water.jpg" );
    
    width = ofGetWidth();
    height = ofGetHeight();

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw in the fbo first
    fbo.begin();
    ofBackground(0);
    ofSetColor(255);
    float w1 = water.width * 2;
    float h1 = water.height * 2;
    water.draw( width/2-w1/2, height/2-h1/2, w1, h1 );
	fbo.end();
    
    //read contents of rendered fbo
    ofPixels pixels;
    fbo.readToPixels(pixels);
    
    //draw it to screen
    ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
    
	shader.begin();
    //Set shader's parameters
	float time = ofGetElapsedTimef();
	shader.setUniform1f( "time", time );
	shader.setUniformTexture( "texture", fbo.getTextureReference(), 1 );
    
	//Draw lines (through vertex->geometry->fragment shaders)
	ofSetColor( 255, 255, 255 );
	int stepx = 10;
	int stepy = 10;
	float len = 20;
	//Scan fbo pixels colors and search for not-transparent pixels
	for (int y=0; y<height; y+=stepy) {
		for (int x=0; x<width; x+=stepx) {
			if ( pixels.getColor( x, y ).a > 0 ) {
				//Draw line
				ofLine( x, y, x, y - len );
			}
		}
	}
    
	//Hint: for better performance, we can use ofMesh and GL_LINE_STRIP in shader ,
	//but in this example we use lines for simplicity
    
	shader.end();
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
