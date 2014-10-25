#version 120 // version of GL Lib
#extension GL_ARB_texture_rectangle : enable //features
#extension GL_EXT_gpu_shader4 : enable //features


uniform sampler2DRect texture0; //says we will be using texture
uniform sampler2DRect texture1; //second texture being used


void main(){
	//Get coordinates of the current pixel in texture
	vec2 pos = gl_TexCoord[0].xy;
    vec4 color0 = texture2DRect (texture0, pos);
    vec4 color1 = texture2DRect (texture1, pos);
    
    //compute resulted color
    vec4 color;
    color.rgb = color0.rgb;
    color.a = color1.r;
    
    //Output of shader
    gl_FragColor = color;

    
}
