/*
 *  UIVisualEffectView.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/6/20.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#import "UIVisualEffectView.h"

#import "UIBlurEffect.h"
#import "UIBlurEffect+Private.h"
#import "UIVisualEffectBackdropView.h"

#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@implementation UIVisualEffectView

- (instancetype)initWithEffect:(UIVisualEffect*)effect {
  if ([effect isKindOfClass:UIBlurEffect.class]) {
    let dummyRectangle = CoreFoundationRectangleMake(0, 0, 0, 0);

    if (!(self = [super initWithFrame:dummyRectangle])) {
      return nil;
    }

    self.effect = effect;

    let backdropView =
      [[_UIVisualEffectBackdropView alloc] initWithFrame:dummyRectangle];
    [self addSubview:backdropView];

    return self;
  } else {
    CDebuggingHaltWithMessage("*** UNSUPPORTED VISUAL EFFECT. ***");
  }
}

- (void)displayLayer:(CoreAnimationLayer*)layer {
  [super displayLayer:layer];

  if ([self.effect isKindOfClass:UIBlurEffect.class]) {
    let effect = (UIBlurEffect*)self.effect;

    [JavaScriptCoreContext updateNode:layer.contents
                        styleProperty:@"background"
                           styleValue:$(@"var(--%@)", effect.background)];
    [JavaScriptCoreContext updateNode:layer.contents
                        styleProperty:@"background-blend-mode"
                           styleValue:$(@"var(--%@)",
                                        effect.backgroundBlendMode)];
  }
}

- (void)layoutSubviews {
  [super layoutSubviews];

  if (self.subviews.count > 0) {
    ((UIView*)[self.subviews objectAtIndex:0]).frame =
      CoreFoundationRectangleMake(
        0,
        0,
        self.bounds.size.width,
        self.bounds.size.height
      );
  }
}

@end

C_ASSUME_NONNULL_END
