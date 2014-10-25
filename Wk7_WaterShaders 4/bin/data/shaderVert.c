#version 120 // version of GL Lib
#extension GL_ARB_texture_rectangle : enable //features
#extension GL_EXT_gpu_shader4 : enable //features

void main() {
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; //translates the current processed vertex position to the screen coordinate system
    
    gl_TexCoord[0] = gl_MultiTexCoord0; //sets the built-in vertex attribute gl_TexCoord[0] equal to the texture coordinate of the bound image
    
	gl_FrontColor = gl_Color; //not needed
}
