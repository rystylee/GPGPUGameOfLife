#version 150

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

out vec2 vTexCoord;
out vec2 vPos;

void main(){
    
    vTexCoord = texcoord;
    vPos = position.xy;
    
    gl_Position = modelViewProjectionMatrix * position;
}
