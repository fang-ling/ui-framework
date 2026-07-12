/*
 *  UITab.h
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

#import "UIViewController.h"
#import "../Graphics/UIImage.h"

#import <CKit/CKit.h>
#import <FoundationKit/FoundationKit.h>
#import <ObjectiveCKit/ObjectiveCKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An object that manages a tab in a tab bar.
 *
 * To create a tab, call
 * ``initWithTitle:image:identifier:viewControllerProvider:``. In the closure,
 * return the view controller your app presents when someone selects the tab.
 * Then pass an array of tabs to your ``UITabBarController``
 * object's ``tabs`` property.
 *
 * ## Topics
 *
 * ### Creating tabs
 *
 * - ``initWithTitle:image:identifier:viewControllerProvider:``
 *
 * ### Accessing a tab's appearance
 *
 * - ``title``
 * - ``identifier``
 * - ``image``
 * - ``viewController``
 */
@interface UITab: ObjectiveCObject

/**
 * A tab's title.
 */
@property (nonatomic, copy) FoundationString* title;

/**
 * A string identifier for a tab.
 *
 * Each identifier must be unique across all the tabs managed by a
 * ``UITabBarController``.
 */
@property (nonatomic, copy, readonly) FoundationString* identifier;

/**
 * A tab's image.
 */
@property (nullable, nonatomic) UIImage* image;

/**
 * The view controller that the system presents when someone selects a tab.
 */
@property (nonatomic, readonly) UIViewController* viewController;

/**
 * Creates a tab object.
 *
 * - Parameters:
 *   - title: The tab's title.
 *   - image: The tab's image.
 *   - identifier: An identifier string for the tab. Each identifier must be
 *     unique across all the tabs managed by a ``UITabBarController``.
 *   - viewControllerProvider: The view controller that the system presents
 *     when someone selects the tab.
 */
- (instancetype)initWithTitle:(FoundationString*)title
                        image:(UIImage*)image
                   identifier:(FoundationString*)identifier
       viewControllerProvider:(UIViewController* (^)(UITab*))
                                viewControllerProvider;

@end

C_ASSUME_NONNULL_END
