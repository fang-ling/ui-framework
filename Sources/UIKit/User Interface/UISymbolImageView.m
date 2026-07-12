/*
 *  UISymbolImageView.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/6/6.
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

#import "UISymbolImageView.h"

#import "../Graphics/UIColor+Private.h"
#import "../Graphics/UIImage+Private.h"
#import "../Graphics/UIImageSymbolConfiguration+Private.h"

#import <CoreAnimationKit/CoreAnimationKit.h>
#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@implementation _UISymbolImageView

+ (Class)layerClass {
  return CoreAnimationSpanLayer.class;
}

- (instancetype)initWithImage:(UIImage*)image {
  if (!(self = [super initWithFrame:CoreFoundationRectangleMake(0, 0, 0, 0)])) {
    return nil;
  }

  self.image = image;

  return self;
}

- (void)setPreferredSymbolConfiguration:(nullable UIImageSymbolConfiguration*)
                                          preferredSymbolConfiguration {
  super.preferredSymbolConfiguration = preferredSymbolConfiguration;

  let styleText = $(
    @"font-size: %fpt; font-weight: %f",
    preferredSymbolConfiguration.pointSize,
    preferredSymbolConfiguration.weight
  );
  self.image.size = [JavaScriptCoreContext measureTextSize:self.image.content
                                                 styleText:styleText];
}

/* MARK: - CoreAnimationLayerDelegate Implementation */
- (void)displayLayer:(CoreAnimationLayer*)layer {
  [super displayLayer:layer];

  [layer.contents setTextContent:self.image.content];

  let configuration = (UIImageSymbolConfiguration*)self.image.configuration;
  if (self.preferredSymbolConfiguration) {
    configuration = self.preferredSymbolConfiguration;
  }

  if (
    configuration &&
    [configuration isKindOfClass:UIImageSymbolConfiguration.class]
  ) {
    [layer.contents setStyleValue:$(@"%fpt", configuration.pointSize)
                      forProperty:@"font-size"];
    [layer.contents setStyleValue:$(@"%d", configuration.weight)
                      forProperty:@"font-weight"];
  }

  if (self.tintColor) {
    [layer.contents setStyleValue:$(@"var(--%@)", self.tintColor.name)
                      forProperty:@"color"];
  }
}

@end

C_ASSUME_NONNULL_END
