cinder-uikit-demo
=================

A lab project that combines Cinder's Hello Cinder demo (http://libcinder.org/docs/v0.8.4/hello_cinder_chapter3.html) (C++) with UIKit (Obj-C) using CCGLTouch (http://cocoacid.org/ios/) - there's nothing earth shattering about this demo since its simply reusing a lot of boilerplate code but I wanted to save this repo so it can be a playground for me to tinker with integrating more Cinder functionality into my iOS apps.

The performance isn't great since CCGLTouch renders a UIImage of every frame of animation in order to place it into a UIView.

The XCode project is located in cinder_0.8.4_mac/CinderPad/CinderPad/ (I had to bundle in the cinder SDK and CCGLTouch as its default setup is to nest the folders in this way, not elegant, but it works...)