#version 120 // version of GL Lib
#extension GL_ARB_texture_rectangle : enable //features
#extension GL_EXT_gpu_shader4 : enable //features

uniform float phase = 0.0;  //phase for sin function
uniform float distortAmt = 0.25; //amt of distortion

void main() {
	
    //get the original position of the vertex
    vec3 v = gl_Vertex.xyz;
    
    //compute the value of distortion for the current vertex
    float distort = distortAmt * sin(phase + 0.015 * v.y);
    
    //move position
    v.x /= 1.0 + distort;
    v.y /= 1.0 + distort;
    v.z /= 1.0 + distort;
    
    //set output position
    vec4 posHomog = vec4( v, 1.0 );
	gl_Position = gl_ModelViewProjectionMatrix * posHomog;
    
    //set output texture coordinate and color
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}
