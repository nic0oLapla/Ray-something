#version 460

uniform vec2 dim;

layout(origin_upper_left) in vec4 gl_FragCoord;


void main() {

//	gl_FragColor = vec4(
//        ((dim.x - gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
//        ((        gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
//        ((dim.x - gl_FragCoord.x) * (        gl_FragCoord.y)) / (dim.x * dim.y),
//        1.0
//    );

	

}

