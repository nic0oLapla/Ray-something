#version 420

uniform vec2 dim;

layout(origin_upper_left) in vec4 gl_FragCoord;

//layout(location = 0) out vec4 colour;

void main() {
//    vec4 colour = vec4(
//        ((dim.x - gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
//        ((        gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
//        ((dim.x - gl_FragCoord.x) * (        gl_FragCoord.y)) / (dim.x * dim.y),
//        1.0
//    );

	gl_FragColor = vec4(
        ((dim.x - gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
        ((        gl_FragCoord.x) * (dim.y - gl_FragCoord.y)) / (dim.x * dim.y),
        ((dim.x - gl_FragCoord.x) * (        gl_FragCoord.y)) / (dim.x * dim.y),
        1.0
    );

}

