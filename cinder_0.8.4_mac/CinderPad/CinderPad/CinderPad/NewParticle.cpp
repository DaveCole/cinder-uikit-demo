//
//  NewParticle.cpp
//  CinderPad
//
//  Created by Dave Cole on 3/27/13.
//  Copyright (c) 2013 Instrument. All rights reserved.
//

#include "NewParticle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
//#include "cinder/app/AppBasic.h"

using namespace ci;

NewParticle::NewParticle(){
    
}

NewParticle::NewParticle( Vec2f loc ){
    mLoc    = loc;
    mDir    = Rand::randVec2f();
    mVel    = Rand::randFloat(5.0f);
    //mRadius = Rand::randFloat(1.0f, 5.0f);
    mRadius = 10.0f;
    mScale  = 7.0f;
    mDir = Rand::randVec2f();
    mDirToCursor = Vec2f::zero();
    mTime = 0.0f;
    mTimeScale = 10.0f;
    
    float xyOffset = sin(cos(sin(mLoc.y * 0.3183f) + cos(mLoc.x * 0.3183f))) + 1.0f;
    //mRadius = xyOffset * xyOffset * 1.8f;
}


void NewParticle::update( const Channel32f &channel, const ci::Vec2i &mouseLoc ){
    //mLoc += mDir * mVel;
    //std::cout << mouseLoc.x;
    
    mDirToCursor = mouseLoc - mLoc;
    
    float distToCursor = mDirToCursor.length();
    //float time = 1; //app::getElapsedSeconds();  // *** to do: put seconds detector back in
    float dist = distToCursor * 0.025f;
    float sinOffset = sin(dist - mTime) + 1.0f;
    
    
    mDirToCursor.safeNormalize();
    mDirToCursor *= sinOffset * 100.0f;
    Vec2f newLoc = mLoc + mDirToCursor;
    newLoc.x = constrain(newLoc.x, 0.0f, channel.getWidth() - 1.0f);
    newLoc.y = constrain(newLoc.y, 0.0f, channel.getHeight() - 1.0f);
    
    float gray = channel.getValue(mLoc);
    mColor = Color(gray,gray,gray);
    //mRadius = channel.getValue(mLoc) * mScale;
}

void NewParticle::draw(){
    gl::color(mColor);
    //gl::drawSolidCircle(mLoc + mDirToCursor * 0.2f, mRadius);
    Vec2f newLoc = mLoc + mDirToCursor * 0.2f;
    Rectf rect(newLoc.x, newLoc.y, newLoc.x + mRadius, newLoc.y + mRadius);
    gl::drawSolidRect(rect);
}

void NewParticle::setTime(float t){
    mTime = t * mTimeScale;
}