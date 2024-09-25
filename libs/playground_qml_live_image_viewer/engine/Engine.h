// Copyright (C) 2024 Marvin-VW
#pragma once

#include "RenderSystem.h"
#include "Shape.h"
#include "CameraModel.h"
#include "HomogenousTransformationMatrix.h"
#include "ClippingSpace.h"
#include "Vectors.h"
#include "Color.h"
#include "Window.h"
#include <opencv2/core.hpp>
#include <vector>
#include "image_processing.h"

class Engine {
public:
    Engine(int frame_width, int frame_height, playground_qml_live_image_viewer::ui::ParameterModel& parameterModel);
    ~Engine();

    cv::Mat run(cv::Mat frame);
    RenderSystem* renderer;
    CameraModel* camera;

    playground_qml_live_image_viewer::ui::ParameterModel& parameterModel;

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
