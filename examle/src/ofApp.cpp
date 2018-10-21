#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	panel.setup();
	panel.add(col1.set("start_color", ofFloatColor(1., 1., 0)));
	panel.add(col2.set("end_color", ofFloatColor(0., 0., 1.)));
	
	button.setup("exec");
	button.addListener(this, &ofApp::genColors);
	panel.add(&button);

	names = {
		"rgb", "hsl", "hsb", "hsv", "Luv", "Lab", "HunterLab", "Lch", "Cmy", "Yxy"
	};
	cols.assign(names.size(), vector<ofFloatColor>());
	gradNum = 11;

	genColors();

	ofBackground(200);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	float s = 50.;
	float offset = 5.;

	for (int i = 0; i < cols.size(); i++) {

		ofSetColor(0);
		ofDrawBitmapString(names[i], 20., 50. + (s + offset) * i);

		for (int j = 0; j < cols[i].size(); j++) {
			ofSetColor(cols[i][j]);
			ofDrawRectangle(100. + (s + offset) *j, 20. + (s + offset) * i, s, s);
		}
	}

	panel.draw();
}


void ofApp::keyPressed(int key){
	

}

void ofApp::genColors() {
	cols[0] = ofxColorSpace::getGradientBy<ofxColorSpace::Rgb>(col1.get(), col2.get(), gradNum);
	cols[1] = ofxColorSpace::getGradientBy<ofxColorSpace::Hsl>(col1.get(), col2.get(), gradNum);
	cols[2] = ofxColorSpace::getGradientBy<ofxColorSpace::Hsb>(col1.get(), col2.get(), gradNum);
	cols[3] = ofxColorSpace::getGradientBy<ofxColorSpace::Hsv>(col1.get(), col2.get(), gradNum);
	cols[4] = ofxColorSpace::getGradientBy<ofxColorSpace::Luv>(col1.get(), col2.get(), gradNum);
	cols[5] = ofxColorSpace::getGradientBy<ofxColorSpace::Lab>(col1.get(), col2.get(), gradNum);
	cols[6] = ofxColorSpace::getGradientBy<ofxColorSpace::HunterLab>(col1.get(), col2.get(), gradNum);
	cols[7] = ofxColorSpace::getGradientBy<ofxColorSpace::Lch>(col1.get(), col2.get(), gradNum);
	cols[8] = ofxColorSpace::getGradientBy<ofxColorSpace::Cmy>(col1.get(), col2.get(), gradNum);
	cols[9] = ofxColorSpace::getGradientBy<ofxColorSpace::Yxy>(col1.get(), col2.get(), gradNum);
}

