#version 330 core

uniform float u_time;
uniform vec2 u_resoultuon;
uniform vec2 u_mousepos;

float plotLine(vec2 norm, vec3 pct){
    return smoothstep(norm-0.01, norm, norm.y);
           smoothstep(norm, norm+0.01, norm.y);
}

void main(){
    vec2 norm = gl_FragCoord.xy / u_resoultuon.xy;


    vec3 pct = abs(sin(u_time));


    gl_FragColor = vec4(1.0,0.0,0.0,1.0);
}
