/*
 *  UITabBarAppearance.h
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

#import "UIBarAppearance.h"

#import <CKit/CKit.h>

C_ASSUME_NONNULL_BEGIN

/**
 * An object for customizing the appearance of a tab bar.
 *
 * After creating a ``UITabBarAppearance`` object, use the methods and
 * properties of this class to specify the appearance of items in the tab bar.
 * Use the inherited properties from ``UIBarAppearance`` to configure the
 * background and shadow attributes of the tab bar itself.
 */
@interface UITabBarAppearance: UIBarAppearance

@end

C_ASSUME_NONNULL_END
