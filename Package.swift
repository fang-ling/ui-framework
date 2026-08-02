// swift-tools-version: 6.3

//===--------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//
//
//  Package.swift
//  ui-kit
//
//  Created by Fang Ling on 2025/12/28.
//
//  This source file is part of the UIKit open source project
//
//  Copyright (c) 2025-2026 Fang Ling <fangling@fangl.ing>
//  Licensed under Apache License v2.0
//
//  See LICENSE for license information
//
//  SPDX-License-Identifier: Apache-2.0
//
//===--------------------------------------------------------------------------------------------------------------------------------------------------------------------------===//

import PackageDescription

let isDevelopment = false

let dependencies = [
  ("c-kit", "main"),
  ("core-animation-kit", "main"),
  ("core-foundation-kit", "main"),
  ("foundation-kit", "main"),
  ("javascript-core-kit", "main")
]

let package = Package(
  name: "ui-kit",
  products: [
    .library(name: "UIKit", targets: ["UIKit"])
  ],
  dependencies: dependencies.map { isDevelopment ? .package(path: "../\($0.0)") : .package(url: "https://github.com/fang-ling/\($0.0)", branch: $0.1) },
  targets: [
    .target(
      name: "UIKit",
      dependencies: [
        .product(name: "CKit", package: "c-kit"),
        .product(name: "CoreAnimationKit", package: "core-animation-kit"),
        .product(name: "CoreFoundationKit", package: "core-foundation-kit"),
        .product(name: "FoundationKit", package: "foundation-kit"),
        .product(name: "JavaScriptCoreKit", package: "javascript-core-kit")
      ]
    )
  ]
)
