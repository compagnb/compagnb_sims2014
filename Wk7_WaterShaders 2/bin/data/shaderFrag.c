#version 120 // version of GL Lib
#extension GL_ARB_texture_rectangle : enable //features
#extension GL_EXT_gpu_shader4 : enable //features

uniform sampler2DRect texture0; //says we will be using texture

uniform float time; //says we will be utilizing a float called time which we are passing from OF

void main(){
	//Get coordinates of the current pixel in texture
	vec2 pos = gl_TexCoord[0].st;
    
    //Change the pos by a sinwave
    //float amp = sin(pos.y *0.03);
    float amp = sin(pos.x *0.03);
    
    //Shift x-coordinate
    pos.x += sin( time * 2.0 ) * amp * 50.0;
        
    //Get pixel color from texture tex0 in position pos
    vec4 color = texture2DRect( texture0, pos );
    
    //Output of shader
    gl_FragColor = color;

    
}
