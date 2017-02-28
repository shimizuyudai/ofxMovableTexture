#include "ofxMovableTexture.h"

void ofxMovableTexture::setup(float x, float y, float w, float h)
{
	isActive = true;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

void ofxMovableTexture::draw(const ofTexture & texture)
{
	if (!isActive)return;
	texture.draw(x,y,w,h);
	if (isSelected) {
		ofPushStyle();
		ofNoFill();
		ofSetColor(0, 255, 0);
		ofDrawRectangle(x, y, w, h);
		ofPopStyle();
	}
}

void ofxMovableTexture::mouseDragged(int x, int y, int button)
{
	if (isSelected) {
		this->x += x - ofGetPreviousMouseX();
		this->y += y - ofGetPreviousMouseY();
	}
}

void ofxMovableTexture::mousePressed(int x, int y, int button)
{
	isSelected = false;
	if (x > this->x && x < this->x + this->w) {
		if (y > this->y && y < this->y + this->h) {
			isSelected = true;
		}
	}
}

void ofxMovableTexture::keyPressed(int key)
{
	if (isSelected) {
		if (key == OF_KEY_BACKSPACE) {
			this->isActive = false;
		}
	}
}

void ofxMovableTexture::setActive(bool isActive)
{
	this->isActive = isActive;
}

ofVec2f ofxMovableTexture::getPosition()
{
	return ofVec2f(this->x,this->y);
}

ofVec2f ofxMovableTexture::getSize()
{
	return ofVec2f(this->w,this->h);
}
