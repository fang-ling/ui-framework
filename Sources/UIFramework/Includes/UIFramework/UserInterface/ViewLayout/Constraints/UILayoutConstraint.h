/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  UILayoutConstraint.h
 *  ui-framework
 *
 *  Created by Fang Ling on 2026/11/28.
 *
 *  This source file is part of the UIFramework open source project
 *
 *  Copyright (c) 2025-2026 Fang Ling <fangling@fangl.ing>
 *  Licensed under Apache License v2.0
 *
 *  See LICENSE for license information
 *
 *  SPDX-License-Identifier: Apache-2.0
 *
 *===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*/

#ifndef UI_LAYOUT_CONSTRAINT_H
#define UI_LAYOUT_CONSTRAINT_H

#import <CFramework/CFramework.h>

#if C_TARGET_OS_APPLE

#import <UIKit/UIKit.h>

#endif

C_ASSUME_NONNULL_BEGIN

#if C_TARGET_OS_APPLE

@compatibility_alias UILayoutConstraint NSLayoutConstraint;

#endif

C_ASSUME_NONNULL_END

#endif
