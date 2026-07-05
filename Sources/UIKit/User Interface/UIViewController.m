/*
 *  UIViewController.m
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

#import "UIViewController.h"

#import "UIScreen.h"

#import <FoundationKit/FoundationKit.h>

C_ASSUME_NONNULL_BEGIN

@interface UIViewController () {
  UIView* _view;
  FoundationMutableArray* _childViewControllers;
}

@property (nonatomic, weak, readwrite) UIViewController* parentViewController;

@end

@implementation UIViewController

- (UIView*)view {
  if (self->_view == nil) {
    [self loadView];
  }

  return self->_view;
}

- (void)setView:(UIView*)view {
  if (self->_view) {
    self->_view.nextResponder = nil;
  }
  self->_view = view;
  self->_view.nextResponder = self;
}

- (CBoolean)isViewLoaded {
  return self->_view != nil;
}

- (void)loadView {
  self.view = [[UIView alloc] initWithFrame:UIScreen.mainScreen.bounds];
  [self viewDidLoad];
}

- (void)viewDidLoad { }

- (FoundationArray<UIViewController*>*)childViewControllers {
  if (self->_childViewControllers == nil) {
    self->_childViewControllers = [FoundationMutableArray makeArray];
  }

  /* TODO: copy */
  return self->_childViewControllers;
}

- (void)addChildViewController:(UIViewController*)childController {
  if (childController.parentViewController) {
    [childController removeFromParentViewController];
  }

  if (self->_childViewControllers == nil) {
    self->_childViewControllers = [FoundationMutableArray makeArray];
  }

  [self->_childViewControllers appendObject:childController];
  childController.parentViewController = self;
}

- (void)removeFromParentViewController {
  if (self.parentViewController) {
    [self.parentViewController->_childViewControllers
     removeAllObjectsWhere:^CBoolean(ObjectiveCAnyObject object) {
      return [object isEqual:self];
    }];
    self.parentViewController = nil;
  }
}

@end

C_ASSUME_NONNULL_END
