#!/bin/bash
# Usage: ./release_xcframework.sh version

# Check if version is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <version>"
    exit 1
fi

# Get the directory of this script
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

version=$1

# Define different targets to build
targets=("debug" "release")

# Loop through each target
for target in "${targets[@]}"; do
    echo "Building $target for version $version"
    "$script_dir/generate_headers.sh" $version $target
    "$script_dir/generate_xcframework.sh" $target $version
done

# Update the binaries in the demo project
rm -rf "$script_dir/../../demo/ios/plugins/rgn/rgn.debug.xcframework"
rm -rf "$script_dir/../../demo/ios/plugins/rgn/rgn.release.xcframework"
mv -f "$script_dir/../bin/rgn.debug.xcframework" "$script_dir/../../demo/ios/plugins/rgn/rgn.debug.xcframework"
mv -f "$script_dir/../bin/rgn.release.xcframework" "$script_dir/../../demo/ios/plugins/rgn/rgn.release.xcframework"

# Remove the binaries
rm "$script_dir/../bin/librgn.arm64-ios.debug.a"
rm "$script_dir/../bin/librgn.arm64-ios.release.a"
rm "$script_dir/../bin/librgn.arm64-simulator.debug.a"
rm "$script_dir/../bin/librgn.arm64-simulator.release.a"
rm "$script_dir/../bin/librgn.armv7-ios.debug.a"
rm "$script_dir/../bin/librgn.armv7-ios.release.a"
rm "$script_dir/../bin/librgn.x86_64-simulator.debug.a"
rm "$script_dir/../bin/librgn.x86_64-simulator.release.a"
rm "$script_dir/../bin/rgn-device.debug.a"
rm "$script_dir/../bin/rgn-device.release.a"
rm "$script_dir/../bin/rgn-simulator.debug.a"
rm "$script_dir/../bin/rgn-simulator.release.a"

echo "All builds completed successfully."