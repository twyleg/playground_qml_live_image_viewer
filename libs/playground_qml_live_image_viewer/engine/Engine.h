// Copyright (C) 2024 Marvin-VW
#pragma once

#include "RenderSystem.h"
#include "Shape/Shape.h"
#include "Camera/CameraModel.h"
#include "Matrix/HomogenousTransformationMatrix.h"
#include "ClippingSpace/ClippingSpace.h"
#include "Vector/Vectors.h"
#include "Color/Color.h"

#include <opencv2/core.hpp>
#include <vector>

class Engine {
public:
    Engine(int frame_width, int frame_height, playground_qml_live_image_viewer::ui::ParameterModel& parameterModel);
    ~Engine();

	cv::Mat run(cv::Mat& frame);
    RenderSystem* renderer;
    CameraModel* camera;

	playground_qml_live_image_viewer::ui::ParameterModel& mParameterModel;

private:
    Shape* shape;
    HomogenousTransformationMatrix* matrix;
    ClippingSpace* clipping;
    Vectors* vec;
    Color* color;

    std::vector<triangle> mesh;
    std::vector<triangle> visible_mesh;
    std::vector<triangle> clipped_mesh;

    cv::Mat engine_frame;

    float is_triangle_facing_camera(triangle& tri, cv::Vec3f cam);
};
