/*===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===*
 *
 *  UIDirectionalRectangleEdge.h
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

#ifndef UI_DIRECTIONAL_RECTANGLE_EDGE_H
#define UI_DIRECTIONAL_RECTANGLE_EDGE_H

#import <CFramework/CFramework.h>

#if C_TARGET_OS_APPLE

#import <UIKit/UIKit.h>

#endif

C_ASSUME_NONNULL_BEGIN

#if C_TARGET_OS_APPLE

typedef NSDirectionalRectEdge UIDirectionalRectangleEdge;

#define UIDirectionalRectangleEdgeLeading NSDirectionalRectEdgeLeading

#endif

C_ASSUME_NONNULL_END

#endif
