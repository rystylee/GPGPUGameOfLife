#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    updateLife.load("shaders/updateLife");
    render.load("shaders/render");
    
    cellWidth = ofGetWidth();
    cellHeight = ofGetHeight();
    
    vector<float> color(cellWidth * cellHeight * 3);
    for(int x=0; x<cellWidth; x++){
        for(int y=0; y<cellHeight; y++){
            int i = cellWidth * y + x;
            float coin = ofRandom(1.0) < 0.5 ? 0.0 : 1.0;
            color[i*3+0] = 0.0;
            color[i*3+1] = coin;
            color[i*3+2] = 0.0;
        }
    }
    
    pingPong.allocate(cellWidth, cellHeight, GL_RGB32F);
    pingPong.src->getTexture().loadData(color.data(), cellWidth, cellHeight, GL_RGB);
    pingPong.dst->getTexture().loadData(color.data(), cellWidth, cellHeight, GL_RGB);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    pingPong.dst->begin();
    ofClear(0);
    
    updateLife.begin();
    updateLife.setUniformTexture("backbuffer", pingPong.src->getTexture(), 0);
    pingPong.src->draw(0, 0);
    updateLife.end();
    
    pingPong.dst->end();
    
    pingPong.swap();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    render.begin();
    render.setUniformTexture("lifeTex", pingPong.dst->getTexture(), 0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    render.end();
    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
