/*
 *  UITabBar.h
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

#import "UITab.h"
#import "UITabBarAppearance.h"
#import "UIView.h"

#import <CKit/CKit.h>

C_ASSUME_NONNULL_BEGIN

@class UITabBar;

/**
 * A protocol defines optional methods for a delegate of a UITabBar object.
 *
 * The ``UITabBar`` class provides the ability for the user to reorder, remove,
 * and add items to the tab bar; this process is referred to as customizing the
 * tab bar. The tab bar delegate receives messages when customizing occurs.
 *
 * ## Topics
 *
 * ### Customizing tab bars
 *
 * - ``tabBar:didSelectItem:``
 */
@protocol UITabBarDelegate

@optional

/**
 * Sent to the delegate when the user selects a tab bar item.
 *
 * - Parameters:
 *   - tabBar: The tab bar that is being customized.
 *   - item: The tab bar item that was selected.
 */
- (void)tabBar:(UITabBar*)tabBar didSelectItem:(UITab*)item;

@end

/**
 * A control that displays one or more buttons in a tab bar for selecting
 * between different subtasks, views, or modes in an app.
 *
 * Typically, you use tab bars in conjunction with a ``UITabBarController``
 * object, but you can also use them as standalone controls in your app. Tab
 * bars always appear across the bottom edge of the screen and display the
 * contents of one or more ``UITabBarItem`` objects. A tab bar's appearance can
 * be customized with a background image or tint color to suit the needs of your
 * interface. Tapping an item selects and highlights that item, and you use the
 * selection of the item to enable the corresponding mode for your app.
 *
 * A ``UITabBarController`` object provides its own tab bar object and you must
 * configure the object provided to you. When creating a tab bar
 * programmatically, use the ``initWithFrame:`` method or another view
 * initializer method to set its initial configuration. Use the methods of this
 * class to configure the appearance of the tab bar. For tab bars you create
 * yourself, you also use the methods of this class to specify the items
 * displayed by the tab bar.
 *
 * > Note: The ``UITabBar`` class and ``UIToolbar`` classes have similar
 *   appearances but different purposes. Use tab bars to convey and change your
 *   app's mode. Use toolbars to present the user with a set of actions that are
 *   relevant to the currently presented content.
 *
 * A tab bar reports selections and user customizations to its delegate object.
 * For tab bars you create yourself, use the delegate to respond to selections
 * or to the addition, removal, or reordering of items in the tab bar. (A
 * ``UITabBarController`` object acts as the delegate for the tab bar it
 * manages.) For more information on implementing a tab bar delegate, see
 * ``UITabBarDelegate``.
 *
 * ### Configure the tab bar items
 *
 * How you configure items at design time depends on whether your tab bar is
 * associated with a ``UITabBarController`` object:
 *
 *   - To configure the tab bar associated with a ``UITabBarController`` object,
 *     configure the view controllers associated with the tab bar controller.
 *     The tab bar automatically obtains its items from the ``tab`` property of
 *     each view controller associated with the tab bar controller.
 *   - To configure tab bar items directly, use the ``setItems:animated:``
 *     method of the tab bar itself.
 *
 * A tab bar displays all of its tabs onscreen at once, using the
 * ``itemPositioning`` property to determine how to position items in the
 * available space. If you have more items than can fit in the available space,
 * display only a subset of them and let the user select which tabs are
 * displayed. The ``beginCustomizingItems:`` method displays an interface for
 * selecting which tab bar items to display.
 *
 * The contents of each item are stored in a ``UITab`` object. Each item
 * contains a title and an image to display in the tab. You can also use tab bar
 * items to add a badge to the corresponding tab. For more information about
 * creating and configuring items, see ``UITab``.
 *
 * ### Respond to tab selections
 *
 * For tab bars with an associated tab bar controller, the tab bar controller
 * automatically manages selections and displays the appropriate view
 * controller. The only time you have to manage selections yourself is when you
 * create the tab bar without a tab bar controller. The tab bar reports
 * selections to the ``tabBar:didSelectItem:`` method of its ``delegate``
 * object, which you can use to respond to selection changes. For more
 * information about implementing the delegate object, see ``UITabBarDelegate``.
 *
 * ## Topics
 *
 * ### Customizing the tab bar behavior
 *
 * - ``delegate``
 * - ``UITabBarDelegate``
 *
 * ### Configuring tab bar items
 *
 * - ``items``
 * - ``setItems:animated:``
 * - ``selectedItem``
 *
 * ### Customizing tab bar appearance
 *
 * - ``standardAppearance``
 * - ``scrollEdgeAppearance``
 */
@interface UITabBar: UIView

/**
 * The tab bar's delegate object.
 */
@property (nullable, nonatomic, weak)
  ObjectiveCAnyObject<UITabBarDelegate> delegate;

/**
 * The items displayed by the tab bar.
 *
 * This property contains an array of ``UITab`` objects, each of which
 * corresponds to a tab displayed by the tab bar. The order of the items in this
 * property corresponds to the order of the items onscreen. You can use this
 * property to access the items as needed.
 *
 * For tab bars you create, you can assign a new set of items to this property
 * to change the displayed items. Changing the items replaces them immediately
 * without animations. You must not modify this property if the tab bar is
 * managed by a ``UITabBarController`` object, and doing so raises an exception.
 * When the tab bar is owned by a tab bar controller, use the tab bar
 * controller's methods to make changes.
 *
 * The default value of this property is `nil`.
 */
@property (nullable, nonatomic, copy) FoundationArray<UITab*>* items;

/**
 * The currently selected item on the tab bar.
 *
 * Use this property to get the currently selected item. If you change the value
 * of this property, the tab bar selects the corresponding item and updates the
 * tab bar's appearance accordingly. Set the property to `nil` to clear the
 * selection.
 *
 * The default value for this property is `nil`.
 */
@property (nullable, nonatomic, weak) UITab* selectedItem;

/**
 * The appearance settings for a standard-height tab bar.
 *
 * The default value of this property is an appearance object containing the
 * system's default appearance settings.
 */
@property (nonatomic, copy) UITabBarAppearance* standardAppearance;

/**
 * The appearance settings for the tab bar when the edge of scrollable content
 * aligns with the edge of the tab bar.
 *
 * When a tab bar controller contains a tab bar and a scroll view, part of the
 * scroll view's content appears underneath the tab bar. If the edge of the
 * scrolled content reaches that bar, UIKit applies the appearance settings in
 * this property.
 *
 * If the value of this property is `nil`, UIKit uses the value of the tab bar's
 * ``standardAppearance`` property, modified to have a transparent background.
 * If no tab bar controller manages your tab bar, UIKit ignores this property
 * and uses the tab bar's standard appearance.
 *
 * You can customize the appearance for specific tab bar items with the
 * ``scrollEdgeAppearance`` property of ``UITab``.
 */
@property (nullable, nonatomic, copy) UITabBarAppearance* scrollEdgeAppearance;

/**
 * Sets the items on the tab bar, optionally animating any changes into
 * position.
 *
 * Use this method to make changes to the currently visible items at runtime.
 * Calling this method on a tab bar that is managed by a ``UITabBarController``
 * object raises an exception. When the tab bar is owned by a tab bar
 * controller, use the tab bar controller's methods to make changes to items.
 *
 * - Parameters:
 *   - items: The array of ``UITab`` objects to display.
 *   - animated: A Boolean indicating whether changes should be animated.
 *     Specify `yes` to animate changes or `no` to display the new items without
 *     animations. When animations are enabled, the tab bar fades out removed
 *     items and fades in new items, adjusting the spacing between items as
 *     needed.
 */
- (void)setItems:(FoundationArray<UITab*>*)items
        animated:(CBoolean)animated;

@end

C_ASSUME_NONNULL_END
