#version 150
precision mediump float;

uniform sampler2DRect backbuffer;

in vec2 vTexCoord;
in vec2 vPos;

out vec4 fragColor;

void main(){
    
    float life = texture(backbuffer, vPos).g;
    float count = 0.0;
    for(int x=-1; x<=1; x++){
        for(int y=-1; y<=1; y++){
            if(!(x == 0 && y == 0)){
                count += texture(backbuffer, vPos+vec2(x,y)).g;
            }
        }
    }
    
    float nextlife = 0.0;
    if(life == 0.0){
        if(count == 3.0){
            nextlife = 1.0;
        } else {
            nextlife = 0.0;
        }
    } else {
        if(count == 0 || count == 1){
            nextlife = 0.0;
        } else if(count == 2 || count == 3){
            nextlife = 1.0;
        } else {
            nextlife = 0.0;
        }
    }
    
    fragColor = vec4(0.0, nextlife, 0.0, 1.0);
}
