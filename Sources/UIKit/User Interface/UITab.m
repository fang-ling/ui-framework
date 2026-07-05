/*
 *  UITab.m
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/6/14.
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

#import "UITab.h"

C_ASSUME_NONNULL_BEGIN

@interface UITab ()

@property (nonatomic, copy, readwrite) FoundationString* identifier;

@property (nonatomic, readwrite) UIViewController* viewController;

@property (nonatomic, copy)
  UIViewController* (^viewControllerProvider)(UITab*);

@end

@implementation UITab

- (instancetype)initWithTitle:(FoundationString*)title
                        image:(UIImage*)image
                   identifier:(FoundationString*)identifier
       viewControllerProvider:(UIViewController* (^)(UITab*))
                                viewControllerProvider {
  if (!(self = [super init])) {
    return nil;
  }

  self.title = title;
  self.image = image;
  self.identifier = identifier;
  self.viewControllerProvider = viewControllerProvider;

  return self;
}

- (UIViewController*)viewController {
  if (self->_viewController == nil) {
    self->_viewController = self.viewControllerProvider(self);
  }
  return self->_viewController;
}

@end

C_ASSUME_NONNULL_END
