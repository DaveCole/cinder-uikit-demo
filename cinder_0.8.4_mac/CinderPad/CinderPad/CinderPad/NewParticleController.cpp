//
//  NewParticleController.cpp
//  CinderPad
//
//  Created by Dave Cole on 3/27/13.
//  Copyright (c) 2013 Instrument. All rights reserved.
//

#include "NewParticleController.h"

//#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

using namespace ci;

NewParticleController::NewParticleController(){
    
}


NewParticleController::NewParticleController(int res, int windowWidth, int windowHeight){
    
    //mXRes = app::getWindowWidth()/res;
	//mYRes = app::getWindowHeight()/res;
	
    mWindowWidth = windowWidth;
    mWindowHeight= windowHeight;
    mXRes = windowWidth/res;
    mYRes = windowHeight/res;
    
    for(int y=0; y < mYRes; y++){
        for (int x=0; x < mXRes; x++){
            addParticles(x,y);
        }
    }
     
}

void NewParticleController::update( const Channel32f &channel, const Vec2i &mouseLoc ){
    for (std::list<NewParticle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p){
        p->update( channel, mouseLoc );
    }
}

void NewParticleController::draw(){
    for (std::list<NewParticle>::iterator p = mParticles.begin(); p!= mParticles.end(); ++p){
        p->draw();
    }
}

void NewParticleController::addParticles(int amt){
    for (int i=0; i < amt; i++){
        float x = Rand::randFloat( mWindowWidth );
        float y = Rand::randFloat( mWindowHeight );
        mParticles.push_back(NewParticle(Vec2f(x,y)));
        
    }
}

void NewParticleController::addParticles(int xi, int yi){
    float x = (xi + 0.5f) * 10.0f;
    float y = (yi + 0.5f) * 10.0f;
    mParticles.push_back(NewParticle(Vec2f(x,y)));
}

void NewParticleController::removeParticles(int amt){
    for (int i=0; i < amt; i++){
        mParticles.pop_back();
    }
}

void NewParticleController::setTime(float t){
    for (std::list<NewParticle>::iterator p=mParticles.begin(); p != mParticles.end(); ++p){
        p->setTime(t);
    }
}