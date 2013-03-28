//
//  NewParticle.h
//  CinderPad
//
//  Created by Dave Cole on 3/27/13.
//  Copyright (c) 2013 Instrument. All rights reserved.
//

#ifndef __CinderPad__NewParticle__
#define __CinderPad__NewParticle__

#include <iostream>
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#endif /* defined(__CinderPad__NewParticle__) */


class NewParticle {
public:
	NewParticle();
    NewParticle( ci::Vec2f );
    void update( const ci::Channel32f &channel, const ci::Vec2i &mouseLoc );
	void draw();
    void setTime(float t);
	
	ci::Vec2f	mLoc;
	ci::Vec2f	mDir;
	float		mVel;
    float       mScale;
    ci::Vec2f   mDirToCursor;
	
	float		mRadius;
    ci::Color   mColor;
    float       mTime;
    float       mTimeScale;
};
