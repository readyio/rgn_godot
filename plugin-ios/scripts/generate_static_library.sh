#!/bin/bash
set -e

# Compile static libraries

plugin="rgn-iac"

# ARM64 Device
scons target=$1 arch=arm64 version=$2
# ARM7 Device
scons target=$1 arch=armv7 version=$2
# x86_64 Simulator
scons target=$1 arch=x86_64 simulator=yes version=$2

# Creating a fat libraries for device and simulator
# lib<plugin>.<arch>-<simulator|ios>.<release|debug|release_debug>.a
lipo -create "./bin/lib$plugin.x86_64-simulator.$1.a" \
    "./bin/lib$plugin.armv7-ios.$1.a" \
    "./bin/lib$plugin.arm64-ios.$1.a" \
    -output "./bin/$plugin.$1.a"