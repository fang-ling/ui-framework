/*
 *  UITabBar.m
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

#import "UITabBar.h"

#import "UIButton.h"
#import "UIVisualEffectView.h"
#import "../Graphics/UIColor.h"

C_ASSUME_NONNULL_BEGIN

@implementation UITabBar

- (void)setItems:(FoundationArray<UITab*>*)items animated:(CBoolean)animated {
  self->_items = items;

  for (let i = self.subviews.count - 1; i >= 0; i -= 1) {
    let subview = (UIView*)self.subviews[i];
    if ([subview isKindOfClass:UIButton.class]) {
      [subview removeFromSuperview];
    }
  }

  for (let i = 0; i < items.count; i += 1) {
    let configuration = [UIButtonConfiguration makePlainButtonConfiguration];
    configuration.title = items[i].title;
    configuration.image = items[i].image;
    configuration.imagePlacement = kUIDirectionalRectangleEdgeTop;
    configuration.imagePadding = 4;

    @weakify(self)
    let action = [UIAction makeActionWithHandler:^(UIAction* action) {
      @strongify(self)

      [self setSelectedItem:items[i]];
      [self.delegate tabBar:self didSelectItem:items[i]];
    }];

    let button = [UIButton makeButtonWithConfiguration:configuration
                                         primaryAction:action];
    button.frame = CoreFoundationRectangleMake(
      i * self.frame.size.width / items.count,
      6,
      self.frame.size.width / items.count,
      40
    );
    button.titleLabel.font = [UIFont makeSystemFontOfSize:10
                                                   weight:kUIFontWeightMedium];

    [self addSubview:button];
  }

  self.needsLayout = yes;
  self.needsDisplay = yes;
}

- (void)setSelectedItem:(nullable UITab*)selectedItem {
  if (self->_selectedItem == selectedItem) {
    return;
  }

  self->_selectedItem = selectedItem;

  if (selectedItem) {
    let selectedIndex = 0;
    for (; selectedIndex < self.items.count; selectedIndex += 1) {
      if (self.items[selectedIndex] == selectedItem) {
        break;
      }
    }

    let buttonIndex = 0;
    for (UIView* subview in self.subviews) {
      if ([subview isKindOfClass:UIButton.class]) {
        let button = (UIButton*)subview;

        @weakify(self)
        button.configurationUpdateHandler = ^(UIButton* button) {
          @strongify(self)

          let configuration = button.configuration;

          configuration.baseForegroundColor = buttonIndex == selectedIndex
            ? UIColor.tintColor
            : [UIColor makeColorWithName:@"color-tab-unselected"];

          button.configuration = configuration;
        };

        [button setNeedsUpdateConfiguration];

        buttonIndex += 1;
      }
    }
  }
}

- (void)setStandardAppearance:(UITabBarAppearance*)standardAppearance {
  self->_standardAppearance = standardAppearance;

  if (standardAppearance.backgroundEffect) {
    let effect = standardAppearance.backgroundEffect;
    let backgroundView = [[UIVisualEffectView alloc] initWithEffect:effect];
    backgroundView.frame = CoreFoundationRectangleMake(
      0,
      0,
      self.bounds.size.width,
      self.bounds.size.height
    );
    [self insertSubview:backgroundView atIndex:0];

    let shadowView = [[UIView alloc] initWithFrame:CoreFoundationRectangleMake(
      0,
      -0.333,
      self.bounds.size.width,
      0.333
    )];
    shadowView.backgroundColor = standardAppearance.shadowColor;
    [self insertSubview:shadowView atIndex:1];
  }
}

@end

C_ASSUME_NONNULL_END
