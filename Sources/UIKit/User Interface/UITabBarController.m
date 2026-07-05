/*
 *  UITabBarController.m
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

#import "UITabBarController.h"

#import "UIScreen.h"

#import <JavaScriptCoreKit/JavaScriptCoreKit.h>

C_ASSUME_NONNULL_BEGIN

@interface UITabBarController ()

@property (nonatomic) UIView* contentView;
@property (nonatomic, readwrite) UITabBar* tabBar;
@property (nonatomic) CInteger selectedIndex;

@end

@implementation UITabBarController

- (instancetype)initWithTabs:(FoundationArray<UITab*>*)tabs {
  if (!(self = [super init])) {
    return nil;
  }

  self.tabs = tabs;

  return self;
}

- (void)setSelectedTab:(nullable UITab*)selectedTab {
  if (self->_selectedTab == selectedTab) {
    return;
  }

  if (self->_selectedTab) {
    [self->_selectedTab.viewController.view removeFromSuperview];
    [self->_selectedTab.viewController removeFromParentViewController];
  }

  self->_selectedTab = selectedTab;

  if (selectedTab) {
    [self addChildViewController:selectedTab.viewController];
    selectedTab.viewController.view.frame = self.contentView.bounds;
    [self.contentView addSubview:selectedTab.viewController.view];
  }

  self.tabBar.selectedItem = selectedTab;
}

- (UITabBar*)tabBar {
  if (!self->_tabBar) {
    let frame = CoreFoundationRectangleMake(
      0,
      UIScreen.mainScreen.bounds.size.height - 83,
      UIScreen.mainScreen.bounds.size.width,
      83
    );
    self->_tabBar = [[UITabBar alloc] initWithFrame:frame];
    self->_tabBar.delegate = self;
    [self->_tabBar setItems:self.tabs animated:yes];

    [self.view addSubview:self->_tabBar];
  }

  return self->_tabBar;
}

- (void)viewDidLoad {
  [super viewDidLoad];

  [self setupContentView];

  if (self.tabs.count > 0) {
    self.selectedTab = [self.tabs objectAtIndex:0];
  }
}

- (void)setupContentView {
  self.contentView = [[UIView alloc] initWithFrame:UIScreen.mainScreen.bounds];

  [self.view addSubview:self.contentView];
}

/* MARK: - UITabBarDelegate Implementation */
- (void)tabBar:(UITabBar*)tabBar didSelectItem:(UITab*)item {
  self.selectedTab = item;
}

@end

C_ASSUME_NONNULL_END
