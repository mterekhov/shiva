#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface CPPBridge : NSObject

- (void)launchEngineWithLayer:(nullable CALayer *) layer;
- (void)stopEngine;
- (void)drawableSizeWillChange: (CGSize)size;
- (void)drawFrame;
- (void)processKeyboardEventWithKeyCode: (NSInteger)keyCode;

@end

NS_ASSUME_NONNULL_END
