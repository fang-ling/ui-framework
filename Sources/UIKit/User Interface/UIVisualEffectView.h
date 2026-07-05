/*
 *  UIVisualEffectView.h
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

#import "UIView.h"
#import "UIVisualEffect.h"

#import <CKit/CKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An object that implements some complex visual effects.
 *
 * Depending on the desired effect, the effect may affect content layered behind
 * the view or content added to the visual effect view's contentView. Apply a
 * visual effect view to an existing view and then apply a ``UIBlurEffect`` or
 * ``UIVibrancyEffect`` object to apply a blur or vibrancy effect to the
 * existing view. After you add the visual effect view to the view hierarchy,
 * add any subviews to the ``contentView`` property of the visual effect view.
 * Don't add subviews directly to the visual effect view itself.
 *
 * ### Set the correct alpha value
 *
 * When using the ``UIVisualEffectView`` class, avoid alpha values that are less
 * than `1`. Creating views that are partially transparent causes the system to
 * combine the view and all the associated subviews during an offscreen render
 * pass. ``UIVisualEffectView`` objects need to be combined as part of the
 * content they're layered on top of in order to look correct. Setting the alpha
 * to less than `1` on the visual effect view or any of its superviews causes
 * many effects to look incorrect or not show up at all.
 *
 * ### Use masks with a visual effect view
 *
 * Masks directly applied to a ``UIVisualEffectView`` are forwarded to the
 * internal views that provide the visual effect, including the ``contentView``
 * itself. You can also apply masks directly to the ``contentView``. Applying a
 * mask to a superview of a ``UIVisualEffectView`` object causes the effect to
 * fail, and an exception is thrown.
 *
 * Any mask provided to ``UIVisualEffectView`` isn't the view that actually
 * performs the mask. UIKit makes a copy of the view and applies it to each
 * subview. To reflect a size change to the mask, you must apply the change to
 * the original mask and reset it on the effect view.
 *
 * ### Capture a snapshot of a visual effect view
 *
 * Many effects require support from the window that hosts the
 * ``UIVisualEffectView``. Attempting to take a snapshot of only the
 * ``UIVisualEffectView`` results in a snapshot that doesn't contain the effect.
 * To take a snapshot of a view hierarchy that contains a
 * ``UIVisualEffectView``, you must take a snapshot of the entire
 * ``UIWindow`` or ``UIScreen`` that contains it.
 *
 * ## Topics
 *
 * ### Creating a visual effect view
 *
 * - ``initWithEffect:``
 *
 * ### Retrieving view information
 *
 * - ``effect``
 */
@interface UIVisualEffectView: UIView

/**
 * The visual effect provided by the view.
 *
 * The effect is either a ``UIBlurEffect`` or a ``UIVibrancyEffect``.
 */
@property (nullable, nonatomic, copy) UIVisualEffect* effect;

/**
 * Creates a new visual effect view with the designated visual effect.
 *
 * - Parameter effect: The ``UIVisualEffect`` you provide for the view. This can
 *   be a ``UIBlurEffect`` or a ``UIVibrancyEffect``.
 *
 * - Returns: The new view containing the designated visual effect.
 */
- (instancetype)initWithEffect:(UIVisualEffect*)effect;

@end

C_ASSUME_NONNULL_END
