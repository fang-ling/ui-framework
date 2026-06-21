/*
 *  UIColor.h
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

#import <CKit/CKit.h>
#import <FoundationKit/FoundationKit.h>
#import <ObjectiveCKit/ObjectiveCKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An object that stores color data and sometimes opacity.
 *
 * Use color to customize your app's appearance, communicate status, and help
 * people visualize data.
 *
 * ``UIColor`` provides a list of class properties that create adaptable and
 * fixed colors such as blue, green, purple, and more. ``UIColor`` also offers
 * properties to specify system-provided colors for UI elements such as labels,
 * text, and buttons. You can create color objects by specifying color component
 * values such as RGB, hue, and saturation. You can also create colors from
 * other color objects and even create a pattern-based color from an image.
 *
 * > Important: Most developers have no need to subclass ``UIColor``. The only
 *   time subclassing might be necessary is if you require support for
 *   additional color spaces or color models. If you do subclass, the properties
 *   and methods you add must be safe to use from multiple threads.
 *
 * ## Topics
 *
 * ### Getting existing colors
 *
 * #### UI element colors
 *
 * ##### Label colors
 *
 * - ``labelColor``
 *
 * ##### Tint color
 *
 * - ``tintColor``
 *
 * ### Color creation
 *
 * #### Creating a color from component values
 *
 * - ``makeColorWithName:``
 */
@interface UIColor: ObjectiveCObject

/**
 * The color for text labels that contain primary content.
 */
@property (class, nonatomic, readonly) UIColor* labelColor;

/**
 * A color value that resolves at runtime based on the current tint color of the
 * app or trait hierarchy.
 */
@property (class, nonatomic, readonly) UIColor* tintColor;

/**
 * Creates a color object using the information from the named asset.
 *
 * - Parameter name: The name of the asset containing the color.
 *
 * - Returns: An initialized color object. The returned object uses the color
 *   space specified for the asset.
 */
+ (instancetype)makeColorWithName:(FoundationString*)name;

@end

C_ASSUME_NONNULL_END
