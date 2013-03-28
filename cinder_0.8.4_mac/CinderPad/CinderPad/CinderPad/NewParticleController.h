//
//  NewParticleController.h
//  CinderPad
//
//  Created by Dave Cole on 3/27/13.
//  Copyright (c) 2013 Instrument. All rights reserved.
//

#ifndef __CinderPad__NewParticleController__
#define __CinderPad__NewParticleController__

#include <iostream>

#endif /* defined(__CinderPad__NewParticleController__) */

#pragma once
#include "NewParticle.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"

#include <list>

class NewParticleController {
public:
    NewParticleController();
    NewParticleController(int res, int windowWidth, int windowHeight);
    void update( const ci::Channel32f &channel, const ci::Vec2i &mouseLoc );
    void draw();
    void addParticles(int amt);
    void addParticles(int xi, int yi);
    void removeParticles(int amt);
    void setTime(float t);
    
    std::list<NewParticle> mParticles;
    int mXRes, mYRes;
    int mWindowWidth, mWindowHeight;
};
