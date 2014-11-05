//Barbara Compagnoni
//Creative Code Fall 2014
//Vertex Deformation

#version 120 //what version of the GL library is being used
#extension GL_ARB_texture_rectangle : enable // enable feature
#extension GL_EXT_gpu_shader4 : enable // enable feature

void main()
{
	gl_FrontColor =  gl_Color;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = gl_Vertex;
}
