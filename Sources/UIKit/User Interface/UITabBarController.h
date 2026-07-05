/*
 *  UITabBarController.h
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
#import "UITabBar.h"
#import "UIViewController.h"

C_ASSUME_NONNULL_BEGIN

/**
 * A container view controller that manages a multi-selection interface, where
 * the selection determines which child view controller to display.
 *
 * The tab bar interface displays tabs at the bottom of the window for
 * selecting between the different modes and for displaying the views for that
 * mode. This class is generally used as-is, but may also be subclassed.
 *
 * Each tab of a tab bar controller interface is associated with a custom view
 * controller. When the user selects a specific tab, the tab bar controller
 * displays the root view of the corresponding view controller, replacing any
 * previous views.
 *
 * ## Topics
 *
 * ### Creating tab bar controllers
 *
 * - ``initWithTabs:``
 *
 * ### Assigning tabs
 *
 * - ``tabs``
 *
 * ### Accessing the tab bar controller properties
 *
 * - ``tabBar``
 *
 * ### Managing the selected tab
 *
 * - ``selectedTab``
 */
@interface UITabBarController: UIViewController <UITabBarDelegate>

/**
 * An array of tabs that the tab bar displays.
 *
 * To set the tab bar's content, assign an array of ``UITab`` objects to this
 * property.
 */
@property (nonatomic, copy) FoundationArray<UITab*>* tabs;

/**
 * The currently selected tab, which can be a root tab or any of their
 * descendants.
 *
 * The default value for this property is `nil`.
 */
@property (nullable, nonatomic) UITab* selectedTab;

/**
 * The tab bar view associated with this controller.
 *
 * You should never attempt to manipulate the ``UITabBar`` object itself stored
 * in this property. If you attempt to do so, the tab bar view throws an
 * exception. To configure the items for your tab bar interface, you should
 * instead assign one or more custom view controllers to the ``tabs`` property.
 * The tab bar collects the needed tab bar items from the view controllers you
 * specify.
 */
@property (nonatomic, readonly) UITabBar* tabBar;

/**
 * Creates a tab bar controller with the specified tabs.
 *
 * - Parameter tabs: An array of tabs.
 */
- (instancetype)initWithTabs:(FoundationArray<UITab*>*)tabs;

@end

C_ASSUME_NONNULL_END
