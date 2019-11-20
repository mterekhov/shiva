//
//  SOpenGLView.m
//  software
//
//  Created by Michael on 30/09/2019.
//  Copyright © 2019 Michael. All rights reserved.
//

#import "SOpenGLView.h"
#import "sgame.h"

static const CGFloat FramesPerSecond = 1.0f / 60.0f;

@interface SOpenGLView ()<NSGestureRecognizerDelegate>

@property (nonatomic, assign) NSTimeInterval animationInterval;
@property (nonatomic, strong) NSTimer *animationTimer;
@property (nonatomic, assign) spcShiva::SGame *shivaEngine;

@end

@implementation SOpenGLView

- (instancetype)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
    {
        return nil;
    }
    
    self.openGLContext.view = self;
    _animationInterval = FramesPerSecond;
    
    _shivaEngine = new spcShiva::SGame();
    _shivaEngine->updateScreenSize(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    
    [self startAnimation];
    
    return self;
}

- (void)dealloc {
    delete self.shivaEngine;
}

- (void)viewDidEndLiveResize
{
    [self stopAnimation];
    self.shivaEngine->updateScreenSize(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    [self startAnimation];
}

- (void)animationTimerHandler
{
    self.shivaEngine->processGameCycle();
    [self.openGLContext flushBuffer];
}

- (void)startAnimation
{
    self.animationTimer = [NSTimer scheduledTimerWithTimeInterval: self.animationInterval
                                                           target: self
                                                         selector: @selector(animationTimerHandler)
                                                         userInfo: nil
                                                          repeats: YES];
}

- (void)stopAnimation
{
    [self.animationTimer invalidate];
    self.animationTimer = nil;
}

#pragma mark - Key events -

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (void)keyDown:(NSEvent *)theEvent
{
    self.shivaEngine->processKeyboardEvent(theEvent.keyCode);
}

- (void)mouseUp:(NSEvent *)event
{
    self.shivaEngine->processMouseEvent(event.locationInWindow.x, event.locationInWindow.y);
}

@end
