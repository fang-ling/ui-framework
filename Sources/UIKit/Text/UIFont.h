/*
 *  UIFont.h
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
#import <ObjectiveCKit/ObjectiveCKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * Constants that represent standard typeface styles.
 *
 * ## Topics
 *
 * ### Using system-defined font weights
 *
 * - ``kUIFontWeightRegular``
 * - ``kUIFontWeightMedium``
 */
typedef CFloatingPoint UIFontWeight;

/**
 * The regular font weight.
 */
extern const UIFontWeight kUIFontWeightRegular;

/**
 * The medium font weight.
 */
extern const UIFontWeight kUIFontWeightMedium;

/**
 * An object that provides access to the font's characteristics.
 *
 * Use ``UIFont`` to access your font's characteristics within your app. It also
 * provides the system with access to the glyph information, used during layout.
 * Font objects are immutable, so it's safe to use them from multiple threads in
 * your app.
 *
 * In Objective-C, don't create font objects using the ``alloc`` and ``init``
 * methods. Instead, use class methods of ``UIFont``, such as
 * ``makePreferredFontForTextStyle:``, to look up and retrieve the desired font
 * object. These methods check for an existing font object with the specified
 * characteristics and return it if it exists. Otherwise, they create a new font
 * object based on the desired font characteristics.
 *
 * ## Topics
 *
 * ### Creating System Fonts
 *
 * - ``makeSystemFontOfSize:``
 * - ``makeSystemFontOfSize:weight:``
 * - ``UIFontWeight``
 *
 * ### Getting Font Metrics
 *
 * - ``pixelSize``
 * - ``lineHeight``
 */
@interface UIFont: ObjectiveCObject

/**
 * The font's pixel size, or the effective vertical pixel size for a font with a
 * nonstandard matrix.
 */
@property (nonatomic, readonly) CFloatingPoint pixelSize;

/**
 * The height, in pixels, of text lines.
 */
@property (nonatomic, readonly) CFloatingPoint lineHeight;

/**
 * Returns the font object for standard interface items in the specified size.
 *
 * Instead of using this method to get a font, it's often more appropriate to
 * use ``makePreferredFontForTextStyle:`` because that method respects the
 * user's selected content size category.
 *
 * - Parameter fontSize: The size (in pixels) to which the font is scaled. This
 *   value must be greater than `0.0`.
 *
 * - Returns: A font object of the specified size.
 */
+ (instancetype)makeSystemFontOfSize:(CFloatingPoint)fontSize;

/**
 * Returns the font object for standard interface items in the specified size
 * and weight.
 *
 * Instead of using this method to get a font, it's often more appropriate to
 * use ``makePreferredFontForTextStyle:`` because that method respects the
 * user's selected content size category.
 *
 * - Parameters:
 *   - fontSize: The size (in pixels) to which the font is scaled. This value
 *     must be greater than `0.0`.
 *   - weight: The weight of the font, specified as a font weight constant. For
 *     a list of possible values, see ``UIFontWeight``. Avoid passing an
 *     arbitrary floating-point number for weight, because a font might not
 *     include a variant for every weight.
 *
 * - Returns: A font object of the specified size and weight.
 */
+ (instancetype)makeSystemFontOfSize:(CFloatingPoint)fontSize
                              weight:(UIFontWeight)weight;

@end

C_ASSUME_NONNULL_END
