//
//  MyCCGLView.h
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

#import "CCGLTouchView.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "NewParticleController.h"


@interface MyCCGLView : CCGLTouchView {
	CameraPersp mCam;
    float mCubeSize;
    
    gl::Texture myImage;
    NewParticleController pc;
    //NewParticle p;
    Channel32f mChannel;
    bool mRenderImage;
    bool mRenderParticles;
    Vec2i mMouseLoc;
}

/**
 *  incoming from controller
 */

- (void)setCubeSize:(float)size;

@end
