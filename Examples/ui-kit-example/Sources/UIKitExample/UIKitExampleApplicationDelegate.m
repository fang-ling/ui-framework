/*
 *  UIKitExampleApplicationDelegate.m
 *  ui-kit-example
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

#import "UIKitExampleApplicationDelegate.h"

#import "UIKitExampleViewController.h"

C_ASSUME_NONNULL_BEGIN

@interface UIKitExampleApplicationDelegate ()

@property (nonatomic) UIWindow* window;

@end

@implementation UIKitExampleApplicationDelegate

- (void)applicationDidFinishLaunching {
  let firstTabImage =
    [UIImage makeImageWithSystemName:@"photo.fill.on.rectangle.fill"];
  let secondTabImage =
    [UIImage makeImageWithSystemName:@"rectangle.stack.fill"];

  let tabBarController = [[UITabBarController alloc] initWithTabs:@[
    [[UITab alloc] initWithTitle:@"First"
                           image:firstTabImage
                      identifier:@"First Tab"
          viewControllerProvider:^UIViewController* (UITab* tab) {
      return [[UIKitExampleViewController alloc] initWithText:@"First Tab 1️⃣"];
    }],
    [[UITab alloc] initWithTitle:@"Second"
                           image:secondTabImage
                      identifier:@"Second Tab"
          viewControllerProvider:^UIViewController* (UITab* tab) {
      return [[UIKitExampleViewController alloc] initWithText:@"Second Tab 2️⃣"];
    }]
  ]];

  let appearance = [[UITabBarAppearance alloc] init];
  tabBarController.tabBar.standardAppearance = appearance;
  tabBarController.tabBar.scrollEdgeAppearance = appearance;

  self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
  self.window.rootViewController = tabBarController;
  [self.window makeKeyAndVisible];
}

@end

C_ASSUME_NONNULL_END
