# Copyright (C) 2024 twyleg
cmake_minimum_required(VERSION 3.16.3)


project(playground_qml_live_image_viewer)

# Externals
add_subdirectory(external/googletest/)

# Libs
add_subdirectory(libs/playground_qml_live_image_viewer/core/)
add_subdirectory(libs/playground_qml_live_image_viewer/ui/)

# Apps
add_subdirectory(apps/playground_qml_live_image_viewer)

#Engine
add_subdirectory(Engine)

# Unit-Test
add_subdirectory(unit_tests/)
