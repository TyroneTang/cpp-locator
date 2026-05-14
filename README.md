## Compile commands
From `/workspace/project`:

1. Configure (only needed first time, or after editing CMakeLists/presets):


`cmake --preset linux-gcc`
This creates the build files under build/linux-gcc/ and tells CMake to use g++ with the vcpkg toolchain.

for clang use:
`cmake --preset linux-clang`

2. Build (Debug):


`cmake --build --preset linux-gcc-debug`
for clang:
`cmake --build --preset linux-clang-debug`


3. Run the resulting executable:


`./build/linux-gcc/Debug/Rocket`
The binary is named Rocket because of project(Rocket ...) in CMakeLists.txt:7.

## For a release build instead

`cmake --build --preset linux-gcc-release`
`./build/linux-gcc/Release/Rocket`