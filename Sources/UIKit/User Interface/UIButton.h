/*
 *  UIButton.h
 *  ui-kit
 *
 *  Created by Fang Ling on 2026/5/31.
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

#import "UIControl.h"
#import "UIButtonConfiguration.h"
#import "../Text/UILabel.h"

#import <CKit/CKit.h>

C_ASSUME_NONNULL_BEGIN

@class UIButton;

/**
 * A closure to update the configuration of a button.
 *
 * - Parameter button: The button to update.
 */
typedef void (^UIButtonConfigurationUpdateHandler)(UIButton* button);

/**
 * A control that executes your custom code in response to user interactions.
 *
 * When you tap a button, or select a button that has focus, the button performs
 * any actions attached to it. You communicate the purpose of a button using a
 * text label, an image, or both. The appearance of buttons is configurable, so
 * you can tint buttons or format titles to match the design of your app.
 *
 * ## Topics
 *
 * ### Creating buttons from a configuration object
 *
 * - ``makeButtonWithConfiguration:primaryAction:``
 *
 * ### Managing the appearance with a configuration object
 *
 * - ``configuration``
 * - ``setNeedsUpdateConfiguration``
 * - ``updateConfiguration``
 * - ``configurationUpdateHandler``
 * - ``UIButtonConfigurationUpdateHandler``
 *
 * ### Managing the title
 *
 * - ``titleLabel``
 */
@interface UIButton: UIControl

/**
 * The configuration for the button's appearance.
 *
 * Setting a configuration opts the button into a configuration system based on
 * ``UIButtonConfiguration``.
 */
@property (nonatomic, copy) UIButtonConfiguration* configuration;

/**
 * A view that displays the value of the ``currentTitle`` property for a button.
 *
 * Although this property is read-only, its own properties are read/write. Use
 * these properties primarily to configure the text of the button. For example:
 *
 * ```objective-c
 * button.titleLabel.font = [UIFont makeSystemFontOfSize:12];
 * ```
 *
 * Do not use the label object to set the text color or the shadow color.
 * Instead, use the ``setTitleColor:forState:`` and
 * ``setTitleShadowColor:forState:`` methods of this class to make those
 * changes. To set the actual text of the label, use ``setTitle:forState:``
 * (`button.titleLabel.text` does not let you set the text).
 *
 * The ``titleLabel`` property returns a value even if the button has not been
 * displayed yet. The value of the property is `nil` for system buttons.
 */
@property (nullable, nonatomic, readonly) UILabel* titleLabel;

/**
 * A closure that executes when the button state changes.
 *
 * Use this property as an alternative to overriding ``updateConfiguration``.
 * Set a closure to respond to button state changes by updating the button
 * configuration.
 */
@property (nullable, nonatomic, copy)
  UIButtonConfigurationUpdateHandler configurationUpdateHandler;

/**
 * Creates a new button with the specified configuration and registers the
 * primary action event.
 *
 * - Parameters:
 *   - configuration: The button configuration.
 *   - primaryAction: The action to perform for the
 *     ``kUIControlEventPrimaryActionTriggered`` control event.
 *
 * - Returns: A new button.
 */
+ (instancetype)
  makeButtonWithConfiguration:(UIButtonConfiguration*)configuration
                primaryAction:(UIAction*)primaryAction;

/**
 * Requests the system update the button configuration.
 *
 * Call this method to make the system call ``updateConfiguration``. The system
 * calls this method automatically when the button's state changes. If you call
 * this method multiple times before the system calls ``updateConfiguration``,
 * the system calls ``updateConfiguration`` once.
 */
- (void)setNeedsUpdateConfiguration;

/**
 * Updates the button configuration in response to a button state change.
 *
 * Override this method in your subclass to respond changes to the button's
 * state. Make any necessary changes and update the button's configuration.
 *
 * Don't call this method directly. Call ``setNeedsUpdateConfiguration`` to
 * request an update to your button.
 */
- (void)updateConfiguration;

@end

C_ASSUME_NONNULL_END
