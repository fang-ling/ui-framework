/*
 *  UIImageView.m
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

#import "UIImageView.h"

#import "UISymbolImageView.h"
#import "../Graphics/UIImage+Private.h"

#import <CoreAnimationKit/CoreAnimationKit.h>
#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@implementation UIImageView

+ (Class)layerClass {
  return CoreAnimationImageLayer.class;
}

+ (instancetype)makeImageViewWithImage:(UIImage*)image {
  if (image.type == kUIImageTypeSymbol) {
    return [[_UISymbolImageView alloc] initWithImage:image];
  }

  let frame = CoreFoundationRectangleMake(
    0,
    0,
    image.size.width,
    image.size.height
  );
  let imageView = [[UIImageView alloc] initWithFrame:frame];

  imageView.image = image;

  return imageView;
}

- (void)setImage:(UIImage*)image {
  self->_image = image;
  self.needsDisplay = yes;
}

- (void)setTintColor:(nullable UIColor*)tintColor {
  self->_tintColor = tintColor;

  self.needsDisplay = yes;
}

/* MARK: - CoreAnimationLayerDelegate Implementation */
- (void)displayLayer:(CoreAnimationLayer*)layer {
  [super displayLayer:layer];

  if (self.image && self.image.type == kUIImageTypeAsynchronousImage) {
    [JavaScriptCoreContext updateNode:layer.contents
                        sourceContent:self.image.content];
  }
}

@end

C_ASSUME_NONNULL_END
