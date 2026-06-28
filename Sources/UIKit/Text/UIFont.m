/*
 *  UIFont.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/6/19.
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

#import "UIFont.h"

#import "UIFont+Private.h"

C_ASSUME_NONNULL_BEGIN

const UIFontWeight kUIFontWeightRegular = 400;

const UIFontWeight kUIFontWeightMedium = 510;

@interface UIFont ()

@property (nonatomic, readwrite) CFloatingPoint pixelSize;

@property (nonatomic, readwrite) CFloatingPoint lineHeight;

@end

@implementation UIFont

+ (instancetype)makeSystemFontOfSize:(CFloatingPoint)fontSize {
  return [UIFont makeSystemFontOfSize:fontSize weight:kUIFontWeightRegular];
}

+ (instancetype)makeSystemFontOfSize:(CFloatingPoint)fontSize
                              weight:(UIFontWeight)weight {
  let font = [[UIFont alloc] init];

  font.pixelSize = fontSize;
  font.weight = weight;

  if (fontSize == 10.0) {
    font.lineHeight = 11.933594;
  } else if (fontSize == 17) {
    font.lineHeight = 20.287109;
  }

  return font;
}

@end

C_ASSUME_NONNULL_END
