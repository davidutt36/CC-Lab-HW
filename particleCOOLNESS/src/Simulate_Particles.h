//
//  Simulate_Particles.h
//  
//
//  Created by David Utt on 11/29/15.
//
//

#ifndef ____Simulate_Particles__
#define ____Simulate_Particles__

#include <stdio.h>
#include "ofMain.h"

class Particle {
public:
    ofPoint loc, vel, acc;
    ofPoint *hist;
    int counter;
    Particle(){};
    Particle(ofPoint l);
    void draw();
    void drawArrowHead(ofPoint v, ofPoint loc, float scale);
};

class testApp : public ofBaseApp{
    
public:
    void setup();
    void draw();
};



#endif /* defined(____Simulate_Particles__) */
