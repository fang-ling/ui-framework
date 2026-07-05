/*
 *  UIBlurEffect.h
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

#import "UIVisualEffect.h"

#import <CKit/CKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * Blur styles available for blur effect objects.
 *
 * ## Topics
 *
 * ### Adaptable styles
 *
 * - ``kUIBlurEffectStyleSystemChromeMaterial``
 */
typedef enum UIBlurEffectStyle {
  /**
   * An adaptable blur effect that creates the appearance of the system chrome.
   */
  kUIBlurEffectStyleSystemChromeMaterial
} UIBlurEffectStyle;

/**
 * An object that applies a blurring effect to the content layered behind a
 * visual effect view.
 *
 * Views that you add to the ``contentView`` of a visual effect view aren't
 * affected by the blur effect.
 *
 * ## Topics
 *
 * ### Creating a blur effect
 *
 * - ``makeEffectWithStyle:``
 *
 * ### Constants
 *
 * - ``UIBlurEffectStyle``
 */
@interface UIBlurEffect: UIVisualEffect

/**
 * Creates a blur effect with the designated style.
 *
 * - Parameter style: The intensity of the blur effect. See
 *   ``UIBlurEffectStyle`` for valid options.
 *
 * - Returns: The blur effect to be used by a ``UIVisualEffectView`` object.
 */
+ (instancetype)makeEffectWithStyle:(UIBlurEffectStyle)style;

@end

C_ASSUME_NONNULL_END
