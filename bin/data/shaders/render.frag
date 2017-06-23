#version 150
precision mediump float;

uniform sampler2DRect lifeTex;

in vec2 vTexCoord;
in vec2 vPos;

out vec4 fragColor;

void main(){
    
    vec4 smpColor = texture(lifeTex, vPos);
    
    fragColor = smpColor;
}
