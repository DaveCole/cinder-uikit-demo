//
//  MyCCGLView.mm
//  CCGLTouchBasic example
//
//  Created by Matthieu Savary on 09/09/11.
//  Copyright (c) 2011 SMALLAB.ORG. All rights reserved.
//
//  More info on the CCGLTouch project >> http://cocoacid.org/ios/
//  License & disclaimer >> see license.txt file included in the distribution package
//
//  Latest revision on 10/06/12.
//

#import "MyCCGLView.h"

#define TOTAL_PARTICLES 4800
#define RESOLUTION 10

using namespace ci;
using namespace ci::app;
using namespace std;


@implementation MyCCGLView

/**
 *	The prepareSettings & setup method
 */

- (void)prepareSettings
{
    [self enableAntiAliasing];
    frameRate = 30;
}

- (void)setup
{
    // Comment the following line to simply override, if you want to not animate
    // automatically, to change the default viewport, to not use CCGLTouch's OpenGLES
    // default params... Check this method in the super class implementation for
    //  more details on what happens.
    [super setup];
    
    
    Url url("http://www.dave-cole.com/tmp/been.jpg");
    mChannel = Channel32f( loadImage( loadUrl(url)));
    //myImage = gl::Texture( loadImage( loadUrl( url ) ) );
    
    //pc.addParticles(1000);
    mRenderParticles = true;
    mRenderImage = false;
    mMouseLoc = Vec2i(0,0);
    
    pc = NewParticleController(RESOLUTION, [self getWindowWidth], [self getWindowHeight]);

    /*
    
    // setup the camera
	mCam.lookAt( Vec3f(-100.0f, 20.0f, 10.0f), Vec3f::zero() );
	mCam.setPerspective( 60.0f, [self getWindowAspectRatio], 1.0f, 1000.0f );
	
    // init value
    mCubeSize = 10;
     
    */
}

/*
- (void)update
{
    //[super update];
    
    }
*/


/**
 *  The draw method
 */

- (void)draw
{
    // UPDATE routines
    pc.update(mChannel, mMouseLoc);

    
    
    // clear out the window with black
	
    gl::clear( Color( 0, 0, 0 ) );
    //gl::draw(myImage, getWindowBounds());
    
    //float x = cos(getElapsedSeconds()) * 20 + getWindowWidth()/2;
    //float y = sin(getElapsedSeconds()) * 20 + getWindowHeight()/2;
    
    pc.draw();
    
    /*
    
	// this pair of lines is the standard way to clear the screen in OpenGL
	gl::clear( Color( 0.9f, 0.9f, 0.9f ), true );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // use the camera
    gl::setMatrices( mCam );
    
    // draw a rotating cube
	glPushMatrix();
    glRotatef(5 * frameCount, 0.0f, 1.0f, 0.0f);
	gl::drawColorCube( Vec3f::zero(), Vec3f(mCubeSize, mCubeSize, mCubeSize) );
	glPopMatrix();
     */
}


/**
 * overridden mouse/touch handlers
 */
- (void)mouseDrag:(ci::app::MouseEvent)event {
    [super mouseDrag:event];
    mMouseLoc = event.getPos();
}

- (void)mouseDown:(ci::app::MouseEvent)event {
    [super mouseDown:event];
    
}


/**
 *  incoming from controller
 */

- (void)setCubeSize:(float)size
{
    //mCubeSize = size * 30 + 10;
    
    //console() << "mCubeSize: " << mCubeSize << endl;
    pc.setTime(size);
}

@end
