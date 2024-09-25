# Copyright (C) 2024 twyleg
set(NAMESPACE playground_qml_live_image_viewer)
set(MODULE engine)

set(TARGET_NAME "${NAMESPACE}_${MODULE}")

#
# find packages
#
find_package(fmt REQUIRED)
find_package(Boost COMPONENTS REQUIRED system)
find_package(OpenCV REQUIRED)

#
# add source files to target
#
add_library(${TARGET_NAME}
    Camera/CameraModel.cc
    Camera/CameraModel.h
    Matrix/HomogenousTransformationMatrix.cc
    Matrix/HomogenousTransformationMatrix.h
    Shape/Shape.cc
    Shape/Shape.h
    FPSCounter/FPSCounter.cc
    FPSCounter/FPSCounter.h
    RenderSystem.cc
    RenderSystem.h
    Engine.cc
    Engine.h
    ClippingSpace/ClippingSpace.cc
    ClippingSpace/ClippingSpace.h
    Vector/Vectors.cc
    Vector/Vectors.h
    Color/Color.cc
    Color/Color.h
)

add_library("${NAMESPACE}::${MODULE}" ALIAS ${TARGET_NAME})

#
# set target properties
#
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 17
        INCLUDE_CURRENT_DIR ON
        AUTOMOC ON
        AUTORCC ON
)

#
# link against libs
#
target_link_libraries(${TARGET_NAME}
    playground_qml_live_image_viewer::core
    playground_qml_live_image_viewer::ui
    fmt::fmt
    Boost::system
    ${OpenCV_LIBS}
)

#
# add parent folder to targets include directories
#
target_include_directories(${TARGET_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../
    PUBLIC ${OpenCV_INCLUDE_DIRS}
    
)
