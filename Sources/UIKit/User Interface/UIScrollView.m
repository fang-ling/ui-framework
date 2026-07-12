/*
 *  UIScrollView.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/7/11.
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

#import "UIScrollView.h"

#import <CoreAnimationKit/CoreAnimationKit.h>
#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@interface UIScrollView ()

@property (nonatomic) UIView* contentView;

@end

@implementation UIScrollView

- (instancetype)initWithFrame:(CoreFoundationRectangle)frame {
  if (!(self = [super initWithFrame:frame])) {
    return nil;
  }

  self.contentView =
    [[UIView alloc] initWithFrame:CoreFoundationRectangleMake(0, 0, 0, 0)];
  [super addSubview:self.contentView];

  self.contentSize = CoreFoundationSizeMake(0, 0);

  return self;
}

- (void)setContentSize:(CoreFoundationSize)contentSize {
  self->_contentSize = contentSize;
  self.contentView.frame = CoreFoundationRectangleMake(
    0,
    0,
    contentSize.width,
    contentSize.height
  );

  self.contentView.needsLayout = yes;
}

- (void)addSubview:(UIView*)view {
  [self.contentView addSubview:view];
}

- (void)insertSubview:(UIView*)view atIndex:(CInteger)index {
  [self.contentView insertSubview:view atIndex:index];
}

/* MARK: - CoreAnimationLayerDelegate Implementation */
- (void)displayLayer:(CoreAnimationLayer*)layer {
  [super displayLayer:layer];

  [layer.contents setStyleValue:@"auto" forProperty:@"overflow"];
}

@end

C_ASSUME_NONNULL_END
