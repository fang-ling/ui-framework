/*
 *  UIBarAppearance.h
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

#import "UIBlurEffect.h"
#import "../Graphics/UIColor.h"

#import <CKit/CKit.h>
#import <ObjectiveCKit/ObjectiveCKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An object for customizing the basic appearance of system bars.
 *
 * A ``UIBarAppearance`` object contains the common traits shared by navigation
 * bars, tab bars, and toolbars. When configuring a specific type of bar, you
 * usually instantiate the appropriate bar appearance subclass. However, you may
 * also create a ``UIBarAppearance`` object, configure its properties, and use
 * it to create new bar appearance objects in your app.
 *
 * ## Topics
 *
 * ### Creating a custom bar appearance object
 *
 * - ``init``
 *
 * ### Configuring the background appearance
 *
 * - ``backgroundEffect``
 *
 * ### Configuring the shadow appearance
 *
 * - ``shadowColor``
 */
@interface UIBarAppearance: ObjectiveCObject

/**
 * The blur effect to apply to the bar's background.
 *
 * The blur effect provides the base layer for the bar's appearance, and it
 * determines how much of the underlying content is visible. UIKit applies the
 * ``backgroundColor`` and ``backgroundImage`` on top of this effect.
 */
@property (nullable, nonatomic, copy) UIBlurEffect* backgroundEffect;

/**
 * The color to apply to the bar's custom or default shadow.
 *
 * UIKit uses this property and the ``shadowImage`` property to determine the
 * shadow's appearance. When ``shadowImage`` is `nil`, the bar displays a
 * default shadow tinted according to the value of this property. If this
 * property is `nil` or contains the ``clearColor`` color, the bar displays no
 * shadow.
 *
 * If ``shadowImage`` contains a template image, the bar uses the image for the
 * shadow and tints it using the value in this property. If this property is
 * `nil` or contains the ``clearColor`` color, the bar displays no shadow.
 * However, if ``shadowImage`` doesn't contain a template image, the bar
 * displays the image without applying the color in this property.
 */
@property (nullable, nonatomic, copy) UIColor* shadowColor;

/**
 * Creates a new bar appearance object containing default values.
 *
 * - Returns: A new bar appearance object containing default values for the
 *   current device idiom.
 */
- (instancetype)init;

@end

C_ASSUME_NONNULL_END
