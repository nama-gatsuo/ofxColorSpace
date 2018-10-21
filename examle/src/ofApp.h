#pragma once

#include "ofMain.h"
#include "ofxColorSpace.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void genColors();

private:
	vector<vector<ofFloatColor>> cols;
	vector<string> names;
	int gradNum;

	ofxButton button;
	ofxPanel panel;
	ofParameter<ofFloatColor> col1;
	ofParameter<ofFloatColor> col2;

};
