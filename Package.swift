// swift-tools-version: 6.3

//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//
//
//  Package.swift
//  ui-framework
//
//  Created by Fang Ling on 2025/12/28.
//
//  This source file is part of the UIFramework open source project
//
//  Copyright (c) 2025-2026 Fang Ling <fangling@fangl.ing>
//  Licensed under Apache License v2.0
//
//  See LICENSE for license information
//
//  SPDX-License-Identifier: Apache-2.0
//
//===----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//

import PackageDescription

let package = Package(
  name: "ui-framework",
  products: [
    .library(name: "UIFramework", targets: ["UIFramework"])
  ],
  dependencies: [
    .package(path: "../c-framework"),
    .package(path: "../foundation-framework")
  ],
  targets: [
    .target(
      name: "UIFramework",
      dependencies: [
        .product(name: "CFramework", package: "c-framework"),
        .product(name: "FoundationFramework", package: "foundation-framework")
      ],
      publicHeadersPath: "Includes"
    )
  ]
)
