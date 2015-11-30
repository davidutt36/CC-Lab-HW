#pragma once

#include "ofMain.h"

class Particle{
    public:
    ofPoint loc,vel, acc;
    ofPoint *hist;
    int counter;
    Particle(){};
    Particle(ofPoint l);
    void update();
    void draw();
    void drawArrowHead(ofPoint v, ofPoint loc, float scale);
    
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
};
