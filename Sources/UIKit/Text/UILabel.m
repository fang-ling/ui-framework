/*
 *  UILabel.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/3/22.
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

#import "UILabel.h"

#import "../Graphics/UIColor+Private.h"
#import "../Text/UIFont+Private.h"

#import <CoreFoundationKit/CoreFoundationKit.h>
#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@implementation UILabel

- (instancetype)initWithFrame:(CoreFoundationRectangle)frame {
  if (!(self = [super initWithFrame:frame])) {
    return nil;
  }

  self.font = [UIFont makeSystemFontOfSize:17];
  self.textColor = UIColor.labelColor;

  return self;
}

+ (Class)layerClass {
  return CoreAnimationParagraphLayer.class;
}

- (void)setText:(nullable FoundationString*)text {
  if (self->_text == text) {
    return;
  }

  self->_text = text;

  self.needsLayout = yes;
  self.needsDisplay = yes;
}

- (void)setFont:(nullable UIFont*)font {
  self->_font = font ?: [UIFont makeSystemFontOfSize:17];

  self.needsLayout = yes;
  self.needsDisplay = yes;
}

- (void)setTextColor:(nullable UIColor*)textColor {
  self->_textColor = textColor ?: UIColor.labelColor;

  self.needsDisplay = yes;
}

- (void)displayLayer:(CoreAnimationLayer*)layer {
  [super displayLayer:layer];

  /* Texts are vertically centered by default. */
  [layer.contents setStyleValue:@"flex" forProperty:@"display"];
  [layer.contents setStyleValue:@"center" forProperty:@"align-items"];

  /* Do not draw text outside the frame. */
  [layer.contents setStyleValue:@"hidden" forProperty:@"overflow"];

  [layer.contents setStyleValue:$(@"%fpx", self.font.pixelSize)
                    forProperty:@"font-size"];
  [layer.contents setStyleValue:$(@"%f", self.font.weight)
                    forProperty:@"font-weight"];
  [layer.contents setStyleValue:$(@"%fpx", self.font.lineHeight)
                    forProperty:@"line-height"];

  if (self.text) {
    [layer.contents setTextContent:self.text];
  }

  if (self.textColor) {
    [layer.contents setStyleValue:$(@"var(--%@)", self.textColor.name)
                      forProperty:@"color"];
  }
}

@end

C_ASSUME_NONNULL_END
