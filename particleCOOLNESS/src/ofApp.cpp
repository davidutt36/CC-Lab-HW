#include "ofApp.h"

Particle *particles;
bool saving = false;

float mag(ofPoint in){
    float retf = sqrt(in.x * in.x + in.y * in.y);
    return retf;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    particles = new Particle[500];
    for(int i = 0; i<500; i++){
        particles[i] = Particle(ofPoint(ofGetWidth()/2,ofGetHeight()/2));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(122,175,224);
    for(int i = 0;i<500;i++){
        particles[i].update();
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

ofImage screenshot;
    screenshot.allocate(ofGetScreenWidth(), ofGetScreenHeight(), OF_IMAGE_COLOR);
    screenshot.grabScreen(0,0,1024,768);
    screenshot.saveImage("screenshot.png");
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
Particle:: Particle(ofPoint l){
    counter = 0;
    float randmin = HALF_PI;
    float randmax = 0;
    
    float r = ofRandom(0, TWO_PI);
    float x = cos(r);
    float y = sin(r);
    acc = ofPoint(x/20, y/20);

    float q = ofRandom(0,1);
    r = ofRandom(randmin,randmax);
    x = cos(r)*q;
    y = sin(r)*q;
    vel = ofPoint(x,y);
    loc = l;
    hist = new ofPoint[500];
}

void Particle::update(){
    vel += acc;
    loc += vel;
    float q = ofRandom(0,1);
    
    if(ofGetFrameNum() % 25 == 0 && counter< 500){
        hist[counter].x = loc.x;
        hist[counter].y = loc.y;
        counter++;
    }
    if(loc.x > ofGetWidth() || loc.x<0){
        vel =vel*(-1);
    }
    if(loc.y > ofGetHeight() || loc.y<0){
        vel=vel*(-q);
    }

}

void Particle::draw(){
    ofFill();
    ofSetColor(100, 100, 100,100);
    drawArrowHead(vel, loc, 2);
    ofNoFill();
//    ofSetColor(118, 208, 244);
    ofBeginShape();
    for(int i =0; i<counter;i++){
        ofVertex(hist[i].x, hist[i].y);
        ofSetColor(118, 208, 244, 20);
    }
    
    if(counter > 0) ofVertex(loc.x,loc.y);
    ofEndShape(false);
}

void Particle::drawArrowHead(ofPoint v, ofPoint loc, float scale){
    ofPushMatrix();
    float arrowsize = 4.0f;
    ofTranslate(loc.x, loc.y,0);
    float rotate = atan2(v.y, v.x);
    ofRotate(ofRadToDeg(rotate), 0, 0, 1);
    
    float len = mag(v) * scale;
    arrowsize = ofMap(len, 0.f, 10.f, 0.f, 1.f, false) * arrowsize;
    
    ofLine(0, 0, len-arrowsize, 0);
    
    ofBeginShape();
    ofVertex(len, 0);
    ofVertex(len-arrowsize, arrowsize/2);
    ofVertex(len-arrowsize, -arrowsize/2);
    ofEndShape(true);
    
    ofPopMatrix();
}








