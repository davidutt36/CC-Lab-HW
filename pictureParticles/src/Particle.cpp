#include "Particle.h"

void Particle::setup() {
    vel.x = 2*ofRandomf();
    vel.y = 2*ofRandomf();
    //angle = ofRandomf()*TWO_PI;
    age = 0;
}

void Particle::draw() {
    ofSetColor(color,ofMap(age,0,20,255,0,true));
    ofLine(oldpos,pos);
}

void Particle::update() {
    //angle += ofSignedNoise(pos.x, pos.y)*TWO_PI;
    vel.rotate(180);
    oldpos = pos;
    pos += vel;
    age++;
}
